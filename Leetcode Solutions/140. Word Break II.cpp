/*
Ques to ask:
    - Does the word in string & wordDict needs to be case (lowercase 
    can't be matched to uppercase) matched too?
    - Can we use a word in dict multiple times in segmentation?
    - Can we've duplicates in wordDict?
    - What if empty string is given as input?
    - Can we've "" in wordDict?
    - In what order do we need to return output.

Sol :
BEST APPROACH
=> DFS : [TIME - O(2^N) SPACE - O(2^n)] -> see explantion below
-> N is len of s
    - We can simply start traversing the string, until we find a word
    which exist in wordDict, and for rest of the string we can call same 
    recursive fun to find the segmented string & then combine the curr str
    & segmented str which came from recursive fun & store this in 
    unordered set to avoid duplicate entries
    - We'll store wordDict in a map to access words fast as compared to
    an array
    - Convert unordered set to vector & return

PS : Search of the word can be done using Trie as well

Follow up :
    - Return true if string can be segmented?
        -> Ref : 139. Word Break
    - Return all the segmented string?
        -> Ref : 140 Word Break II
*/
class Solution {
public:
    //TIME - EXPONENTIAL -> 2^N
    unordered_map<string, int>mp;
    unordered_set<string>segments;
    void generateSegmentedString(string s, int idx, string tempStr){
        if(idx >= s.length()){
            tempStr.pop_back();
            segments.insert(tempStr);
            return;
        }
        
        string str = "";
        for(int i=idx;i<s.length();i++){
            str += s[i];
            if(mp[str] > 0)
                generateSegmentedString(s, i+1, tempStr + str + " ");
        }
    }
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        for(int i=0;i<wordDict.size();i++) mp[wordDict[i]]++;
        
        generateSegmentedString(s, 0, "");

        return vector<string>(segments.begin(), segments.end());
    }
};
/*
TIME COMPLEXITY EXPLANATION
Since str len = N.
In worst case, each segment of str is found in dict then we've to break
str in all possible segments, then we'd have 2^N paths.

T(N) -> time complexity of breaking str, in worst case each char is a
seperate segment.

T(N) = T(N-1) + T(N-2) + T(N-3) + ... T(1)
T(N-1) = T(N-2) + T(N-3) + ...

=> T(N) = 2*T(N-1) = 4*T(N-2) = 8*T(N-3) = 2^(n-1) * T(1) = 2^N 
T(N-1) = 2*T(N-2) = 4*T(N-3) 

SPACE COMPLEXITY EXPLANATION
Since we'll have 2^N recurisve calls, so stack space will be 2^n
*/