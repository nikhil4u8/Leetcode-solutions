/*
Ques to ask:
    - Does the word in string & wordDict needs to be case (lowercase 
    can't be matched to uppercase) matched too?
    - Can we use a word in dict multiple times in segmentation?
    - Can we've duplicates in wordDict?
    - What if empty string is given as input?
    - Can we've "" in wordDict?

Sol :
=> DFS with memo : [TIME - O(2^N) SPACE - O(2^n)] -> see explantion below
-> N is len of s
    - We can simply start traversing the string, until we find a word
    which exist in wordDict, and for rest of the string we can call same 
    recursive fun to check if it can be segmented or not, if it can be 
    segmented then return true, otherwise keep on traversing.
    - To save some time by not computing already computed cases, we can 
    do memoziation

Follow up :
    - Return true if string can be segmented?
        -> Ref : 139. Word Break
    - Return all the segmented string?
        -> Ref : 140 Word Break II
*/
class Solution {
public:
    unordered_map<string, int>mp;
    unordered_map<int, bool>memo;
    bool canBeSegmented(string s, int startIdx){
        if(startIdx >= (int)s.length()) return memo[startIdx] = true;

        if(mp[s.substr(startIdx)] == 1) return memo[startIdx] = true;
        if(memo.find(startIdx) != memo.end()) return memo[startIdx];

        string str = "";
        for(int i=startIdx;i<s.length();i++){
            str += s[i];
            if(mp[str] == 1 && canBeSegmented(s, i+1)) 
                return memo[startIdx] = true;
        }

        return memo[startIdx] = false;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        for(int i=0;i<wordDict.size();i++) mp[wordDict[i]]++;

        return canBeSegmented(s, 0);
    }
};
/*
TIME COMPLEXITY EXPLANATION
Since str len = N, so there are N+1 ways/intervals to partition it into 
2 parts. Each interval has 2 choices - split or not. In worst case we've 
to check all possibilities, which becomes O(2^(n+1)) -> O(2^n)
*/