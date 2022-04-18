#include <stdio.h>
#include <time.h>
#define MAX_COUNT 10000

void merge(int arr[], int left, int mid, int right) {
	int merge_tmp[MAX_COUNT];
	int i, j, k, l;
	i = left;
	j = mid + 1;
	k = left;
	;
	while (i <= mid && j <= right) {		// �պ�
		if (arr[i] <= arr[j])
			merge_tmp[k++] = arr[i++];
		else
			merge_tmp[k++] = arr[j++];
	}

	if (i > mid) {							//���� �ִ� �� ó��
		for (l = j; l <= right; l++)
			merge_tmp[k++] = arr[l];
	}

	else {
		for (l = i; l <= mid; l++)
			merge_tmp[k++] = arr[l];
	}

	for (l = left; l <= right; l++) {		//�ӽ� �迭�� �ִ� ���� ����Ʈ�� �纹��
		arr[l] = merge_tmp[l];
	}
}

void MergeSort(int arr[], int left, int right) {
	if (left == right) return;				//���� �ϳ��� ���� �� ���� ������ ���� ������ ���� �Ϸ� �� ����

	int mid = (left + right) / 2;			//�߰� ���� ���
	MergeSort(arr, left, mid);				//�߰� �� �Ʒ��κ� ����
	MergeSort(arr, mid + 1, right);			//�߰� �� ���κ� ����
	merge(arr, left, mid, right);			//�պ�
}

int main() {
	clock_t start_Mg = clock();				//�ð� ���� ����

	int i, j, data[MAX_COUNT];

	srand(time(NULL));

	for (i = 0; i < MAX_COUNT; i++) {
		data[i] = rand() % MAX_COUNT + 1;	 //�迭 ���� ������ 1 ���ϸ� 
		for (j = 0; j < i; j++) {
			if (data[i] == data[j]) {
				i--;
				break;
			}
		}
	}

	for (i = 0; i < MAX_COUNT; i++) {		//���� �� ������
		printf("%d, ", data[i]);
	}

	printf("\n");

	MergeSort(data, 0, MAX_COUNT - 1);		//Merge Sort ���� �� �ð� ���

	clock_t end_Mg = clock();				//�ð� ���� ����

	for (i = 0; i < MAX_COUNT; i++) {		// ��� ���
		printf("%d, ", data[i]);
	}

	printf("\n");


	printf("Merge Sort ���� �ð�: %lf\n", (double)(end_Mg - start_Mg) / CLOCKS_PER_SEC);

	return 0;
}