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
//	x = printf("%d", 1234);//printf���������ķ���ֵ����ִ�������������ʾ���ַ�����
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
//	y = scanf("%d", &x);//scanf()�����ķ���ֵ����ִ�����������ɹ���õ����ݵĸ���������Ƿ�ʱ��ֵΪ��
//	printf("x=%d,y=%d", x, y);
//	system("pause");
//	return 0;
//}
//*********************************************************************************
//C�����еĳ��������γ�����ʵ�ͳ������ַ��ͳ������ַ������������ų�����ö�ٳ����ȡ�
//һ�����γ�����������ʽ��ʮ���ƣ��˽��ƣ�ʮ������������
//1��ʮ������������0 - 9��ʮ��������������ɣ�����ߵ����ֲ���Ϊ0.
//2���˽����������������㣨0����ͷ����0 - 7��˸����ֺ���������ɡ�
//3��ʮ������������������0x(0X)��ͷ����0 - 9��a, b, c, d, e, f��ʮ�������ź���������ɡ�
//�����ַ��ͳ�������һ�Ե�������������һ���ַ����磺'a';
//���ַ�Ҳ���ַ���������0���ַ���ֵΪ0�����Ա�ʾΪ'', Ҳ���Ա�ʾΪ'\0', ������������'\0'��ʾ���ַ���
//ת���ַ����Է�б�ߣ�\����ͷ���ַ�����
//�����ַ�����������˫�����������ġ�C���Թ涨����ÿһ���ַ�����ϵͳ�Զ���һ�����ַ�'\0'��Ϊ�ַ����Ľ�����־
//���ж��ַ����ĳ��ȣ��ַ����ĳ��ȱ�ʵ�ʳ��ȴ�1.�մ��ĳ���Ϊ1��������Ϊ0��
//int main()
//{
//	printf("Hello c\n");
//	printf("\110\145\154\x6c\157\54c\12");
//	printf("\"12\4=3\"\t\\is a string\\\n");
//	system("pause");
//	return 0;
//}
//********************************ָ��*********************************
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
//*****************************����뾶Ϊ1����Ϊ2��Բ�������������**********************************
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
//	printf("�������߼��нǣ�\n");
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
//***********************��������֮��********************************************
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
//			printf("���ݴ���");
//	system("pause");
//	return 0;
//}
//***********************************************************************************
//int main()
//{
//	char grade;
//	printf("������ȼ���");
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
//	printf("������ɼ���");
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
//	printf("������x:");
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
//		printf("������x:");
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
//	printf("������x:");
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
	printf("����������");
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