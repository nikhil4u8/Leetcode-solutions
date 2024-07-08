/*
Ques to ask : 
    - Can weight array be empty?
    - Can days == 0?
    - Can weight[i] == 0?

Sol : 
SAY THIS FIRST
- If we don't have D days to ship, then min cap to ship in a day will be 
max weight in array. And max cap to ship will be sum(weight array).
- So, our ideal cap will lie in b/w (min cap - max cap)

=> Linear Search : [TIME - O(weight_sum) SPACE - O(1)]
    - We can linear search b/w (min_cap - max_cap) and find the smallest
    cap in which all the packages can be shipped in D days.

BEST APPROACH
=> Binary Search : [TIME - O(Nlog(weightSum)) SPACE - O(1)]
    - we'll have a array st 0,0,0,0,1,1,1 : where 0 represent weight can't
    be shipped in K days & 1 represent weight can be shipped in K day, so 
    we need to find cap on which first occurance of 1 is there.
*/
class Solution {
public:
//BEST APPROACH
//Binary Search
//TIME - O(Nlog(weightSum)) SPACE - O(1)
    //binary search in weight array
    int isDelivered(int cap, vector<int>weights){
        int temp_sum = 0, days = 0;
        for(int i=0;i<weights.size();i++){
            if(weights[i] > cap) return INT_MAX;
            temp_sum += weights[i];
            if(temp_sum > cap){
                days++;
                temp_sum = weights[i];
            }
        }

        return days+1;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int max_cap = 0;
        for(int i=0;i<weights.size();i++) max_cap += weights[i];

        int start = 0, end = max_cap;
        while(start < end){
            int mid = start + (end-start)/2;
            int temp_days = isDelivered(mid, weights);

            if(temp_days <= days) end = mid;
            else start = mid+1;
        }
        
        return end;
    }
};