#define _CRT_SECURE_NO_WARNINGS 1
#include"PCB.h"
#include<iostream>
using namespace std;

int main()
{
	int chose;
	while (1)
	{
		cout << "-------进程调度算法-------" << endl << endl << endl;
		cout << "------1.先来先服务------" << endl;
		cout << "------2.短作业优先------" << endl;
		cout << "------3.时间片轮转------" << endl;
		cin >> chose;
		switch (chose)
		{
		case 1:FCFS();
			break;
		case 2:SJF();
			break;
		case 3:RR();
			break;
		default:
			cout << "输入错误！！!" << endl;
		}
	}

	system("pause");
	return 0;
}