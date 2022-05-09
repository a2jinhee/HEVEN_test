#include <stdio.h>
#include<stdlib.h>
#include<math.h>
#define _CRT_SECURE_NO_WARNINGS

int main() {

	int N, a, b;
	int n[50][50];
	int open[50][50]; 
	int car[50][50]; int xcar, ycar;
	int goal[50][50]; int xgoal, ygoal;
	int wall[50][50];


	scanf("%d", &N);
	scanf("%d %d", &a, &b);

	for (int k = 0; k < N; k++) {
		for (int i = 0; i < a; i++) {
			for (int j = 0; j < b; j++) {
				scanf("%d", &n[a][b]);

				switch (n[a][b]) {
				case 0: open[a][b] = 1; break;
				case 1: car[a][b] = 1;
					xcar = a, ycar = b; break;
				case 2: goal[50][50] = 1;
					xgoal = a, ygoal = b; break;
				case 3:wall[50][50] = 1; break;

				}
			}
		}
		printf("\n");
	}
	

	return 0;

}


