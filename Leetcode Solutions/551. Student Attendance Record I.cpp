class Solution {
public:
    bool checkRecord(string s) {
        int absent = 0, late = 0, present = 0;
        
        for(int i=0;i<s.length();i++){
            if(s[i] == 'A'){
                absent++;
                if(absent >= 2) return false;
                late = 0;
            }
            if(s[i] == 'L'){
                late++;
                if(late >= 3) return false; 
            }
            if(s[i] == 'P') late = 0;
        }
        
        return true;
    }
};