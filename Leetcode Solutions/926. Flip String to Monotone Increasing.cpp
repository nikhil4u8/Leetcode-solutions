class Solution {
public:
// TIME - O(N) SPACE - O(N)
    int minFlipsMonoIncr(string s) {
        int ans = INT_MAX;

        int n = s.length(), sum = 0;
        vector<int>prefix_sum(n, 0);
        vector<int>suffix_sum(n, 0);

        for(int i=s.length()-1;i>=0;i--){
            suffix_sum[i] = sum + s[i] - '0';
            sum = suffix_sum[i];
        }

        sum = 0;

        for(int i=0;i<s.length();i++){
            prefix_sum[i] = sum + s[i] - '0';
            sum = prefix_sum[i];
            ans = min(ans, prefix_sum[i] + n - i - 1 - suffix_sum[i]);
        }

        return ans;
    }
};