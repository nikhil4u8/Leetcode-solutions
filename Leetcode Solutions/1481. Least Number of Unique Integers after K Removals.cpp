class Solution {
public:
//TIME - O(N) SPACE - O(N)
//Storing freq of elements in map, now firstly removing all unique elements, then removing elements
//having freq = 2, then freq = 3, until k == 0, and counting freq of unique elements removed
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        int ans = 0;
        unordered_map<int, int>mp;
        map<int, int>freq;
        for(int i=0;i<arr.size();i++) mp[arr[i]]++;

        ans = mp.size();
        for(auto it : mp) freq[it.second]++;

        for(auto it : freq){
            ans -= it.second;
            k -= it.second*it.first;
            if(k <= 0){
                k += it.second*it.first;
                ans += it.second;

                ans -= k / it.first;
                return ans;
            }
        }

        return ans;
    }
};