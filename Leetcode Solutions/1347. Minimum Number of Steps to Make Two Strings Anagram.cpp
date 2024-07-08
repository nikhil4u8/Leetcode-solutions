/*
Ques to ask :
    - What if len of both string are different?
*/
//TIME - O(N) SPACE - O(N)
class Solution {
public:
    int minSteps(string s, string t) {
        int count = 0;

        unordered_map<char, int>mp;
        for(int i = 0;i<s.length();i++) mp[s[i]]++;
        for(int i=0;i<t.length();i++){
            if(mp[t[i]] > 0) mp[t[i]]--;
            else count++;
        }

        return count;
    }
};