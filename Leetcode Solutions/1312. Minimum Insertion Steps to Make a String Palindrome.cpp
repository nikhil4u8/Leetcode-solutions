class Solution {
public:
    //Find len of longest palindromic subsequence and we just need to add other non-palindromic letters only
    //The minimum number of insertions in the string str[l…..h] can be given as:  
        //minInsertions(str[l+1…..h-1]) if str[l]==str[h]
        //min(minInsertions(str[l…..h-1]), minInsertions(str[l+1…..h])) + 1 otherwis
    //Recursive way
    int min_ope(string str,int left,int right){
        if(left>=right) return 0;
        
        if(str[left] == str[right]) return min_ope(str,left+1,right-1);
        return 1 + min(min_ope(str,left+1,right),min_ope(str,left,right-1));
    }
    int minInsertions(string s) {
        return min_ope(s,0,s.length()-1);
    }
    //TIME - O(N*N) SPACE - O(N*N)
    int minInsertions(string s) {
        string str = s;
        int n = s.length();
        reverse(str.begin(),str.end());
        
        vector<vector<int>>dp(n+1,vector<int>(n+1,0));
        
        for(int i=0;i<=n;i++){
            for(int j=0;j<=n;j++){
                if(i==0 || j==0) dp[i][j] = 0;
                else if(str[i-1] == s[j-1]) dp[i][j] = 1 + dp[i-1][j-1];
                else dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
            }
        }
        
        return s.length() - dp[n][n];
    }
};

**FOLLOW-UP
    1.Minimum replacement steps to make a string palindromic (no insertion allowed) 
    2.Minimum total steps of insertion and replacement to make a string palindromic
    3.Assuming each insertion has a cost cost_i, each deletion has a cost cost_d, and each replacement 
    has a cost cost_r, what is the minimum total cost to make a string palindromic? Give any of such 
    palindromes as well.
    4.Suppose a string consists of lowercase letters only. Suppose further that the insertion cost of 
    a letter is given by an array cost_i[26] (26 means the length of the array, i.e., the total number 
    of lowercase letters), the deletion cost of a letter is given by cost_d[26], and the replacement 
    cost from one letter to another is given by a matrix cost_r[26][26] (cost_r[k][k] = 0 for all legal 
    k). All costs are guaranteed to be positive integers. Give the minimum total cost to make the 
    string a palindrome, as well as any such qualified resulting palindrome.

Solution::--
1.
int min_ope(string str,int left,int right){
    int min_no_of_replacement = 0;
        while(left<=right){
            if(str[left] != str[right]) min_no_of_replacement++;
            left++;
            right--;
        }
        return min_no_of_replacement;
}


//EDIT DISTANCE
/*Given two strings word1 and word2, return the minimum number of operations required to convert word1 
to word2.

You have the following three operations permitted on a word:

Insert a character
Delete a character
Replace a character
*/
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