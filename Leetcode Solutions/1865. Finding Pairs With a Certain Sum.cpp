class FindSumPairs {
public:
    //TIME - O(N) SPACE - O(N)
    unordered_map<int,int>mp;
    vector<int>arr1,arr2;
    FindSumPairs(vector<int>& nums1, vector<int>& nums2) {
        arr1 = nums1;
        arr2 = nums2;
        for(int i=0;i<nums2.size();i++) mp[nums2[i]]++;
    }
    //TIME - O(1)
    void add(int index, int val) {
        mp[arr2[index]]--;
        if(mp[arr2[index]] == 0) mp.erase(arr2[index]);
        arr2[index] += val;
        mp[arr2[index]]++;
    }
    //TIME - O(N)
    int count(int tot) {
        int ans = 0;
        for(int i=0;i<arr1.size();i++) ans += mp[tot-arr1[i]];
        
        return ans;
    }
};
