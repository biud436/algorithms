#include <iostream>

int main(int argc, char** argv)
{
	int n, r = 2, i = 0;
	std::cin >> n;
	
	if(n == 0) {
		std::cout << 0 << std::endl;
		return 0;
	}
	if(n == 1) {
		std::cout << 1 << std::endl;
		return 0;
	}
			
	for(;;)
	{
		r += 6 * i;
		i++;
		
		if(r > n) {
			break;
		}
		
	}
	
	std::cout << i << std::endl;
	
	return 0;
}