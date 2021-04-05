#include <iostream>
using namespace std;
#define parent(x) (x-1)/2
const int SIZE = 15;
int L[SIZE] = { 10, 4, 7, 1, -2, 12, 28, 66, 9, 3, 5, 7, 6, 21, 11 };

void print_data()
{
	//결과 출력
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
	// 힙을 만든다. 
	for(int i=(SIZE-1); i>=0; i--){ 
		// 가장큰 숫자(root)를 맨 마지막 원소와 스왑 
		int temp = L[i];
		L[i] = L[0];
		L[0] = temp;
		// 맨마지막원소(가장큰원소)를 제외하고 다시 힙을 만든다. 
		heap(L, i);
	}
}

int main(void){
	// 결과 출력 
	cout << "정렬 전 데이터:";
	print_data();
	sort(L, SIZE);
	cout<<endl << "정렬 후 데이터:";
	print_data();
	return 0;
} 
