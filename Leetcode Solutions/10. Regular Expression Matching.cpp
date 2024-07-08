/*
Requirement - 
1. s contains only lowercase English letters.
2. p contains only lowercase English letters, '.', and '*'.
3. It is guaranteed for each appearance of the character '*', 
there will be a previous valid character to match.
*/
class Solution {
public:
//TIME - O(N*M) SPACE - O(N*M)
    vector<vector<int>>dp;
    bool isMatching(string s, string p, int n, int m){
        if(n == 0 && m == 0) return dp[n][m] = true;

        //S -> "" , P != ""
        if(n == 0) 
            return dp[n][m] = p[m-1] == '*' ? isMatching(s,p,n,m-2) : false;
        //s != "", p == "". so there will be no match 
        if(m == 0) return dp[n][m] = false;

        if(dp[n][m] != -1) return dp[n][m] == 1 ? true : false;

        //it has to match a char
        if(p[m-1] == '.') return dp[n][m] = isMatching(s, p, n-1, m-1);
        
        //p[m-1] is some char
        if(p[m-1] != '*') 
            return dp[n][m] = s[n-1] == p[m-1] && isMatching(s, p, n-1, m-1);

        //if p[m-1] == '*'
        for(int i=n;i>=0;i--){
            if(i != n && s[i] != p[m-2] && p[m-2] != '.') break;
            if(isMatching(s, p, i, m-2)) return dp[n][m] = true;
        }

        return dp[n][m] = false;
    }
    bool isMatch(string s, string p) {
        int n = s.length(), m = p.length();
        dp = vector<vector<int>>(n+1, vector<int>(m+1, -1));

        return isMatching(s, p, n, m);
    }
};