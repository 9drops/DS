#include <stdio.h>

/*O(n2)*/
int max_seg_1(int array[], int n)
{
	int i, j, k;
	int max = 0, this_max;

	for (i = 0; i < n; i++) {
		this_max = 0;
		for (j = i; j < n; j++) {
			this_max += array[j]; 
			if (this_max > max)
				max = this_max;
		}
	}

	return max;
}

/*O(n)*/
int max_seg_2(int array[], int n)
{
	int max, this_max, i;
	max = this_max = 0;
	for (i = 0; i < n; i++) {
		this_max += array[i];
		if (this_max > max)
			max = this_max;
		else if (this_max < 0)
			this_max = 0;
	}
	
	return max;
}

int main()
{
	int array[] = {1, 2, 3, -1, 5, 6};
	int n = sizeof(array) / sizeof(int);
	printf("O(n2)max:%d, O(n)max:%d\n", max_seg_1(array, n), max_seg_2(array, n));
	return 0;
}
