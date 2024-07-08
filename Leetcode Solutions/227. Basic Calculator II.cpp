/*
Ques to ask :
    - Do we need to solve experssion as per BODMAS or linearly? Which one 
    has higher precedance / or * and + or - ? What will be the output of 
    2*5/3 = 3 (* priority) or 2 (/ priority)?
    - Do we have negative number?
    - What to do when /0?
    - What if multiplication result in number > INT_MAX?
    - What happens in case of 6/4? Rounding off decimal output?
    - Is there any white space? Is there any brackets?
    - Is str a valid string? 

Sol :
SAY IN THIS MANNER
=> Using Stack : [TIME - O(N) SPACE - O(N)]
Step 1: Only '+' is present
    - If we've only '+', then while traversing string, if we prev operator,
    as '+' then put curr number in a stack & return sum(stack)

Step 2 : Only '+', '-' present
    - We still view it as last case, like "3 - 1" is same as "3 + (-1)", 
    we when we encounter prev operation as '+' or '-', we'll combine 
    previous operation & curr number & put it in stack  & return sum(stack)

Step 3 : '+', '-', '*', '/' present
    - When we encounter any number , so we need to consider prev operation. 
    If prev operation is '+' / '-' then simply combine it with curr number 
    & put it in stack, if prev operation is '*', '/', then to perform 
    these operation we need prev num too which is top element of stack, 
    then perform operation & put result back in stack.


BEST APPROACH
=> Using Two Pointer : [TIME - O(N) SPACE - O(1)]
    - If we look then stack is used to store all the number with previous 
    operation '+'/'-' or calculated from '*', '/', it's mainly used to 
    know the previous number for '*','/' calculation.
    - To satisfy above purpose, use a variable to keep track of top 
    element in stack & instead of storing every number in stack except 
    the top one, we can maintain another variable to store the sum of all 
    num in stack which won't be used in current / next operations. 
    Anyway, at the end we need to sum everything right.

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
//Approach 2
//TIME - O(N) SPACE - O(1)
    int calculate(string s) {
        int result = 0, currNum = 0, prevNum = 0, n = s.length();
        char prevOperation = '+';

        for(int i=0;i<n;i++){
            if(s[i] == ' ' && i != n-1) continue;
            if(s[i] >= '0' && s[i] <= '9') currNum = currNum*10 + (s[i] - '0');
            if(!(s[i] >= '0' && s[i] <= '9') || i == n-1){
                if(prevOperation == '+' || prevOperation == '-'){
                    result += prevNum;
                    currNum = prevOperation == '-' ? -currNum : currNum;
                }else
                    currNum=prevOperation == '*' ? prevNum*currNum : prevNum/currNum;

                prevNum = currNum;
                prevOperation = s[i];
                currNum = 0;
            }
        }

        result += prevNum;
        return result;
    }
//Approach 1
//TIME - O(N) SPACE - O(N)
    int calculate(string s) {
        stack<int>sta;
        int curr = 0, n = s.length();
        char prev_sign = '+';

        for(int i=0;i<s.length();i++){
            if(s[i] == ' ' && i != n-1) continue;
            if(s[i] >= '0' && s[i] <= '9') curr = curr*10 + (s[i] - '0');
            if(!(s[i] >= '0' && s[i] <= '9') || i == n-1){
                if(prev_sign == '-') curr *= -1;
                else if(prev_sign == '*'){
                    curr *= sta.top();
                    sta.pop();
                }else if(prev_sign == '/'){
                    curr = sta.top() / curr;
                    sta.pop();
                }

                sta.push(curr);
                prev_sign = s[i];
                curr = 0;
            }
        }

        int ans = 0;
        while(!sta.empty()){
            ans += sta.top();
            sta.pop();
        }
        
        return ans;
    }
};