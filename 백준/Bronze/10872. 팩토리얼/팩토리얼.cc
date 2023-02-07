#include <stdio.h>

int factor(int val)
{
	if(val == 0)
	{
		return 1;
	} 
	else 
	{
		return val * factor(val - 1);
	}
}

int main(void)
{
	int a;
	scanf("%d", &a);

	printf("%d", factor(a));
	
	return 0;
}