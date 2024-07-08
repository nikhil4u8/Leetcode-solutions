//Approach 1 - LCS
//Approach 2 - Sorting
//Approach 3 - Intersection of Set
class Solution {
public:
// TIME - O(n+m) SPACE - O(N) / O(M)
//in unordered_set, time complexity of deletion/insertion is O(1) in avg 
//case scenerio, and O(N) in worst case, as it is implemented using
//hash table, so in case of collision worst case complexity is O(n)
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int>st;
        vector<int>ans;
        
        for(int i=0;i<nums1.size();i++) st.insert(nums1[i]);
        for(int i=0;i<nums2.size();i++){
            auto it = st.find(nums2[i]);
            if(it != st.end()){
                ans.push_back(nums2[i]);
                st.erase(it);
            }
        }
        
        return ans;
    }
};