#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int a[] = {9,1,7,5,3,8,2};

void swap(int *x, int *y)
{
	int tmp = *x;
	*x = *y;
	*y = tmp;
}

/*** bubble sort ***/
void bubble_sort(int *arr, int len)
{
	for (int i = 0; i < len; ++i)
		for (int j = 1; j < len-i; ++j)
			if (arr[j] < arr[j-1])
				swap(&arr[j], &arr[j-1]);
}
/*******************/

/*** insertion sort ***/
void insertion_sort(int *arr, int len)
{
	for (int i = 1; i < len; ++i)
	{
		int key = arr[i];
		int j = i-1;
		while ((j >= 0) && (arr[j] > key))
		{
			arr[j+1] = arr[j];
			--j;
		}
		arr[j+1] = key;
	}
}
/**********************/

/*** selection sort ***/
void selection_sort(int *arr, int len)
{
	for (int i = 0; i < len-1; ++i)
	{
		int min = i;
		
		for (int j = i; j < len; ++j)
			if (arr[min] > arr[j])
				min = j;

		swap(&arr[min], &arr[i]);
	}
}
/**********************/

/*** merge sort ***/
void merge(int *a, int *b, int lena, int lenb)
{
	int i = 0, j = 0, k = 0;
	int *tmp = (int *)malloc(sizeof(int) * (lena + lenb));
	
	while (i < lena && j < lenb)
		tmp[k++] = (a[i] < b[j] ? a[i++] : b[j++]);
	while (i < lena)
		tmp[k++] = a[i++];
	while (j < lenb)
		tmp[k++] = b[j++];

	memcpy(a, tmp, sizeof(int) * (lena + lenb));
	free(tmp);
}
void merge_sort(int *arr, int l, int r)
{
	if (r <= l) return;
	
	int mid = (l+r)/2;

	merge_sort(arr, l, mid);
	merge_sort(arr, mid+1, r);
	merge(arr+l, arr+mid+1, mid-l+1, r-mid);
}
/******************/

/*** quick sort ***/
void quick_sort(int *arr, int l, int r)
{
	if (l >= r) return;
	int len = r-l+1;
	int i, j;
	int pivot;
	
	swap(&arr[l + rand() % len], &arr[r]);
	pivot = arr[r];
	
	for (i = l-1, j = l; j <= r; ++j)
		if (arr[j] < pivot)
			swap(&arr[++i], &arr[j]);

	swap(&arr[i+1], &arr[r]);
	quick_sort(arr, l, i);
	quick_sort(arr, i+2, r);
}
/******************/

/*** counting sort ***/
int count[10];
void counting_sort(int *arr, int len)
{
	memset(count, 0, sizeof(count));
	for (int i = 0; i < len; ++i)
		++count[arr[i]];
	for (int i = 0, p = 0; i < 10; ++i)
		while (count[i]--)
			arr[p++] = i;
}
/*********************/

void print_arr(int *arr, int len)
{
	for (int i = 0; i < len; ++i)
		printf("%d ", arr[i]);
	puts("");
}

int main()
{
	int arr[7];

	memcpy(arr, a, sizeof(a));
	bubble_sort(arr, 7);
	print_arr(arr, 7);
	
	memcpy(arr, a, sizeof(a));
	insertion_sort(arr, 7);
	print_arr(arr, 7);

	memcpy(arr, a, sizeof(a));
	selection_sort(arr, 7);
	print_arr(arr, 7);
	
	memcpy(arr, a, sizeof(a));
	merge_sort(arr, 0, 6);
	print_arr(arr, 7);

	memcpy(arr, a, sizeof(a));
	quick_sort(arr, 0, 6);
	print_arr(arr, 7);

	memcpy(arr, a, sizeof(a));
	counting_sort(arr, 7);
	print_arr(arr, 7);

	return 0;
}
