class Solution {
public:
    bool isValid(string s) {
        stack<char>sta;
        
        for(int i=0;i<s.length();i++){
            if(!sta.empty() && s[i] == ')' && sta.top() == '(') sta.pop();
            else if(!sta.empty() && s[i] == ']' && sta.top() == '[') sta.pop();
            else if(!sta.empty() && s[i] == '}' && sta.top() == '{') sta.pop();
            else sta.push(s[i]);
        }
        
        return sta.empty();
    }
};