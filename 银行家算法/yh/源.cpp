#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<cstdio>
#include<windows.h>
#include<vector>
using namespace std;
//采用矩阵表示
//方便起见，提前初始化好

//代表有几个进程
const int I = 5;

//代表有几类资源
const int R = 3;

//A,B,C三类资源的总数
int mem[R] = { 10, 5, 7 };

//一共5个进程，对各类资源最大需求量
int Max[I][R] = { { 7, 5, 3 }, { 3, 2, 2 }, { 9, 0, 2 }, { 2, 2, 2 }, { 4, 3, 3 } };

//每个进程当前已分配各类资源数
int Allocation[I][R] = { { 0, 1, 0 }, { 2, 0, 0 }, { 3, 0, 2 }, { 2, 1, 1 }, { 0, 0, 2 } };

//每个进程当前的需求量
int Need[I][R] = { { 7, 4, 3 }, { 1, 2, 2 }, { 6, 0, 0 }, { 0, 1, 1 }, { 4, 3, 1 } };

//系统当前剩余可分配的各类资源
int Available[R] = { 3, 3, 2 };


template<typename T, typename K>
void Sub(K* ptr, T* str, int n)
{
	while (n--)
	{
		*ptr = *ptr - *str;
		ptr++;
		str++;
	}
}

template<typename T, typename K>
void Add(K* ptr, T* str, int n)
{
	while (n--)
	{
		*ptr = *ptr + *str;
		ptr++;
		str++;
	}
}


bool Comper(int* arr1, int* arr2)
{
	for (int i = 0; i < R; ++i)
	{
		if (arr1[i] > arr2[i])
			return false;
	}
	return true;
}

vector<int> result;  //记录安全序列
bool Find(int* work)
{
	int WorkAllocation[I][R] = { 0 };
	vector<string> finash(5, "false");
	int WorkMartix[I][R] = { 0 };

	int count = I*I;  //控制循环次数
	int i = 0;
	while (count--)
	{
		const char* tmp = finash[i].c_str();
		if (strcmp(tmp, "false") == 0)
		{
			//可以满足需求
			if (Comper(Need[i], work))
			{
				result.push_back(i); //记下进程号
				finash[i] = "true";    //状态标记为已完成；
				//tag += 1;
				//更新数据
				Add(WorkMartix[i], work, R);
				Add(work, Allocation[i], R);
				Add(WorkAllocation[i], work, R);
			}
		}

		if (result.size() == I)
			break;

		++i;
		if (i == I)
			i = 0;
	}

	if (result.size() != I)
	{
		cout << endl << " 资源试分配后系统不安全，此时系统不分配资源，试分配未发现安全序列!!!" << endl;
		return false;
	}

	//HANDLE handle;
	//handle = GetStdHandle(STD_OUTPUT_HANDLE);
	//SetConsoleTextAttribute(handle, FOREGROUND_INTENSITY | FOREGROUND_RED);//设置为红

	printf("\n安全序列为:");
	for (int i = 0; i < I; ++i)
	{
		printf("P[%d] ", result[i]);
	}
	cout << endl;
	printf("进程\t work\t need\t allocation\t work + allocation\t Finish\n");

	for (int i = 0; i < I; ++i)
	{
		int k = result[i];
		printf("P%d\t", result[i]);
		for (int j = 0; j < R; ++j)
		{
			cout << WorkMartix[k][j] << " ";
		}
		printf("\t ");
		for (int j = 0; j < R; ++j)
		{
			cout << Need[k][j] << " ";
		}
		printf("\t  ");
		for (int j = 0; j < R; ++j)
		{
			cout << Allocation[k][j] << " ";
		}
		printf("\t\t");
		for (int j = 0; j < R; ++j)
		{
			cout << WorkAllocation[k][j] << " ";
		}
		printf("\t\t  ");
		cout << finash[k].c_str() << endl;
	}
	result.clear();
	return true;
}


//T0时刻的安全序列
void T0Try()
{
	int work[R] = { 0 };
	memmove(work, Available, R*sizeof(int));
	Find(work);
}

//请求时调用试分配
void RequestTry(int pos, int* request)
{
	if (pos >= I)
	{
		cout << endl << "注意：无此进程！！！" << endl;
		return;
	}
	for (int i = 0; i < R; ++i)
	{
		if (request[i] > Need[pos][i])
			throw - 1;
		if (request[i] > Available[i])
			throw - 2;
	}
	int work[R] = { 0 };
	int tmpneed[R] = { 0 };
	int tmpAllocate[R] = { 0 };

	memmove(tmpneed, Need[pos], R*sizeof(int));
	memmove(tmpAllocate, Allocation[pos], R*sizeof(int));

	Add(Allocation[pos], request, R);
	Sub(Need[pos], request, R);

	int tmpAv[R] = { 0 };
	memmove(tmpAv, Available, R*sizeof(int));
	Sub(Available, request, R);
	memmove(work, Available, R*sizeof(int));

	bool ret = Find(work);

	if (ret)
		return;
	//复位
	memmove(Need[pos], tmpneed, R*sizeof(int));
	memmove(Allocation[pos], tmpAllocate, R*sizeof(int));
	memmove(Available, tmpAv, R*sizeof(int));
}


void DisPlay()
{
	cout << endl << "t0时刻的状态" << endl;
	printf("进程\t Max\t Allocation\t Need\t Available\n");

	for (int i = 0; i < I; ++i)
	{
		printf("P%d\t", i);
		for (int j = 0; j < R; ++j)
		{
			cout << Max[i][j] << " ";
		}
		printf("\t   ");
		for (int j = 0; j < R; ++j)
		{
			cout << Allocation[i][j] << " ";
		}
		printf("\t");
		for (int j = 0; j < R; ++j)
		{
			cout << Need[i][j] << " ";
		}
		printf("\t  ");
		for (int j = 0; j < R; ++j)
		{
			if (i == 0)
				cout << Available[j] << " ";
			else
				cout << " " << " ";
		}
		cout << endl;
	}
}

void test()
{
	while (1)
	{
		int choose = 0;
		cout << endl << endl;
		cout << "            *******银行家算法*******" << endl;
		cout << "            1. 查看t0时刻资源分配情况" << endl;
		cout << "            2. 查看t0时刻状态是否安全" << endl;
		cout << "            3. 为进程申请资源" << endl;
		cout << "            0. 退出" << endl;
		cout << "请输入选项：";
		cin >> choose;
		int id = -1;
		int request[R] = { 0 };
		switch (choose)
		{
		case 0:
			exit(0);
			break;
		case 1:
			DisPlay();
			break;
		case 2:
			T0Try();
			break;
		case 3:
			cout << "请依次输入要申请的进程号（0,1,2,3,4）和各类资源个数（中间用空格隔开）：" << endl;
			cin >> id;
			for (int i = 0; i < R; ++i)
			{
				cin >> request[i];
			}
			try{ RequestTry(id, request); }
			catch (int n)
			{
				if (n == -1)
					cout << endl << "注意：超过进程的需求（Need）!" << endl;
				else
					cout << endl << "注意：申请量超过当前剩余资源数，需要等待!" << endl;
			}
			break;
		default:
			cout << "注意：输入有误" << endl;
			break;
		}
	}
}

int main()
{
	test();
	system("pause");
	return 0;
}
