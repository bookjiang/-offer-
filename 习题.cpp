//分治法，先快速排序，在依次比较相邻的差
#include <iostream>
#include <Windows.h>
#include "io.h"
#include "problem.h"
using namespace std;
int partion(double  b[], int low, int high);
void quicksort(double b[], int low, int high);

/**************************************************
@brief   :1.3求数组中相差最小的两个元素的差
@idea   :先快排在找
@parameter   :
@author  :
@input   ：
@output  ：
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
	cout << "最小差俩个元素为" << num1 << "和" << num2 << endl;
	cout << "最小差为" << dif << endl;
}

//快排，1.找轴值；2.左边递归快排；3.右边递归快排
void quicksort(double b[], int low, int high)
{
	if (low < high)  //居然没有设置递归结束条件，该死啊啊啊
	{
		int axis = partion(b, low, high);
		quicksort(b, low, axis - 1);
		quicksort(b, axis + 1, high);
	}

}


//返回轴值位置
int partion(double  b[], int low, int high)
{
	double  key = b[low];//选着第一个为轴值
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
//1.6子递归程序
double  pro1_6_1(int k)
{
	/*cout <<"k  "<< k << endl;
	cout <<"max  "<< max << endl;*/
	if (k > max)
	{
		return 0;
	}
	k++;
	double  n1 = (double)((double)(k - 1) / (double)(2 * (k - 1) + 1));//注意整数运算默认结果为整数，故需要强制转化为浮点数
	//cout << "n1" << n1 << endl;
	double n = (double)(2 + n1 * (double)pro1_6_1(k));
	//cout << "n" << n << endl;
	return  n;
}

/**************************************************
@brief   :1.6 求解π
@idea   :，利用数学公式求解
@parameter   :
@author  :
@input   ：
@output  ：
@time    :
**************************************************/
void problem1_6()
{
	cout << "请输入公式结束的k值";
	cin >> max;
	int k = 1;
	double value = pro1_6_1(k);
	cout << "π约为" << value << endl;

}



/**************************************************
@brief   :完美数
@idea   :从1开始循环至开根号值
@parameter   :
@author  :
@input   ：
@output  ：
@time    :
**************************************************/
void problem1_7()
{
	int k;//保存输入的数
	int sum = 0;//保存因子之和
	cout << "请输入数字" << endl;
	cin >> k;
	for (int i = 1; i <= k / 2; i++)
	{
		if (k % i == 0)
		{
			sum = sum + i;
		}
	}
	if (sum == k)
		cout << k << "是完美数" << endl;
	else
		cout << k << "不是完美数" << endl;
}



/**************************************************
@brief   :kmp算法求next数组
@idea   :
@parameter   :
@author  :
@input   ：
@output  ：
@time    :
**************************************************/
void getNext(char T[], int next[])
{
	int j = 0;
	int k = -1;
	next[0] = -1;
	while (T[j] != '\0')
	{
		if (k == -1)     //无相同子串
		{
			next[++j] = 0; k = next[j - 1];
		}
		else if (T[j - 1] == T[k])  //相等则加一
		{
			next[++j] = k + 1; k = next[j - 1];
		}
		else				//不相等则取T[0]...T[j]下一个相等子串
		{
			k = next[k];
		}
	}
}


/**************************************************
@brief   :kmp算法
@idea   :
@parameter   :
@author  :
@input   ：
@output  ：
@time    :
**************************************************/
void problem3_kmp()
{
	//cout << "请输入主串" << endl;
	char s[100];
	char t[100];
	//cout << "请输入主串" << endl;
	int next[100];
	cout << "请输入主串" << endl;
	cin >> s;
	cout << "请输入查询子串" << endl;
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
		cout << "匹配成功，开始位置为" << n << endl;
	}
	else
	{
		cout << "匹配失败" << endl;
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