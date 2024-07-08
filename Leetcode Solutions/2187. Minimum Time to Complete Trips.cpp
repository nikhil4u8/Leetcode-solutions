class Solution {
public:
    //TIME - O(NlogD) SPACE - O(1)
    //D is Maximum possible time = ~10^14 (from worst case constraints)
    long long int isPossible(long long int time, vector<int>bus){
        long long int total_trip = 0;
        
        for(int i=0;i<bus.size();i++)
            total_trip += time/(long long int)bus[i];
        
        return total_trip;
    }
    long long minimumTime(vector<int>& time, int totalTrips) {
        sort(time.begin(), time.end());
        
        long long int start = 0, end = (long long)time[0]*(long long)totalTrips, ans = end;
        
        while(start <= end){
            long long int mid = start + (end - start)/2;
            long long int trip = isPossible(mid, time);
            
            if(trip >= totalTrips){
                ans = min(ans, mid);
                end = mid - 1;
            }else start = mid + 1;
        }
        
        return ans;
    }
};