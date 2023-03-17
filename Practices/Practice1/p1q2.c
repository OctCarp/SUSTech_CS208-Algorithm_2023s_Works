#include <stdio.h>

int calc(int n);

int main() {
    int N;
    scanf("%d",&N);

    printf("Total ways number is %d", calc(N));

    return 0;
}

int calc(int n) {
    if (n <= 2) return n;
    return calc(n - 1) + calc(n - 2);
}
