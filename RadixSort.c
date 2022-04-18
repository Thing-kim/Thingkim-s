#define _CRT_SECURE_NO_WARNINGS				//예외처리
#include <stdio.h>
#include <time.h>
#define MAX_COUNT 10000

void RadixSort(int arr[], int n) {
	int result[MAX_COUNT], maxValue = 0;
	int exp = 1;
	for (int i = 0; i < n; i++) {
		if (arr[i] > maxValue) maxValue = arr[i];
	}
	while (maxValue / exp > 0) {			// 자릿수 계산
		int bucket[10] = { 0 };
		for (int i = 0; i < n; i++) {		// 자릿수 배열 처리
			bucket[arr[i] / exp % 10]++;
		}									
		for (int i = 1; i < 10; i++) {		// 누적 계산 : 결과 배열을 만들기 위해 누적으로 계싼
			bucket[i] += bucket[i - 1];			
		}
		for (int i = n - 1; i >= 0; i--) {	//같은 자릿수 끼리는 순서 유지
			result[--bucket[arr[i] / exp % 10]] = arr[i];
		}
		for (int i = 0; i < n; i++) {
			arr[i] = result[i];
		}									// 기본 배열 갱신
		exp *= 10;
	}
}

int main() {
	clock_t start_Rd = clock();				//시간 측정 시작

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

	RadixSort(data, MAX_COUNT);				//Exchange Sort 동작 

	clock_t end_Rd = clock();				//시간 측정 종료

	for (i = 0; i < MAX_COUNT; i++) {		// 출력 결과
		printf("%d, ", data[i]);
	}

	printf("\n");

	printf("Radix Sort 실행 시간: %lf\n", (double)(end_Rd - start_Rd) / CLOCKS_PER_SEC);

	return 0;
}
