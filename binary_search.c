#include <stdio.h>

/*递归算法*/
int bsearch_recursion(int array[], int low, int high, int key)
{
	int mid_index, mid_value;
	mid_index = low + (high - low) / 2;
	mid_value = array[mid_index];
	
	if (low < high && key != mid_value) {
		if (key > mid_value) return bsearch_recursion(array, mid_index + 1, high, key);		
		if (key < mid_value) return bsearch_recursion(array, low, mid_index - 1, key);
	} else if (key == mid_value)
		return mid_index;
	else 
		return -1;
}

/*循环算法*/
int bsearch_loop(int *array, int low, int high, int key)
{
	int mid_index = low + (high - low) / 2;
	int mid_value = *(array + mid_index);
	while (low < high && key != mid_value) {
		if (key > mid_value)
			low = mid_index + 1;
		if (key < mid_value)
			high = mid_index - 1;
			
		mid_index = low + (high - low) / 2;
		mid_value = *(array + mid_index);
	}
	
	return (*(array + mid_index) == key ? mid_index : -1);
}

/*插入排序*/
void insert_sort(int *array, int left, int right)
{
	int i, j, tmp;
	for (i = left + 1; i <= right; ++i) {
		tmp = *(array + i);
		for (j = i; *(array + j - 1) > tmp && j > 0; --j) 
			*(array + j) = *(array + j - 1);
		*(array + j) = tmp;			
	}
}

int main(int argc, char **argv)
{
	int a[] = {7, 6, 5, 4, 3, 2, 1};
	/*二分查找的数组必须排序好的*/
	insert_sort(a, 0, sizeof(a) / sizeof(int) - 1);
	printf("bsearch_recursion, index:%d\n", bsearch_recursion(a, 0, sizeof(a) / sizeof(int) - 1, 2));
	printf("bsearch_loop, index:%d\n", bsearch_loop(a, 0, sizeof(a) / sizeof(int) - 1, 2));
	return 0;
}
