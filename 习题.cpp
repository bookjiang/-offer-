//���η����ȿ������������αȽ����ڵĲ�
#include <iostream>
#include <Windows.h>
#include "io.h"
#include "problem.h"
using namespace std;
int partion(double  b[], int low, int high);
void quicksort(double b[], int low, int high);

/**************************************************
@brief   :1.3�������������С������Ԫ�صĲ�
@idea   :�ȿ�������
@parameter   :
@author  :
@input   ��
@output  ��
@time    :
**************************************************/
void problem1_3()
{
	double arry[100];
	int size;
	size = fileRead(arry);
	quicksort(arry, 0, size - 1);
	double num1 = arry[0];
	double num2 = arry[1];
	double dif = num2 - num1;
	for (int i = 2; i < size; i++)
	{
		if ((arry[i] - arry[i - 1]) < dif)
		{
			dif = arry[i] - arry[i - 1];
			num1 = arry[i - 1];
			num2 = arry[i];
		}
	}
	cout << "��С������Ԫ��Ϊ" << num1 << "��" << num2 << endl;
	cout << "��С��Ϊ" << dif << endl;
}

//���ţ�1.����ֵ��2.��ߵݹ���ţ�3.�ұߵݹ����
void quicksort(double b[], int low, int high)
{
	if (low < high)  //��Ȼû�����õݹ��������������������
	{
		int axis = partion(b, low, high);
		quicksort(b, low, axis - 1);
		quicksort(b, axis + 1, high);
	}

}


//������ֵλ��
int partion(double  b[], int low, int high)
{
	double  key = b[low];//ѡ�ŵ�һ��Ϊ��ֵ
	while (low < high)
	{
		while (key < b[high] && low < high)
			high--;
		b[low] = b[high];
		while (key > b[low] && low < high)
			low++;
		b[high] = b[low];

	}
	b[low] = key;
	return low;

}




int max = 0;
//1.6�ӵݹ����
double  pro1_6_1(int k)
{
	/*cout <<"k  "<< k << endl;
	cout <<"max  "<< max << endl;*/
	if (k > max)
	{
		return 0;
	}
	k++;
	double  n1 = (double)((double)(k - 1) / (double)(2 * (k - 1) + 1));//ע����������Ĭ�Ͻ��Ϊ����������Ҫǿ��ת��Ϊ������
	//cout << "n1" << n1 << endl;
	double n = (double)(2 + n1 * (double)pro1_6_1(k));
	//cout << "n" << n << endl;
	return  n;
}

/**************************************************
@brief   :1.6 ����
@idea   :��������ѧ��ʽ���
@parameter   :
@author  :
@input   ��
@output  ��
@time    :
**************************************************/
void problem1_6()
{
	cout << "�����빫ʽ������kֵ";
	cin >> max;
	int k = 1;
	double value = pro1_6_1(k);
	cout << "��ԼΪ" << value << endl;

}



/**************************************************
@brief   :������
@idea   :��1��ʼѭ����������ֵ
@parameter   :
@author  :
@input   ��
@output  ��
@time    :
**************************************************/
void problem1_7()
{
	int k;//�����������
	int sum = 0;//��������֮��
	cout << "����������" << endl;
	cin >> k;
	for (int i = 1; i <= k / 2; i++)
	{
		if (k % i == 0)
		{
			sum = sum + i;
		}
	}
	if (sum == k)
		cout << k << "��������" << endl;
	else
		cout << k << "����������" << endl;
}



/**************************************************
@brief   :kmp�㷨��next����
@idea   :
@parameter   :
@author  :
@input   ��
@output  ��
@time    :
**************************************************/
void getNext(char T[], int next[])
{
	int j = 0;
	int k = -1;
	next[0] = -1;
	while (T[j] != '\0')
	{
		if (k == -1)     //����ͬ�Ӵ�
		{
			next[++j] = 0; k = next[j - 1];
		}
		else if (T[j - 1] == T[k])  //������һ
		{
			next[++j] = k + 1; k = next[j - 1];
		}
		else				//�������ȡT[0]...T[j]��һ������Ӵ�
		{
			k = next[k];
		}
	}
}


/**************************************************
@brief   :kmp�㷨
@idea   :
@parameter   :
@author  :
@input   ��
@output  ��
@time    :
**************************************************/
void problem3_kmp()
{
	//cout << "����������" << endl;
	char s[100];
	char t[100];
	//cout << "����������" << endl;
	int next[100];
	cout << "����������" << endl;
	cin >> s;
	cout << "�������ѯ�Ӵ�" << endl;
	cin >> t;
	getNext(t, next);
	int i = 0, j = 0;
	while (s[i] != '\0' && t[j] != '\0')
	{
		if (s[i] == t[j])
		{
			i++; j++;
		}
		else
		{
			j = next[j];
			if (j == -1)
			{
				i++; j++;
			}
		}
	}
	if (t[j] == '\0')
	{
		int n = (i - strlen(t) + 1);
		cout << "ƥ��ɹ�����ʼλ��Ϊ" << n << endl;
	}
	else
	{
		cout << "ƥ��ʧ��" << endl;
	}
}


void TheBeatyOfTheProgramming1_1()
{
	for (; ; )
	{
		for (int i = 0; i < 2800000000; i++)
			;
		Sleep(10);
	}
	
}


void 