#include <iostream>
#include <sstream>
#include <deque>
#include <vector>

int main(int argc, char** argv)
{
    int N, M;

    std::cin >> N >> M;

    std::deque<int> dq;
    std::vector<int> target(M);

    for (int i = 1; i <= N; ++i)
    {
        dq.push_back(i);
    }

    for (int i = 0; i < M; ++i)
    {
        std::cin >> target[i];
    }

    int leftShiftCount = 0;
    int rightShiftCount = 0;

    for (int i = 0; i < M; ++i)
    {
        int targetIndex = 0;

        for (int j = 0; j < dq.size(); ++j)
        {
            if (dq[j] == target[i])
            {
                targetIndex = j;
                break;
            }
        }

        if (targetIndex <= dq.size() / 2)
        {
            while (dq.front() != target[i])
            {
                int frontElement = dq.front();
                dq.pop_front();
                dq.push_back(frontElement);
                ++leftShiftCount;
            }
        }
        else
        {
            while (dq.front() != target[i])
            {
                int backElement = dq.back();
                dq.pop_back();
                dq.push_front(backElement);
                ++rightShiftCount;
            }
        }

        dq.pop_front();
    }

    std::cout << leftShiftCount + rightShiftCount << '\n';

    return 0;
}
