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
	int pivot, temp; //���� ������ ���Ҹ� pivot���� ����
	int low, high;
	low = left - 1; high = right;
	pivot = L[right];//���� ������ ���Ҹ� pivot���� ����
	do {
		//L[low]�� pivot���� ������ low�� ����
		do { low = low + 1; } while (L[low] < pivot);
		//L[high]�� pivot���� ũ��� high�� ����
		do { high = high - 1; } while (L[high] > pivot);
		if (low < high) {//L[low]���� L[high]�� �ٲ��ֱ�
			temp = L[low]; L[low] = L[high]; L[high] = temp;
		}
	} while (low < high);
	//low�� high��ġ�� �������� ��
	temp = L[low]; L[low] = L[right]; L[right] = temp;
	return low;//pivot�� ��ġ�� low ��ȯ���ֱ�
}

void sort(int L[], int left, int right)
{
	int p ;
	if (left < right) {
		//p�� �������� ����, ���������� �����ϱ�
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
