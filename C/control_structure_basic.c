#include <stdio.h> 
int main(void)
{
   	int 	na=5, 	nb=3, 	nx;
	float 	da=4.0, db=3.2, dx;

	nx = db;
	printf("%d\n", nx);	// 1

	nx = db/da;
	printf("%d\n", nx);	// 2

	dx = na/nb;
	printf("%.1f\n", dx);   // 3

	dx = (double)nb/na;
	printf("%.1f\n", dx);   // 4

	dx = (int)db/na;
	printf("%.1f\n", dx);   // 5

	return 0;
}