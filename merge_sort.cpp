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
		int mid = (l + r) / 2;//중간값 구하기
		merge_sort(L, l, mid);//처음~중간 정렬
		merge_sort(L, mid + 1, r);//중간~마지막 정렬
		sort(L,l,mid,r);//처음~마지막 전체 정렬
	}
}
void sort(int L[], int l, int mid, int r) {
	int i=l, j=mid+1, k=r;
	int temp[SIZE] = {};
	while (i <= mid && j <= r) {//i,j가 중간값을 넘지 않았을 때까지
		if (L[i] < L[j]) {//i<j라면
			temp[k++] = L[i++];//temp에 L[i]값 복사
		}
		else {
			temp[k++] = L[j++];//temp에 L[j]값 복사
		}
	}
	while (i <= mid) {//i가 중간값보다 작을 때까지
		temp[k++] = L[i++];//temp에 L[i]값 복사
	}
	while (j <= r) {//j가 r값보다 작을 때까지
		temp[k++] = L[j++];//temp에 L[j]값 복사
	}
	for (int i = l; i <= r; i++) {
		L[i] = temp[i];//L에 temp값 복사
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
