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

void sort()//�ִ밪�� �̿��� ��������
{
	int i, j, max;//max=�ִ밪
	int temp;
	for (i = SIZE; i > 0; i--) {//0����n����
		max = 0;//max�ε����� 0���� �������ֱ�
		for (j = 1; j <= i; j++) {
			if (L[j] > L[max]) max = j; //L[j]���� L[max](L[0])������ ũ�ٸ� max �ε��� �������ֱ�
		}
		temp = L[max];//temp���� max������ �����ֱ�
		L[max] = L[i];//max���� ������ ���ҿ� �ִ� ������
		L[i] = temp;//�� ������ ���� max������
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
