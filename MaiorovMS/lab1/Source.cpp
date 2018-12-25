#include <iostream>
using namespace std;
int main()
{
	float a;
	int fool = 0, x=1;
	float b;
	float otvet;
	char znak;
	setlocale(LC_ALL, "Rus");
	while (x == 1) {
		cout << "Введите числа для последующих действий:\n";
		cin >> a >> b;
		cout << "Введите знак действия\n";
		cin >> znak;
		switch (znak) {
		case '+':
			otvet = a + b;
			break;
		case '-':
			otvet = a - b;
			break;
		case '*':
			otvet = a * b;
			break;
		case '/':
			if (b == 0) {
				++fool;
				cout << "Нельзя делить на 0\n";
				break;
			}
			else {
				otvet = a / b;
				break;
			}
		default: {
			++fool;
			cout << "Введен недопустимый символ\n";
		}
		}
		if (fool == 0)
			cout << "Результат-" << " " << otvet << endl;
		cout << "Для продолжения работы калькулятора введите <1>" << endl;
		cout << "Для завершения работы калькулятора введите <0>" << endl;
		cin >> x;
	}
}
