#include <stdio.h>

#define TRUE 1
#define FALSE 0

#define INF  100000000	//���� ����Ǿ� ���� �ʴ� ����� ���� �������� ó��


int arr[6][6] = {		// ���� ���
	{0, 5, INF, 2, 4, INF},
	{5, 0, 3, 3, INF, INF},
	{INF, 3, 0, 3, 4, 2},
	{2, 3, 3, 0, 1, INF},
	{4, INF, INF, 1, 0, 2},
	{INF, INF, 2 ,INF, 2, 0}
};

int dist[6], found[6], path[6][6], check[6];


void path_init(int path[][6]) {			//path ������� �ʱ�ȭ �Լ�

	int i, j;

	for (i = 0; i < 6; i++)
		for (j = 0; j < 6; j++)
			path[i][j] = INF;
}



int choose(int dist[], int n, int found[]) {	//�ִܰŸ��� �ִ� ������ ã�´�

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



void shortest_path(int start, int n) {		//�ִ� ���
	int i, j, u, w;
	for (i = 0; i < n; i++) {//�ʱ�ȭ
		dist[i] = arr[start][i];
		found[i] = FALSE;
		check[i] = TRUE;
		path[i][0] = start;
	}

	found[start] = TRUE;											//���� ���� �湮 ǥ��
	dist[start] = 0;

	for (i = 0; i < n - 2; i++) {
		u = choose(dist, n, found);
		found[u] = TRUE;
		for (w = 0; w < n; w++) {
			if (!found[w]) {
				if (dist[u] + arr[u][w] < dist[w]) {
					if (i == 0) {									//ó������ ������ ������ ����
						path[w][check[w]] = u;						//���ŵ� ��θ� ��� �迭�� ����
						check[w]++;
					}
					else {
						for (j = 0; j < (check[u] + 1); j++) {		//����� ��ŭ �ݺ�
							path[w][j] = path[u][j];				//��θ� ����
							path[w][j + 1] = u;						//���κп� �ڱ��ڽ��� ����
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
	printf("���� ����: ");
	scanf_s("%d", &start);
	printf("\n");
	shortest_path(start, 6);

	for (i = 0; i < 6; i++) {					//����� ��ε� ���
		printf("%d���� %d������ �ִܰŸ� : %d \n", start, i, dist[i]);
		printf("%d���� %d������ ��� : ", start, i);
		for (j = 0; j < 6; j++) {
			if (path[i][j] != INF) {
				printf("%d->", path[i][j]);		//����� ��θ� ���
			}
		}
		printf("%d\n", i);
	}
}
