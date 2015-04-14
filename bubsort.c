#include <stdio.h>

void swap(int *a, int *b)
{
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

void bubsort(int array[], int n)
{
	int i, j, tmp, swap_flag = 0;
	for (i = 0; i < n - 1; ++i) {
		for (j = n - 1; j > i; --j) {
			if (array[j] < array[j - 1]) {
				swap(&array[j], &array[j - 1]);	
				swap_flag = 1;
			}		
		}
		
		if (!swap_flag) break;
	}

}



int main()
{
	int array[] = {8, 7, 6, 5, 4, 3};	
	bubsort(array, sizeof(array) / sizeof(int));
	return 0;
}
