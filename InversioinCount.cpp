// code to find inversion count in nlog(n).
// to get answer pass the array and size to mergeSort function all other function are helper fucntions, so ignore
// inversion count is number of pairs in array such that a[i]>a[j] and i<j.
// Inversion Count for an array indicates – how far (or close) the array is from being sorted. If array is already sorted then
// inversion count is 0. If array is sorted in reverse order that inversion count is the maximum.

ll _mergeSort(int arr[], int temp[], int left, int right); 
ll merge(int arr[], int temp[], int left, int mid, int right); 

ll mergeSort(int arr[], int array_size) 
{ 
	int temp[array_size]; 
	return _mergeSort(arr, temp, 0, array_size - 1); 
} 

ll _mergeSort(int arr[], int temp[], int left, int right) 
{ 
	ll mid, inv_count = 0; 
	if (right > left) { 
		mid = (right + left) / 2; 
		inv_count += _mergeSort(arr, temp, left, mid); 
		inv_count += _mergeSort(arr, temp, mid + 1, right); 
		inv_count += merge(arr, temp, left, mid + 1, right); 
	} 
	return inv_count; 
} 

ll merge(int arr[], int temp[], int left, 
		int mid, int right) 
{ 
	int i, j, k; 
	ll inv_count = 0; 

	i = left;
	j = mid; 
	k = left;
	while ((i <= mid - 1) && (j <= right)) { 
		if (arr[i] <= arr[j]) { 
			temp[k++] = arr[i++]; 
		} 
		else { 
			temp[k++] = arr[j++]; 
			explanation/diagram for merge()*/
			inv_count = inv_count + (mid - i); 
		} 
	} 
	while (i <= mid - 1) 
		temp[k++] = arr[i++]; 
	while (j <= right) 
		temp[k++] = arr[j++];
	for (i = left; i <= right; i++) 
		arr[i] = temp[i]; 

	return inv_count; 
} 
