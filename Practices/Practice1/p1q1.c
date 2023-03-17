#include <stdio.h>

int step;

void move(int n, int from, int to, int aux);

int main() {
    step = 0;

    int N;
    scanf("%d", &N);
    move(N, 1, 3, 2);

    printf("Total steps number is %d", step);

    return 0;
}

void move(int n, int from, int to, int aux) {
    if (n == 1) {
        printf("Move disk 1 from rod %d to rod %d\n", from, to);
        ++step;
        return;
    }

    move(n - 1, from, aux, to);

    printf("Move disk %d from rod %d to rod %d\n", n, from, to);
    ++step;

    move(n - 1, from, to, aux);
}