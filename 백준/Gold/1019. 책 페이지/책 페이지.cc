#include <iostream>
#include <string>
#include <map>

// https://www.slideshare.net/Baekjoon/baekjoon-online-judge-1019?qid=9aa7818e-779e-499a-9c13-d2a5ac2ef8af&v=&b=&from_search=1
std::map<int, int> countDigits(int n) {
    std::map<int, int> digitCount;

    int start = 1; // 페이지 번호 범위의 시작
    int end = n; // 페이지 번호 범위의 끝

    int pow = 1; // 자릿수 (1, 10, 100, 1000, ...)

    while (start <= end) {
        // A는 일의 자리가 0이 되어야 한다.
        while (start % 10 != 0 && start <= end) {
            std::string page = std::to_string(start);
            for (char digit : page) {
                int num = digit - '0';
                digitCount[num] += pow;
            }
            start++;
        }

        if (start > end) {
            break;
        }

        // B는 일의 자리가 9가 되어야 한다.
        while (end % 10 != 9 && start <= end) {
            std::string page = std::to_string(end);
            for (char digit : page) {
                int num = digit - '0';
                digitCount[num] += pow;
            }
            end--;
        }

        // A = 50
        // B = 69
        // 6 - 5 + 1 = 2줄
        // 50 51 52 53 54 55 56 57 58 59
        // 60 61 62 63 64 65 66 67 68 69
        int cnt = end / 10 - start / 10 + 1;
        for (int i = 0; i < 10; ++i) {
            digitCount[i] += cnt * pow;
        }

        start /= 10;
        end /= 10;
        pow *= 10;
    }

    return digitCount;
}

int main(int argc, char** argv)
{
    int N;
    std::cin >> N;

    std::map<int, int> digitCount = countDigits(N);

    for (int i = 0; i < 10; ++i) {
        std::cout << digitCount[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}