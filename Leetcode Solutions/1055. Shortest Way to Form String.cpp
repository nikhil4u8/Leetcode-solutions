class Solution {
public:
    int shortestWay(string source, string target) {
        unordered_map<int, vector<int>>mp;
        for(int i=0;i<source.length();i++) 
            mp[source[i]].push_back(i);
        
        int last_idx = -1,count=0;
        for(int i=0;i<target.length();){
            char x = target[i];
            
            if(mp.find(x) == mp.end()) return -1;
            
            auto temp = upper_bound(mp[x].begin(), mp[x].end(), last_idx);
            if(temp == mp[x].end()){
                count++;
                last_idx = -1;
                continue;
            }
            if(*temp == last_idx) temp++;
            if(temp == mp[x].end()){
                count++;
                last_idx = -1;
                continue;
            }
            
            last_idx = *temp;
            i++;
        }
        
        if(last_idx != -1) count++;
        
        return count;
    }
};