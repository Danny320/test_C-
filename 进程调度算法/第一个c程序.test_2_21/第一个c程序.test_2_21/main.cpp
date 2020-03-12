#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
//#define add(a,b) a+b
//int main(void)
//{
//	printf("%d\n", 5 * add(3, 4));
//	system("pause");
//	return 0;
//}
//*************************************************************************
//int main()
//{
//	int a;
//	printf("a=");
//	scanf("%d", &a);
//	printf("a=%d\n", a);
//	system("pause");
//	return 0;
//}
//*****************************************************************************
//int main()
//{
//	int x, y;
//	x = printf("%d", 1234);//printf（）函数的返回值，是执行这个函数后显示的字符个数
//	printf("\nx=%d\n", x);
//	y = printf("Everybody! I am coming!");
//	printf("\ny=%d\n", y);
//	system("pause");
//	return 0;
//}
//*******************************************************************************
//int main()
//{
//	int x, y;
//	printf("x=");
//	y = scanf("%d", &x);//scanf()函数的返回值，是执行这个函数后成功获得的数据的个数，输入非法时其值为零
//	printf("x=%d,y=%d", x, y);
//	system("pause");
//	return 0;
//}
//*********************************************************************************
//C语言中的常量有整形常量，实型常量，字符型常量，字符串常量，符号常量，枚举常量等。
//一，整形常量有三种形式：十进制，八进制，十六进制整数。
//1，十进制整数：由0 - 9这十个数和正负号组成，最左边的数字不能为0.
//2，八进制整数：必须以零（0）开头并由0 - 7这八个数字和正负号组成。
//3，十六进制整数：必须以0x(0X)开头，由0 - 9，a, b, c, d, e, f这十六个符号和正负号组成。
//二，字符型常量是用一对单引号括起来的一个字符，如：'a';
//空字符也是字符，它包含0个字符，值为0，可以表示为'', 也可以表示为'\0', 程序中总是用'\0'表示空字符。
//转义字符是以反斜线（\）开头的字符串，
//三，字符串常量是用双引号括起来的。C语言规定：在每一个字符串后，系统自动加一个空字符'\0'作为字符串的结束标志
//以判断字符串的长度，字符串的长度比实际长度大1.空串的长度为1，而不是为0。
//int main()
//{
//	printf("Hello c\n");
//	printf("\110\145\154\x6c\157\54c\12");
//	printf("\"12\4=3\"\t\\is a string\\\n");
//	system("pause");
//	return 0;
//}
//********************************指针*********************************
//int main()
//{
//	int x = 3, *p = &x;
//	printf("%d\n", p);
//	printf("%d\n", &(*p));
//	printf("%d\n", x);
//	printf("%d\n",*(&x));
//	system("pause");
//	return 0;
//}
//*****************************求出半径为1，高为2的圆柱体底面积和体积**********************************
//#define PI 3.1416
//#define ARRA(r) PI*(r)*(r)
//#define VOLUME(r,h) PI*(r)*(r)*h
//int main()
//{
//	printf("area is %f\n", ARRA(1));
//	printf("volume is %f\n", VOLUME(1, 2));
//	system("pause");
//	return 0;
//}
//************************************************************************
//#define PI 3.14
//#include<math.h>
//int main()
//{
//	float a, b, c, alfa;
//	printf("输入两边及夹角：\n");
//	scanf("%f %f %f", &a, &b, &alfa);
//	c = sqrt(a*a + b*b - 2 * a*b*cos(alfa*PI / 180));
//	printf("c=%d\n", c);
//	system("pause");
//	return 0;
//}
//********************************************************************
//int main()
//{
//	char ch;
//	scanf("%c",&ch);
//	ch = (ch >= 'A'&&ch <= 'Z') ? (ch + 32) : ch;
//	printf("ch=%c\n",ch);
//	system("pause");
//	return 0;
//}
//***********************计算两数之和********************************************
//int main()
//{
//	float a, b, sum;
//	scanf("%f%f", &a, &b);
//	sum = a + b;
//	printf("%f+%f=%f\n", a, b, sum);
//	system("pause");
//	return 0;
//}
//*********************************************************************
//int main()
//{
//	float x;
//	int y;
//	printf("x=");
//	scanf("%f",&x);
//	if (x >= 0)
//	{
//		y = 1;
//	}
//	if (x < 0)
//	{
//		y = -1;
//	}
//	printf("%0.2f,%d\n", x, y);
//	system("pause");
//	return 0;
//}
//**************************************************************************
//#include<math.h>
//int main()
//{
//	float a, b, c, area, s;
//	printf("side a="); scanf("%f", &a);
//	printf("side b="); scanf("%f", &b);
//	printf("side c="); scanf("%f", &c);
//		if (a + b > c&&a + c > b&&b + c > a)	
//		{
//			s = 0.5*(a + b + c);
//			area = sqrt(s*(s - a)*(s - b)*(s - c));
//			printf("%f\n", area);
//		}
//		else
//			printf("数据错误");
//	system("pause");
//	return 0;
//}
//***********************************************************************************
//int main()
//{
//	char grade;
//	printf("请输入等级：");
//	scanf("%c",&grade);
//	if (grade == 'A')
//	{
//		printf("85~100\n");
//	}
//	else if (grade == 'B')
//	{
//		printf("70~84\n");
//	}
//	else if (grade == 'C')
//	{
//		printf("60~69\n");
//	}
//	else if (grade == 'D')
//	{
//		printf("<60");
//	}
//	else
//	{
//		printf("Error\n");
//	}
//	system("pause");
//	return 0;
//}
//*****************************************************************************
//int main()
//{
//	char grade;
//	printf("请输入成绩：");
//	scanf("%c", &grade);
//	switch (grade)
//	{
//	case'A':printf("85~100\n"); break;
//	case'B':printf("70~84\n"); break;
//	case'C':printf("60~69\n"); break;
//	case'D':printf("<60\n"); break;
//	default:printf("Error\n");
//	}
//	system("pause");
//	return 0;
//}
//********************************************************************************
//int main()
//{
//	float x, y;
//	printf("请输入x:");
//	scanf("%f", &x);
//	if (x < 2)
//	{
//		y = x;
//	}
//	if (x >= 2 && x < 10)
//	{
//		y = 2*x - 1;
//	}
//	if ("x>=10")
//	{
//		y = 3*x + 10;
//	}
//	printf("%0.2f,0.2%f\n", x, y);
//	system("pause");
//	return 0;
//}
//*************************************************************************************
//int main()
//{
//	float x, y;
//		printf("请输入x:");
//		scanf("%f", &x);
//		if (x < 2)
//		{
//			y = x;
//		}
//		else if (x >= 2 && x < 10)
//		{
//			y = 2 * x - 1;
//		}
//		else if ("x>10")
//			y = 3 * x + 10;
//		printf("%f,%f\n", x, y);
//	system("pause");
//	return 0;
//}
//******************************************************************************
//int main()
//{
//	float x, y;
//	printf("请输入x:");
//	scanf("%f", &x);
//	int z = 1 * (x < 2) + 2 * (x >= 2 && x<10) + 3 * (x>10);
//	switch (z)
//	{
//	case 1:y = x; break;
//	case 2:y = 2 * x - 1; break;
//	case 3:y = 3 * x + 1; break;
//	}
//	printf("%f,%f\n", x, y);
//	system("pause");
//	return 0;
//
//}
//*****************************************************************************
int main()
{
	int year, month, days;
	printf("请输入年月");
	scanf("%d,%d", &year, &month);
	if (month == 1 || month == 3 || month == 5 || month == 7 || month == 9 || month == 12)
		days = 31;
	else
	{
		if (year % 4 == 0 && year % 100 != 0 || year % 400 == 0)
			days = 29;
		else
			days = 28;

	{


	system("pause");
	return 0;
}