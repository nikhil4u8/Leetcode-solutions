/*
Ques to ask : 
    - What about the duplicates in t? Do we need to match those too?
    - What if there are multiple substr? Which one to return?
    - What if no such str exist?
    - Can 'a' in T match with 'A' in S?

Sol : 
=> Checking every substr : [TIME - O(N^2*M) SPACE - O(1)]
-> N : len of S
-> M : len of T
    - For every substr in S, we've to check if T is present of not, if yes, 
    then keep track of smallest such substr, else move on to next substr

=> Sliding window : [TIME - O(N + M) SPACE - O(26)]
    - Create a freq map, and take 2 pointer, left & right to keep track of 
    window which have all the char present in T.
    - Move the right pointer until we've found all element in T, then move 
    left pointer to remove elements from start then start moving right again 
    until we've found all element in T.
    - Meanwhile keep track of smallest window in which all elements of T
    are found.
*/
class Solution {
public:
    string minWindow(string s, string t) {
        int n = s.length(), m = t.length();

        unordered_map<char, int>freq;
        //time - O(T len)
        for(int i=0;i<m;i++) freq[t[i]]++;

        int start = 0, end = 0, ans_start = 0, min_window_len = INT_MAX;
        int count = freq.size();
        string ans = "";

        //time - O(2*S_len)
        while(end < n){
            // moving right pointer until count == 0
            freq[s[end]]--;
            if(freq[s[end]] == 0) count--;

            //when we've found perfect window then start moving left ptr until 
            //perfect window remains
            while(count == 0){
                if(min_window_len > end - start + 1){
                    min_window_len = end - start + 1;
                    ans_start = start;
                }

                freq[s[start]]++;

                if(freq[s[start]] > 0) count++;
                start++;
            }

            end++;
        }
        
        if(min_window_len == INT_MAX) return "";
        return s.substr(ans_start, min_window_len);
    }
};