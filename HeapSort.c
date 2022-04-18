#include <stdio.h>
#include <time.h>
#define MAX_COUNT 10000


void heap(int* arr, int n) {			//힙 상태 만들기 
	for (int i = 1; i < n; ++i) {
		int child = i;
		while (child !=0) {					//최상단까지 점검

			int root = (child - 1) / 2;
			if (arr[root] < arr[child]) {
				int tmp = arr[root];
				arr[root] = arr[child];
				arr[child] = tmp;			//자식 노드가 부모보다 크면 교환
			}
			child = root;
		}
	}
}

int main() {
	clock_t start_H = clock();				//시간 측정 시작

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

	heap(data, MAX_COUNT);						//힙정렬 동작 및 시간 재기

	for (int i = MAX_COUNT - 1; i >=0 ; i--) {	
		int temp = data[i];
		data[i] = data[0];
		data[0] = temp;				//최상단 노드와 최하단 노드 교체

		heap(data, i);				//가장 큰 원소 제외하고 다시 힙 만듬

	}				
	clock_t end_H = clock();		//시간 측정 종료

	for (i = 0; i < MAX_COUNT; i++) {		// 출력 결과
		printf("%d, ", data[i]);
	}

	printf("\n");

	printf("Heap Sort 실행 시간: %lf\n", (double)(end_H - start_H) / CLOCKS_PER_SEC);

	return 0;
}