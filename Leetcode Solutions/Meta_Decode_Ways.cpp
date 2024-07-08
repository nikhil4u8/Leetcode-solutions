/*
Ques to ask :
    - Can there be '0' in str.
    - What to return in empty string?

Sol : 
    - For a character s[i], we have 2 ways to decode:
        Single digit: Require s[i] != '0' (decoded to 1..9)
        Two digits: Require i + 1 < len(s) and (s[i] == 1 
        (decoded to 10..19) or s[i] == 2 and s[i+1] <= '6') 
        (decoded to 20..26).

Follow up :
    - Print all the strings too
*/
class Solution {
public:
    //RECURSIVE + MEMO
    //TIME - O(N) SPACE - O(N)
    vector<int>dp = vector<int>(101, -1);
    int numDecodings(string s, int idx = 0) {
        if(idx >= s.length()) return dp[idx] = 1;
        
        if(dp[idx] != -1) return dp[idx];
        
        int ans = 0;
        if(s[idx] != '0'){
            ans += numDecodings(s, idx+1);
            
            if(idx != s.length()-1){
                int num = (s[idx] - '0')*10 + (s[idx+1] - '0');
                if(num <= 26) ans += numDecodings(s, idx+2);   
            }
            
            return dp[idx] = ans;
        }
        
        return dp[idx] = 0;
    }
    //DP
    //TIME - O(N) SPACE - O(N)
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
};

//Follow up
//TIME - O(N) SPACE - O(N)
vector<string>ans;
void findAllDecoding(string s, int idx, string temp_str){
    if(idx >= s.length()){
        ans.push_back(temp_str);
        return;
    }

    if(s[idx] != '0'){
        temp_str += char('A' + (s[idx]-'0' - 1));
        findAllDecoding(s, idx+1, temp_str);

        if(idx + 1 < s.length()){
            int temp = (s[idx]-'0')*10 + (s[idx + 1] - '0');
            temp_str.pop_back();
            temp_str += char('A' + temp - 1);
            if(temp <= 26) findAllDecoding(s, idx+2, temp_str);
        }
    }
}
vector<string> numDecodings(string s) {
    findAllDecoding(s, 0, "");
    return ans;
}