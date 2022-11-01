#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "disk.h"
#include "fs.h"

void FileSysInit(void)
{
    int i;

    DevCreateDisk();

    DevOpenDisk();

    char *pMem = (char*)malloc(BLOCK_SIZE);
    
    for(i = 7; i < FS_DISK_CAPACITY/BLOCK_SIZE; i++)
    {
        DevWriteBlock(i, pMem);
    }

    memset(pMem, 0, BLOCK_SIZE);
    
    for(i = 0; i < 7; i++)
    {
        DevWriteBlock(i, pMem);
    }

    free(pMem);
}

void SetInodeBytemap(int inodeno)
{
    char *pMem = (char*)malloc(BLOCK_SIZE);

    DevReadBlock(1, pMem);

    pMem[inodeno] = 1;

    DevWriteBlock(1, pMem);

    free(pMem);
}


void ResetInodeBytemap(int inodeno)
{
    char *pMem = (char*)malloc(BLOCK_SIZE);

    DevReadBlock(1, pMem);

    pMem[inodeno] = 0;

    DevWriteBlock(1, pMem);

    free(pMem);
}


void SetBlockBytemap(int blkno)
{
    char *pMem = (char*)malloc(BLOCK_SIZE);

    DevReadBlock(2, pMem);

    pMem[blkno] = 1;

    DevWriteBlock(2, pMem);

    free(pMem);
}


void ResetBlockBytemap(int blkno)
{
    char *pMem = (char*)malloc(BLOCK_SIZE);

    DevReadBlock(2, pMem);

    pMem[blkno] = 0;

    DevWriteBlock(2, pMem);

    free(pMem);
}


void PutInode(int inodeno, Inode* pInode)
{
    char *pMem = (char*)malloc(BLOCK_SIZE);
    
    int inodeIndex = 0;

    inodeIndex = ((inodeno%16)*32);
    
    pMem[inodeIndex] = pInode->allocBlocks;

    pMem[inodeIndex + 4] = pInode->size;

    pMem[inodeIndex + 8] = pInode->type;

    for(int i = 3; i < 7; i++)
    {
        pMem[inodeIndex + i * 4] = pInode->dirBlockPtr[i-3];
    }

    pMem[inodeIndex + 28] = pInode->indirectBlockPtr;

    DevWriteBlock((int)(3+inodeno/16), pMem);

    free(pMem);
}


void GetInode(int inodeno, Inode* pInode)
{
    char *pMem = (char*)malloc(BLOCK_SIZE);

    DevReadBlock((int)(3+inodeno/16), pMem);
    
    int inodeIndex=0;

    inodeIndex = ((inodeno%16)*32);

    pInode->allocBlocks = pMem[inodeIndex];

    pInode->size = pMem[inodeIndex + 4];

    pInode->type = pMem[inodeIndex + 8];

    for(int i = 3; i < 7; i++)
    {
        pInode->dirBlockPtr[i-3] = pMem[inodeIndex + i * 4];
    }

    pInode->indirectBlockPtr = pMem[inodeIndex + 28];

    free(pMem);
}


int GetFreeInodeNum(void)
{
    char *pMem = (char*)malloc(BLOCK_SIZE);
    
    DevReadBlock(1, pMem);

    for(int i = 0; i < 64; i++)
    {
        if(pMem[i] == 0)
            return i;
    }

    free(pMem);
}


int GetFreeBlockNum(void)
{
    char *pMem = (char*)malloc(BLOCK_SIZE);

    DevReadBlock(2, pMem);

    for(int i = 0; i < 512; i++)
    {
        if(pMem[i] == 0)
            return i;
    }

    free(pMem);
}

void PutIndirectBlockEntry(int blkno, int index, int number)
{
	char *pMem = (char*)malloc(BLOCK_SIZE);

    DevReadBlock(blkno, pMem);

    pMem[index*4] = number;

    DevWriteBlock(blkno, pMem);

    free(pMem);
}

int GetIndirectBlockEntry(int blkno, int index)
{
    char *pMem = (char*)malloc(BLOCK_SIZE);
    
    DevReadBlock(blkno, pMem);

    int num = pMem[index*4];

    return num;

    free(pMem);
}

void PutDirEntry(int blkno, int index, DirEntry* pEntry)
{
	char *pMem = (char*)malloc(BLOCK_SIZE);

    DevReadBlock(blkno, pMem);
	
	memcpy((pMem + index*32), pEntry, sizeof(DirEntry));

    DevWriteBlock(blkno, pMem);

    free(pMem);
}

int GetDirEntry(int blkno, int index, DirEntry* pEntry)
{	
	char *pMem = (char*)malloc(BLOCK_SIZE);

	DevReadBlock(blkno, pMem);

	memcpy((DirEntry*)pEntry, pMem + index*32, sizeof(DirEntry));

	if(((DirEntry*)pMem + index) -> inodeNum == INVALID_ENTRY)
		return -1;
	else
		return 1;

	free(pMem);
}

void RemoveIndirectBlockEntry(int blkno, int index)
{
    int *pMem = (int*)malloc(BLOCK_SIZE);

    DevReadBlock(blkno, (char*)pMem);

    pMem[index] = INVALID_ENTRY;

    DevWriteBlock(blkno, (char*)pMem);

    free(pMem);
}

void RemoveDirEntry(int blkno, int index)
{
    DirEntry *pMem = (DirEntry*)malloc(BLOCK_SIZE);

    DevReadBlock(blkno, (char*)pMem);

    (pMem + index) -> inodeNum = INVALID_ENTRY;

    DevWriteBlock(blkno, (char*)pMem);

    free(pMem);
}
