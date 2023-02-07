#include <iostream>

int main(int argc, char** argv)
{
	int n;
	double max;
	double input[1000], output[1000], ret = {0.0,};
	
	max = -1000.0;
	
	std::cin >> n;
	
	for(int i = 0; i < n; i++) {
		std::cin >> input[i];
		
		if(input[i] > max) {
			max = input[i];
		}
	}
	
	for(int i = 0; i < n; i++) 
	{
		output[i] = ((1.0 * input[i]) / max) * 100.0;
		ret += output[i];
	}
	
	ret = (1.0 * ret) / (1.0 * n);
	std::cout.precision(11);
	std::cout << std::fixed << ret << std::endl;

	return 0;
}