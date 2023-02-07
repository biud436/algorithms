#include <iostream>

int main(int argc, const char * argv[])
{
    int N;
    std::cin >> N;
    
    int sum = 0;
    int target = N;
    
    int c = 0;
    int result = 0;
    
    for(int i = 0; i < N; i++)
    {
        c = i;
        sum = 0;
        
        while(c != 0) {
            sum += c % 10;
            c = c / 10;
        }
        
        sum += i;
        
        if(sum == target)
        {
            result = i;
            break;
        }
    }
    
    std::cout << result << std::endl;
    
    return 0;
}

