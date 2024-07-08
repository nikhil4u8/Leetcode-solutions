/*
Sol :
    - Maintain a map having freq & first index of all character
    - traverse the freq map and find min index of char whose freq == 1
*/
class Solution {
public:
//TIME - O(N) SPACE - O(26)
    int firstUniqChar(string s) {
        unordered_map<char, pair<int,int>>mp;
        for(int i=0;i<s.length();i++){
            if(mp.find(s[i]) != mp.end()) mp[s[i]].first++;
            else mp[s[i]] = {1, i};
        }

        int mini = INT_MAX;
        for(auto it : mp){
            if(it.second.first == 1 && it.second.second < mini) mini = it.second.second;
        }

        return mini == INT_MAX ? -1 : mini;
    }
};