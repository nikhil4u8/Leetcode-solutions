class Solution {
public:
//TIME - O(N) SPACE - O(1)
    int compress(vector<char>& chars) {
        string ans = "";
        char prev;
        int count = 0, j = 0;
    
        for(int i=0;i<chars.size();i++){
            if(chars[i] != prev){
                if(i != 0){
                    ans += prev;
                    if(count > 1) ans += to_string(count);
                }
                prev = chars[i];
                count = 1;
            }else count++;
        }   

        ans += prev;
        if(count > 1) ans += to_string(count);

        for(int i=0;i<ans.length();i++) chars[i] = ans[i];
        
        return ans.length();
    }
};