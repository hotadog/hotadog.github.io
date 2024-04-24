#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<math.h>
#include<windows.h>

int n;//��Ŀ����
int max;//���������
int symbol;//�����
int flag_decimal; //�Ƿ���С��
int flag_parenthese;//�Ƿ�������
int flag_file;//�Ƿ������ļ�
FILE* r;

void correctAnswer(int y[])       //���������
{
	int i;
	if (flag_file == 2)      //�ļ����
	{
		fprintf(r, "\n��ȷ�𰸣�\n");
		for (i = 1; i < n + 1; i++)
		{
			fprintf(r, "(%d) %d\n", i, y[i]);
		}
	}
	else         //��Ļ���
	{
		printf("\n��ȷ�𰸣�\n");
		for (i = 1; i < n + 1; i++)
		{
			printf("(%d) %d\n", i, y[i]);
		}
	}
}

void  decimalsAnswer(double y[])     //С�������
{
	int i;
	if (flag_file == 1)
	{
		printf("\n��ȷ�𰸣�\n");
		for (i = 1; i < n + 1; i++)
		{
			printf("(%d) %.2f\n", i, y[i]);
		}
	}
	else
	{
		fprintf(r, "\n��ȷ�𰸣�\n");
		for (i = 1; i < n + 1; i++)
		{
			fprintf(r, "(%d) %.2f\n", i, y[i]);
		}
	}
}

void integer()  //������������
{
	int i;
	int a, b;
	int x[1000];//��
	char c;//����
	for (i = 1; i < n + 1; i++)
	{
		a = rand() % max;
		b = rand() % max;
		if (symbol == 1)
		{
			c = '+';
			x[i] = a + b;
		}
		else if (symbol == 2)
		{
			c = '-';
			x[i] = a - b;
		}
		else if (symbol == 3)
		{
			c = '*';
			x[i] = a * b;
		}
		else if (symbol == 4)
		{
			c = '/';
			while (b == 0)
			{
				b = rand() % max;
			}
			x[i] = a / b;
		}
		if (flag_file == 1)
		{
			printf("(%d) %d%c%d=\n", i, a, c, b);
		}
		else
		{
			fprintf(r, "(%d) %d%c%d=\n", i, a, c, b);
		}
	}
	correctAnswer(x);   //��ȡ��
}

void  decimals()  //С������������
{
	int i;
	double x[1000], a, b;
	char c;
	for (i = 1; i < n + 1; i++)
	{
		a = rand() % (max * 100) / 100.00;
		b = rand() % (max * 100) / 100.00;
		if (symbol == 1)
		{
			c = '+';
			x[i] = a + b;
		}
		else if (symbol == 2)
		{
			c = '-';
			x[i] = a - b;
		}
		else if (symbol == 3)
		{
			c = '*';
			x[i] = a * b;
		}
		else if (symbol == 4)
		{
			c = '/';
			while (b == 0)
			{
				b = rand() % (max * 100) / 100.00 + 1;
			}
			x[i] = a / b;
		}
		if (flag_file == 1)
		{
			printf("(%d) %.2f%c%.2f=\n", i, a, c, b);
		}
		else
		{
			fprintf(r, "(%d) %.2f%c%.2f=\n", i, a, c, b);
		}
	}
	decimalsAnswer(x);   //��ȡ��
}

void  mixinteger()  //������㣨������
{
	int i;
	int a, b, c;
	int x[1000];//��
	char d, e;//����
	for (i = 1; i < n + 1; i++)
	{
		a = rand() % max;
		b = rand() % max;
		c = rand() % max;
		if (i % 4 == 0)    //  a-b*c,(a-b)*c
		{
			d = '-';
			e = '*';
			if (flag_parenthese == 1)   //������
			{
				x[i] = a - b * c;
			}
			else             //������
			{
				x[i] = (a - b) * c;
			}
		}
		else if (i % 3 == 0)    //a+b/c,(a+b)/c
		{
			d = '+';
			e = '/';
			while (c == 0)
			{
				c = rand() % max;
			}
			if (flag_parenthese == 1)//������
			{
				x[i] = a + b / c;
			}
			else//������
			{
			x[i] = (a + b) / c;
			}
		}
		else if (i % 2 == 0)    //a-b/c,(a-b)/c
		{
			d = '-';
			e = '/';
			while (c == 0)
			{
				c = rand() % max;
			}
			if (flag_parenthese == 1)
			{
				x[i] = a - b / c;
			}
			else
			{
				x[i] = (a - b) / c;
			}
		}
		else   //a+b*c,(a+b)*c
		{
			d = '+';
			e = '*';
			if (flag_parenthese == 1)
			{
				x[i] = a + b * c;
			}
			else
			{
				x[i] = (a + b) * c;
			}
		}

	if (flag_file == 1)   //�������Ļ
		{
			if (flag_parenthese == 1)
			{
				printf("(%d) %d%c%d%c%d=\n", i, a, d, b, e, c);
			}
			else
			{
				printf("(%d) (%d%c%d)%c%d=\n", i, a, d, b, e, c);
			}
		}
		else //������ļ�
		{
			if (flag_parenthese == 1)
			{
				fprintf(r, "(%d) %d%c%d%c%d=\n", i, a, d, b, e, c);
			}
			else
			{
				fprintf(r, "(%d) (%d%c%d)%c%d=\n", i, a, d, b, e, c);
			}
		}
	}
	correctAnswer(x);   //��ȡ��
}

