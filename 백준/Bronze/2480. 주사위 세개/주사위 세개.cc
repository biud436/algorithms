#include <iostream>
#include <vector>

int main(int argc, const char * argv[]) {
    
    int a, b, c, result, max = 0;
    
    std::cin >> a >> b >> c;
    
    if(a == b && b == c)
    {
        result = 10000 + (a * 1000);
    } else if(a == b || a == c) {
        result = 1000 + (a * 100);
    } else if(b == c)
    {
        result = 1000 + (b * 100);
    } else {
        if(a > b) {
            max = a;
        }
        if(b > max) {
            max = b;
        }
        if(c > max) {
            max = c;
        }
        
        result = max * 100;
    }
    
    std::cout << result << std::endl;
}