int firstocc(vector<int>&arr, int n, int x){
	int low = 0, high = n-1, first = -1;

	while(low<=high){
		int mid = (low+high)/2;
		if(arr[mid]==x){
			first = mid;
			high = mid-1;
		}else if(arr[mid]>x)
				high = mid - 1;
		else 
			low = mid+1;
	}
	return first;
}

int lastocc(vector<int>&arr, int n, int x){
	int low = 0, high = n-1, last = -1;

	while(low<=high){
		int mid = (low+high)/2;
		if(arr[mid]==x){
			last = mid;
			low = mid+1;
		}else if(arr[mid]>x)
				high = mid - 1;
		else 
			low = mid+1;
	}
	return last;
}


int count(vector<int>& arr, int n, int x) {
	int f = firstocc(arr, n, x);
	int l = lastocc(arr, n, x);
	if(f!=-1)
		return l-f+1;
	return 0;
}
