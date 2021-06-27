#pragma once

#ifndef PROBLEM_H
#define PROBLEM_H
#include"stdafx.h"
#include<vector>
using namespace std;  //这个遗漏会报错：未标识错误
void problem1_3();
void problem1_6();
void problem1_7();
void problem3_kmp();
void TheBeatyOfTheProgramming1_1();
bool duplicate(int numbers[], int length, int* duplication);
long Fibonacci(unsigned int n);
long Fibonacci_improvement(unsigned int n);
bool hasPath(char* matrix, int rows, int cols, char* str);
double Power(double base, int exponent);
int pivotIndex(vector<int>& nums);
//TreeNode* reConstructBinaryTree(vector<int> pre, vector<int> vin);
#endif // ! PROBLEM_H

