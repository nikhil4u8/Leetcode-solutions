class Solution {
public:
    string findReplaceString(string s, vector<int>& indices, vector<string>& sources, vector<string>& targets) {
        string res = "";
        int index = 0;
        
        unordered_map<int, pair<string, string>>mp;
        for(int i=0;i<indices.size();i++) mp[indices[i]] = {sources[i], targets[i]};
        
        for(int i=0;i<s.length();){
            if(mp.find(i) != mp.end()){
                int src_len = mp[i].first.length();
                string substr = s.substr(i, src_len);
                
                if(substr == mp[i].first){
                    res += mp[i].second;
                    i += src_len;
                    index++;
                    continue;
                }
                index++;
            }
            res += s[i++];
        }
        
        return res;
    }
};