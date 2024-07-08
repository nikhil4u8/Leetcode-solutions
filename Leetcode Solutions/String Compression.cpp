class Solution {
public:
    int compress(vector<char>& chars) {
        int j = 0,count = 1;
        
        for(int i=1;i<chars.size();i++){
            if(chars[i]==chars[i-1]) count++;
            else{
                chars[j++] = chars[i-1];
                string str = to_string(count);
                if(count!=1){
                    for(int k=0;k<str.length();k++) chars[j++] = str[k]; 
                }
                count = 1;
            }
        }
        
        chars[j++] = chars[chars.size()-1];
        string str = to_string(count);
        
        if(count!=1){
            for(int k=0;k<str.length();k++) chars[j++] = str[k];
        }
        
        chars.resize(j);
        return j;
    }
};