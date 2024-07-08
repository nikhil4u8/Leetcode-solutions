class Solution {
public:
    //TIME - O(N^3) SPACE - O(N^3)
//     vector<vector<vector<int>>>dp;
//     bool isValid(string s, int open, int close, int idx){
//         if(open < close) return dp[open][close][idx] = false;
//         if(idx == s.length()) return dp[open][close][idx] = (open == close);
        
//         if(dp[open][close][idx] != -1) return dp[open][close][idx] == 1;
        
//         if(s[idx] == ')') return dp[open][close][idx] = isValid(s, open, close+1, idx+1);
//         if(s[idx] == '(') return dp[open][close][idx] = isValid(s, open+1, close, idx+1);
        
//         return dp[open][close][idx] = isValid(s, open+1, close, idx+1) || 
//                isValid(s, open, close+1, idx+1) || 
//                isValid(s, open, close, idx+1);
//     }
//     bool checkValidString(string s) {
//         dp = vector<vector<vector<int>>>(101, vector<vector<int>>(101, vector<int>(101, -1)));
//         return isValid(s, 0, 0, 0);
//     }
    bool checkValidString(string s) {
        int balance = 0;
        for(int i=0;i<s.length();i++){
            if(s[i] == '(' || s[i] == '*') balance++;
            else balance--;
            if(balance < 0) return false;
        }
        
        if(balance == 0) return true;
        balance = 0;
        
        for(int i=s.length()-1;i>=0;i--){
            if(s[i] == ')' || s[i] == '*') balance++;
            else balance--;
            if(balance < 0) return false;
        }
        return true;
    }
};