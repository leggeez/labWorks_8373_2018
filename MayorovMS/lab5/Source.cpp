#include <iostream>
#include <conio.h>
using namespace std;
const int x = 3, y = 3;

int sum(int i1, int j1, int A1[x][y], int B1[x][y], int C1[x][y]) {
	C1[i1][j1] = A1[i1][j1] + B1[i1][j1];
	return 0;
}

int dif(int i1, int j1, int A1[x][y], int B1[x][y], int C1[x][y]) {
	C1[i1][j1] = A1[i1][j1] - B1[i1][j1];
	return 0;
}

int mult(int A1[x][y], int B1[x][y], int C1[x][y]) {
	int summa = 0;
	for (int i = 0; i < x; i++) {
		for (int z = 0; z < x; z++) {
			for (int j = 0; j < y; j++) {
				summa += A1[i][j] * B1[j][z];
			}
			C1[i][z] = summa;
			summa = 0;
		}
	}
	return 0;
}


int main() {
	setlocale(LC_ALL, "Rus");
	int A[x][y], B[x][y], C[x][y];
	int n;

	cout << "Введите матрицу A" << endl;
	for (int i = 0; i < x; i++) {
		cout << endl;
		for (int j = 0; j < y; j++) {
			cin >> A[i][j];
		}
	}


	cout << "Введите матрицу B" << endl;
	for (int i = 0; i < x; i++) {
		cout << endl;
		for (int j = 0; j < y; j++) {
			cin >> B[i][j];
		}
	}


	cout << "A:" << "\t\t\t\t\t" << "B:" << endl;
	for (int i = 0; i < x; i++) {
		cout << endl;
		for (int j = 0; j < y; j++) {
			cout << A[i][j] << "\t";
		}
		cout << "\t\t";
		for (int j1 = 0; j1 < y; j1++) {
			cout << B[i][j1] << "\t";
		}
	}

	
	int on=1,error;
	while (1) 
	{
		if (on == 1) {
			cout << "\n\n" << "Выберите операцию:" << "\n" << "1.Сложение" << "\t\t" << "2.Вычитание" << "\t\t" << "3.Умножение" << endl;
			cin >> n;
			switch (n) {
			case 1:	for (int i = 0; i < x; i++) {
				for (int j = 0; j < y; j++) {
					sum(i, j, A, B, C);
				}
			}
					break;
			case 2:	for (int i = 0; i < x; i++) {
				for (int j = 0; j < y; j++) {
					dif(i, j, A, B, C);
				}
			}
					break;
			case 3: mult(A, B, C);
				break;
			default: cout << "!!!!!!!Введено некоректное число!!!!!!!" << endl;
				error = 0;
				break;
			}
			if (error) {
				cout << "\n\n" << "Результат: " << endl;
				for (int i = 0; i < x; i++) {
					cout << endl;
					for (int j = 0; j < y; j++) {
						cout << C[i][j] << "\t";
					}
				}
			}
		}
		else return 0;
		cout << "\n" << "Вы хотите продолжить вычисления? " << "\n" << "1. - ДА" << "\t\t" << "2. - НЕТ" << endl;
		cin >> on;
	}
}
