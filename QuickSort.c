#include <stdio.h>
#include <time.h>
#define MAX_COUNT 10000

void QSort(int* arr, int L, int R) {
	if (L >= R) {		//그대로 두기
		return;
	}

	int pivot = L;
	int i = L + 1;		//L 출발
	int j = R;			//R 출발
	int temp;

	while (i <= j) {    // L이 R보다 오른쪽에 있을 때까지 반복
		while (i <= R && arr[i] <= arr[pivot])    // L이 pivot보다 큰 값 or pivot을 만날 때까지 
			i++;
		while (j > L && arr[j] > arr[pivot])    // R이 pivot보다 작은 값 or pivot을 만날 때까지 
			j--;
		if (i <= j) {   // L이 R보다 왼쪽에 있다면 교환
			temp = arr[i];
			arr[i] = arr[j];
			arr[j] = temp;
		}
		else {			//피봇 정렬
			temp = arr[j];
			arr[j] = arr[pivot];
			arr[pivot] = temp;
		}
	}

	QSort(arr, L, j - 1);	// 피봇 왼쪽 분할
	QSort(arr, j + 1, R);	// 피봇 오른쪽 분할
}

int main() {
	clock_t start_Q = clock();				//시간 측정 시작

	int i, j, data[MAX_COUNT];

	srand(time(NULL));						//시간에서 랜덤 값 추출

	for (i = 0; i < MAX_COUNT; i++) {
		data[i] = rand() % MAX_COUNT + 1;	//배열 수로 나누고 1 더하면 배열 사이즈 내에 있는 값
		for (j = 0; j < i; j++) {
			if (data[i] == data[j]) {
				i--;
				break;
			}
		}
	}

	for (i = 0; i < MAX_COUNT; i++) {		//정렬 전 데이터 출력
		printf("%d, ", data[i]);
	}

	printf("\n");

	QSort(data, 0, MAX_COUNT - 1);			//Quick Sort 동작 및 시간 재기

	clock_t end_Q = clock();				//시간 측정 종료

	for (i = 0; i < MAX_COUNT; i++) {		// 출력 결과
		printf("%d, ", data[i]);
	}

	printf("\n");

	printf("Quick Sort 실행 시간: %lf\n", (double)(end_Q - start_Q) / CLOCKS_PER_SEC);

	return 0;
}
