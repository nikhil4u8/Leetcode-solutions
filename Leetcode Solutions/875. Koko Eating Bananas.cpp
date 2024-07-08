class Solution {
public:
// TIME - O(NlogM) SPACE - O(1)
// n -> size of piles
// m -> 1 to max(piles)
    int calculateHours(int k, vector<int>&piles){
        int hours = 0;
        for(int i=0;i<piles.size();i++) 
            hours += ceil((double)piles[i]/(double)k);
        return hours;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int maxi_piles = *max_element(piles.begin(), piles.end());
        if(h == piles.size()) return maxi_piles;

        int start = 1, end = maxi_piles;
        while(start < end){
            int mid = start + (end-start)/2;
            int temp_hour = calculateHours(mid, piles);
            if(temp_hour > h) start = mid+1;
            else end = mid;
        }

        return end;
    }
};