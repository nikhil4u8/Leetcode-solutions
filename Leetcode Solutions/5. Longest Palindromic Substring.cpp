// TIME - O(N^2) SPACE - O(1)
class Solution {
public:
    string max_str = "";
    void expand(string str, int start, int end){
        while(start>=0 && end<str.length() && str[start] == str[end]){
            start--;
            end++;
        }
        int len = end-start-1;
        if(max_str.length() < len) max_str = str.substr(start+1, len);
    }
    string longestPalindrome(string s) {
        for(int i=0;i<s.length();i++){
            expand(s, i, i);
            if(i>0) expand(s, i-1, i);
        }
        
        return max_str;
    }
};