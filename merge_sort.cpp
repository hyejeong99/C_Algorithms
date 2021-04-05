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

void merge_sort(int L[], int l, int r)
{
	if (l < r) {
		int mid = (l + r) / 2;//�߰��� ���ϱ�
		merge_sort(L, l, mid);//ó��~�߰� ����
		merge_sort(L, mid + 1, r);//�߰�~������ ����
		sort(L,l,mid,r);//ó��~������ ��ü ����
	}
}
void sort(int L[], int l, int mid, int r) {
	int i=l, j=mid+1, k=r;
	int temp[SIZE] = {};
	while (i <= mid && j <= r) {//i,j�� �߰����� ���� �ʾ��� ������
		if (L[i] < L[j]) {//i<j���
			temp[k++] = L[i++];//temp�� L[i]�� ����
		}
		else {
			temp[k++] = L[j++];//temp�� L[j]�� ����
		}
	}
	while (i <= mid) {//i�� �߰������� ���� ������
		temp[k++] = L[i++];//temp�� L[i]�� ����
	}
	while (j <= r) {//j�� r������ ���� ������
		temp[k++] = L[j++];//temp�� L[j]�� ����
	}
	for (int i = l; i <= r; i++) {
		L[i] = temp[i];//L�� temp�� ����
	}

}
void main()
{
	cout << "Input Data : ";
	print_data();

	/* sort the elements of array L[] in ascending order */
	sort(L, 0,(0+SIZE-1)/2, SIZE - 1);

	cout << "\n\nSorted Data : ";
	print_data();

}
