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
//函数中数组用堆栈开辟，结束回收，解决堆栈损坏问题
//把加减乘除运算需求改为可自选符号组成
//输出是一个函数 一个数组存操作数 一个数组存符号
//添加对小数的小数点后取值位控制
//随机括号的数量和位置
int Max, N, OperationalSymbolSelection, WhetherDecimal, OutputMethods, WhetherBraces, File, Reset,Length,nGrade;
char lbrace = '(', rbrace = ')';
char Grade[4];
FILE* p;
void IntegerArithmeticAnswerOutput(int x[])//整数运算答案
{
	int i;
	if (OutputMethods == 1)      //输出到文件
	{
		printf("\n正确答案：\n");
		for (i = 1; i < N + 1; i++)
			printf("(%d) %d\n", i, x[i]);
	}
	else         //输出到屏幕
	{
		fprintf(p, "\n正确答案：\n");
		for (i = 1; i < N + 1; i++)
			fprintf(p, "(%d) %d\n", i, x[i]);
	}
}
void DecimalArithmeticAnswerOutput(double y[])     //小数运算答案
{
	int i;
	if (OutputMethods == 1)
	{
		printf("\n正确答案：\n");
		for (i = 1; i < N + 1; i++)
			printf("(%d) %.2f\n", i, y[i]);
	}
	else
	{
		fprintf(p, "\n正确答案：\n");
		for (i = 1; i < N + 1; i++)
			fprintf(p, "(%d) %.2f\n", i, y[i]);
	}
}
void SingleOperatorIntegerArithmetic()//整数单符号运算
{
	int i, j, m, k,sum = 0;
	int *result;
	result= (int*)malloc(sizeof(int) * Length);
	char op;
	for (i = 1; i<= N; i++)
	{
		sum = 0;	//重置答案
		while (1)	//取算式长度
		{
			Length = rand() % 7;
			if (Length > 1)
				break;
		}
		int* number;	//操作数 数组
		number = (int*)malloc(sizeof(int) * Length);
		for (j = 0; j < Length; j++)	//取被操作数
		{
			number[j] = rand() % Max;
			if (OperationalSymbolSelection == 4 && number[j] == 0)j--;
		}
		if (OperationalSymbolSelection == 1)//加法运算
		{
			for (k = 0; k < Length; k++)
			{
				sum += number[k];
			}
			result[i] = sum;
			op = '+';
		}
		else if (OperationalSymbolSelection == 2)	//减法运算
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
void SingleOperatorDecimalArithmetic()//小数运算
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
		double* number;	//操作数 数组
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
void MultipleOperatorDecimalArithmetic()  //混合运算（小数）
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
		double* number;	//操作数 数组
		number = (double*)malloc(sizeof(double) * Length);
		char* operation;	//运算符号数组
		operation = (char*)malloc(sizeof(char) * (Length - 1));
		for (int j = 0; j < Length; j++)	//取被操作数
		{
			number[j] = (rand() % (Max * 100)) / 100.00;
		}
		
		for (int j = 0; j < Length-1; j++)	//取符号
		{
			operation[j] = Grade[rand() % nGrade];
		}
		
		s.push_back(number[0]);
		for (int j = 0, k = 1; k< Length; )
		{
			s.push_back(operation[j++]);
			s.push_back(number[k++]);
		}
		
		if (WhetherBraces == 1)//有括号
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
void MultipleOperatorIntegerArithmetic()  //混合运算（整数）
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
		int* number;	//操作数 数组
		number = (int*)malloc(sizeof(int) * Length);
		char* operation;	//运算符号数组
		operation = (char*)malloc(sizeof(char) * (Length - 1));
		for (int j = 0; j < Length; j++)	//取被操作数
		{
			number[j] = rand() % Max;
		}
		
		for (int j = 0; j < Length-1; j++)	//取符号
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
		
		if (WhetherBraces == 1)//有括号
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
	fopen_s(&p, "结对编程.txt", "w");
	printf("***********四则运算**************\n");
	printf("1.请设置题目数量:");
	scanf_s("%d", &N);
	printf("\n2.请选择运算难度(1.加法专项练习  2.减法专项练习  3.乘法专项练习  4.除法专项练习  5.混合运算练习)：");
	scanf_s("%d", &OperationalSymbolSelection);
	if (OperationalSymbolSelection == 5)
	{
		printf("\n是否有括号(1.有 2.没有):");
		scanf_s("%d", &WhetherBraces);
		printf("\n请输入要添加的运算符号个数：");
		scanf_s("%d", &nGrade);
		printf("\n请选择要添加的运算符号：（1.加法  2.减法  3.乘法  4.除法）：");
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
	printf("\n3.请设置最大数：");
	scanf_s("%d", &Max);
	printf("\n4.是否有小数(1.有  2.没有)：");
	scanf_s("%d", &WhetherDecimal);
	printf("\n5.选择输出方式(1.显示在屏幕上 2.生成文件):");
	scanf_s("%d", &OutputMethods);

	if (OutputMethods == 2)
		printf("\n已生成四则运算.txt文件");
		//p = fopen_s("四则运算.txt", "w");
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
			MultipleOperatorIntegerArithmetic();  //混合运算（无小数、有无括号）
		else
			MultipleOperatorDecimalArithmetic(); //混合运算（有小数、有无括号）
	}
	fclose(p);

	printf("\n是否重新运行该程序?   <1>是   <2>退出\n");
	scanf_s("%d", &Reset);
	if (Reset == 1)
	{
		system("cls");  //清屏，重新运行
		main();
	}
}