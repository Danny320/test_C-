#define _CRT_SECURE_NO_WARNINGS 1
//#include<stdio.h>
//#include<stdlib.h>
//#define __DEBUG__
//int main()
//{
//	int i = 0;
//	int arr[10] = { 0 };
//	for (i = 0; i < 10; i++)
//	{
//		arr[i] = i;
//
//#ifdef __DEBUG__//添加调试信息，条件编译
//		if (i == 5)
//		{
//			printf("%d\n", arr[i]);
//		}
//#endif
//	}
//	system("pause");
//	return 0;
//}
//#include<stdio.h>
//#include<stdlib.h>
//#include<math.h>
//int main()
//{
//	unsigned int num = 10;
//	unsigned int ret = 0;
//	int i = 0;
//	//for (i = 0; i < 32; i++)
//	//{
//	//	ret += (num & 1)* pow(2.0, 31 - i);
//	//	//ret += ((num & 1) << (31 - i));
//	//	num >>= 1;
//	//}
//	for (i = 0; i < 32; i++)
//	{
//		ret <<= 1;
//		ret |= (num & 1);
//		num >>= 1;
//	}
//	printf("%u\n", ret);
//	system("pause");
//	return 0;
//}
