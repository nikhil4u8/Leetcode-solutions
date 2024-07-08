class Solution {
public:
// TIME - O(logN) SPACE - O(1)
    int peakIndexInMountainArray(vector<int>& arr) {
        int i=0,j=arr.size()-1;
        
        while(i<=j){
            int mid = (i+j)/2;
            
            if(mid == 0 && arr[mid] > arr[mid+1]) return mid;
            if(mid == 0 && arr[mid] < arr[mid+1]) i = mid + 1;
            else if(mid == arr.size()-1 && arr[mid] > arr[mid-1]) return mid;
            else if(mid == arr.size()-1 && arr[mid] < arr[mid-1]) j = mid - 1;
            else if(arr[mid] > arr[mid-1] && arr[mid] > arr[mid+1]) return mid;
            else if(arr[mid] > arr[mid-1] && arr[mid] < arr[mid+1]) i = mid + 1;
            else j = mid - 1;
        }
        
        return -1;
    }
};

class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int start = 0, end = arr.size() - 1;
        while(start < end){
            int mid = start + (end - start)/2;
            if(mid == arr.size()-1 && arr[mid] > arr[mid-1]) return mid;
            if(arr[mid] > arr[mid+1]) end = mid;
            else start = mid + 1; 
        }

        return start;
    }
};