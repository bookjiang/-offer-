#include "stdafx.h"
#include "io.h"
using namespace std;
const char* filenameRead = "C:\\Users\\��־ǿ\\Documents\\Visual Studio 2017\\Projects\\�㷨����������⼯\\�㷨����������⼯\\read.txt";
const char* filenameWrite = "C:\\Users\\��־ǿ\\Documents\\Visual Studio 2017\\Projects\\�㷨����������⼯\\�㷨����������⼯\\write.txt";
/**************************************************
@brief   :�ļ���������
@parameter   :
@author  :
@input   �������������Ļ�����
@output  ����������и���
@time    :
**************************************************/
int  fileRead(double arry[])
{
	int i = 0;
	ifstream f(filenameRead, ios::in);
	while (!f.eof())
	{
		f >> arry[i++];
	}
	f.close();
	/*cout << "i" << i << endl;
	for (int j = 0; j < i; j++)
	{
		cout << arry[j] << "   ";
	}*/
	return i;

}