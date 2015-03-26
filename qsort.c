#include <stdio.h>
#define CUTOFF 3

void swap(int *a, int *b)
{
	int tmp = *a;
	*a = *b;
	*b = tmp;
}


int median3(int array[], int left, int right)
{
	int mid = left + (right - left) / 2;
	if (array[mid] < array[left])
		swap(&array[mid], &array[left]);
	if (array[left] > array[right])
		swap(&array[left], &array[right]);
	if (array[mid] > array[right])
		swap(&array[mid], &array[right]);
	swap(&array[mid], &array[right - 1]); /*Hide pivot*/
	return array[right - 1]; /*Return pivot*/
}


void insert_sort(int array[], int left, int right)
{
	int i, j, tmp;
	for (i = left + 1; i <= right; i++) {
		tmp = array[i];
		for (j = i; j > 0 && array[j - 1] > tmp; j--)
			array[j] = array[j - 1];
		array[j] = tmp;
	}	
}

void qsort(int array[], int left, int right)
{
	int i, j, mid, pivot;
	
	if (right - left >= CUTOFF) {
		mid = left + (right - left) / 2;
		pivot = median3(array, left, right);
		i = left;
		j = right - 1;
		
		for (;;) {	
			while (array[++i] < pivot);
			while (array[--j] > pivot);
			if (i < j)
				swap(&array[i], &array[j]);
			else
				break;
		}
		
		swap(&array[i], &array[right - 1]);/*Restore pivot*/
		qsort(array, left, i - 1);
		qsort(array, i + 1, right);
	} else
		insert_sort(array, left, right);
}


int main()
{
	int array[] = {7, 6, 5, 1, 3, 2, 4};
	qsort(array, 0, 6);
	return 0;
}
