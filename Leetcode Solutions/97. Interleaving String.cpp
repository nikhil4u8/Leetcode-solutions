class Solution {
public:
    vector<vector<vector<int>>>dp = vector<vector<vector<int>>>(101, vector<vector<int>>(101, vector<int>(201, -1)));
    
    bool isPossible(string s1, string s2, string s3, int n1, int n2, int n3){
        if(n3 == 0) return dp[n1][n2][n3] = n1 == 0 && n2 == 0;
        
        if(dp[n1][n2][n3] != -1) return dp[n1][n2][n3] == 1;
        
        if(n1>0 && n2>0){
            if(s3[n3-1] == s1[n1-1] && s3[n3-1] == s2[n2-1])
                return dp[n1][n2][n3] = isPossible(s1, s2, s3, n1-1, n2, n3-1) || 
                       isPossible(s1, s2, s3, n1, n2-1, n3-1);
        }
        
        if(n2>0 && s3[n3-1] == s2[n2-1])
            return dp[n1][n2][n3] = isPossible(s1, s2, s3, n1, n2-1, n3-1);
        
        if(n1>0 && s3[n3-1] == s1[n1-1])
            return dp[n1][n2][n3] = isPossible(s1, s2, s3, n1-1, n2, n3-1);
        
        return dp[n1][n2][n3] = false;
    }
    bool isInterleave(string s1, string s2, string s3) {
        int n1 = s1.length();
        int n2 = s2.length();
        int n3 = s3.length();
        return isPossible(s1, s2, s3, n1, n2, n3);
    }
};