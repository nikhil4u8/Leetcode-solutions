/*
Template - Clarifying Ques -> Approach desc -> Code for approach -> Follow-ups
*/
/*
Clarifying Ques - 1. Expression is valid or not?
                  2. Range of Tokens? Can there be integer overflow? 
                  3. What to do in case of dividing by zero?
*/
/*
Approach -
1. In-place evaluation 
2. Using Stack 
*/
class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        int top = 0;
        for(auto t : tokens){
            if(t == "+" || t == "-" || t == "*" || t == "/"){
                int n1 = stoi(tokens[--top]);
                int n2 = stoi(tokens[--top]);
                int res;
                
                if(t == "+") res= n1 + n2;
                else if(t == "-") res = n2 - n1;
                else if(t == "*") res = n1 * n2;
                else res = n2 / n1;
                tokens[top++] = to_string(res);
            }else tokens[top++] = t;
        }
        
        return stoi(tokens[0]);
    }
    //Using Stack
    //TIME - O(N) SPACE - O(N)
//     int evalRPN(vector<string>& tokens) {
//         stack<int>sta;
        
//         for(int i=0;i<tokens.size();i++){
//             string symbol = tokens[i];
//             if(symbol == "+" || symbol == "-" || symbol == "*" || symbol == "/"){
//                 int n1 = sta.top(); sta.pop();
//                 int n2 = sta.top(); sta.pop();
                
//                 if(symbol == "+") sta.push(n1+n2);
//                 else if(symbol == "-") sta.push(n2-n1);
//                 else if(symbol == "*") sta.push(n1*n2);
//                 else sta.push(n2/n1);
//             }else{
//                 int n = 0, i=0,sign = 1;
//                 if(symbol[i] == '-'){
//                     sign = -1;
//                     i++;
//                 }
//                 while(i<symbol.length()) n = n*10 + (symbol[i++]-'0');
                
//                 sta.push(sign*n);
//             }
//         }
        
//         return sta.top();
//     }
};