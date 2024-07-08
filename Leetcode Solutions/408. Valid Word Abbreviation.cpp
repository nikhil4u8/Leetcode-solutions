/*
Ques to ask :
    - Does words / abbr contains upper case? Do we've to treat upper / lower
    case differently?
    - Can word str contains digits too?
    - Does word str contain one word or multiple word?
    - Can word str contain other char like '.' / ',' / '@' ?
    - Can "aa" match to "11" [a -> 1, a -> 1]?
    - Can we match "a" to "1", "01", "a0"?
    - are leading "0" allowed in abbr string?
    - What is abbr str length? (used in TC / SC)

Sol : 
    - When abbr mismatches word, then check if abbr has digit or not, if 
    it has digits then find the num and increment word pointer by that
    digit to skip those, at the end check if both the pointer reached 
    the end of the word or not.

Edge case :
    - Can we match "a" to 01 / a0 / 1?
    - "hi" , "2i"
    - "hi" , "1"
    - leading 0 ?
    - len of digit > len of word, can digit cross INT_MAX?
*/
class Solution {
public:
//TIME - O(min(len of word, len of abbr))
//SPACE - O(len of abbr) -> space for storing num
    bool validWordAbbreviation(string word, string abbr) {
        int j = 0, i = 0;
        while(i<abbr.length() && j<word.length()){
            if(abbr[i] != word[j]){
                //if abbr is different and not a digit then false
                if(!(abbr[i] >= '0' && abbr[i] <= '9')) return false;
                if(abbr[i] == '0') return false;

                int n = 0;
                while(i<abbr.length() && abbr[i] >= '0' && abbr[i] <= '9')
                    n = n*10 + (abbr[i++]-'0');
                
                j += n;
            }else{
                i++;
                j++;
            }
        }
        
        return i == abbr.length() && j == word.length();
    }
};