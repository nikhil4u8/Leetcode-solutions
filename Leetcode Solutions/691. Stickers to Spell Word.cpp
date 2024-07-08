/*
Ques to ask :
    - Can 'a' in stickers match with 'A' in target?
    - Can we use a word from sticker multiple times?
    - What to return when target can't be formed using stickers?
    - If input = ["with"], target = "tw", does the ans = 1?

Sol : 
=> Backtracking : [TIME - O(M^N) SPACE - O(26*M)]
-> M : len of sticker
-> N : len of target
-> TC : For each of the n positions of the target string we have m stickers 
to choose from, so m * m * m..(n times) = m^n.

    - Create a freq map of all the char which we've in sticker array
    - Traverse each character of the target, and maintain a char available 
    array.
        - if we've character in our charAvailable array then we'll just 
        remove currChar from charAvailable & recursively call our DFS fun 
        to process next char in target str.
        - If currChar doens't exist in charAvailable array, then we've to 
        find all words in sticker array which contains that char and for 
        each word add freq of all char present in that word to charAvailable 
        array & increment the sticker used count too, then call DFS fun
        recursively to process next char in target str.
    - In end we'll keep track of min stickers used and return it.
*/
class Solution {
public:
    unordered_map<string, int> dp;
    int helper(unordered_map<int, unordered_map<int, int>>& countMap, string target) {
        if (dp.count(target)) return dp[target];

        int ans = INT_MAX, n = countMap.size();
        vector<int> tar(26, 0);

        for (char c:target) tar[c-'a']++;

        // try every sticker
        for (int i = 0; i < n; i++) {
            // optimization
            if (countMap[i][target[0]-'a'] == 0) continue; 

            string s;
            // apply a sticker on every character a-z
            for (int j = 0; j < 26; j++) 
                if (tar[j] - countMap[i][j] > 0) 
                    s += string(tar[j] - countMap[i][j], 'a'+j);

            int tmp = helper(countMap, s);
            if (tmp!= -1) ans = min(ans, 1+tmp);
        }

        dp[target] = ans == INT_MAX? -1:ans;
        return dp[target];
    }
    int minStickers(vector<string>& stickers, string target) {
        int m = stickers.size();
        unordered_map<int, unordered_map<int, int>>countMap;

        // count characters a-z for each sticker 
        for (int i = 0; i < m; i++) 
            for (char c:stickers[i]) countMap[i][c-'a']++;

        dp[""] = 0;
        return helper(countMap, target);
    }
};