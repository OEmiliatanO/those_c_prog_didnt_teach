#include <stdio.h>

int a[] = {1,2,3,5,7,8,9};

int binary_search(int* arr, int l, int r, int val)
{
	// special case
	if (l == r) return (arr[l] == val ? l : -1);
	// special case
	if (l > r) return -1;

	int mid = (l+r)/2;
	
	if (arr[mid] == val)
		return mid;

	if (arr[mid] > val)
		return binary_search(arr, l, mid-1, val);
	else if (arr[mid] < val)
		return binary_search(arr, mid+1, r, val);

	// not found
	return -1;
}

int main()
{
	printf("8 is at %d\n", binary_search(a, 0, 6, 8));
	printf("9 is at %d\n", binary_search(a, 0, 6, 9));
	printf("2 is at %d\n", binary_search(a, 0, 6, 2));
	printf("1 is at %d\n", binary_search(a, 0, 6, 1));
	printf("5 is at %d\n", binary_search(a, 0, 6, 5));
	return 0;
}
