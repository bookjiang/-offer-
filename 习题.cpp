//分治法，先快速排序，在依次比较相邻的差
#include <iostream>
#include <Windows.h>
#include "io.h"
#include "problem.h"
#include <vector>
#include"stdafx.h"
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





//1.6子递归程序
double  pro1_6_1(int k,int max)
{
	//int max = 0;
	/*cout <<"k  "<< k << endl;
	cout <<"max  "<< max << endl;*/
	if (k > max)
	{
		return 0;
	}
	k++;
	double  n1 = (double)((double)(k - 1) / (double)(2 * (k - 1) + 1));//注意整数运算默认结果为整数，故需要强制转化为浮点数
	//cout << "n1" << n1 << endl;
	double n = (double)(2 + n1 * (double)pro1_6_1(k,max));
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
	int max=0;
	cout << "请输入公式结束的k值";
	cin >> max;
	int k = 1;
	double value = pro1_6_1(k,max);
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


bool duplicate(int numbers[], int length, int* duplication) {

	if (numbers == NULL || length <= 0)
	{
		return false;
	}

	for (int i = 0; i < length; i++)
	{
		if (numbers[i] >= length || numbers[i] < 0)
		{
			return false;
		}
	}
	for (int i = 0; i < length; i++)
	{
		while (numbers[i] != i)
		{
			if (numbers[i] == numbers[numbers[i]])
			{
				//cout << numbers[i] << endl;
				*duplication = numbers[i];
				//cout << *duplication << endl;
				return true;
			}
			//swap
			int temp;
			temp = numbers[i];
			numbers[i] = numbers[temp];
			numbers[temp] = temp;
		}
	}
	return false;
}



/**************************************************
@brief   :菲波那切数列递归求值
@idea   :
@parameter   :
@author  : zhiqiang
@input   ：
@output  ：
@time    :
**************************************************/

long Fibonacci(unsigned int n)
{
	if (n <= 0)
		return 0;
	if (n == 1)
		return 1;
	int k = n;
	return Fibonacci(n - 1) + Fibonacci(n - 2);
}


long Fibonacci_improvement(unsigned int n)
{
	int f1 = 0;
	int f2 = 1;
	for (int i = 2; i <= n; i++)
	{
		int temp = f1 + f2;
		f1 = f2;
		f2 = temp;
	}
	return f2;

}




/**************************************************
@brief   :面试题12：矩阵中的路径
@idea   :
@parameter   :
@author  : zhiqiang
@input   ：
@output  ：
@time    :
**************************************************/

bool solu(char* matrix, int rows, int cols, char* str, int row, int col, int index, int* visited)
{
	if (row < 0 || col<0 || index < 0 || row >= rows || col >= cols || index >= strlen(str))//index<=不能加等号
		return false;
	bool k = 0;
//	if (visited[index] == '/0')
//		return 1;
	int len = strlen(str)-1;
	//cout << "长度" << len << endl;
	cout << "matrix:" << matrix[row * cols + col] <<":"<<row<<":"<<col<<":"<<index<<":"<< endl;
	cout << "str:" << str[index] <<":"<<len<< endl;
	if (index == len) return 1;
	if (row - 1 >= 0 && visited[(row - 1) * cols + col] != 1 && matrix[(row - 1) * cols + col] == str[index])//查看上方
	{
		
		if (index == len) return 1;
		visited[(row - 1) * cols + col] = 1;//访问过，标记一下
		k = solu(matrix, rows, cols, str, row - 1, col, index + 1, visited);
		if (k == 1) return k;//如果找到就不用再往下遍历了
		visited[(row - 1) * cols + col] = 0;//递归回来，还原一下
	}
	if (row + 1 < rows && visited[(row + 1) * cols + col] != 1 && matrix[(row + 1) * cols + col] == str[index])//查看下方
	{
		if (index == len) return 1;
		visited[(row + 1) * cols + col] = 1;
		k = solu(matrix, rows, cols, str, row + 1, col, index + 1, visited);
		if (k == 1) return k;//如果找到就不用再往下遍历了
		visited[(row + 1) * cols + col] = 0;
	}
	if (col - 1 >= 0 && visited[row * cols + col - 1] != 1 && matrix[row * cols + col - 1] == str[index])//查看左方
	{
		if (index == len) return 1;
		visited[row * cols + col - 1] = 1;//访问过，标记一下
		k = solu(matrix, rows, cols, str, row, col - 1, index + 1, visited);
		if (k == 1) return k;//如果找到就不用再往下遍历了
		visited[row * cols + col - 1] = 0;//递归回来，还原一下
	}
	if (col + 1 <= cols && visited[row * cols + col + 1] != 1 && matrix[row * cols + col + 1] == str[index])//查看右方
	{
		if (index == len) return 1;
		visited[row * cols + col + 1] = 1;//访问过，标记一下
		k = solu(matrix, rows, cols, str, row, col + 1, index + 1, visited);
		if (k == 1) return k;//如果找到就不用再往下遍历了
		visited[row * cols + col + 1] = 0;//递归回来，还原一下
	}

	return k;
}


bool hasPath(char* matrix, int rows, int cols, char* str)
{
	bool k = false;
	int row, col;//保存目前矩阵遍历的位置
	int index = 0;//保存数组中遍历位置
	int* visited = new int(rows * cols);
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			visited[i * cols + j] = int(0);
		}
	}
	if (rows == 0 || cols == 0 || str == nullptr)  //考虑例外
		return false;
	for (row = 0; row < rows; row++)
	{
		for (col = 0; col < cols; col++)
		{
			if (matrix[row * cols + col] == str[0])
			{
				cout << "m1" << matrix[row * cols + col] << endl;
				cout << "s1" << str[0] << endl;
				visited[row * cols + col] = 1;
				k= solu(matrix, rows, cols, str, row, col, index+1, visited);  //不能直接用return xxx
				if (k == 1)return k;
				visited[row * cols + col] = 0;
			}

		}

	}
	return k;

}



/**************************************************
@brief   :面试题16：数值的整数次方
@idea   :
@parameter   :
@author  : zhiqiang
@input   ：
@output  ：
@time    :
**************************************************/
double PowerwithUnsignedExponent(double base, unsigned int exponentTemp)
{
	if (exponentTemp == 0)
		return 1;
	if (exponentTemp == 1)
		return base;
	double result = PowerwithUnsignedExponent(base, exponentTemp >> 1);
	result *= result;
	if (exponentTemp & 0x1 == 1)  //用位运算判断奇偶
		result *= base;
	return result;
}
double Power(double base, int exponent) {
	double dis = 1e-6;
	if (abs(base - 0.0) < dis && exponent <= 0)  //发生错误，注意利用差来判断浮点数的相等
		return 0;
	unsigned int exponentTemp = exponent;
	if (exponent < 0)
	{
		exponentTemp = -exponent;
	}
	double result = PowerwithUnsignedExponent(base, exponentTemp);
	if (exponent < 0)
		result = 1.0 / result;
	return result;


}



//leetcode 寻找数组的中心索引
int pivotIndex(vector<int>& nums)
{
	int leftSum=0, rightSum=0;
	for (int i = 1; i < nums.size(); i++)
	{
		leftSum += nums[i];
	}
	for (int i = 0; i < nums.size(); i++)
	{
		if (rightSum == leftSum)
		{
			return i;
		}
		else
		{
			rightSum += nums[i];
			leftSum -= nums[i+1];
		}
	}
	return -1;
}



