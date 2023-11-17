#include "functions.h"
#include "constants.h"
#include <iostream>
#include <iomanip>
#include <numbers>
#include <cmath>

using namespace std;
using namespace std::numbers;

void manager() {
    /*�������, ���������� �� ����� ������ �������������
    ������������ ������ ����� ������ (1, 2, 3 ��� 4),
    ����� ���� ������ ������� �������� �������, ���������� �� ������� ��������������� ������*/
    int choose;
    cout << "\n������� ����� ������, ������� ������ ���������: " << endl;
    cin >> choose;
    switch (choose) {
    case 1:
        int m, n;
        cout << "\n������� ����� n � m:" << endl;
        cin >> n >> m;
        cout << "\n" << summ(n, m) << "\n\n" << "������ ������� ������!" << endl;
        break;
    case 2:
        double a;
        cout << "\n������� ����� a:" << endl;
        cin >> a;
        cout << "\n" << setprecision(12) << multiply(a) << "\n" << "\n������ ������� ������!" << endl;
        break;
    case 3:
        series_sum(constants::EPS, constants::STEP);
        cout << "\n������ ������� ������!" << endl;
        break;
    case 4:
        double x;
        //const auto default_precision{ cout.precision() };
        //cout << default_precision;
        cout << "\n������� �������e x:" << endl;
        cin >> x;
        sum_count_manager(x);
        cout << "\n������ ������� ������!" << endl;
        break;
    default:
        cout << "�������� ������ �����. ��������� ����" << endl;
    }
}

int summ(int n, int m) {
    /*������� ���� ����� ����������� �����, ������� ������� �� 5 � �� ������� �� m(m < n).
    ���������� ����������� ����� n � �������� m �������� � ����������*/
    int result = 0;
    for (int i = 0; i <= n; i += 5) {
        if (i % m != 0) {
            result += i;
        }
    }
    return result;
}

double multiply(double a) {
    /*������� ��� ���������� ������������. ����� a �������� � ����������*/
    double result = 1;
    double i = 2;
    if (a >= 0) {
        do {
            result *= double(i * i);
            i += 2;
        } while (i <= 8);
        result -= a;
        return result;
    }
    else {
        i = 3;
        result = (i - 2);
        do {
            result *= double(i - 2);
            i += 3;
        } while (i <= 9);
        return result;
    }
}

void series_sum(double eps, double delta = 0.2) {
    /*�������, ����������� �������� ������� e^2x ��� ������ x �� 0 �� 1 � ����� delta.
    ������ ������ ����������� � ����������� ��������, ���������� �� ���������������� ����������
    ��������� ���� �������. ������ ������ ������� �������� ��������, ��������� �������������� ��������� "e"
    �� ������������� ����� <numbers>. ������� ��������� � ���� �������.*/
    cout << setprecision(6) << "\n" << setw(5) << "x  |" << setw(10) 
         << "y(x)  |" << setw(10) << "s(x)  |" << setw(5) << "n  " 
         << "\n" << "------------------------------" << endl;
    for (double x = 0; x <= static_cast<double>(1); x += delta) {
        double n = 1, s = 0, prev = 0, next = 1;
        do {
            prev = next;
            s += prev;
            next = prev * (static_cast<double>(2) * x / n);
            n++;
        } while (abs(prev) > eps);
        double y = pow(e, static_cast<double>(2) * x);
        cout << setw(3) << x << setw(3) << "| " << setw(7) << y << setw(3) << "| " 
             << setw(7) << s << setw(3) << "| " << setw(3) << n << endl;
    }
}

void sum_count_manager(double x, double n){
    char status = 'y';
    do {
        cout << "������� �������e n:" << endl;
        cin >> n;
        sum_count(x, n);
        cout << "\nRecalculate for a another n? (y/n)" << endl;
        cin >> status;
    } while (status != 'n');
}

void sum_count(double x, double n) {
    double result = 1;
    int even_odd = 0;
    for (auto i = 2; i <= static_cast<int>(n); ++i) {
        even_odd = static_cast<int>(pow(-1, i + 1));
        result += ((static_cast<double>(2) * i + 1) / (static_cast<double>(2) * i)) * pow(x, i - 1) * even_odd;
        switch (i) {
        case 3:
            cout << "\nIntermediate result for 3 first terms: " << fixed << result << endl;
            break;
        case 5:
            cout << "Intermediate result for 5 first terms: " << fixed << result << endl;
            break;
        case 10:
            cout << "Intermediate result for 10 first terms: " << fixed << result << endl;
            break;
        }
    }
    cout << "\nResult for " << static_cast<int>(n) + 1 << " terms: " << result << endl;
}