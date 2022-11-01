#include <stdio.h>

int main(void)
{
	typedef struct
	{
		char name[10];
		int stnum;
		int A;
		int B;
		int C;
		int D;
	}Student;

	FILE* fp;
	FILE* fp2;

	Student s1 = {0};


	int num;
	int sd = 1;
	int del;
	printf("1.정보입력  2.Display  3.저장  4.읽기  5.삭제\n");
	scanf("%d", &num);

	switch (num)
	{
	case 1:
		fp = fopen("a,bin", "wt");
		char str1[10] = "a,bin";
		if (fp == NULL)
		{
			puts("파일오픈실패!");
			return -1;
		}
		printf("학번, 이름, A,B,C,D과목들의 점수를 순서대로 입력해주세요! \n");
		scanf("%d %s %d %d %d %d", &s1.stnum, s1.name, &s1.A, &s1.B, &s1.C, &s1.D);
		fprintf(fp, "%d %s %d %d %d %d", s1.stnum, s1.name, s1.A, s1.B, s1.C, s1.D);
		printf("정보가 입력되었습니다.");
		fclose(fp);
		break;

	case 2:
		fp = fopen("a,bin", "rt");
		char str2[10] = "a,bin";
		if (fp == NULL)
		{
			puts("파일이 존재하지 않습니다.");
			return -1;
		}
		fscanf(fp, "%d %s %d %d %d %d", &s1.stnum, s1.name, &s1.A, &s1.B, &s1.C, &s1.D);
		printf("%d번 학생의 정보 \n", sd); sd++;
		printf("학번 : %d \n", s1.stnum); 
		printf("이름 : %s \n",s1.name);
		printf("A과목 점수 : %d \n", s1.A);
		printf("B과목 점수 : %d \n", s1.B);
		printf("C과목 점수 : %d \n", s1.C);
		printf("D과목 점수 : %d \n", s1.D);
		fclose(fp);
		break;

	case 3:
		fp = fopen("a,bin", "wt");
		if (fp == NULL)
		{
			puts("파일오픈실패!");
			return -1;
		}
		fprintf(fp, "%d %s %d %d %d %d", s1.stnum, s1.name, s1.A, s1.B, s1.C, s1.D);
		printf("정보가 파일이 저장되었습니다.");
		fclose(fp);
		break;

	case 4:
		fp = fopen("a,bin", "rt");
		if (fp == NULL)
		{
			puts("파일이 존재하지 않습니다.");
			return -1;
		}
		fscanf(fp, "%d %s %d %d %d %d", &s1.stnum, s1.name, &s1.A, &s1.B, &s1.C, &s1.D);
		printf("파일을 읽었습니다.");
		printf("%d", s1.stnum);
		fclose(fp);
		break;

	case 5:
		printf("삭제할 학생의 번호를 입력해주세요.\n");
		scanf("%d", &del);
		if (del == 1)
		{
			fp = fopen("a,bin", "wt");
			if (fp == NULL)
			{
				puts("파일오픈실패!");
				return -1;
			}
			for (int i = 0; i < 10; i++)
			{
				s1.name[i] = NULL;
			}
			s1.stnum = NULL ;
			s1.A = NULL;
			s1.B = NULL;
			s1.C = NULL;
			s1.D = NULL;
			fprintf(fp, "%d %s %d %d %d %d", s1.stnum, s1.name, s1.A, s1.B, s1.C, s1.D);
			fclose(fp);
			printf("%d번 학생의 정보를 삭제하엿습니다.", del);
		}
		else
		{
			printf("%d번 학생의 정보는 존재하지 않습니다.",del);
			return -1;
		}
		break;

	default:
		break;
	}

	return 0;
}