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
	clock_t start_Ex = clock();				//시간 측정 시작

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

	ExSort(data, MAX_COUNT);				//Exchange Sort 동작 

	clock_t end_Ex = clock();				//시간 측정 종료

	for (i = 0; i < MAX_COUNT; i++) {		// 출력 결과
		printf("%d, ", data[i]);
	}

	printf("\n");

	printf("Exchange Sort 실행 시간: %lf\n", (double)(end_Ex - start_Ex) / CLOCKS_PER_SEC);

	return 0;
}



