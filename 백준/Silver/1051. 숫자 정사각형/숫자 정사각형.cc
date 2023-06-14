#include <iostream>

int main(int argc, char** argv) {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int N, M;

    std::cin >> N >> M;

    int** arr = new int*[N];
    for (int i = 0; i < N; ++i) {
        arr[i] = new int[M];
    }

    for (int i = 0; i < N; ++i) {
        std::string str;
        std::cin >> str;
        for (int j = 0; j < M; ++j) {
            arr[i][j] = str[j] - '0';
        }
    }

    int max = 0;

    // 주어진 2차원 배열에서 만들 수 있는 가장 큰 정사각형의 한 변의 길이를 제한하는 값
    int min = N < M ? N : M;

    int topLeft, topRight, bottomLeft, bottomRight;

    for (int i = 0; i < N; ++i) { // 행 (i는 0 ~ N-1)
        for (int j = 0; j < M - 1; ++j) { // 열 (j는 0 ~ M-2)

            // k 변수는 정사각형의 한 변의 길이를 나타낸다.
            for (int k = 1; k < min; ++k) {

                // 배열의 범위 (정사각형의 크기)를 벗어나는 것을 방지한다.
                if (i + k >= N || j + k >= M) {
                    break;
                }

                topLeft = arr[i][j];
                topRight = arr[i][j + k];
                bottomLeft = arr[i + k][j];
                bottomRight = arr[i + k][j + k];

                // 정사각형인지 체크한다.
                if (topLeft == topRight && 
                    topLeft == bottomLeft && 
                    topLeft == bottomRight) {

                    // 정사각형이 형성되었으므로 최대 크기 갱신
                    if (max < k) {
                        max = k;
                    }
                }
            }
        }
    }

    std::cout << (max + 1) * (max + 1) << "\n";
    
}