class Solution {
public:
    //TIME - O(N) SPACE - little bit more than O(N)
    vector<vector<int>> groupThePeople(vector<int>& groupSizes) {
        unordered_map<int,vector<int>>mp;
        int mini = INT_MAX,maxi=INT_MIN;
        
        for(int i=0;i<groupSizes.size();i++){
            maxi = max(maxi,groupSizes[i]);
            mini = min(mini,groupSizes[i]);
            mp[groupSizes[i]].push_back(i);
        }
        
        vector<vector<int>>res;
        
        for(int i=mini;i<=maxi;i++){
            int j=0;
            while(j<mp[i].size()){
               vector<int>temp;
               for(int count=0;count<i && j<mp[i].size();j++,count++) temp.push_back(mp[i][j]);
               res.push_back(temp);
            }
        }
        
        return res;
    }
    //TIME = O(N) SPACE - O(N)
    //BETTER VERSION
    vector<vector<int>> groupThePeople(vector<int>& groupSizes) {
        unordered_map<int,vector<int>>mp;
        vector<vector<int>>res;
        
        for(int i=0;i<groupSizes.size();i++){
            mp[groupSizes[i]].push_back(i);
            if(groupSizes[i]==mp[groupSizes[i]].size()){
                res.push_back(mp[groupSizes[i]]);
                mp[groupSizes[i]].clear();
            }
        }
        
        return res;
    }
};