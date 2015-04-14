int bsearch(int array[], int low, int high, int key)
{
	int mid_index, mid;
	mid_index = low + (high - low) / 2;
	mid = array[mid_index];
	
	if (low > high) return -1;
	if (key > mid) return bsearch(array, mid_index + 1, high, key);		
	else if (key < mid) return bsearch(array, low, mid_index - 1, key);
	else return mid_index;
}


int main(int argc, char **argv)
{
	int a[] = {1, 2, 3, 4, 5, 6, 7};
	printf("index:%d\n", bsearch(a, 0, 6, 2));
	return 0;
}
