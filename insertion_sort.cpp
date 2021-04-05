#include <iostream>
using namespace std;

const int SIZE = 15;
int L[SIZE] = { 10, 4, 7, 1, -2, 12, 28, 66, 9, 3, 5, 7, 6, 21, 11 };


void print_data()
{
	for (int i = 0; i < SIZE; i++)
		cout << " " << L[i] << " ";
	cout << endl;
}

void sort()
{
	int i, j;
	int temp;

	for (i = 1; i <= SIZE; i++) {
		temp = L[i];//맨 앞 데이터를 temp로 설정
		j = i;
		while (j > 0 && L[j - 1] > temp) {//j가 0보다 크고, insert[j-1]이 temp보다 클 때
			L[j] = L[j - 1];//자리 바꿔주기
			j--;//j감소
		}
		L[j] = temp;//가장 작은 원소를 다시 temp로
	}
}

void main()
{
	cout << "Input Data : ";
	print_data();

	/* sort the elements of array L[] in ascending order */
	sort();

	cout << "\n\nSorted Data : ";
	print_data();

}
