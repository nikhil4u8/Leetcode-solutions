/*
Ques to ask : 
    - What if string is already palindrome
    - Can string contains spaces or special char or numbers?
    - Is 'a' & 'A' same?

Sol :
=> Brute force [TIME - O(N^2) SPACE - O(1)]
    - Traverse the string & remove each char & check if str is Palin or not
    - If in end str is not Palin after removing 1 char, check if whole str
    is Palin or not, if it is then return true, else false

BEST APPROACH
=> Optimised [TIME - O(N) SPACE - O(1)]
    - Maintain 2 pointer, left / right, & move inwards.
    - Whenever there is a mismatch, we can exclude the char at left or
    right and see if the remaining substr is Palin or not, if it is then
    return true, else false

Follow up : 
    - Return how many min char removal required to make it Palindrome. 
    (Solve using DP : See 1143. Longest Palindromic Seq)
    - Delete atmost K to make it palindrome
        -> Ref : 1216. Valid Palindrome III
    - if a string is infinitely large and you cannot load it all in RAM 
    and can only access blocks of string which will contain some k 
    contiguous chars. 
        -> Access 1st and last block and keep checking
*/
class Solution {
public:
//TIME - O(N) SPACE - O(1)
    bool checkPalin(string s, int i, int j){
        while(i<j){
            if(s[i] != s[j]) return false;
            i++;
            j--;
        }
        return true;
    }
    bool validPalindrome(string s) {
        int i = 0, j = s.length()-1;
        while(i < j){
            //When char are unequal then we need to check removing both char one by one if 
            //str becomes palindrome or not, if it does then return true
            if(s[i] != s[j]) return checkPalin(s, i, j-1) || 
                                    checkPalin(s, i+1, j);
            
            i++;
            j--;
        }

        return true;
    }
};

//FOLLOW UP - 2
//DELETE AT MOST K

class Solution {
    bool helper(String s, int i, int j, int k) {
        if (j <= i) return true;
        
        while (i < j) {
            if (s[i] != s[j]) {
                //further char can't be removed
                if (k == 0) return false;
                
                //decrement k & check if by removing a char str become Palin
                k--;
                return helper(s, i + 1, j, k) || helper(s, i, j - 1, k);
            }
            i++;
            j--;
        }
        
        return true;
    }
    bool validPalindrome(String s) {
        if (s == null || s.isEmpty()) {
            return true;
        }
        
        return helper(s, 0, s.length() - 1, 1);
    }
}