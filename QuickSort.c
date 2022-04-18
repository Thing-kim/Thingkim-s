#include <stdio.h>
#include <time.h>
#define MAX_COUNT 10000

void QSort(int* arr, int L, int R) {
	if (L >= R) {		//�״�� �α�
		return;
	}

	int pivot = L;
	int i = L + 1;		//L ���
	int j = R;			//R ���
	int temp;

	while (i <= j) {    // L�� R���� �����ʿ� ���� ������ �ݺ�
		while (i <= R && arr[i] <= arr[pivot])    // L�� pivot���� ū �� or pivot�� ���� ������ 
			i++;
		while (j > L && arr[j] > arr[pivot])    // R�� pivot���� ���� �� or pivot�� ���� ������ 
			j--;
		if (i <= j) {   // L�� R���� ���ʿ� �ִٸ� ��ȯ
			temp = arr[i];
			arr[i] = arr[j];
			arr[j] = temp;
		}
		else {			//�Ǻ� ����
			temp = arr[j];
			arr[j] = arr[pivot];
			arr[pivot] = temp;
		}
	}

	QSort(arr, L, j - 1);	// �Ǻ� ���� ����
	QSort(arr, j + 1, R);	// �Ǻ� ������ ����
}

int main() {
	clock_t start_Q = clock();				//�ð� ���� ����

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

	QSort(data, 0, MAX_COUNT - 1);			//Quick Sort ���� �� �ð� ���

	clock_t end_Q = clock();				//�ð� ���� ����

	for (i = 0; i < MAX_COUNT; i++) {		// ��� ���
		printf("%d, ", data[i]);
	}

	printf("\n");

	printf("Quick Sort ���� �ð�: %lf\n", (double)(end_Q - start_Q) / CLOCKS_PER_SEC);

	return 0;
}
