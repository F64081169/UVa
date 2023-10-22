/*
The idea is to create a recursive function to implement the binary search where the search region is [l, r]. For each recursive call:

1.We calculate the mid value as mid = (l + h) / 2
2.Then try to figure out if l to mid is sorted, or (mid+1) to h is sorted
3.Based on that decide the next search region and keep on doing this till the element is found or l overcomes h.
*/
// Search an element in sorted and rotated
// array using single pass of Binary Search
#include <bits/stdc++.h>
using namespace std;

// Returns index of key in arr[l..h] if
// key is present, otherwise returns -1
int search(int arr[], int l, int h, int key)
{
	if (l > h)
		return -1;

	int mid = (l + h) / 2;
	if (arr[mid] == key)
		return mid;

	/* If arr[l...mid] is sorted */
	if (arr[l] <= arr[mid]) {
		/* As this subarray is sorted, we can quickly
		check if key lies in half or other half */
		if (key >= arr[l] && key <= arr[mid])
			return search(arr, l, mid - 1, key);
		/*If key not lies in first half subarray,
		Divide other half into two subarrays,
		such that we can quickly check if key lies
		in other half */
		return search(arr, mid + 1, h, key);
	}

	/* If arr[l..mid] first subarray is not sorted, then
	arr[mid... h] must be sorted subarray */
	if (key >= arr[mid] && key <= arr[h])
		return search(arr, mid + 1, h, key);

	return search(arr, l, mid - 1, key);
}

// Driver program
int main()
{
	int arr[] = { 4, 5, 6, 7, 8, 9, 1, 2, 3 };
	int n = sizeof(arr) / sizeof(arr[0]);
	int key = 3;
	int i = search(arr, 0, n - 1, key);

	if (i != -1)
		cout << "Index: " << i << endl;
	else
		cout << "Key not found";
}

// This code is contributed by Aditya Kumar (adityakumar129)
