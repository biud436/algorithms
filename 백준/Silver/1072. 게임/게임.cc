#include <iostream>
#include <string>

int main(int argc, char** argv)
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    long long X, Y, Z;
    std::cin >> X >> Y;

    Z = (Y * 100) / X; // 88%

    if (Z >= 99) {
        std::cout << -1 << std::endl;
        return 0;
    }

    long long left = 0, right = 1000000000;
    long long mid = 0, newZ = 0;

    while (left <= right) {
        mid = (left + right) / 2;
        newZ = (Y + mid) * 100 / (X + mid);

        if(newZ > Z) {
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }

    std::cout << left << std::endl;

    return 0;
}