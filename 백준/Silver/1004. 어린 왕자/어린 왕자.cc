#include <iostream>
#include <cmath>

struct Point 
{
    int x;
    int y;
};

struct Planet 
{
    Point position;
    int r;
};

int getCountIsEnterOrExit(
        const Point& start, 
        const Point& end, 
        const Planet& planet) 
{
    Point center = planet.position;

    // 출발 지점과 행성계와의 거리가 행성계 내부(지름)에 포함되는지 여부
    bool startInside = (pow(start.x - center.x, 2) + pow(start.y - center.y, 2)) < pow(planet.r, 2);

    // 도착 지점과 행성계와의 거리가 행성계 내부(지름)에 포함되는지 여부
    bool endInside = (pow(end.x - center.x, 2) + pow(end.y - center.y, 2)) < pow(planet.r, 2);

    // 진입 혹은 이탈이 발생하는 경우
    if ((startInside && !endInside) || (!startInside && endInside)) {
        return 1;
    }

    // 출발 지점에 행성계가 포함되어있으면, 이탈 횟수가 추가된다.
    // 도착 지점에 행성계가 포함되면, 진입 횟수가 추가된다.
    // 둘다 포함되면 진입/이탈 횟수가 0이다.

    return 0;
}

int main() 
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int T;
    int n = 0;
    int count = 0;
    std::cin >> T;

    for (int t = 0; t < T; ++t) 
    {
        // 출발점 좌표, 도착점 좌표
        Point start, end;
        std::cin >> start.x >> start.y >> end.x >> end.y;

        // 행성계의 갯수
        std::cin >> n;

        count = 0;
        for (int i = 0; i < n; ++i) 
        {
            Planet planet;
            std::cin >> planet.position.x >> planet.position.y >> planet.r;
            count += getCountIsEnterOrExit(start, end, planet);
        }

        std::cout << count << "\n";
    }

    return 0;
}