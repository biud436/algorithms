#include <iostream>

int main(int argc, char** argv)
{
	int n[3], temp;
	
	std::cin >> n[0] >> n[1] >> n[2];
	
	for(int i = 0; i < 3; i++) 
	{		
		for(int j = i; j < 3 - i; j++) {
			if(n[i] > n[j + 1]) {
				temp = n[i];
				n[i] = n[j+1];
				n[j+1] = temp;
			}
		}
	}
	
	std::cout << n[1] << std::endl;;
	
	return 0;
}