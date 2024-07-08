class Solution {
public:
    //TIME - O(N)  SPACE - O(1)
    int myAtoi(string s) {
        int i=0,num=0,len=s.length();
        
        while(i<len && s[i]==' ') i++;
        
        int sign = 1;
        
        if(i<len && s[i] == '-') sign = -1;
        else if(i<len && s[i] == '+') sign = 1;
        else if(i<len && s[i]>='0' && s[i]<='9') num = s[i]-'0';
        else return 0;
        
        i++;
        
        while(i<len){
            if(s[i]>='0' && s[i]<='9'){
                if(num>INT_MAX/10) return sign==1 ? INT_MAX : INT_MIN;
                if(num==INT_MAX/10 && sign==1 && s[i]-'0'>=8) return INT_MAX;
                if(num==INT_MAX/10 && sign==-1 && s[i]-'0'>=8) return INT_MIN;
               
                num = num*10 + (s[i]-'0');
            }else return num*sign;
            i++;
        }
        
        return num*sign;
    }
};