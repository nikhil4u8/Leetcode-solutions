/*
Ques to ask :
    - If a char is present in s but not in order?
    - Can s / order str have any special char? Or blank space?
    - What if order has duplicate char? like "xax"
Sol :
=> Using custom sort : [TIME - O(NlogN) SPACE - O(1)]
    - Use hashmap to store position of each char in order str, then sort 
    the str using the comparator function which uses the map to determine 
    the order.

BEST APPROACH
=> Using frequency of each char : [TIME - O(N) SPACE - O(1)]
    - Instead of sorting, we can simply store freq of char present in str 
    in a vector
    - Then while traversing order string, if order[i] is present in str, 
    then we'll add that char to result str, and in end add all left over 
    char which aren't there in order string.

Follow up :
    - The char of str which aren't present in order str must be sorted as 
    per English Alphabet order.
        -> simply traverse freq vector from 0th idx & start adding all char
*/
class Solution {
public:
//Approach - 2
//TIME - O(N) SPACE - O(1)
    string customSortString(string order, string str) {
        vector<int>count(26, 0);     
        //storing freq of char in str   
        for(int i=0;i<str.length();i++) count[str[i]]++;
        
        string result = "";
        //adding char as per the order mention in order string
        for(int i=0;i<order.length();i++) {
            char ch = order[i];
            while(count[ch-'a']--) result += ch;
        }
        
        //Add the characters which are not present in "order"
        for(int i=0;i<str.length();i++) {
            while(count[ch-'a']--) result += ch;
        }
        
        return result;
    }
//Approach - 1 
//TIME - O(NlogN) SPACE - O(1)
    string customSortString(string order, string s) {
        vector<int>ordering(26, INT_MAX);
        for(int i=0;i<order.length();i++) ordering[order[i] - 'a'] = i;

        auto cmp = [&](char &a, char &b) {
            return ordering[a-'a'] < ordering[b-'a'];
        };

        sort(s.begin(), s.end(), cmp);
        return s;
    }

//FOLLOW UP
    string customSortString(string order, string str) {
        vector<int> index(26, INT_MAX);
        
        for(int i = 0; i<order.length(); i++) index[order[i]-'a'] = i;
        
        auto lambda = [&](char &ch1, char &ch2) {
            //char not in order str, sorted as per english order
            if(index[ch1-'a'] == index[ch2-'a'])
                return ch1 < ch2;    
            return index[ch1-'a'] < index[ch2-'a'];
        };
        
        sort(begin(str), end(str), lambda);
        return str;
        
    }
};