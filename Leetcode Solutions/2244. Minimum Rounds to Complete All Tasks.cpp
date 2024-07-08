class Solution {
public:
// TIME - O(N) SPACE - O(N)
    int minimumRounds(vector<int>& tasks) {
        unordered_map<int, int>mp;
        int count = 0;

        for(int i=0;i<tasks.size();i++) mp[tasks[i]]++;
        for(auto it : mp){
            if(it.second == 1) return -1;
            if(it.second%3 == 0) count += it.second/3;
            else count += it.second/3 + 1;

            cout<<it.second<<" "<<count<<"\n";
        }

        return count;
    }
};