class Solution {
public:
    int convertTime(string current, string correct) {
        int h1 = 0, h2 = 0, m1 = 0, m2 = 0, flag = 0;
        
        for(int i=0;i<5;i++){
            if(current[i] == ':') flag = 1;
            else if(flag == 0){
                h1 = h1*10 + (current[i] - '0');
                h2 = h2*10 + (correct[i] - '0');
            }else{
                m1 = m1*10 + (current[i] - '0');
                m2 = m2*10 + (correct[i] - '0');
            }
        }
        
        int minute_diff = abs(h2-h1)*60 + m2 - m1;
        
        int ans = 0;
        ans += minute_diff/60;
        minute_diff %= 60;
        
        ans += minute_diff/15;
        minute_diff %= 15;
        
        ans += minute_diff/5;
        minute_diff %= 5;
        
        ans += minute_diff/1;
        minute_diff %= 1;
        
        return ans;
    }
};