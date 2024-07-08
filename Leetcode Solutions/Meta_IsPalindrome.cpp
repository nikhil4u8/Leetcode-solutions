/*
Ques to ask : 
    - What if string is already palindrome

Sol :
    - There can be many test cases, and any char removal is possible, so 
    when char are unequal try removing each one of the char and see if str 
    becomes palin or not, if it does then return true, otherwise move on.

Follow up : 
    - Return how many min char removal required to make it Palindrome. 
    (Solve using DP : See 1143. Longest Palindromic Seq)
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