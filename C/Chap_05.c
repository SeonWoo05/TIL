#include <stdio.h>
int main(void) {
    int b, e, n;
    int v;

    scanf("%d%d%d", &b, &e, &n);

    for (v=b; v<=e && !(n%v==0); v=v+1)
        ;
    if (v<=e)
        printf("found.\n");
    else
        printf("not found.\n");

    return 0;
} // v가 e보다 커지기전에 n%v가 0이 되는지