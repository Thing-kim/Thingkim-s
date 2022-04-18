#include <stdio.h>
#include <time.h>
#define MAX_COUNT 10000

void ExSort(int arr[], int n) {
	
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n-1  ; j++) {
			if (arr[j] > arr[j+1]) {	//swap
				int tmp = arr[j];
				arr[j] = arr[j+1];
				arr[j+1] = tmp;
			}
		}
	}
	return;
}

int main() {
	clock_t start_Ex = clock();				//�ð� ���� ����

	int i, j, data[MAX_COUNT];

	srand(time(NULL));						//�ð����� ���� �� ����

	for (i = 0; i < MAX_COUNT; i++) {
		data[i] = rand() % MAX_COUNT + 1;	//�迭 ���� ������ 1 ���ϸ� �迭 ������ ���� �ִ� ��
		for (j = 0; j < i; j++) {
			if (data[i] == data[j]) {
				i--;
				break;
			}
		}
	}

	for (i = 0; i < MAX_COUNT; i++) {		//���� �� ������ ���
		printf("%d, ", data[i]);
	}

	printf("\n");

	ExSort(data, MAX_COUNT);				//Exchange Sort ���� 

	clock_t end_Ex = clock();				//�ð� ���� ����

	for (i = 0; i < MAX_COUNT; i++) {		// ��� ���
		printf("%d, ", data[i]);
	}

	printf("\n");

	printf("Exchange Sort ���� �ð�: %lf\n", (double)(end_Ex - start_Ex) / CLOCKS_PER_SEC);

	return 0;
}



