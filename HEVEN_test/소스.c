#include <stdio.h>
#include<stdlib.h>
#include<math.h>
#define _CRT_SECURE_NO_WARNINGS

int goal[50][50]; 
int open[50][50];
int car[50][50];
int wall[50][50];

int openPath(int* n, int xcar, int ycar) {

	if (n[xcar, ycar] != 0) {
		return 0;
	}
	return 1; 
}

int findPath(int *diffPath) {
	int min = 0;
	for (int i = 0; i < 4; i++) {
		if (diffPath[i] == NULL) {
			continue;
		}
		if (diffPath[i] < diffPath[min]){
			min = i;
		}
	}
	return min;
}

int main() {
	int n[50][50];
	int diffPath[4];
	int N, a, b;
	int xgoal, ygoal;
	int xcar, ycar;
	int cost = 0;

	scanf("%d", &N);
	scanf("%d %d", &a, &b);

	for (int k = 0; k < N; k++) {
		for (int i = 0; i < a; i++) {
			for (int j = 0; j < b; j++) {
				scanf("%d", &n[i][j]);

				switch (n[i][j]) {
				case 0: open[i][j] = 1; break;
				case 1: car[i][j] = 1; xcar = i, ycar = j; break;
				case 2: goal[i][j] = 1; xgoal = i, ygoal = j; break;
				case 3: wall[i][j] = 1; break;
				}
			}
		}

		while ((xcar != xgoal) || (ycar != ygoal)) {

			if (openPath(n, xcar + 1, ycar)) {
				diffPath[0] = abs(xgoal - (xcar + 1)) + abs(ygoal - ycar);
			}
			else {
				diffPath[0] = NULL; 
			}
			if (openPath(n, xcar - 1, ycar)) {
				diffPath[1] = abs(xgoal - (xcar - 1)) + abs(ygoal - ycar);
			}
			else {
				diffPath[1] = NULL;
			}
			if (openPath(n, xcar, ycar + 1)) {
				diffPath[2] = abs(xgoal - xcar) + abs(ygoal - (ycar + 1));
			}
			else {
				diffPath[2] = NULL;
			}
			if (openPath(n, xcar, ycar - 1)) {
				diffPath[3] = abs(xgoal - xcar) + abs(ygoal - (ycar - 1));
			}
			else {
				diffPath[3] = NULL;
			}

			switch (findPath(diffPath)) {
			case 0: xcar = xcar + 1; break;
			case 1: xcar = xcar - 1; break;
			case 2: ycar = ycar + 1; break;
			case 3: ycar = ycar - 1; break;
			}

			cost++;
		}

		printf("%d", cost);
		printf("\n");

	}
	
	return 0;

}


