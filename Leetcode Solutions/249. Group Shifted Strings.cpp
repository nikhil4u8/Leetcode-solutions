/*
Ques to ask :
    - Is there any upper case in string?
    - Is 'dcb' -> 'cba' valid example?
    - Is "acb"->"bdc" valid example?
    - Can we've duplicate str in array, like "a", "a", are they grouped 
    together?
    - What if one of the input string is empty string?
    - What happens when we hit z? Ex: 'abc'...'xyz' what after this?
    - Does the output needs to be sorted?

Sol :
SAY THIS FIRST
- A seq is something that from wherever you start from, at the end you 
should come back to the point where you start from, 
Ex : "abc" -> "bcd" ->.....-> "xyz" -> ... -> "abc"
     "a" -> "a" -> "a" : Self looping

- Here a seq means the relative distance of the character a string is the 
same & we use the first character in a string as a reference for each 
string.


=> Generating all seq : [TIME - O(26*N) SPACE - O(N) -> visited array]
    - Traverse the string array & for every string we'll generate whole 
    seq considering strs[i] as starting point & find all the string 
    present in array who're a part of the seq & group them together & mark 
    them visited
    - Move on to the next string in array & if it's not visited then 
    repeat step 1 else ignore it


BEST APPROACH
=> Grouping string using hash : 
-> [TIME - O(N*L) SPACE - O(N*L)], L->len of longest str
    - In above approach, if you notice then in every seq one thing which 
    remain constant is the delta between consecutive letter of each str in 
    seq.
    - We can use hashmap to group string, but for that we need some hash 
    val i.e some criteria to grp strings. Then return all hashmap.values()
    - The key can be represented as a tuple of "difference" b/w adjacent 
    char in a str
    - Convert the tuple to string & use it as key in hashmap.
    - For cases when seq is decreasing direction i.e for -ve differences, 
    we need to increment them by 26 to keep all differences positive. 
    - EDGE CASE : 'az' -> 'ba', initially diff = 25 (since a->b->c->x->z->a
    if cyclic, so if z = 1, a = 2, b = 3 i.e diff b/w 'z'/'a' will be -1), 
    next diff b/w 'b'/'a' = -1, so to avoid -ve diff we'll store 
    diff = (26 + s[i] - s[i-1])%26

Edge Case : 
    - "ba", "az", "zx"
    - ""
    - "abc", "abc" 
        -> a seq generate from "abc" contains "abc", hence grouped 
        together.
*/
class Solution {
public:
//TIME - O(N*L) SPACE - O(N*L), L->len of longest str
    string getDiffKey(string str){
        string ans = "";
        for(int i=1;i<str.length();i++)
            ans += to_string((26 + str[i] - str[i-1])%26) + ",";
        
        if(!ans.empty()) ans.pop_back();
        return ans;
    }
    vector<vector<string>> groupStrings(vector<string>& strings) {
        unordered_map<string, vector<string>>mp;
        
        for(int i=0;i<strings.size();i++){
            string str = strings[i];
            string diffKey = getDiffKey(str);
            
            mp[diffKey].push_back(str);
        }

        vector<vector<string>>ans;
        for(auto it : mp) ans.push_back(it.second);
        return ans;
    }
};