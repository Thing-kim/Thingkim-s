#include <stdio.h>

#define TRUE 1
#define FALSE 0

#define INF  100000000	//직접 연결되어 있지 않는 노드의 값은 무한으로 처리


int arr[6][6] = {		// 인접 행렬
	{0, 5, INF, 2, 4, INF},
	{5, 0, 3, 3, INF, INF},
	{INF, 3, 0, 3, 4, 2},
	{2, 3, 3, 0, 1, INF},
	{4, INF, INF, 1, 0, 2},
	{INF, INF, 2 ,INF, 2, 0}
};

int dist[6], found[6], path[6][6], check[6];


void path_init(int path[][6]) {			//path 인접행렬 초기화 함수

	int i, j;

	for (i = 0; i < 6; i++)
		for (j = 0; j < 6; j++)
			path[i][j] = INF;
}



int choose(int dist[], int n, int found[]) {	//최단거리에 있는 정점을 찾는다

	int i, min, minpos;
	min = 2147483647;
	minpos = -1;

	for (i = 0; i < n; i++)
		if (dist[i] < min && !found[i]) {
			min = dist[i];
			minpos = i;
		}
	return minpos;
}



void shortest_path(int start, int n) {		//최단 경로
	int i, j, u, w;
	for (i = 0; i < n; i++) {//초기화
		dist[i] = arr[start][i];
		found[i] = FALSE;
		check[i] = TRUE;
		path[i][0] = start;
	}

	found[start] = TRUE;											//시작 정점 방문 표시
	dist[start] = 0;

	for (i = 0; i < n - 2; i++) {
		u = choose(dist, n, found);
		found[u] = TRUE;
		for (w = 0; w < n; w++) {
			if (!found[w]) {
				if (dist[u] + arr[u][w] < dist[w]) {
					if (i == 0) {									//처음에는 인접한 정점에 연결
						path[w][check[w]] = u;						//갱신된 경로를 경로 배열에 저장
						check[w]++;
					}
					else {
						for (j = 0; j < (check[u] + 1); j++) {		//저장된 만큼 반복
							path[w][j] = path[u][j];				//경로를 갱신
							path[w][j + 1] = u;						//끝부분에 자기자신을 저장
							check[w]++;
						}
					}
					dist[w] = dist[u] + arr[u][w];
				}
			}
		}
	}
}


void main() {
	int i, j, start;

	path_init(path);
	printf("시작 정점: ");
	scanf_s("%d", &start);
	printf("\n");
	shortest_path(start, 6);

	for (i = 0; i < 6; i++) {					//저장된 경로들 출력
		printf("%d에서 %d까지의 최단거리 : %d \n", start, i, dist[i]);
		printf("%d에서 %d까지의 노드 : ", start, i);
		for (j = 0; j < 6; j++) {
			if (path[i][j] != INF) {
				printf("%d->", path[i][j]);		//저장된 경로를 출력
			}
		}
		printf("%d\n", i);
	}
}