void mixDecimals()  //������㣨С����
{
	int i;
	double x[1000], a, b, c;
	char d, e;
	for (i = 1; i < n + 1; i++)
	{
		a = rand() % (max * 100) / 100.00 + 1;
		b = rand() % (max * 100) / 100.00 + 1;
		c = rand() % (max * 100) / 100.00 + 1;
		if (i % 4 == 0)    //  a-b*c,(a-b)*c
		{
			d = '-';
			e = '*';
			if (flag_parenthese == 1)   //������
			{
				x[i] = a - b * c;
			}
			else
			{
				x[i] = (a - b) * c;
			}
		}
		else if (i % 3 == 0)    //a+b/c,(a+b)/c
		{
			d = '+';
			e = '/';
			while (b == 0)
			{
				c = rand() % (max * 100) / 100.00 + 1;
			}
			if (flag_parenthese == 1)
			{
				x[i] = a + b / c;
			}
			else
			{
				x[i] = (a + b) / c;
			}
		}
		else if (i % 2 == 0)    //a-b/c,(a-b)/c
		{
			d = '-';
			e = '/';
			while (b == 0)
			{
				b = rand() % (max * 100) / 100.00 + 1;
			}
			if (flag_parenthese == 1)
			{
				x[i] = a - b / c;
			}
			else
			{
				x[i] = (a - b) / c;
			}
		}
		else   //a+b*c,(a+b)*c
		{
			d = '+';
			e = '*';
			if (flag_parenthese == 1)
			{
				x[i] = a + b * c;
			}
			else
			{
				x[i] = (a + b) * c;
			}
		}
		if (flag_file == 1)
		{
			if (flag_parenthese == 1)
			{
				printf("(%d) %.2f%c%.2f%c%.2f=\n", i, a, d, b, e, c);
			}
			else
			{
				printf("(%d) (%.2f%c%.2f)%c%.2f=\n", i, a, d, b, e, c);
			}
		}
		else
		{
			if (flag_parenthese == 1)
			{
				fprintf(r, "(%d) %.2f%c%.2f%c%.2f=\n", i, a, d, b, e, c);
			}
			else
			{
				fprintf(r, "(%d) (%.2f%c%.2f)%c%.2f=\n", i, a, d, b, e, c);
			}
		}
	}
	decimalsAnswer(x);   //��ȡ��
}

int main()
{
	printf("\n==============================��ӭ����Сѧ�����������Զ�����ϵͳ==============================\n\t\t\t\t( ע�⣺�������������Ϊ���� )\n\n");
	printf("1.��������Ŀ������");
	scanf_s("%d", &n);
	printf("\n2.��ѡ�����㷽����1.�ӷ� 2.���� 3.�˷� 4.���� 5.�������)��");
	scanf_s("%d", &symbol);
	printf("\n3.�������������");
	scanf_s("%d", &max);
	printf("\n4.�Ƿ���С����1.�� 2.��)��");
	scanf_s("%d", &flag_decimal);
	printf("\n5.�Ƿ������ţ�1.�� 2.��)��ע�����ڻ������ʱѡ����������һ��Ϊ��");
	scanf_s("%d", &flag_parenthese);
	printf("\n6.�����ʽ��1.��ʾ����Ļ   2.������ļ�)��");
	scanf_s("%d", &flag_file);
	if (flag_file == 2)
	{
		printf("\n������  ����Ŀ.txt��  �ļ���  ����������.exe��  ���ڵ��ļ�����");
	}
	r = fopen("��Ŀ.txt", "w");
	printf("\n\n");
	if (symbol != 5)
	{
		if (flag_decimal == 1)
		{
			integer();  //�ǻ����������
		}
		else
		{
			decimals();  //�ǻ��С������
		}
	}
	else
	{
		if (flag_decimal == 1)
		{
			mixinteger();  //�����������
		}
		else
		{
			mixDecimals();  //���С������
		}
	}
	fclose(r);
	printf("\n�Ƿ��ٴ����иó���?   (1.����  2.�˳�)\n");
	int res;
	scanf_s("%d", &res);
	if (res == 1)
	{
		system("cls");
		main();
	}
}