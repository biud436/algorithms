#include <cstdio>

int fib[42] = {0, 1, };

int init_fibonacci(int n) {
    if (n == 0) {
        return 0;
    } else if (n == 1) {
        return 1;
    } else if (fib[n] != 0) {
        return fib[n];
    } else {
        fib[n] = init_fibonacci(n-1) + init_fibonacci(n-2);
        return fib[n];
    }
}


int main(int argc, char** argv)
{
    // 테스트 케이스의 개수 T
    int T;
    scanf("%d", &T);

    // N = 0 이면 1 0
    // N = 1 이면 0 1
    // N = 2 이면 1 1
    // N = 3 이면 1 2
    // N = 4 이면 2 3
    // N = 5 이면 3 5 
    // N = 6 이면 5 8

    for (int i = 0; i < T; ++i) 
    {
        int N;
        scanf("%d", &N);

        if (N == 0) {
            printf("1 0\n");
        } else if (N == 1) {
            printf("0 1\n");
        } else {
            init_fibonacci(N);
            printf("%d %d\n", fib[N-1], fib[N]);
        }
    }

    return 0;
}