/*
Ques to ask :
    - Does s & p contains both lower / upper case? And are both considered 
    same or not?

Sol :
=> Generate all possible continous substring
    - Since anagrams of p shares the same length as p, so we'll Generate 
    all possible continous substring of len p from string s, and check if 
    it's a anagram or not, if it is then add starting idx to ans.

BEST APPORACH
=> Sliding window : [TIME - O(N) SPACE - O(26)]
    - Since in previous approach, we'll have to traverse through so many 
    char again & again. To avoid this we can use a sliding window of 
    size(p) instead.
    - Firstly, store freq of char of p in a map.
    - Then create a window of len size(p), then in each iteration expand 
    the window to right to explore more anagrams meanwhile shrinking the 
    window from left to maintain window size. And for each window we'll 
    check if it's a anagram or not.
*/
class Solution {
public:
//BEST APPROACH
//TIME - O(N) SPACE - O(26)
    vector<int> findAnagrams(string s, string p) {
        int n = s.length(), m = p.length();
        //storing freq of char in p
        //Increment to setup hash of all characters currently in the window. 
        //Later on, these get DECREMENTED when a character is found
        //Positive count later on means that the character is still "needed" 
        //in the anagram
        //Negative count means that either the character was found more 
        //times than necessary Or that it isn't needed at all
        unordered_map<char, int>freq;
        for(int i=0;i<m;i++) freq[p[i]]++;

        vector<int>ans;
        int start = 0, end = 0;

        //Before we begin this, the "window" has a length of 0, start and 
        //end pointers both at 0, last char is processed in next loop
        while(end < m - 1){
            //decrementing freq of processed char
            freq[s[end]]--;
            //if char processing is finished remove it from map since this 
            //char is not needed anymore, removal is necessary so that when 
            //a anagram is found map should be empty.
            if(freq[s[end]] == 0) freq.erase(s[end]);
            end++;
        }

        //Here, we'll just increment start / end one by one, and at every 
        //point we'll check if map is empty or not, if it is then we've 
        //found our idx, if there is some element left then this window is 
        //not a anagram
        while(end < n){
            freq[s[end]]--;
            //removal is necessary so that when a anagram is found map 
            //should be empty.
            if(freq[s[end]] == 0) freq.erase(s[end]);

            if(freq.empty()) ans.push_back(start);

            freq[s[start]]++;
            if(freq[s[start]] == 0) freq.erase(s[start]);

            //increment window by one char
            start++;
            end++;
        }

        return ans;
    }
};