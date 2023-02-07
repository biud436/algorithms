#include <iostream>

int extract_digit1(int value)
{
	return value % 10;
}

int extract_digit10(int value)
{
	return value % 100 / 10;
}

int main(int argc, char** argv)
{
	int n, count;
	int a, b, c;
	int seed = 0;
	
	std::cin >> n;
	
	count = 0;
	
	seed = n;

	while(true) {
		
		a = extract_digit10(seed);
		b = extract_digit1(seed);
		c = extract_digit1(a + b);
		
		seed = (b * 10) + c;
		
		count++;
		
		if(seed == n)
			break;
				
	}
	
	std::cout << count << std::endl;
	
	return 0;
}