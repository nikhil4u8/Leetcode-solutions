class Solution {
public:
    string reorderSpaces(string text) {
        int space = 0,word = 0;
        
        for(int i=0;i<text.length();i++){
            if(text[i] == ' ') space++;
            else if(i == 0 || (i != 0 && text[i-1] == ' ')) word++;
        }

        int gap, left_space;
        if(word == 1) gap = 0, left_space = space;
        else gap = space/(word-1), left_space = space%(word-1);
        
        int j = 0, flag = 0;
        string res = "";
        
        for(int i=0;i<text.length();i++){
            if(text[i] != ' '){
                flag = true;
                res += text[i];
            }else if(flag){
                j = gap;
                while(j--) res += ' ';
                flag = false;
            }
        }
        
        if(res[res.length()-1] == ' ') res = res.substr(0,res.length() - gap);
        while(left_space--) res += ' ';
        
        return res;
    }
};