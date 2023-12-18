#pragma once
#include <iostream>
#include <cmath>
#include <iomanip>
#include <cstring>
#include "constants.h"

using func_ref_1 = double (*)(double);
using func_ref_2 = double (*)(double, double);
using func_ref_3 = double (*) (func_ref_1, double, double, double, int&);

struct I_print {	//������ ��� ������ ����������� ��������������
	std::string function_name;//�������� �������
	double integral_sum;	//�������� ������������ �����
	double exact_value;	//������ �������� ���������
	int n;	//����� ��������� ������� �������������� 
	//��� ������� ���������� ��������� ��������
};

double IntRect(func_ref_1 f, double a, double b, double eps, int& n);
double IntTrap(func_ref_1 f, double a, double b, double eps, int& n);
void PrintTabl(I_print i_prn[], int k);

double Sin_exact(double a, double b);
double X_exact(double a, double b);
double PowX_exact(double a, double b);
double Arctan_exact(double a, double b);
double MySin(double x);
double MyX(double x);
double MyPowX(double x);
double MyArctan(double x);
