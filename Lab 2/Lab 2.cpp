#include <iostream>
using namespace std;

void print_info(int h, int m);
void padez_minutes(int min);
void padez_hours(int hr);
void time_of_day(int hrs);

int main(){
	setlocale(LC_ALL, "Russian");
	int hours, minutes;
	for (;;) {
		cout << "\nвведите время суток:\n" << endl;
		link:
		cin >> hours;
		if (hours == -1)
			break;
		cin >> minutes;
		if ((0 <= hours) and (hours < 24) and (0 <= minutes) and (minutes < 60))
			print_info(hours, minutes);
		else {
			cout << "\nНеверный формат ввода. Повторите ввод:\n" << endl;
			goto link;
			continue;
		}
	}
	return 0;
}


void print_info(int h, int m) {
	cout << "\n";
	if (m == 0) {
		if (h == 0)
			cout << "полночь" << endl;
		else if (h == 12)
			cout << "полдень" << endl;
		else {
			padez_hours(h);
			time_of_day(h);
			cout << " ровно" << endl;
		}
	}
	else {
		padez_hours(h);
		padez_minutes(m);
		time_of_day(h);
	}
	cout << "\n";
}


void padez_minutes(int mn){
	int padezh = mn % 10;
	if (11 <= mn and mn <= 16)
		cout << mn << " минут ";
	else if (padezh == 1)
		cout << mn << " минутa ";
	else if (2 <= padezh and padezh <= 4)
		cout << mn << " минуты ";
	else
		cout << mn << " минут ";
}

void padez_hours(int hr){
	if (hr > 12)
		hr %= 12;
	if (hr == 1)
		cout << hr << " час ";
	else if (hr >= 2 and hr <= 4)
		cout << hr << " часа ";
	else
		cout << hr << " часов ";
}

void time_of_day(int hrs){
	if (0 <= hrs and hrs < 5)
		cout << "ночи";
	else if (5 <= hrs and hrs < 12)
		cout << "утра";
	else if (12 <= hrs and hrs < 18)
		cout << "дня";
	else
		cout << "вечера";
}