/*
Ques to ask : 
    - Does string contains blank spaces or multiple type of brackets?
    - Can we've input = "+1" or "-1"?
    - Can there be 2 consecutive operator in input? Is input is valid?
    - Can we've number > INT_MAX or < INT_MIN?

Sol : 
BEST APPROACH
=> Using Stack and recusion : [TIME - O(N) SPACE - O(N)]
Step 1: Only '+' is present
    - If we've only '+', then while traversing string, if we prev operator,
    as '+' then put curr number in a stack & return sum(stack)

Step 2 : Only '+', '-' present
    - We still view it as last case, like "3 - 1" is same as "3 + (-1)", 
    we when we encounter prev operation as '+' or '-', we'll combine 
    previous operation & curr number & put it in stack  & return sum(stack)

Step 3 : Only '+', '-', () present
    - When we encounter space we'll skip it
    - When we encounter a sign then we'll process element which is associated 
    with prevSign then update prevSign with current Sign.
    - When we encounter (), then we'll take the whole string inside bracket 
    and recursively call calculate fun to solve that string, then add result 
    to and according to the sign outside of bracket.

Follow up:
    - When string contains '+', '-', '*', '/'?
        -> Ref : 227. Basic Calculator II
    - When string contains (), '+', '-'?
        -> Ref : 224. Basic Calculator
    - When string contains (), '+', '-', '*', '/'?
        -> Ref : 772. Basic Calculator III
    - When string contains '+', '-', '*', '/', '^'?
        -> Ref : Basic Calculator IV
    - When string contains (), '+', '-', '*', '/', '^'?
        -> Ref : Basic Calculator V
    - A num is given in form of string, add operator in it st it evalutate
    to target?
        -> Ref : 282. Expression Add Operators
*/
class Solution {
public:
//BEST APPROACH
//TIME - O(N) SPACE - O(N)
    bool isDigit(char c){
        return c >= '0' && c <= '9';
    }
    bool isOperator(char c){
        return c == '+' || c == '-';
    }
    int calculate(string s) {
        int ans = 0, num = 0, n = s.length();
        char prevSign = '+';

        for(int i=0;i<s.length();i++){
            if(s[i] == ' ' && i != n-1) continue;

            if(isDigit(s[i])) num = num*10 + (s[i] - '0');
            if(isOperator(s[i]) || i == n-1){
                ans += prevSign == '-' ? -num : num;
                num = 0;
                prevSign = s[i];
            }else if(s[i] == '('){
                int balance = 1;
                i++;
                string tempStr = "";

                //collecting string inside bracket
                while(!sta.empty()){
                    if(s[i] == '(') balance++;
                    else if(s[i] == ')') balance--;
                    if(balance == 0) break;

                    tempStr += s[i++];    
                }

                int tempAns = calculate(tempStr);
                ans += prevSign == '-' ? -tempAns : tempAns;
            }
        }

        return ans;
    }
};