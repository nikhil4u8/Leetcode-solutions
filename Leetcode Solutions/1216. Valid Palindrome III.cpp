/*
Sol :
BEST APPROACH
EXPLAIN TIME COMPLEXITY
=> Valid Palindrome II follow up : [TIME - O(2^K) SPACE - O(k)]
    - Maintain 2 pointer, left / right who'll be approaching towards each 
    other.
    - Whenever both pointer aren't pointing on same char, then there are 
    2 possible branches we can take.
    - One branch is to take out left-most char & other is to take out 
    right-most char & check if remaining string is valid with atmost 
    (k-1) removal operation 


SAY ONLY WHEN ASKED FOR DP SOLUTION
=> Using Longest Palindromic Subsequence : [TIME - O(N^2) SPACE - O(N)]
    - LPS = LCS(str, reverse_str), so len(Str) - len(LPS) <= K, then 
    string is K palindrome
    - LCS : First, we check the last char of string, if they're same then 
    they're part of subseq, so include them & recursively call fun to find 
    count of common char in rest of the str, if char are not same, then 
    that char can occur either of the char can occur in another str at 
    prev idx, so recursively call fun LCS(x,y,n-1,m) & LCS(x,y,n,m-1) & 
    return maximum among both
*/
class Solution {
public:
//BEST APPROACH
//Using Recursion
//TIME - O(2^K) SPACE - O(k)
/*-> TIME : Recursive tree have at most k level (max char to delete), where
each node is a substring which has atmost 2 branches i.e removing either
left or right char from a substr of node_str
-> SPACE : Height of the recursive tree
*/
    bool removeKCharToMakePalindrome(string str, int k, int start, int end){
        if(k < 0) return false;
        while(start < end){
            if(str[start] != str[end]){
                //further char can't be removed
                if (k == 0) return false;
                
                //decrement k & check if by removing a char str become Palin
                return removeKCharToMakePalindrome(str, k-1, start + 1, end) || 
                       removeKCharToMakePalindrome(str, k-1, start, end - 1);
            }
            start++;
            end--;
        }

        return true;
    }
    bool isValidPalindrome(string s, int k) {
        int n = s.length();
        return removeKCharToMakePalindrome(s, k, 0, n-1);
    }

//USING LPS
//TIME - O(N^2) SPACE - O(N)
    int lcs(string X, string Y, int m, int n) {
        vector<vector<int>>dp(m+1, vector<int>(n+1, 0));
        for (int i = 0; i <= m; i++) {
            for (int j = 0; j <= n; j++) {
                if (i == 0 || j == 0) dp[i][j] = 0;
                else if (X[i - 1] == Y[j - 1]) dp[i][j] = dp[i - 1][j - 1] + 1;
                else dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
        return dp[m][n];
    }
    bool isValidPalindrome(string str, int k) {
        int n = str.length();

        string revStr = str;
        reverse(revStr.begin(), revStr.end());
        int lps = lcs(str, revStr, n, n);

        return (n - lps <= k);
    }

};