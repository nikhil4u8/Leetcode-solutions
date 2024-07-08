class Solution {
public:
    bool ispalin(string s){
        int l=0,r=s.length()-1;
        while(l<r){
            if(s[l++]!=s[r--]) return false;
        }
        
        return true;
    }
    int removePalindromeSub(string s) {
        //if string is palindrome then return 1
        //if string is not palindrome then remove all 'a' and then remove all 'b' so return 2
        return ispalin(s) ? 1 : 2;
    }
};
**FOLLOW-UP
    1.if all the character are used
        we can use dp for finding longest palindrome then by using recursion we can do that