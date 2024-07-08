class Solution {
public:
    //TIME - O(N) SPACE - O(N)
    int maxDepth(string s) {
        int maxi = 0;
        stack<pair<char,int>>st;
        
        for(int i=0;i<s.length();i++){
            if(s[i]=='(' || s[i]==')'){
                if(!st.empty() && s[i]==')' && st.top().first=='(') st.pop();
                else{
                  int t;
                  if(st.empty()) t=0;
                  else t = st.top().second;
                  st.push({s[i],t+1});
                  maxi = max(maxi,t+1);
                }
            }
        }
        
        return maxi;
    }
    //TIME - O(N)  SPACE - O(1)
    int maxDepth(string s) {
        int res = 0;
        int depth = 0;
        for(int i =0 ; i < s.size(); ++i)
        {
            if(s[i] == '(')  depth++;
            else if(s[i] == ')') depth--;
            res = max(depth, res);
        }
    return res;
    }
};

**FOLLOW-UP
    1.What if there are [], {}, and ()? What if there are non VPS?
        If there were brackets and curly braces mixed with the parenthesis, we'd need to keep track of
        the last opened bracket -type. data structure used is Stack, which allows us to 
        keep track of the last added bracket in a LIFO (last-in-first-out) order. Once a matched pair 
        is found, the last item in the stack is removed (the deepest current nesting).

