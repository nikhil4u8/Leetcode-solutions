class Solution {
public:
//TIME - O(N*M) SPACE - O(1)
//N->account.size
//M->max(account[i].size()) 
    int maximumWealth(vector<vector<int>>& accounts) {
        int maxi = 0;
        for(int i=0;i<accounts.size();i++){
            int sum = 0;
            for(int j=0;j<accounts[i].size();j++) sum += accounts[i][j];
            
            maxi = max(maxi, sum);
        }
        return maxi;
    }
};