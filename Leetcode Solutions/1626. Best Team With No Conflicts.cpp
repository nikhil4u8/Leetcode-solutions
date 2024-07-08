class Solution {
public:
//TIME - O(N^2) SPACE - O(N)
    int bestTeamScore(vector<int>& scores, vector<int>& ages) {
        int n = scores.size();

        vector<pair<int, int>>vec;
        for(int i=0;i<n;i++) vec.push_back({ages[i], scores[i]});
        
        sort(vec.begin(), vec.end());        

        vector<int>dp(n, 0);
        int ans = 0;

        for(int i=0;i<n;i++){
            int maxi = 0;

            for(int j=0;j<i;j++){
                if(vec[j].first < vec[i].first && 
                vec[j].second <= vec[i].second)
                    maxi = max(maxi, dp[j]);
                else if(vec[j].first == vec[i].first)
                    maxi = max(maxi, dp[j]);
            }

            dp[i] = vec[i].second + maxi;
            cout<<dp[i]<<" ";
            ans = max(ans, dp[i]);
        }        

        return ans;
    }
};