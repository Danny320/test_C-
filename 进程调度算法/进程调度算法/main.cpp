#define _CRT_SECURE_NO_WARNINGS 1
#include"PCB.h"
#include<iostream>
using namespace std;

int main()
{
	int chose;
	while (1)
	{
		cout << "-------���̵����㷨-------" << endl << endl << endl;
		cout << "------1.�����ȷ���------" << endl;
		cout << "------2.����ҵ����------" << endl;
		cout << "------3.ʱ��Ƭ��ת------" << endl;
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
			cout << "������󣡣�!" << endl;
		}
	}

	system("pause");
	return 0;
}