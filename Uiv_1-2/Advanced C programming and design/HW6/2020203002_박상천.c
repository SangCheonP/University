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
	printf("1.�����Է�  2.Display  3.����  4.�б�  5.����\n");
	scanf("%d", &num);

	switch (num)
	{
	case 1:
		fp = fopen("a,bin", "wt");
		char str1[10] = "a,bin";
		if (fp == NULL)
		{
			puts("���Ͽ��½���!");
			return -1;
		}
		printf("�й�, �̸�, A,B,C,D������� ������ ������� �Է����ּ���! \n");
		scanf("%d %s %d %d %d %d", &s1.stnum, s1.name, &s1.A, &s1.B, &s1.C, &s1.D);
		fprintf(fp, "%d %s %d %d %d %d", s1.stnum, s1.name, s1.A, s1.B, s1.C, s1.D);
		printf("������ �ԷµǾ����ϴ�.");
		fclose(fp);
		break;

	case 2:
		fp = fopen("a,bin", "rt");
		char str2[10] = "a,bin";
		if (fp == NULL)
		{
			puts("������ �������� �ʽ��ϴ�.");
			return -1;
		}
		fscanf(fp, "%d %s %d %d %d %d", &s1.stnum, s1.name, &s1.A, &s1.B, &s1.C, &s1.D);
		printf("%d�� �л��� ���� \n", sd); sd++;
		printf("�й� : %d \n", s1.stnum); 
		printf("�̸� : %s \n",s1.name);
		printf("A���� ���� : %d \n", s1.A);
		printf("B���� ���� : %d \n", s1.B);
		printf("C���� ���� : %d \n", s1.C);
		printf("D���� ���� : %d \n", s1.D);
		fclose(fp);
		break;

	case 3:
		fp = fopen("a,bin", "wt");
		if (fp == NULL)
		{
			puts("���Ͽ��½���!");
			return -1;
		}
		fprintf(fp, "%d %s %d %d %d %d", s1.stnum, s1.name, s1.A, s1.B, s1.C, s1.D);
		printf("������ ������ ����Ǿ����ϴ�.");
		fclose(fp);
		break;

	case 4:
		fp = fopen("a,bin", "rt");
		if (fp == NULL)
		{
			puts("������ �������� �ʽ��ϴ�.");
			return -1;
		}
		fscanf(fp, "%d %s %d %d %d %d", &s1.stnum, s1.name, &s1.A, &s1.B, &s1.C, &s1.D);
		printf("������ �о����ϴ�.");
		printf("%d", s1.stnum);
		fclose(fp);
		break;

	case 5:
		printf("������ �л��� ��ȣ�� �Է����ּ���.\n");
		scanf("%d", &del);
		if (del == 1)
		{
			fp = fopen("a,bin", "wt");
			if (fp == NULL)
			{
				puts("���Ͽ��½���!");
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
			printf("%d�� �л��� ������ �����Ͽ����ϴ�.", del);
		}
		else
		{
			printf("%d�� �л��� ������ �������� �ʽ��ϴ�.",del);
			return -1;
		}
		break;

	default:
		break;
	}

	return 0;
}