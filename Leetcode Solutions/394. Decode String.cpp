class Solution {
public:
    string decodeString(string s) {
        int n = s.length();
        string ans = "";
        
        for(int i=0;i<n;i++){
            int num = 0;
            
            while(i<n && s[i]>='0' && s[i]<='9') num = num*10 + (s[i++]-'0');
            
            if(s[i] == '['){
                string temp_str = "";
                
                stack<char>sta;
                sta.push(s[i++]);
                
                while(i<n && !sta.empty()){
                    if(!sta.empty() && s[i] == ']' && sta.top() == '[') sta.pop();
                    else if(s[i] == '[') sta.push(s[i]);
                    
                    if(sta.empty()) break;
                    
                    temp_str += s[i++];
                }
                
                temp_str = decodeString(temp_str);
                
                while(num--) ans += temp_str;
            }else ans += s[i];
        }
        
        return ans;
    }
};