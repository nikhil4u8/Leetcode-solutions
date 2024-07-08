class Solution {
public:
    //TIME - O(N*LlogL) ->L is max len of string SPACE - O(N*L)
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<string>>mp;
        vector<vector<string>>res;
        
        for(int i=0;i<strs.size();i++){
            string str = strs[i];
            sort(str.begin(),str.end());
            mp[str].push_back(strs[i]);
        }
        
        for(auto it:mp){
            res.push_back(it.second);
        }
        
        return res;
    }
};