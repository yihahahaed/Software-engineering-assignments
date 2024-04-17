#include<stdio.h>
#include<iostream>
#include<stdlib.h>
#include<string.h>
#include <ctype.h>
using namespace std;
void A();  //  A -> V:=E
void E();  //  E -> TE'
void T();  //  T -> FT'
void E1(); //  E'-> +TE'|-TE'|null
void T1(); //  T'-> *FT'|/FT'|null
void F();  //  F -> V|(E)
void V();  //  V -> a|b|c|d|e...|z

char s[50], n = '1';   //s[50]���ڴ������ĸ�ֵ���ʽ
char Table[50][3];  //�����м��������ķ��ű�
int SIGN, sym;   //symΪs[50]�е�ǰ������ŵ��±�
int list_n = 0;   //���ű���±�
/*������ݹ鼰����
A -> V:=E
E -> TE'
E'-> +TE'|-TE'|null
T -> FT'
T'-> *FT'|/FT'|null
F -> V|(E)
V -> a|b|c|d|e...|z
*/
int main()
{
	SIGN = 0;  //SIGN����ָʾ��ֵ���ʽ�Ƿ���ִ���
	sym = 0;
	cin >> s;
	if (s[0] == '\0')  //û����������ֱ���˳�
		return 0;
	A();
	if (s[sym] != '\0' && SIGN == 0)
	{
		printf("ERROR!\n");
		exit(0);
	}
	return 0;
}
void A()  //  A -> V:=E
{
	V();
	if (s[sym] == ':' && s[sym + 1] == '=') //�жϸ�ֵ���Ƿ���ƴд����
	{
		sym += 2;
		E();
		printf("%s:=%s", Table[list_n - 2], Table[list_n - 1]);
		printf("     (:=,%s,-,%s)\n", Table[list_n - 1], Table[list_n - 2]);
	}
	else
	{
		printf("The assignment Symbol spelling mistakes!\n"); //��ֵ��ƴд����
		SIGN = 1;
		exit(0);
	}
}
void V()  // V -> a|b|c|d|e...|z
{
	if (islower(s[sym]))
	{
		Table[list_n][0] = s[sym];              //�Ѷ�ȡ��Сд��ĸ������ű����ڷ����������м����
		Table[list_n][1] = '\0';
		list_n++;
		sym++;
	}
	else
	{
		printf("Operand Errors!\n");      //����������
		SIGN = 1;
		exit(0);
	}
}
void E()     //E -> TE'
{
	if (SIGN == 0)
	{
		T();
		E1();
	}
}
void T()   // T -> FT'
{
	if (SIGN == 0)
	{
		F();
		T1();
	}
}
void E1()               //E'-> +TE'|-TE'|null
{
	int p;
	if (SIGN == 0)
	{
		if (s[sym] == '+' || s[sym] == '-')
		{
			p = sym;                  //��p��¼����'+'��'-'ʱsym��ֵ
			sym++;
			T();
			char ch[3];
			ch[0] = 'T';
			ch[1] = n;
			ch[2] = '\0';
			if (s[p] == '+')
			{
				printf("%s:=%s+%s", ch, Table[list_n - 2], Table[list_n - 1]);                //�������ַ����
				printf("     (+,%s,%s,%s)\n", Table[list_n - 2], Table[list_n - 1], ch);             //�����Ԫʽ
			}
			else
			{
				printf("%s:=%s-%s", ch, Table[list_n - 2], Table[list_n - 1]);               //�������ַ����
				printf("     (-,%s,%s,%s)\n", Table[list_n - 2], Table[list_n - 1], ch);        //�����Ԫʽ
			}
			strcpy(Table[list_n - 2], ch);           //����ǰ������ʽ���ڷ��ű���
			list_n--;
			n++;
			E1();
		}
	}
}
void T1()  //  T'-> *FT'|/FT'|null
{
	int p;
	if (SIGN == 0)
	{
		if (s[sym] == '*' || s[sym] == '/')
		{
			p = sym;
			sym++;
			F();
			char ch[3];
			ch[0] = 'T';
			ch[1] = n;
			ch[2] = '\0';
			if (s[p] == '*')
			{
				printf("%s:=%s*%s", ch, Table[list_n - 2], Table[list_n - 1]);   //�������ַ����
				printf("     (*,%s,%s,%s)\n", Table[list_n - 2], Table[list_n - 1], ch);//�����Ԫʽ
			}
			else
			{
				printf("%s:=%s/%s", ch, Table[list_n - 2], Table[list_n - 1]);   //�������ַ����
				printf("     (/,%s,%s,%s)\n", Table[list_n - 2], Table[list_n - 1], ch);//�����Ԫʽ
			}
			strcpy(Table[list_n - 2], ch);      //����ǰ������ʽ���ڷ��ű���
			list_n--;
			n++;
			T1();
		}
	}
}
void F()    //F -> V|(E)
{
	if (SIGN == 0)
	{
		if (s[sym] == '(')
		{
			sym++;
			E();
			if (s[sym] == ')')
				sym++;
			else
			{
				printf("ERROR!\n");
				SIGN = 1;
				exit(0);
			}
		}
		else if (islower(s[sym]))  //�ж�s[sym]�Ƿ���Сд��ĸ
			V();
		else
		{
			printf("ERROR!\n");
			SIGN = 1;
			exit(0);
		}
	}
}