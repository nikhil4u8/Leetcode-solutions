class Solution {
public:
    int hIndex(vector<int>& citations) {
        int n = citations.size();
        int low=0,high=n-1;
        
        while(low<=high){
            int mid = (low+high)/2;
            // There's (n - mid) papers with an equal or higher citation count than citations[mid]
            // If (citations[mid] == n - mid) it's the optimal result and can be returned right away
            if (citations[mid] == n - mid)
                return citations[mid];

            // If citations[mid] is less than (n - mid), narrow down on the right half to look for a paper
            // at a future index that meets the h-index criteria. Otherwise, narrow down on the left half
            if(citations[mid] < n - mid) low = mid + 1;
            else high = mid - 1;
        }
        
        return n - low;
    }
};