#include <iostream>
#include <string>
#include <stack>
#include <math.h>
using namespace std;

class Kalkulator {
private:
	double wynik = 0;
	double memory = 0;

	void Func(string s) {
		if (s == "C") {
			wynik = 0;
		}
		else if (s == "CE") {
			cout << "Koniec Programu!" << endl;
			system("pause");
			exit(0);
		}
		else if (s == "M+") {
			memory += wynik;
		}
		else if (s == "M-") {
			memory -= wynik;
		}
		else if (s == "MC") {
			memory = 0;
		}
		else if (s == "MR") {
			wynik = memory;

		}
	}

	bool isFunc(string s) {
		return (s == "C" || s == "CE" || s == "M+" || s == "M-" || s == "MR" || s == "MC");
	}

	bool isDig(char c) {
		return (c >= '0' && c <= '9');
	}
	bool isDot(char c) {
		return (c == '.');
	}
	bool isOperator(char c) {
		return (c == '+' || c == '-' || c == '*' || c == '/');
	}
	double licz(double v1, double v2, char op) {
		if (op == '+') return v1 + v2;
		if (op == '-') return v1 - v2;
		if (op == '*') return v1 * v2;
		if (op == '/') {
			if (v2 == 0) {
				cout << "Nie dziel przez 0! Koniec programu!" << endl;
				system("pause");
				exit(0);
			}
			else {
				return v1 / v2;
			}
		}
	}

	double	getVal(string s) {
		int pos = 0;
		double val = 0;
		int flag = 0;
		int times = 0;

		while (pos < s.length()) {
			char spot = s[pos];

			if (isDig(spot)) {
				val = (val * 10) + (double)(spot - '0');
				if (flag == 1) {
					times--;
				}
			}
			else if (isDot(spot)) {
				flag = 1;
			}
			pos++;
		}

		val = val * pow(10, times);
		return val;
	}

	void refresh(double x) {
		system("cls");
		cout << x << endl;
	}

public:
	void calculate() {
		double val1 = 0;
		double val2 = 0;
		int flag = 0;
		char op;
		string s;


		cin >> s;
		char c = s[0];
		if (isFunc(s)) {
			Func(s);
			refresh(wynik);
			return;
		}
		else {
			refresh(wynik);
			while (!isOperator(c)) {

				val1 = getVal(s);
				wynik = val1;
				refresh(wynik);
				cin >> s;
				if (isFunc(s)) {
					Func(s);
					refresh(wynik);
					return;
				}
				c = s[0];
			}
		}
		refresh(wynik);

		op = c;
		cin >> s;

		if (isFunc(s)) {
			Func(s);
			refresh(wynik);
			return;
		}
		else {

			val2 = getVal(s);
			wynik = val2;
			refresh(wynik);
		}

		cin >> s;
		if (isFunc(s)) {
			Func(s);
			refresh(wynik);
			return;
		}
		else {
			refresh(wynik);

			if (s == "%") {
				val2 = val1 * val2*0.01;
				wynik = licz(val1, val2, op);
			}
			else if (s == "=") {
				wynik = licz(val1, val2, op);
			}
		}
		refresh(wynik);

	}

	Kalkulator() {}
};

int main() {
	Kalkulator *nowy = new Kalkulator;
	cout << "--------------------------------------------------------------" << endl << endl;
	cout << "                  KALKULATOR PROSTY                             " << endl << endl;
	cout << "--------------------------------------------------------------" << endl << endl;
	cout << "Instrukcja: " << endl;
	cout << "1. Wpisz 1 argument - zatwierdz Enterem " << endl;
	cout << "2. Wpisz operator dzialania - zatwierdz Enterem " << endl;
	cout << "3. Wpisz 2 argument - zatwierdz Enterem " << endl;
	cout << "4. Wpisz \"=\" dla normalnego dzialania lub" << endl;
	cout << " \"%\" jezeli drugi argument ma byc procentem" << endl;
	cout << "-zatwierdz Enterem " << endl;

	system("pause");
	system("cls");
	cout << "0" << endl;

	while (1) {
		nowy->calculate();
	}


	system("pause");
	return 0;
}