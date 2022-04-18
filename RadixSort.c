#define _CRT_SECURE_NO_WARNINGS				//����ó��
#include <stdio.h>
#include <time.h>
#define MAX_COUNT 10000

void RadixSort(int arr[], int n) {
	int result[MAX_COUNT], maxValue = 0;
	int exp = 1;
	for (int i = 0; i < n; i++) {
		if (arr[i] > maxValue) maxValue = arr[i];
	}
	while (maxValue / exp > 0) {			// �ڸ��� ���
		int bucket[10] = { 0 };
		for (int i = 0; i < n; i++) {		// �ڸ��� �迭 ó��
			bucket[arr[i] / exp % 10]++;
		}									
		for (int i = 1; i < 10; i++) {		// ���� ��� : ��� �迭�� ����� ���� �������� ���
			bucket[i] += bucket[i - 1];			
		}
		for (int i = n - 1; i >= 0; i--) {	//���� �ڸ��� ������ ���� ����
			result[--bucket[arr[i] / exp % 10]] = arr[i];
		}
		for (int i = 0; i < n; i++) {
			arr[i] = result[i];
		}									// �⺻ �迭 ����
		exp *= 10;
	}
}

int main() {
	clock_t start_Rd = clock();				//�ð� ���� ����

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

	RadixSort(data, MAX_COUNT);				//Exchange Sort ���� 

	clock_t end_Rd = clock();				//�ð� ���� ����

	for (i = 0; i < MAX_COUNT; i++) {		// ��� ���
		printf("%d, ", data[i]);
	}

	printf("\n");

	printf("Radix Sort ���� �ð�: %lf\n", (double)(end_Rd - start_Rd) / CLOCKS_PER_SEC);

	return 0;
}
