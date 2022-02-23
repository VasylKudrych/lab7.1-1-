#include <iostream>
#include <iomanip>
#include <time.h>
using namespace std;

void Create(int** a, const int rowCount, const int colCount, const int High,
	const int Low)
{
	for (int i = 0; i < rowCount; i++)
		for (int j = 0; j < colCount; j++)
			a[i][j] = Low + rand() % High;
}
void Print(int** a, const int rowCount, const int colCount)
{
	cout << endl;
	for (int i = 0; i < rowCount; i++)
	{
		for (int j = 0; j < colCount; j++)
			cout << setw(4) << a[i][j];
		cout << endl;
	}
	cout << endl;
}
void Change(int** a, const int col1, const int col2, const int rowCount)
{
	int tmp;
	for (int i = 0; i < rowCount; i++)
	{
		tmp = a[i][col1];
		a[i][col1] = a[i][col2];
		a[i][col2] = tmp;
	}
}
void Sort(int** a, const int rowCount, const int colCount)
{
	for (int j0 = 0; j0 < colCount - 1; j0++)
		for (int j1 = 0; j1 < colCount - j0 - 1; j1++)
			if ((a[0][j1] < a[0][j1 + 1])
				||
				(a[0][j1] == a[0][j1 + 1] &&
					a[1][j1] > a[1][j1 + 1])
				||
				(a[0][j1] == a[0][j1 + 1] &&
					a[1][j1] == a[1][j1 + 1] &&
					a[2][j1] < a[2][j1 + 1]))
				Change(a, j1, j1 + 1, rowCount);
}

void Calc(int** a, const int rowCount, const int colCount, int& S, int& k)
{
	S = 0;
	k = 0;
	for (int i = 0; i < rowCount; i++)
		for (int j = 0; j < colCount; j++)
			if (a[i][j] % 2 == 0 && j % 2 == 0 && j % 2 == 0)
			{
				S += a[i][j];
				k++;
				a[i][j] = 0;
			}
}

int main()
{
	srand((unsigned)time(NULL));
	int Low = 4;
	int High = 45;
	int rowCount = 9;
	int colCount = 7;
	int** a = new int* [rowCount];
	for (int i = 0; i < rowCount; i++)
		a[i] = new int[colCount];
	Create(a, rowCount, colCount, High, Low);
	Print(a, rowCount, colCount); cout << endl;
	Sort(a, rowCount, colCount);
	Print(a, rowCount, colCount); cout << endl;
	int S = 0;
	int k = 0;
	Calc(a, rowCount, colCount, S, k);
	cout << "sum = " << S << endl;
	cout << "amount = " << k << endl;
	Print(a, rowCount, colCount); cout << endl;

	for (int i = 0; i < rowCount; i++)
		delete[] a[i];
	delete[] a;
	return 0;
}
