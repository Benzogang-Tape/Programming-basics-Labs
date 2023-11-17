#include <iostream>
using namespace std;

void average();

int main() {
    system("chcp 1251 > nul");
    char str1[88];
    cout << "Hello world" << endl;
    cout << "Enter the string:" << endl;
    cin >> str1;
    cout << "The value of str1:" << str1 << endl;
    float x2, x1, res;
    cin >> x1 >> x2;
    res = x1 + x2;
    cout << "\n" << res << endl;
    average();
    system("pause");
    return 0;
}

void average() {
    const int N = 5;
    int a[N] = { 1, 2, 3, 4, 5 };
    int sum = 0;
    int i;
    for (i = 0; i < N; i++)
        sum += a[i];
    int avrg = sum / N;
    cout << "average = " << avrg << endl;
}