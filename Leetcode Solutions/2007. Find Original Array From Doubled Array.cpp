class Solution {
public:
    vector<int> findOriginalArray(vector<int>& changed) {
        int len = changed.size();
        
        unordered_map<int,int>mp;
        for(int i=0;i<len;i++) mp[changed[i]]++;
        
        sort(changed.begin(), changed.end());
        vector<int>ans;
        
        for(int i=len-1;i>=0;i--){
            if(mp[changed[i]] == 0) continue;
            
            int num = changed[i]/2;
            
            mp[changed[i]]--;
            
            if(mp[num] == 0 || changed[i] % 2 != 0) return {};
            mp[num]--;
            
            ans.push_back(num);
        }
        
        return ans;
    }
};