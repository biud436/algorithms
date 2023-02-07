#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

int main(int argc, const char * argv[])
{
    int n, m, r;
    std::cin >> n >> m;
    
    std::vector<int> items;
    std::vector<int> numbers;
    
    for(int i = 0; i < n; i++)
    {
        std::cin >> r;
        items.push_back(r);
    }
    
    int condition = n * (n - 1) * (n - 2);
    int a,b,c;

    const int MAX = n - 1;
    const int MIN = 0;
    
    int result = 0;
    int result_max = 0;
    
    for(int i = 0; i < n; i++)
    {
        for(int j = i + 1; j < n; j++) {
            for(int k = j + 1; k < n; k++) {
                result = items[i] + items[j] + items[k];
                
                if(result <= m && result > result_max) {
                    result_max = result;
                }
            }
        }
    }
    
    std::cout << result_max << std::endl;
    
    return 0;
}

