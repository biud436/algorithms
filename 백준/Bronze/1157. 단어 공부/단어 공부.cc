#include <iostream>
#include <string>
#include <vector>

int main(int argc, char** argv)
{	
	std::string raw;
	size_t i; 
	int max = 0;
	std::string last_char = "";
	std::vector<bool> flag;
	
	int data[256] = {0,};
	
	std::cin >> raw;
	
	if(raw.size() > 1000000)
	{
		raw.resize(1000000);
	}
	
	for(i = 0; i < raw.length(); i++)
	{
		for(int j = 'A'; j <= 'Z'; j++)
		{		
			if(raw[i] == j)
				data[raw[i]]++;
		}
		for(int j  = 'a'; j <= 'z'; j++)
		{
			if(raw[i] == j)			
				data[raw[i]-0x20]++;
		}		
	}

	for(i = 'A'; i <= 'Z'; i++)
	{
		if(data[i] >= max)
		{
			max = data[i];
			last_char = static_cast<char>(i);	
		}
	}
	
	for(i = 0; i < 256; i++)
	{
		if(data[i] >= max) {
			flag.push_back(data[i]);
		}
	}
	
	if(flag.size() >= 2)
	{
		std::cout << "?" << std::endl;
	}
	else
	{
		std::cout << last_char << std::endl;	
	}
		
	return 0;
}