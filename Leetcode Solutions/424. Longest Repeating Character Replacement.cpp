class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = s.length();

        vector<int>freq(26, 0);
        int start = 0, end = 0;
        int maxi = 0;
        
        while(end < n){
            int len = end - start + 1;
            freq[s[end]-'A']++;
            int max_freq = *max_element(freq.begin(), freq.end());
            
            while(len - max_freq > k){
                freq[s[start]-'A']--;
                start++;
                len = end - start + 1;
                max_freq = *max_element(freq.begin(), freq.end());
            }
            
            maxi = max(maxi, end - start + 1);s
            end++;
        }
        
        return maxi;
    }
};