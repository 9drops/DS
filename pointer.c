#include <stdio.h>

int func1(int a)
{
	printf("%s be called\n", __func__);
	return a;
}

int func2(int a)
{
	printf("%s be called\n", __func__);
	return a;
}

int (*func3(int array[4]))[4]
{
	return array;
}

int main()
{
	
	int array[4] = {1, 2, 3, 4};
	int( *p)[4] = array;
	int (*pfunc[])(int) = {func1, func2};
	printf("%d, %d, %d\n", (*p)[1], pfunc[1](3), (*func3(array))[1]);
	
	return 0;
}
