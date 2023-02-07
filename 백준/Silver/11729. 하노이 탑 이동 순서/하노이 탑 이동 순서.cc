#include <iostream>
#include <vector>
#include <sstream>

void move(int n, int from, int by, int to, int* count, std::stringstream& buffer)
{
	(*count)++;
	
	if(n <= 1)
	{
		buffer << from << " " << to << std::endl;
	}
	else
	{
		move(n-1, from, to, by, count, buffer);
		buffer << from << " " << to << std::endl;
		move(n-1, by, from, to, count, buffer);
	}
}

int main(int argc, char** argv)
{
	int n, count = 0;
	std::cin >> n;
	
	std::stringstream ret;
	
	move(n, 1, 2, 3, &count, ret);
	std::cout << count << std::endl;
	std::cout << ret.str();
	
	return 0;
}