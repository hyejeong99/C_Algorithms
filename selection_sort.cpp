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

void sort()//최대값을 이용한 선택정렬
{
	int i, j, max;//max=최대값
	int temp;
	for (i = SIZE; i > 0; i--) {//0부터n까지
		max = 0;//max인덱스를 0으로 설정해주기
		for (j = 1; j <= i; j++) {
			if (L[j] > L[max]) max = j; //L[j]값이 L[max](L[0])값보다 크다면 max 인덱스 변경해주기
		}
		temp = L[max];//temp값을 max값으로 정해주기
		L[max] = L[i];//max값은 마지막 원소에 있던 값으로
		L[i] = temp;//맨 마지막 원소 max값으로
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
