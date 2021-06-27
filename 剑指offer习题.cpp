//#include <iostream>
#include "stdafx.h"
#include "io.h"
#include "problem.h"

using namespace std;
int main()
{
	//double arry[20];
	//fileRead(arry);
	//problem1_3();
	//problem1_6();
	//problem1_7();
	//problem3_kmp();
	//TheBeatyOfTheProgramming1_1();


	//int numbers[7] = { 2,3,1,0,2,5,3 };
	//int length = 7;
	//int *duplication=new(int);
	//*duplication = -1;
	//bool signal= duplicate(numbers, length, duplication);
	//if (signal) { cout << *duplication << endl; }
	//else cout << "无重复数字" << endl;


	//菲波那切数列
	//cout << "请输入数字" << endl;
	//int n;
	//cin >> n;
	//n = Fibonacci_improvement(n);
	//cout << "结果为" << n<<endl;
	//


	////面试题12：矩阵中的路径
	//int rows = 3;
	//int cols = 4;
	//char matrix[12];
	////matrix = new char[3*4];
	////string f = "abcesfcsadee";

	//strcpy(matrix, "ABCESFCSADEE");
	////cout << "ma" << matrix << endl;
	////strcpy_s(matrix, strlen(f)+1, f);

	////char* str;
	////str = new char[5];
	////strcpy_s(str,6, "bcced");
	////strcpy(str, "bcced");
	//char str[7];
	////strcpy(str, 'a');
	//str[0] = 'A';
	//str[1] = 'B';
	//str[2] = 'C';
	//str[3] = 'C';
	//str[4] = 'E';
	//str[5] = 'D';
	//str[6] = '\0';
	////cout << "str" << str << endl;
	////cout << "str长度" << strlen(str) << endl;
	//bool k = hasPath(matrix, rows, cols, str);
	////cout << "k:" << k << endl;
	//if (k)
	//	cout << "含有" << endl;
	//else
	//	cout << "不含" << endl;

	//double base = 2.0;
	//int exponent = 3;
	//double result = Power(base, exponent);
	//cout << result << endl;



	//vector<vector<char>> board = { {'X','.','.','X'},{'.','.','.','X'},{'.','.','.','X'} };
	//int n = board.size();
	//cout << "n" << n << endl;


	//string a = "abcd";
	//for (int i = 0; i < a.length(); i++)
	//	cout << a[i] << "\n" << endl;

	int num[6] = { 1,7, 3, 6, 5, 6 };
	vector<int> nums(num, num + 6);
	int result = pivotIndex(nums);
	cout << result << endl;
	//system("pause");
	getchar();
	return 0;
}