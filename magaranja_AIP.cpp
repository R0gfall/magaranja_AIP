#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
#define N 24


	int cheak(char* x, char y)
	{
		for (char i = 0; i < 81; i++) {
			if (x[i] == y) {
				return 1;
			}
		}
		return 0;
	}

int flag = 1;


int func(int desk[N][N], int n, int x, int y)
{
	if (desk[x][y] == 1) {
		return 0;
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if ((i == x) || (j == y)) {
				if (desk[i][j] == 1) {
					return 0;
				}
			}
			else if ((i - j) == (x - y)) {
				if (desk[i][j] == 1) {
					return 0;
				}
			}
			else if ((i + j) == (x + y)) {
				if (desk[i][j] == 1) {
					return 0;
				}
			}
			else if ((abs(x - i) == 2 && abs(y - j) == 1) || (abs(x - i) == 1 && abs(y - j) == 2)) {
				if (desk[i][j] == 1) {
					return 0;
				}
			}
		}
	}
	return 1;

}
void putdesk(int desk[N][N], int n, int l, int x, int y)
{
	int j;
	for (int i = x; i < n; ++i) {
		if (i == x) {
			j = y;
		}
		else {
			j = 0;
		}
		for (j; j < n; j++) {
			if (func(desk, n, i, j) == 1) {
				desk[i][j] = 1;
				l--;
				if (l > 0) {
					putdesk(desk, n, l, i, j);
				}
				else {
					flag = 0;
					FILE* out = fopen("output.txt", "a");
					for (int m = 0; m < n; m++) {
						for (int z = 0; z < n; z++) {
							if (desk[m][z] == 1) {
								fprintf(out, "(%d,%d) ", m, z);
							}
						}
					}
					fprintf(out, "\n");

				}
				desk[i][j] = 0;
				l++;
			}
		}

	}
}

int main()
{
	int tik = 1, n, l, k, i, j, y, x;
	int desk[N][N];

	FILE* fin = fopen("input.txt", "r");

	for (i = 0; i < N; i++)
		for (j = 0; j < N; j++)
			desk[i][j] = 0;
	fscanf(fin, "%d %d %d", &n, &l, &k);
	for (i = 0; i < k; i++) {
		fscanf(fin, "%d %d", &x, &y);
		desk[x][y] = 1;
	}
	fclose(fin);
	putdesk(desk, n, l, 0, 0);
	if (flag) {
		FILE* out = fopen("output.txt", "a");
		fprintf(out, "no solutions");
		fclose(out);
	}
	fclose(fin);

}
