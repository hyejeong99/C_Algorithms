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

int partition(int L[], int left, int right) {
	int pivot, temp; //가장 마지막 원소를 pivot으로 설정
	int low, high;
	low = left - 1; high = right;
	pivot = L[right];//가장 마지막 원소를 pivot으로 설정
	do {
		//L[low]가 pivot보다 작으면 low를 증가
		do { low = low + 1; } while (L[low] < pivot);
		//L[high]가 pivot보다 크면면 high를 감소
		do { high = high - 1; } while (L[high] > pivot);
		if (low < high) {//L[low]값과 L[high]값 바꿔주기
			temp = L[low]; L[low] = L[high]; L[high] = temp;
		}
	} while (low < high);
	//low와 high위치가 엇갈렸을 때
	temp = L[low]; L[low] = L[right]; L[right] = temp;
	return low;//pivot의 위치인 low 반환해주기
}

void sort(int L[], int left, int right)
{
	int p ;
	if (left < right) {
		//p를 기준으로 왼쪽, 오른쪽으로 정렬하기
		p = partition(L, left, right);
		sort(L, left, p - 1);
		sort(L, p + 1, right);
	}
}


int main()
{
	cout << "Input Data : ";
	print_data();

	/* sort the elements of array L[] in ascending order */
	sort(L,0,SIZE-1);

	cout << "\n\nSorted Data : ";
	print_data();

}
