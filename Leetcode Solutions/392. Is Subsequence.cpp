class Solution {
public:
    bool isSubsequence(string str, string s) {
        int j=0,k=0;
        while(j<str.length() && k<s.length()){
            if(str[j] == s[k]) j++;
            k++;
        }
        
        return j == str.length();
    }
};