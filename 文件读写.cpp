#include "stdafx.h"
#include "io.h"
using namespace std;
const char* filenameRead = "C:\\Users\\吴志强\\Documents\\Visual Studio 2017\\Projects\\算法分析与设计题集\\算法分析与设计题集\\read.txt";
const char* filenameWrite = "C:\\Users\\吴志强\\Documents\\Visual Studio 2017\\Projects\\算法分析与设计题集\\算法分析与设计题集\\write.txt";
/**************************************************
@brief   :文件读入数组
@parameter   :
@author  :
@input   ：输入接受数组的缓存区
@output  ：输出数组中个数
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