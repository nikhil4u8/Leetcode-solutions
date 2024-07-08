class Solution {
public:
// TIME - O(2^N) SPACE - O(N)
/*In the worst case, our algorithm will exhaust all possible 
combinations from the input array. Again, in the worst case, 
let us assume that each number is unique. The number of 
combination for an array of size NNN would be 2N2^N2 N, i.e. 
each number is either included or excluded in a combination.
*/
    set<vector<int>>ans;
    void getSumWays(vector<int>temp, int target, unordered_map<int, int>mp){
        if(target <= 0){
            if(target == 0){
                sort(temp.begin(), temp.end());
                ans.insert(temp);
            }
            return;
        }

        for(auto it : mp){
            if(it.second <= 0 || target<it.first) continue;

            mp[it.first]--;
            temp.push_back(it.first);
            getSumWays(temp, target-it.first, mp);
            temp.pop_back();
            mp[it.first]++;
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {       
        unordered_map<int, int>mp;
        for(int i=0;i<candidates.size();i++) mp[candidates[i]]++;

        getSumWays({}, target, mp);
        return vector(ans.begin(), ans.end());
    }
};