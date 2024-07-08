/*
Ques to ask:
    - Can string contains spaces or special char or numbers?
    - Is 'a' & 'A' same?

Follow up : 
    - Return how many min char removal required to make it Palindrome. 
    (Solve using DP : See 1143. Longest Palindromic Seq)
    - Delete atmost 1 char to make it palindrome
        -> Ref : 680. Valid Palindrome II
    - Delete atmost K to make it palindrome
        -> Ref : 1216. Valid Palindrome III
*/
class Solution {
public:
//TIME - O(N) SPACE - O(1)
    bool isPalindrome(string s) {
        int start = 0, end = s.length()-1;
        transform(s.begin(), s.end(), s.begin(), ::tolower);

        //convert all char to lowercase
        //skip all char who aren't alphabets or numbers
        //check for other characters
        while(start < end){
            if(!((s[start] >= 'a' && s[start] <= 'z') ||
                (s[start] >= '0' && s[start] <= '9'))){
                start++;
                continue;
            }
            if(!((s[end] >= 'a' && s[end] <= 'z') || 
                (s[end] >= '0' && s[end] <= '9'))){
                end--;
                continue;
            }

            if(s[start] != s[end]) return false;
            start++;
            end--;
        }

        return true;
    }
};