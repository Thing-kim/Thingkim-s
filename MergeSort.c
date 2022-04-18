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
	while (i <= mid && j <= right) {		// 합병
		if (arr[i] <= arr[j])
			merge_tmp[k++] = arr[i++];
		else
			merge_tmp[k++] = arr[j++];
	}

	if (i > mid) {							//남아 있는 값 처리
		for (l = j; l <= right; l++)
			merge_tmp[k++] = arr[l];
	}

	else {
		for (l = i; l <= mid; l++)
			merge_tmp[k++] = arr[l];
	}

	for (l = left; l <= right; l++) {		//임시 배열에 있는 값을 리스트로 재복사
		arr[l] = merge_tmp[l];
	}
}

void MergeSort(int arr[], int left, int right) {
	if (left == right) return;				//원소 하나씩 남을 때 왼쪽 오른쪽 개수 같으니 분할 완료 후 리턴

	int mid = (left + right) / 2;			//중간 지점 계산
	MergeSort(arr, left, mid);				//중간 값 아래부분 정렬
	MergeSort(arr, mid + 1, right);			//중간 값 윗부분 정렬
	merge(arr, left, mid, right);			//합병
}

int main() {
	clock_t start_Mg = clock();				//시간 측정 시작

	int i, j, data[MAX_COUNT];

	srand(time(NULL));

	for (i = 0; i < MAX_COUNT; i++) {
		data[i] = rand() % MAX_COUNT + 1;	 //배열 수로 나누고 1 더하면 
		for (j = 0; j < i; j++) {
			if (data[i] == data[j]) {
				i--;
				break;
			}
		}
	}

	for (i = 0; i < MAX_COUNT; i++) {		//정렬 전 데이터
		printf("%d, ", data[i]);
	}

	printf("\n");

	MergeSort(data, 0, MAX_COUNT - 1);		//Merge Sort 동작 및 시간 재기

	clock_t end_Mg = clock();				//시간 측정 종료

	for (i = 0; i < MAX_COUNT; i++) {		// 출력 결과
		printf("%d, ", data[i]);
	}

	printf("\n");


	printf("Merge Sort 실행 시간: %lf\n", (double)(end_Mg - start_Mg) / CLOCKS_PER_SEC);

	return 0;
}