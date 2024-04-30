#include<stdio.h>
#include<string.h>
#include<time.h>
#include<stdlib.h>
#include<windows.h>
#include<iostream>
#include<math.h>
#include <string>
#include <vector>
using namespace std;
//�����������ö�ջ���٣��������գ������ջ������
//�ѼӼ��˳����������Ϊ����ѡ�������
//�����һ������ һ������������ һ����������
//��Ӷ�С����С�����ȡֵλ����
//������ŵ�������λ��
int Max, N, OperationalSymbolSelection, WhetherDecimal, OutputMethods, WhetherBraces, File, Reset,Length,nGrade;
char lbrace = '(', rbrace = ')';
char Grade[4];
FILE* p;
void IntegerArithmeticAnswerOutput(int x[])//���������
{
	int i;
	if (OutputMethods == 1)      //������ļ�
	{
		printf("\n��ȷ�𰸣�\n");
		for (i = 1; i < N + 1; i++)
			printf("(%d) %d\n", i, x[i]);
	}
	else         //�������Ļ
	{
		fprintf(p, "\n��ȷ�𰸣�\n");
		for (i = 1; i < N + 1; i++)
			fprintf(p, "(%d) %d\n", i, x[i]);
	}
}
void DecimalArithmeticAnswerOutput(double y[])     //С�������
{
	int i;
	if (OutputMethods == 1)
	{
		printf("\n��ȷ�𰸣�\n");
		for (i = 1; i < N + 1; i++)
			printf("(%d) %.2f\n", i, y[i]);
	}
	else
	{
		fprintf(p, "\n��ȷ�𰸣�\n");
		for (i = 1; i < N + 1; i++)
			fprintf(p, "(%d) %.2f\n", i, y[i]);
	}
}
void SingleOperatorIntegerArithmetic()//��������������
{
	int i, j, m, k,sum = 0;
	int *result;
	result= (int*)malloc(sizeof(int) * Length);
	char op;
	for (i = 1; i<= N; i++)
	{
		sum = 0;	//���ô�
		while (1)	//ȡ��ʽ����
		{
			Length = rand() % 7;
			if (Length > 1)
				break;
		}
		int* number;	//������ ����
		number = (int*)malloc(sizeof(int) * Length);
		for (j = 0; j < Length; j++)	//ȡ��������
		{
			number[j] = rand() % Max;
			if (OperationalSymbolSelection == 4 && number[j] == 0)j--;
		}
		if (OperationalSymbolSelection == 1)//�ӷ�����
		{
			for (k = 0; k < Length; k++)
			{
				sum += number[k];
			}
			result[i] = sum;
			op = '+';
		}
		else if (OperationalSymbolSelection == 2)	//��������
		{
			sum = number[0];
			for (k = 1; k < Length; k++)
			{
				sum -= number[k];
			}
			result[i] = sum;
			op = '-';
		}
		else if (OperationalSymbolSelection == 3)
		{
			sum = number[0];
			for (k = 1; k < Length; k++)
			{
				sum *= number[k];
			}
			result[i] = sum;
			op = '*';
		}
		else if (OperationalSymbolSelection == 4)
		{
			sum = number[0];
			for (k = 1; k < Length; k++)
			{
				sum /= number[k];
			}
			result[i] = sum;
			op = '/';
		}
		if (OutputMethods == 1)
		{
			printf("%d", number[0]);
			for (m = 1; m < Length; m++)
				printf("%c%d",op,number[m]);
			printf("=\n");
		}
		else
		{
			fprintf(p, "%d", number[0]);
			for (m = 1; m < Length; m++)
				fprintf(p, "%c%d", op, number[m]);
			fprintf(p, "=\n");
		}
		free(number);
	}
	IntegerArithmeticAnswerOutput(result);
}
void SingleOperatorDecimalArithmetic()//С������
{
	char op;
	int i, j, m, k;
	double *result;
	result = (double*)malloc(sizeof(double) * N);
	double sum;
	for (i = 1; i <= N; i++)
	{
		sum = 0;
		while (1)
		{
			Length = rand() % 7;
			if (Length >1)
				break;
		}
		double* number;	//������ ����
		number = (double*)malloc(sizeof(double) * Length);
		for (j = 0; j < Length; j++)
		{
			number[j] = (rand() % (Max * 100)) / 100.00;
		}
		
		if (OperationalSymbolSelection == 1)
		{
			op = '+';
			for (k = 0; k < Length; k++)
			{
				sum = sum + number[k];
			}
			result[i] = sum;
			cout << endl << sum;
		}
		else if (OperationalSymbolSelection == 2)
		{
			op = '-';
			sum = number[0];
			for (k = 1; k < Length; k++)
			{
				sum -= number[k];
			}
			result[i] = sum;
		}
		else if (OperationalSymbolSelection == 3)
		{
			op = '*';
			sum = number[0];
			for (k = 1; k < Length; k++)
			{
				sum *= number[k];
			}
			result[i] = sum;
		}
		else if (OperationalSymbolSelection == 4)
		{
			op = '/';
			sum = number[0];
			for (k = 1; k < Length; k++)
			{
				sum /= number[k];
			}
			result[i] = sum;
		}
		if (OutputMethods == 1)
		{
			printf("%.2f", number[0]);
			for (m = 1; m < Length; m++)
				printf("%c%.2f", op,number[m]);
			printf("=\n");
		}
		else
		{
			fprintf(p, "%.2f", number[0]);
			for (m = 1; m < Length; m++)
				fprintf(p, "%c%.2f",op,number[m]);
			fprintf(p, "=\n");
		}
		free(number);
	}
	DecimalArithmeticAnswerOutput(result);
}
void MultipleOperatorDecimalArithmetic()  //������㣨С����
{
	for (int i = 0; i < N; i++)
	{
		while (1)
		{
			Length = rand() % 7;
			if (Length > nGrade+1)
				break;
		}
		
		int nbrace=0;
		vector <double>s;
		double* number;	//������ ����
		number = (double*)malloc(sizeof(double) * Length);
		char* operation;	//�����������
		operation = (char*)malloc(sizeof(char) * (Length - 1));
		for (int j = 0; j < Length; j++)	//ȡ��������
		{
			number[j] = (rand() % (Max * 100)) / 100.00;
		}
		
		for (int j = 0; j < Length-1; j++)	//ȡ����
		{
			operation[j] = Grade[rand() % nGrade];
		}
		
		s.push_back(number[0]);
		for (int j = 0, k = 1; k< Length; )
		{
			s.push_back(operation[j++]);
			s.push_back(number[k++]);
		}
		
		if (WhetherBraces == 1)//������
		{
			while (1)
			{
				nbrace = rand() % (Length/2);
				if (nbrace > 0)break;
			}
			for (int j = 0; j < nbrace; j++)
			{
				int left, right;
				while (1)
				{
					left = rand() % s.size();
					right = rand() % s.size();
					if (left < right-3 && s[left] != 40 && s[left] != 43 && s[left] != 42 && s[left] != 41 && s[left] != 47 && s[left] != 45 && s[right] >= 40 && s[right] <= 47&&s[right]!=rbrace && s[left] != lbrace)break;
				}
				
				s.insert(s.begin()+left, 40);
				s.insert(s.begin() + right+1, 41);
			}
		}
		if (OutputMethods == 1)
		{
			cout << endl;
			for (int j = 0; j < Length*2-1+nbrace*2; j++)
			{
				if (s[j] == 40 || s[j] == 41 || s[j] == 42 || s[j] == 43 || s[j] == 45 || s[j] == 47)
					printf_s("%c", int(s[j]));
				else printf_s("%.2f", s[j]);
			}
			
		}
		free(number);
		free(operation);
		s.clear();
	}

}
void MultipleOperatorIntegerArithmetic()  //������㣨������
{
	for (int i = 0; i < N; i++)
	{
		string s;
		while (1)
		{
			Length = rand() % 10;
			if (Length > (nGrade + 1))
				break;
		}
		
		int nbrace=0;
		int* number;	//������ ����
		number = (int*)malloc(sizeof(int) * Length);
		char* operation;	//�����������
		operation = (char*)malloc(sizeof(char) * (Length - 1));
		for (int j = 0; j < Length; j++)	//ȡ��������
		{
			number[j] = rand() % Max;
		}
		
		for (int j = 0; j < Length-1; j++)	//ȡ����
		{
			operation[j] = Grade[rand() % nGrade];
		}
		
		s+=number[0]+'0';
		for (int j = 0, k = 1, m=1 ; j < Length-1; )
		{
			s+=operation[j];
			j++;
			s+= (number[k] + '0');
			k++;
		}
		
		if (WhetherBraces == 1)//������
		{
			while (1)
			{
				nbrace = rand() % (Length / 2);
				if (nbrace > 0)break;
			}
			
			for (int j = 0; j < nbrace; j++)
			{
				int left, right;
				while (1)
				{
					left = rand() % s.length();
					right = rand() % s.length();
					if (left < right-3 && s[left] >= '0' && s[left] <= '9' && s[right - 1] >= '0' && s[right - 1] <= '9')break;
				}
				s.insert(left,1,lbrace);
				s.insert(right+1,1,rbrace);
			}
		}
		cout << endl << "(" << i << ")";
		for (int j = 0; j < Length * 2 - 1 + nbrace * 2; j++)
		{
			cout <<  s[j];
		}
		
		free(number);
		free(operation);
		s.clear();
	}
}
int main()
{
	fopen_s(&p, "��Ա��.txt", "w");
	printf("***********��������**************\n");
	printf("1.��������Ŀ����:");
	scanf_s("%d", &N);
	printf("\n2.��ѡ�������Ѷ�(1.�ӷ�ר����ϰ  2.����ר����ϰ  3.�˷�ר����ϰ  4.����ר����ϰ  5.���������ϰ)��");
	scanf_s("%d", &OperationalSymbolSelection);
	if (OperationalSymbolSelection == 5)
	{
		printf("\n�Ƿ�������(1.�� 2.û��):");
		scanf_s("%d", &WhetherBraces);
		printf("\n������Ҫ��ӵ�������Ÿ�����");
		scanf_s("%d", &nGrade);
		printf("\n��ѡ��Ҫ��ӵ�������ţ���1.�ӷ�  2.����  3.�˷�  4.��������");
		for (int i = 0; i < nGrade; i++)
		{
			int ii;
			scanf_s("%d",&ii);
			if (ii == 1)Grade[i] = '+';
			else if (ii == 2)Grade[i] = '-';
			else if (ii == 3)Grade[i] = '*';
			else if (ii == 4)Grade[i] = '/';
		}
	}
	printf("\n3.�������������");
	scanf_s("%d", &Max);
	printf("\n4.�Ƿ���С��(1.��  2.û��)��");
	scanf_s("%d", &WhetherDecimal);
	printf("\n5.ѡ�������ʽ(1.��ʾ����Ļ�� 2.�����ļ�):");
	scanf_s("%d", &OutputMethods);

	if (OutputMethods == 2)
		printf("\n��������������.txt�ļ�");
		//p = fopen_s("��������.txt", "w");
		printf("\n\n");
	if (OperationalSymbolSelection != 5)
	{
		if (WhetherDecimal == 2)
			SingleOperatorIntegerArithmetic();
		else
			SingleOperatorDecimalArithmetic();
	}
	else
	{
		if (WhetherDecimal == 2)
			MultipleOperatorIntegerArithmetic();  //������㣨��С�����������ţ�
		else
			MultipleOperatorDecimalArithmetic(); //������㣨��С�����������ţ�
	}
	fclose(p);

	printf("\n�Ƿ��������иó���?   <1>��   <2>�˳�\n");
	scanf_s("%d", &Reset);
	if (Reset == 1)
	{
		system("cls");  //��������������
		main();
	}
}