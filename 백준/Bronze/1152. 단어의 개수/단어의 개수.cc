#include <iostream>
#include <string>
#include <cctype>

int main(int argc, char** argv)
{	
	std::string raw;
	int count = 0;
	bool found = false;
	
	std::getline(std::cin, raw);
		
    raw.erase(0, raw.find_first_not_of(' '));
    raw.erase(raw.find_last_not_of(' ') + 1);

	for(size_t i = 0; i < raw.length(); i++)
	{
		if(isspace(raw[i])) 
		{
			count++;
			found = true;
		}
	}
	
	if(raw.length() == 0) {
		std::cout << 0 << std::endl;
	} else {
		count = found ? (count + 1) : 1;
		std::cout << count << std::endl;		
	}	

	return 0;
}