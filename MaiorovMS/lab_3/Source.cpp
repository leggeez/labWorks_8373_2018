#include <iostream>
#include "string.h"
#include "conio.h"

using namespace std;

int main()
{
	const int size = 20;
	const int size2 = 200;
	char str[size2];
	char str2[size2];
	char str3[size][size2];
	int length;
	int z = 0, y = 0, j = 0, max = 0;
	int x = 1;
	int *sum = new int[x];
	setlocale(LC_ALL, "Rus");
	cout << "Введите строку " << endl;;
	cin.getline(str, size2);
	length = strlen(str);

	for (int i = 0; i < length; i++) {
		if (str[i] == ' ')  x++;
	}

	for (int i = 0; i < x; i++) {
		sum[i] = 0;
		while ((str[j] != ' ') && (str[j] != '\0')) {
			str3[i][z] = str[j];
			sum[i] += (int)(str[j]);
			j++;
			z++;
		}
		j++;
		str3[i][z] = '\0';
		z = 0;
	}


	for (int i = 0; i < x; i++) {
		z = 0;
		for (j = 0; j< x; j++) {
			if (sum[j] < sum[max]) {
				max = j;
			}
		}
		while (str3[max][z] != '\0')
		{
			str2[y] = str3[max][z];
			z++;
			y++;
		}
		str2[y] = ' ';
		sum[max] = 100000000;
		y++;
	}
	str2[y] = '\0';
	for (int i = 0; i <= length; i++)
	{
		cout << str2[i];
	}
	delete sum;
	_getch();
	return 0;
}
