class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        vector<int> ans;
        sort(arr.begin(),arr.end());
        map<int,vector<vector<int> > > mp;
        
        for(int i=1;i<arr.size();i++){
            mp[arr[i] - arr[i-1]].push_back({arr[i-1] , arr[i]});
        }

        return mp.begin()->second;
    }
};