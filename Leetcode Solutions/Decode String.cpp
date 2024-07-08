/*
TIME - O(maxK^countK * N)
SPACE - O(1) | O(N) -> recursive stack

maxK -> max val of K
countK -> count of nested K values
N -> max len of encoded string

Ex - 20[a10[bcd]] -> maxK = 20, countK = 2, N -> 3


Desc :- 
    - k >= 0
    - Max len of output <= 10^5
    - Int in s belongs to [1, 300]
    - s consist of lower case letters, digit, square brackets.
    - s.length() <= 30

Ques to ask :-
    - Can any no be negative / 0 / 1, or no number before bracket.
    - Can there be other type of bracket except '[]'.
    - Can there be input like 3a / 2[4] / [abcd].
    - Can k be double digit.
    - Can there be white spaces?
    - Can string be empty?

Sol :-
    - We'll firstly check if there is a number or not, if there is no number
    present then we'll just add it to ans string, otherwise, first we'll find
    the number and then find the internal string and recursively call decodeString
    to find decoded string of substring, and add it K times to original string.
    
Edge cases :-
    - Empty string, 1[a], 0[a], 3
*/
class Solution {
public:
    string decodeString(string s) {
        string ans = "";

        for(int i=0;i<s.length();i++){
            int n = 0;
            while(i<s.length() && s[i]>='0' && s[i]<='9') n=n*10+(s[i++]-'0');

            if(s[i] == '['){
                string temp_str = "";
                int balance = 1;
                i++;

                while(balance != 0){
                    if(s[i] == '[') balance++;
                    else if(s[i] == ']') balance--;
                    if(balance == 0) break;
                    
                    temp_str += s[i++];
                }

                temp_str = decodeString(temp_str);
                while(n--) ans += temp_str;
            }else ans += s[i];
        }

        return ans;
    }
};