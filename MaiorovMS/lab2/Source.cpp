#include<iostream>
#include<ctime>
#include <conio.h>

using namespace std;
int main() {
	double z,max,min,sum;
	int x, y = 0;
	srand(time(0));
	setlocale(LC_ALL, "Rus");
	const int size = 10;
	int arr[size],arr2[size];
	cout << "Введенный массив:" << "\n\n";
	for (int i = 0; i < size; i++) {
		arr[i] = 1 + rand() % 100;
		cout << arr[i] << "\t";
	}
	cout << "\n\n";
	while (y < size - 1) {
		x = 0;
		while (x < size - 1) {
			if (arr[x] < arr[x + 1]) {
				z = arr[x];
				arr[x] = arr[x + 1];
				arr[x + 1] = z;	
			}
			x++;
		}
		y++;
	}
	cout << "Отсортированный по убыванию массив:" << "\n\n";
	for (int i = 0; i < size; i++) {
		cout << arr[i] << "\t";
	}
	cout << "\n";
	x = 0;
	min = 300;
	max = 0;
	sum = 0;
	int n=0;
	double average;
	for (int i = 0; i < size; i++) {
		if (arr[i] % 2 != 0) {
			arr2[x] = arr[i];
			x++;
			if (arr[i] > max) {
				max = arr[i];
			}
			if (arr[i] < min) {
				min = arr[i];
			}
			sum += arr[i];
			n++;
		}
	}
	average = sum / n;
	cout << endl;
	cout << "Массив из нечетных элементов 1 массива:" << "\n\n";
	for (int i = 0; i < x; i++) {
		cout << arr2[i] << "\t";
	}
	cout <<"\n\n"<< "Минимальный элемент="  << min << "\n\n";
	cout << "Максимальный элемент=" << max << "\n\n";
	cout << "Среднее арифметическое элементов=" << average << "\n\n ";
	_getch();
	return 0;
}
