/*
Ques to ask :
    - Can n == 0?
    - What is the limit of n?

Sol :
=> Following Rule : [TIME - O(2^N) SPACE - O(1)]
-> TIME explanation below
    - Run while loop from 1 to N, and start from initial str = "1" &
    traverse it & count freq of adjacent similar digits then append 
    "freq + digit" in new str, similar convert whole str.
    - for next iteration make the output of curr iteration as input of
    next iteration. 
*/
class Solution {
public:
    string countAndSay(int n) {
        int tempN = 1;
        string str = "1";

        while(tempN < n){
            int i = 1, freq = 1;
            string tempStr = "";

            while(i <= str.length()){
                if(i < str.length() && str[i] == str[i-1]) freq++;
                else{
                    tempStr += to_string(freq) + str[i-1];
                    freq = 1;
                }
                i++;
            }

            str = tempStr;
            tempN++;
        }

        return str;
    }
};
/*
TIME :
We can assume that in worst case the current string does not have any adjacent 
chars that are similar, say '121'. With this logic, the length of the string would 
get doubled every time i.e. '111211'. So the length of the strings would be 
1,2,4,8,16,... - so for each word we need to traverse it which takes O(len)
time, hence TC = O(2^0) + O(2^1) + O(2^2) + ... + O(2^N) = O(2^(n+1)) 
TC = O(2^N)

SPACE : 
For each N, we'll require 2^N str space for tempStr, so worst case 
space = 2^N
*/