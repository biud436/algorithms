#include <iostream>
#include <unordered_map>

int main()
{
    int N;

    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::cin >> N;

    while (N--)
    {
        int T;
        std::cin >> T;

        std::unordered_map<long long, int> count;

        long long majorityNum = 0;
        int majorityCount = 0;

        for (int i = 0; i < T; ++i)
        {
            long long num;
            std::cin >> num;

            ++count[num];

            if (count[num] > majorityCount)
            {
                majorityCount = count[num];
                majorityNum = num;
            }
        }

        if (majorityCount > T / 2)
        {
            std::cout << majorityNum << '\n';
        }
        else
        {
            std::cout << "SYJKGW" << '\n';
        }
    }

    return 0;
}