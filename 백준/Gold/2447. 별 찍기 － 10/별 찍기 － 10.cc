#include <iostream>

typedef struct _state {
	int width;
} State;

State state;

void init_star(char* star, int n)
{
	for(int x = 0; x < n; x++)
	{
		for(int y = 0; y < n; y++)
		{
			star[y * n + x] = ' ';
		}
	}
}

void draw_star(int x, int y, int size, char* star)
{
	int n = size / 3;
	
	if(size == 1)
	{
		star[y * state.width + x] = '*';
		return;
	}
	
	for(int i = 0; i < 3; ++i)
	{
		for(int j = 0; j < 3; ++j)
		{
			if(i == 1 && j == 1)
			{
				continue;
			}
			draw_star(x + (i * n), y + (j * n), n, star);
		}
		
	}

}

int main(int argc, char** argv)
{
	int n;
	std::cin >> n;
	
	char* star = new char[n * n];
	state.width = n;

	init_star(star, n);
	
	draw_star(0, 0, n, star);
	
	for(int x = 0; x < n; x++)
	{
		for(int y = 0; y < n; y++)
		{
			std::cout << star[y * n + x];
		}
		std::cout << std::endl;
	}	
	
	delete star;

	return 0;
}