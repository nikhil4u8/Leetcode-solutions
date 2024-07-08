/*
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
    int calculate(string s) {
        stack<int>sta;
        int curr_val = 0, sign = 1;
        char ope = '+';
        
        for(int i=0;i<s.length();i++){
            char curr = s[i];
            
            if(isdigit(curr)) curr_val = curr_val*10 + (curr - '0');
            if(!isdigit(curr) || i == s.length()-1){
                if(curr == '('){
                    stack<char>temp_sta;
                    string temp_str = "";
                    temp_sta.push(s[i++]);
                    
                    while(!temp_sta.empty()){
                        if(s[i] == ')') temp_sta.pop();
                        else if(s[i] == '(') temp_sta.push(s[i]);
                        if(!temp_sta.empty())
                            temp_str += s[i];
                        i++;
                    }
                    
                    curr_val = calculate(temp_str);
                    curr = s[i];
                }
                
                
                if(ope == '+') sta.push(curr_val);
                else if(ope == '-') sta.push(-curr_val);
                else if(ope == '*'){
                    int last = sta.top(); sta.pop();
                    sta.push(last * curr_val);   
                }else if(ope == '/'){
                    int last = sta.top(); sta.pop();
                    sta.push(last / curr_val);
                }
                
                ope = curr;
                curr_val = 0;
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