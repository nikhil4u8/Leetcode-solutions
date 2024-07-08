class Solution {
public:
    //TIME - O(N)  SPACE - O(N)
    //marking all correct bracket as true and then counting max continous brackets
    int longestValidParentheses(string s) {
       int n = s.size();
        stack<int> st;
        vector<bool> v(n,0);
        for(int i = 0 ; i < n ; i++)
        {
            if(s[i] == '(')  st.push(i);
            else{
                if(!st.empty()){
                    v[st.top()] = 1;
                    v[i] = 1;
                    st.pop();
                }
            }
        }
        
        int ans = 0,cnt = 0;
        bool cont = 0;
        for(int i = 0 ; i < n ; i++){
            if(v[i]){
                if(!cont)cont = 1;
                ans = max(ans,++cnt);
            }
            else  cont = cnt = 0;
        }
        return ans;
    }
    //TIME - O(N) SPACE - O(N)
    int longestValidParentheses(string s) {
        stack<pair<char,int>>sta;
        int max_len = 0;
        sta.push({'$',-1});
        
        for(int i=0;i<s.length();i++){
            if(!sta.empty() && s[i]==')' && sta.top().first=='('){
                sta.pop();
                max_len = max(max_len,i-sta.top().second);
            }else sta.push({s[i],i});
        }
        
        return max_len;
    }
    //TIME - O(N)  SPACE - O(1)
    //+1 to represent '(' and -1 for ')'; if sum == 0, then the substring is balanced;
//sum < 0 means the expression is unbalanced, where I give up the current length and start again.
//when we scan from left side, we can only find the expression unbalanced when ')' appears too often, and '(' should also be checked for balance, so we should scan again from right side.
    //why we need forward and backward pass consider the case of (()()
    int longestValidParenthesesOnline(String s) {
        if (s == null) return -1;
        if (s.length() == 0) return 0;
        char[] str = s.toCharArray();
        int sum = 0, res = 0, len = 0, n = s.length();
		// Scan the string from left side, plus 1 for '(' and minus 1 for ')'.
        for (int i = 0; i < n; i++) {
            if (str[i] == '(') sum++;
            else sum--;
            if (sum < 0) {
                sum = 0;
                len = 0;
            } else {
                len++;
                if (sum == 0) res = Math.max(res, len);
            }
        }
		// Scan again from right side, plus 1 for ')' and minus 1 for '('.
        sum = 0;
        len = 0;
        for (int i = n - 1; i >= 0; i--) {
            if (str[i] == ')') sum++;
            else sum--;
            if (sum < 0) {
                sum = 0;
                len = 0;
            } else {
                len++;
                if (sum == 0) res = Math.max(res, len);
            }
        }
        return res;
    }
};