#include <stdio.h>

void twochar(char A[]) {
	for (int i=1; A[i]; i++) {
		if (A[i-1] != A[i]) {
			printf("Yes");
			return;
		}
	}
	printf("No");
}

int main() {
    char A[100];

	scanf("%s", A);

	twochar(A);

    return 0;
}