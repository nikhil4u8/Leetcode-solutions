/*
Sol :
=> Using Stack - [TIME - O(N) SPACE - O(N)]
    - If '(' is found then add it to stack & pop it if found a complimentary
    ')' bracket for it.
    - Add ')' if there isn't any complimentary bracket to pair it up.
    - In end return size of stack as these number of brackets didn't had 
    complimentary brackets.


BEST APPROACH
=> Balance string - [TIME - O(N) SPACE - O(1)]
    - Instead of using stack, we can keep track of unmatched_open and 
    unmatched_close brackets by maintaining 2 variables.
    - If '(' comes then do unmatched_open++
    - If ')' comes & if unmatched_open > 0 then do unmatched_open--, 
    else unmatched_close++;


Edge case :
    - "((", "))", "())(("    

Follow up :
    - Multiple brackets? -> Use stack
    - Find if str is valid : Ref 20. Valid Parentheses
    - Find if str is valid with * : Ref 678. Valid Parenthesis String
    - Find score of str : Ref 856. Score of Parentheses
    - Len of longest valid str : 32. Longest Valid Parentheses
*/
class Solution {
public:
//TIME - O(N) SPACE - O(1)
    int minAddToMakeValid(string s) {
        int unmatched_open = 0, unmatched_close = 0;
        for(int i=0;i<s.length();i++){
            //currently '(' doesn't have complimentary ')' so increment 
            //unmatched_open
            if(s[i] == '(') unmatched_open++;
            else if(s[i] == ')'){
                //We found ')' bracket to balance it up with '(', so 
                //decrement
                if(unmatched_open > 0) unmatched_open--;
                //There is close paran but there isn't an open one to 
                //balance it out so increment unmatched_close
                else unmatched_close++;
            }
        }

        return unmatched_open + unmatched_close;
    }
};