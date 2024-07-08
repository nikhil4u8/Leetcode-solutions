class Solution {
public:
    int longestSubsequence(vector<int>& arr, int difference) {
        int n = arr.size(), maxi = 0;
        unordered_map<int, int>mp;
        
        for(int i=0;i<n;i++){
            if(mp.find(arr[i] - difference) != mp.end())
                mp[arr[i]] = max(mp[arr[i]], mp[arr[i]-difference] + 1);
            maxi = max(maxi, 1 + mp[arr[i]]);
        }
        
        return maxi;
    }
};