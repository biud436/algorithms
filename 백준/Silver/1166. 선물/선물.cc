#include <iostream>
#include <string>
#include <cstdio>

int main(int argc, char** argv)
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    double N, L, W, H;
    std::cin >> N >> L >> W >> H;

    double left = 0.0, right = 1000000000.0;
    double count = 0.0;
    double mid = 0.0;
    double result = 0.0;

    for (int i = 0; i < 10000; ++i) {
        mid = (left + right) / 2.0;
        count = (long long)(L / mid) * (long long)(W / mid) * (long long)(H / mid);

        if (count >= N) {
            result = mid;
            left = mid;
        } else {
            right = mid;
        }
    }

    printf("%.10lf\n", result);

    return 0;
}