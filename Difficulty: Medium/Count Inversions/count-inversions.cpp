class Solution {
	public:
	int cnt = 0;
	void merge(vector<int> &arr, int low, int mid, int high)
	{
		vector<int> temp;
		int left = low;
		int right = mid + 1;
		int x = 0;
		
		while (left <= mid && right <= high) {
			if (arr[left] <= arr[right]) {
				temp.push_back(arr[left]);
				left++;
			}
			else {
				temp.push_back(arr[right]);
				cnt += mid - left + 1;
				right++;
			}
		}
		while (left <= mid) {
			temp.push_back(arr[left]);
			left++;
		}
		while (right <= high) {
			temp.push_back(arr[right]);
			right++;
		}
		
		for (int i = low; i <= high; i++) {
			arr[i] = temp[i - low];
		}
	}
	
	void mergeSort(vector<int> &arr, int low, int high)
	{
		// code here
		if (low >= high)
			return;
		int mid = (low + high)/2;
		mergeSort(arr, low, mid);
		mergeSort(arr, mid + 1, high);
		merge(arr, low, mid, high);
		
	}
	int inversionCount(vector<int> &arr) {
		// Code Here
		// 1,2 2,0 3,3 4,1 5,4
		
		// 4,1 3,3 2,0 1,2
		
		// 5,4
		//
		int n = arr.size();
		mergeSort(arr, 0, n - 1);
		return cnt;
		
	}
};
