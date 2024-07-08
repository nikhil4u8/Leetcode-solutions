/*
Sol :
=> Counting char in str : [TIME - O(N) SPACE - O(1)]
    - Finding freq of all char in str, if string is of even len then every
    char should occur even times, if string is of odd len then only one 
    char should occur odd number of times.
*/
class Solution {
public:
    bool canPermutePalindrome(string s) {
        unordered_map<char, int>mp;
        for(int i=0;i<s.length();i++) mp[s[i]]++;
        
        int count = 0;
        for(auto it : mp){
            if(it.second % 2 == 1) count++;
        }

        return s.length() % 2 == 0 ? count == 0 : count == 1;
    }
};