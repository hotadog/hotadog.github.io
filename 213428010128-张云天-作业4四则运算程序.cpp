#include<stdio.h>
#include<math.h>
#include<windows.h>

int n;//题目数量
int max;//输入最大数
int symbol;//运算符
int flag_decimal; //是否是小数
int flag_parenthese;//是否是括号
int flag_file;//是否生成文件
FILE* r;

void correctAnswer(int y[])       //整数运算答案
{
	int i;
	if (flag_file == 2)      //文件输出
	{
		fprintf(r, "\n正确答案：\n");
		for (i = 1; i < n + 1; i++)
		{
			fprintf(r, "(%d) %d\n", i, y[i]);
		}
	}
	else         //屏幕输出
	{
		printf("\n正确答案：\n");
		for (i = 1; i < n + 1; i++)
		{
			printf("(%d) %d\n", i, y[i]);
		}
	}
}

void  decimalsAnswer(double y[])     //小数运算答案
{
	int i;
	if (flag_file == 1)
	{
		printf("\n正确答案：\n");
		for (i = 1; i < n + 1; i++)
		{
			printf("(%d) %.2f\n", i, y[i]);
		}
	}
	else
	{
		fprintf(r, "\n正确答案：\n");
		for (i = 1; i < n + 1; i++)
		{
			fprintf(r, "(%d) %.2f\n", i, y[i]);
		}
	}
}

void integer()  //整数四则运算
{
	int i;
	int a, b;
	int x[1000];//答案
	char c;//符号
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
	correctAnswer(x);   //获取答案
}

void  decimals()  //小数的四则运算
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
	decimalsAnswer(x);   //获取答案
}

void  mixinteger()  //混合运算（整数）
{
	int i;
	int a, b, c;
	int x[1000];//答案
	char d, e;//符号
	for (i = 1; i < n + 1; i++)
	{
		a = rand() % max;
		b = rand() % max;
		c = rand() % max;
		if (i % 4 == 0)    //  a-b*c,(a-b)*c
		{
			d = '-';
			e = '*';
			if (flag_parenthese == 1)   //无括号
			{
				x[i] = a - b * c;
			}
			else             //有括号
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
			if (flag_parenthese == 1)//有括号
			{
				x[i] = a + b / c;
			}
			else//无括号
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

	if (flag_file == 1)   //输出到屏幕
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
		else //输出到文件
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
	correctAnswer(x);   //获取答案
}

void mixDecimals()  //混合运算（小数）
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
			if (flag_parenthese == 1)   //有括号
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
	decimalsAnswer(x);   //获取答案
}

int main()
{
	printf("\n==============================欢迎进入小学生四则运算自动生成系统==============================\n\t\t\t\t( 注意：所有输入的数均为常数 )\n\n");
	printf("1.请输入题目个数：");
	scanf_s("%d", &n);
	printf("\n2.请选择运算方法（1.加法 2.减法 3.乘法 4.除法 5.混合运算)：");
	scanf_s("%d", &symbol);
	printf("\n3.请输入最大数：");
	scanf_s("%d", &max);
	printf("\n4.是否含有小数（1.无 2.有)：");
	scanf_s("%d", &flag_decimal);
	printf("\n5.是否含有括号（1.无 2.有)：注：仅在混合运算时选择，其余运算一律为无");
	scanf_s("%d", &flag_parenthese);
	printf("\n6.输出方式（1.显示在屏幕   2.输出到文件)：");
	scanf_s("%d", &flag_file);
	if (flag_file == 2)
	{
		printf("\n已生成  ‘题目.txt’  文件到  ‘四则运算.exe’  所在的文件夹中");
	}
	r = fopen("题目.txt", "w");
	printf("\n\n");
	if (symbol != 5)
	{
		if (flag_decimal == 1)
		{
			integer();  //非混合整数运算
		}
		else
		{
			decimals();  //非混合小数运算
		}
	}
	else
	{
		if (flag_decimal == 1)
		{
			mixinteger();  //混合整数运算
		}
		else
		{
			mixDecimals();  //混合小数运算
		}
	}
	fclose(r);
	printf("\n是否再次运行该程序?   (1.继续  2.退出)\n");
	int res;
	scanf_s("%d", &res);
	if (res == 1)
	{
		system("cls");
		main();
	}
}
