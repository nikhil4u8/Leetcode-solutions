class Solution {
public:
    //TIME - O(N*M) SPACE - O(N*M)
    int min_ope(string str1,string str2,int n,int m,vector<vector<int>>&dp){
        if(n==0 && m==0) return dp[n][m] = 0;
        if(n==0) return dp[n][m] = m;
        if(m==0) return dp[n][m] = n;
        
        if(dp[n][m] != -1) return dp[n][m];
        
        if(str1[n-1] == str2[m-1]) return dp[n][m] = min_ope(str1,str2,n-1,m-1,dp);
        
        int mini = INT_MAX;
        
        //Insert at str2 ending
        mini = min(mini,min_ope(str1,str2,n-1,m,dp));
        //Delete at str2 ending
        mini = min(mini,min_ope(str1,str2,n,m-1,dp));
        //Replace 
        mini = min(mini,min_ope(str1,str2,n-1,m-1,dp));
        
        return dp[n][m] = 1 + mini;
    }
    int minDistance(string word1, string word2) {
        int n = word1.length();
        int m = word2.length();
        vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
        
        return min_ope(word1,word2,n,m,dp);
    }
};