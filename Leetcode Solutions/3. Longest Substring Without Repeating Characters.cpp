1. First, try every substring using 2 for loops
    Check if each substring is "valid"
    If valid, update our "best" result
    TIME - O(n^3)

2.Second, why not "expand" a window from each character?
    We loop over each character and call a function to "expand" a window
    We try to increment the window by one to the right, if we ecounter a duplicate value, we stop
    TIME - O(N^2)

//BEST SOLUTION
3.We can optimise sliding window technique
    scan the string from left to right and keep track of index of every char
    and if we see any char already appeared then we make our window small and start
    our new window from index_of_repeated_char + 1
    And find maximum length
    TIME - O(N) SPACE - O(N)

**FOLLOW-UP
1. Input is an infinite stream
    same code also string can be stored in linked list form
2. If at most K same elements are allowed in window?


class Solution {
public:
//TIME - O(N) SPACE - O(1)
//Sliding window method & Follow Up - 1 / 2 covered
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int>mp;
        int window_start = 0, max_window_len = 0;

        for(int i=0;i<s.length();i++){
            //increasing freq of element in mp
            mp[s[i]]++;

            //Follow Up : If asked that atmost K elements are allowed 
            //in widnow then change 2 to K

            //if a repeated char is found, then make window small until 
            //we reach the repeated char, since we can't include that
            while(mp[s[i]] >= 2) mp[s[window_start++]]--;

            //finding max len of window
            max_window_len = max(max_window_len, i - window_start + 1);
        }

        return max_window_len;
    }
};

//BRUTE FORCE -> checking all substring if they're a fit or not
//TIME - O(N^3) SPACE - O(M)
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.length();

        int res = 0;
        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {
                if (checkRepetition(s, i, j)) {
                    res = max(res, j - i + 1);
                }
            }
        }

        return res;
    }

    bool checkRepetition(string& s, int start, int end) {
        vector<int> chars(128);

        for (int i = start; i <= end; i++) {
            char c = s[i];
            chars[c]++;
            if (chars[c] > 1) {
                return false;
            }
        }

        return true;
    }
};