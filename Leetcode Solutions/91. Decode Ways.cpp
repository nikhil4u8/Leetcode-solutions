/*
Ques to ask :
    - Does str contains leading '0', spaces or any other special char?
    - '101' -> 'AA' or 'JA', which mapping is correct?
    - Invalid input then what is the output is? like having i/o having 
    leading 0.
    - What to return when str == ""?

Sol :
BEST APPROACH
=> Recursion - [TIME - O(N) SPACE - O(N) -> recursive stack]
    - Traverse the str, and for each s[i] char we've 2 ways to decode :
        - Single digit decode : Mapping single digit to a char & making 
        sure it's not a '0'
        - Two Digit decode : We can take i, i+1 idx and combine them to 
        make a digit so that it can be mapped to a char & making sure 
        that it doesn't have leading zeros and it's <= 26.
    - After every case recursively call numDecoding fun to find total ways 
    to decode rest of the str.

=> Can be solved using DP - [TIME - O(N) SPACE - O(1)]
Follow up :
    - Return all decoded string ?
        -> maintain a temp_str variable (pass it as a param in fun) to 
        store decoding while calling numDecoding fun recrusively
*/
class Solution {
public:
    vector<int>dp = vector<int>(101, -1);
    int numDecodings(string s, int idx = 0) {
        // we have consumed the whole input sucessfully. 
        if(idx >= s.length()) return dp[idx] = 1;   
        //leading zero so no way to decode      
        if(s[idx] == '0') return dp[idx] = 0;

        //If already cahced, use the cached value   
        if(dp[idx] != -1) return dp[idx];

        //mapping one digit to char
        int totalDecoding = numDecodings(s, idx+1);
        
        //left one character, only one way to decode
        if(idx + 1 < s.length()){
            //mapping 2 digit to char & making sure nextDigit has val <= 26 for mapping
            int nextDigit = (s[idx]-'0')*10 + (s[idx+1]-'0');
            if(nextDigit <= 26 && nextDigit >= 10) 
                totalDecoding += numDecodings(s, idx+2);
        }

        return dp[idx] = totalDecoding;
    }
};

//DP
//TIME - O(N) SPACE - O(N)
//Just convert from Top-down DP to Bottom-up DP approach.
int numDecodings(string s) {
    int n = s.length();
    vector<int>dp(n+1, 0);
    dp[n] = 1;
    
    for(int i = n-1;i>=0;i--){
        if(s[i] == '0') dp[i] = 0;
        else{
            dp[i] += dp[i+1];
            
            if(i != n-1){
                int num = (s[i] - '0')*10 + (s[i+1] - '0');
                if(num <= 26) dp[i] += dp[i+2];
            }
        }
    }
    
    return dp[0];
}
//Bottom Down DP
//TIME - O(N) SPACE - O(1)
/*
Since our dp only need to keep up to 3 following states:
    - Current state, let name dp corresponding to dp[i]
    - Last state, let name dp1 corresponding to dp[i+1]
    - Last twice state, let name dp2 corresponding to dp[i+2]
So we can achieve O(1) in space.
*/
class Solution { // 0 ms, faster than 100.00%
public:
    int numDecodings(const string& s) {
        int n = s.size(), dp = 0, dp1 = 1, dp2 = 0;
        for (int i = n - 1; i >= 0; --i) {
            if (s[i] != '0') // Single digit
                dp += dp1;
            if (i+1 < s.size() && (s[i] == '1' || s[i] == '2' && s[i+1] <= '6')) // Two digits
                dp += dp2;
            dp2 = dp1;
            dp1 = dp;
            dp = 0;
        }
        return dp1;
    }
};