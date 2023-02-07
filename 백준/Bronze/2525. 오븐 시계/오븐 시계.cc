#include <iostream>

int main(int argc, const char * argv[]) {
    int h = 0, m = 0;
    int a = 0;
    int result_minutes = 0;
    
    std::cin >> h >> m;
    std::cin >> a;
    
    result_minutes = m + a;
    
    while(result_minutes >= 60)
    {
        result_minutes -= 60;
        h += 1;
    }
    
    if(h >= 24) {
        h -= 24;
    }
    
    std::cout << h << " " << result_minutes << std::endl;
    
    return 0;
}

