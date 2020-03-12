#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<cstdio>
#include<windows.h>
#include<vector>
using namespace std;
//���þ����ʾ
//�����������ǰ��ʼ����

//�����м�������
const int I = 5;

//�����м�����Դ
const int R = 3;

//A,B,C������Դ������
int mem[R] = { 10, 5, 7 };

//һ��5�����̣��Ը�����Դ���������
int Max[I][R] = { { 7, 5, 3 }, { 3, 2, 2 }, { 9, 0, 2 }, { 2, 2, 2 }, { 4, 3, 3 } };

//ÿ�����̵�ǰ�ѷ��������Դ��
int Allocation[I][R] = { { 0, 1, 0 }, { 2, 0, 0 }, { 3, 0, 2 }, { 2, 1, 1 }, { 0, 0, 2 } };

//ÿ�����̵�ǰ��������
int Need[I][R] = { { 7, 4, 3 }, { 1, 2, 2 }, { 6, 0, 0 }, { 0, 1, 1 }, { 4, 3, 1 } };

//ϵͳ��ǰʣ��ɷ���ĸ�����Դ
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

vector<int> result;  //��¼��ȫ����
bool Find(int* work)
{
	int WorkAllocation[I][R] = { 0 };
	vector<string> finash(5, "false");
	int WorkMartix[I][R] = { 0 };

	int count = I*I;  //����ѭ������
	int i = 0;
	while (count--)
	{
		const char* tmp = finash[i].c_str();
		if (strcmp(tmp, "false") == 0)
		{
			//������������
			if (Comper(Need[i], work))
			{
				result.push_back(i); //���½��̺�
				finash[i] = "true";    //״̬���Ϊ����ɣ�
				//tag += 1;
				//��������
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
		cout << endl << " ��Դ�Է����ϵͳ����ȫ����ʱϵͳ��������Դ���Է���δ���ְ�ȫ����!!!" << endl;
		return false;
	}

	//HANDLE handle;
	//handle = GetStdHandle(STD_OUTPUT_HANDLE);
	//SetConsoleTextAttribute(handle, FOREGROUND_INTENSITY | FOREGROUND_RED);//����Ϊ��

	printf("\n��ȫ����Ϊ:");
	for (int i = 0; i < I; ++i)
	{
		printf("P[%d] ", result[i]);
	}
	cout << endl;
	printf("����\t work\t need\t allocation\t work + allocation\t Finish\n");

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


//T0ʱ�̵İ�ȫ����
void T0Try()
{
	int work[R] = { 0 };
	memmove(work, Available, R*sizeof(int));
	Find(work);
}

//����ʱ�����Է���
void RequestTry(int pos, int* request)
{
	if (pos >= I)
	{
		cout << endl << "ע�⣺�޴˽��̣�����" << endl;
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
	//��λ
	memmove(Need[pos], tmpneed, R*sizeof(int));
	memmove(Allocation[pos], tmpAllocate, R*sizeof(int));
	memmove(Available, tmpAv, R*sizeof(int));
}


void DisPlay()
{
	cout << endl << "t0ʱ�̵�״̬" << endl;
	printf("����\t Max\t Allocation\t Need\t Available\n");

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
		cout << "            *******���м��㷨*******" << endl;
		cout << "            1. �鿴t0ʱ����Դ�������" << endl;
		cout << "            2. �鿴t0ʱ��״̬�Ƿ�ȫ" << endl;
		cout << "            3. Ϊ����������Դ" << endl;
		cout << "            0. �˳�" << endl;
		cout << "������ѡ�";
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
			cout << "����������Ҫ����Ľ��̺ţ�0,1,2,3,4���͸�����Դ�������м��ÿո��������" << endl;
			cin >> id;
			for (int i = 0; i < R; ++i)
			{
				cin >> request[i];
			}
			try{ RequestTry(id, request); }
			catch (int n)
			{
				if (n == -1)
					cout << endl << "ע�⣺�������̵�����Need��!" << endl;
				else
					cout << endl << "ע�⣺������������ǰʣ����Դ������Ҫ�ȴ�!" << endl;
			}
			break;
		default:
			cout << "ע�⣺��������" << endl;
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
