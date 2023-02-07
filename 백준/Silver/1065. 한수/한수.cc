#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

// 123 246 369 789
bool is_han(int exp)
{
	std::string expression = std::to_string(exp);
	int len = expression.length();
	std::vector<int> data;
	std::vector<int> acc;
	int sum = 0;
	bool ret = false;
	
	if(len == 0) 
		return false;	
	
	if(len <= 2)
		return true;
	
	for(int i = 0; i < len; i++)
	{
		data.push_back(expression[i] - '0');
	}
	
	// std::cout << exp <<  " : ";
	for(int i = 0; i < len - 1; i++)
	{
		acc.push_back(data[i+1] - data[i]);
		// std::cout << acc[i] << " ";
	}
	
	// std::cout << std::endl;
			
	if(std::equal(acc.begin() + 1, acc.end(), acc.begin()))
		return true;
		
	return false;
	
}

int main(int argc, char** argv)
{
	int n, sum = 0;
	std::cin >> n;
	
	for(int i = 1; i <= n; i++)
	{
		if(is_han(i)) {
			sum++;
		}
	}
	
	std::cout << sum << std::endl;
	
	return 0;
}