#include <stdio.h>

void bubsort(int array[], int n)
{
	int i, j, tmp, swap = 0;
	for (i = 0; i < n - 1; i++) {
		for (j = i + 1; j < n; j++) {
			if (array[i] > array[j]) {
				tmp = array[i];
				array[i] = array[j];
				array[j] = tmp;		
				swap = 1;
			}		
		}
		
		if (!swap) break;
	}

}



int main()
{
	int array[] = {8, 7, 6, 5, 4, 3};	
	bubsort(array, sizeof(array) / sizeof(int));
	return 0;
}
