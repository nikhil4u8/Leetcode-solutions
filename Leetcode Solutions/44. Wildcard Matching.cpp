class Solution {
public:
    //Recrusive + memo
    bool compare(string s,string p,int n,int m,vector<vector<int>>&dp){
        if(n<0 || m<0) return false;
        if(n==0 && m==0) return dp[n][m] = true;
        if(n>0 && m==0) return dp[n][m] = false;
        
        if(dp[n][m] != -1) return dp[n][m] == 1;
        
        if(p[m-1]>='a' && p[m-1]<='z'){
            if(n>0 && s[n-1] == p[m-1]) return dp[n][m] = compare(s,p,n-1,m-1,dp);
            return dp[n][m] = false;
        }
        
        if(p[m-1] == '?') return dp[n][m] = compare(s,p,n-1,m-1,dp);
        
        bool ans = false;
        if(p[m-1] == '*'){
            for(int i=n;i>=0;i--){
                if(dp[i][m-1] != -1) ans = ans || (dp[i][m-1] == 1);
                else ans = ans || compare(s,p,i,m-1,dp);
                if(ans) return dp[n][m] = true;
            }
            
            //instead of for loop, we can also do
            //return compare(s,p,n-1,m-1) || compare(s,p,n,m-1) || compare(s,p,n-1,m);
        }
        
        return dp[n][m] = ans;
    }
    bool isMatch(string s, string p) {
        vector<vector<int>>dp((int)s.length()+1,vector<int>((int)p.length()+1,-1));
        return compare(s,p,s.length(),p.length(),dp);
    }
    //DP
    //TIME - O(N*M) SPACE - O(N*M)
    bool isMatch(string s, string p) {
        int n = s.length();
        int m = p.length();
        vector<vector<bool>>dp(n+1,vector<bool>(m+1,false));
        dp[0][0] = true;
        
        for(int i=1;i<=n;i++) dp[i][0] = false;
        
        for (int i=1;i<=m;i++){
            if(p[i - 1]== '*') dp[0][i] = dp[0][i-1];
	    }
        
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(p[j-1]>='a' && p[j-1]<='z' && s[i-1]==p[j-1]) dp[i][j] = dp[i-1][j-1];
                else if(p[j-1] == '?') dp[i][j] = dp[i-1][j-1];
                else if(p[j-1] == '*') dp[i][j] = dp[i-1][j-1] || dp[i][j-1] || dp[i-1][j];
            }
        }
        
        return dp[n][m];
    }
};