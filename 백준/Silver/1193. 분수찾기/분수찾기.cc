#include <iostream>
#include <string>

void print(int n)
{
	int e = 1;

	for(int i = 1; i <= n; i++)
	{
		for(int j = 0; j < i; j++)
		{
			if(n != e++) 
				continue;

			if(i % 2 == 0)
			{
				std::cout << j+1 << "/" << i-j << std::endl;
			}
			else
			{
				std::cout << i-j << "/" << j+1 << std::endl;
			}

			return;
		}
	}
}

int main(int argc, char** argv)
{
	int n;
	std::cin >> n;
	print(n);
	return 0;
}