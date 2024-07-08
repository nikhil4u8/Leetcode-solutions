class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& values) {
        if(values.size() == 0) return 0;
        int maxi = values[0] + 0, ans = 0;
        for(int i=1;i<values.size();i++){
            ans = max(ans, maxi + values[i] - i);
            maxi = max(maxi, values[i] + i);
        }
        return ans;
    }
};