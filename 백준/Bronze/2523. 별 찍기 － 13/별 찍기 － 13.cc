#include <iostream>

void pack(int div, int i)
{
	for(int j = 0; j < div - i; j++) 
	{
		std::cout << "*";
	}
	std::cout << std::endl;	
}

int main(int argc, char** argv)
{
	int n;
	std::cin >> n;
	
	int max = (2 * n) - 1;
	int div = (2 * n) / 2;
		
	for(int i = div - 1; i >= 0; i--)
	{	
		pack(div, i);
	}	
	
	for(int i = 1; i < div; i++)
	{	
		pack(div, i);
	}	
	
	return 0;
}