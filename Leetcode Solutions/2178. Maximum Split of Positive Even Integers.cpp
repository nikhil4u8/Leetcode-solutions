class Solution {
public:
    vector<long long> maximumEvenSplit(long long finalSum) {
        if(finalSum % 2 != 0) return {};
        
        vector<long long>ans;
        
        long long curr_sum = 0, i = 2;
        
        while(curr_sum + i <= finalSum){
            ans.push_back(i);
            curr_sum += i;
            i += 2;
        }
        
        int len = ans.size();
        if(curr_sum != finalSum) ans[len-1] += finalSum - curr_sum;
        
        return ans;
    }
};