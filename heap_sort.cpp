#include <iostream>
using namespace std;
#define parent(x) (x-1)/2
const int SIZE = 15;
int L[SIZE] = { 10, 4, 7, 1, -2, 12, 28, 66, 9, 3, 5, 7, 6, 21, 11 };

void print_data()
{
	//��� ���
	for (int i = 0; i < SIZE; i++) {
		cout << L[i] << " ";
	}
}
void heap(int* data, int num) {
	for (int i = 1; i < num; i++) {
		int child = i;
		while (child > 0) {
			int root = parent(child);
			if (data[root] < data[child]) {
				int temp = data[root];
				data[root] = data[child];
				data[child] = temp;
			}child = root;
		}
	}
}
void sort(int *data, int num){
	heap(L, SIZE);
	// ���� �����. 
	for(int i=(SIZE-1); i>=0; i--){ 
		// ����ū ����(root)�� �� ������ ���ҿ� ���� 
		int temp = L[i];
		L[i] = L[0];
		L[0] = temp;
		// �Ǹ���������(����ū����)�� �����ϰ� �ٽ� ���� �����. 
		heap(L, i);
	}
}

int main(void){
	// ��� ��� 
	cout << "���� �� ������:";
	print_data();
	sort(L, SIZE);
	cout<<endl << "���� �� ������:";
	print_data();
	return 0;
} 
