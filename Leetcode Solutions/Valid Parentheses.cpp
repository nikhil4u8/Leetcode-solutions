class Solution {
public:
    bool isValid(string s) {
        stack<char>cache;
        
        for(int i=0;i<s.length();i++){
            if(s[i] == ')'){
                if(!cache.empty() && cache.top()=='(') cache.pop();
                else cache.push(')');
            }else if(s[i]==']'){
                if(!cache.empty() && cache.top()=='[') cache.pop();
                else cache.push(']');
            }else if(s[i]=='}'){
                if(!cache.empty() && cache.top()=='{') cache.pop();
                else cache.push('}');
            }else cache.push(s[i]);
        }
        
        return cache.empty();
    }
};