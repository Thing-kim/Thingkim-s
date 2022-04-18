#include <stdio.h>
#include <time.h>
#define MAX_COUNT 10000


void heap(int* arr, int n) {			//�� ���� ����� 
	for (int i = 1; i < n; ++i) {
		int child = i;
		while (child !=0) {					//�ֻ�ܱ��� ����

			int root = (child - 1) / 2;
			if (arr[root] < arr[child]) {
				int tmp = arr[root];
				arr[root] = arr[child];
				arr[child] = tmp;			//�ڽ� ��尡 �θ𺸴� ũ�� ��ȯ
			}
			child = root;
		}
	}
}

int main() {
	clock_t start_H = clock();				//�ð� ���� ����

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

	heap(data, MAX_COUNT);						//������ ���� �� �ð� ���

	for (int i = MAX_COUNT - 1; i >=0 ; i--) {	
		int temp = data[i];
		data[i] = data[0];
		data[0] = temp;				//�ֻ�� ���� ���ϴ� ��� ��ü

		heap(data, i);				//���� ū ���� �����ϰ� �ٽ� �� ����

	}				
	clock_t end_H = clock();		//�ð� ���� ����

	for (i = 0; i < MAX_COUNT; i++) {		// ��� ���
		printf("%d, ", data[i]);
	}

	printf("\n");

	printf("Heap Sort ���� �ð�: %lf\n", (double)(end_H - start_H) / CLOCKS_PER_SEC);

	return 0;
}