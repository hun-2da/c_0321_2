#include<stdio.h>
#include<stdlib.h>

#define MAX_NUMBER 101
typedef struct {
	float coef;
	int expon;
}polynomial;
polynomial number[MAX_NUMBER] = { {7,6},{5,3},{9,2},{1,0},{5,3},{2,2},{1,1},{10,0} };
int next_n = 8;

char compare(int a, int b) {
	if (a > b)return '>';
	else if (a == b) return '=';
	else return '<';
}
void attach(float coef, int expon) {
	if (next_n > MAX_NUMBER) {
		fprintf(stderr, "항의 개수가 너무 많으\n");
		exit(1);
	}
	number[next_n].coef = coef;
	number[next_n].expon = expon;
	next_n++;
}
void poly_add2(int As, int Ae, int Bs, int Be, int* Cs, int* Ce) {
	float tempcoef;
	*Cs = next_n;
	while (As <= Ae && Bs <= Be)
		switch (compare(number[As].expon, number[Bs].expon)) {
		case '>':
			attach(number[As].coef, number[As].expon);
			As++;	break;
		case '=':
			tempcoef = number[As].coef * number[Bs].coef;
			if (tempcoef)
				attach(tempcoef, number[As].expon);
			As++; Bs++; break;
		case '<':
			attach(number[Bs].coef, number[Bs].expon);
			Bs++;	break;
		}
	for (; As <= Ae; As++)
		attach(number[As].coef, number[As].expon);
	for (; Bs <= Be; Bs++)
		attach(number[Bs].coef, number[Bs].expon);
	*Ce = next_n - 1;
}
void print_poly(int s, int e) {
	for (int i = s; i < e; i++)
		printf("%3.1fx^%d + ", number[i].coef, number[i].expon);

	printf("%3.1fx^%d\n", number[e].coef, number[e].expon);

}
void main() {
	int As = 0, Ae = 3, Bs = 4, Be = 7, Cs, Ce;
	poly_add2(As, Ae, Bs, Be, &Cs, &Ce);
	print_poly(As, Ae);
	print_poly(Bs, Be);
	printf("-----------------------------------------\n");
	print_poly(Cs, Ce);
	return 0;
}