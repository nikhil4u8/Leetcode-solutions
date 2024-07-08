class Solution {
public:
//TIME - O(N) SPACE - O(1)
//to make it smallest possible just replace the first non 'a' char with 'a', in case if all letters
//are 'a' then replace the last one with 'b'
    string breakPalindrome(string palindrome) {
        int n = palindrome.length();
        for(int i=0;i<n/2;i++){
            if(palindrome[i] != 'a'){
                palindrome[i] = 'a';
                return palindrome;
            }
        }
        if(n != 1){
            palindrome[n-1] = 'b';
            return palindrome;
        }
        return "";
    }
};