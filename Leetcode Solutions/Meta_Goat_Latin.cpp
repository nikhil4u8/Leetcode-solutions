/*
Ques to ask :
    - Does sentence contain 'a' & 'A'?
    - Does it has leading / trailing spaces?
    - Does it has ',',';','/' anything else?
*/
//TIME - O(N) SPACE - O(1)
class Solution {
public:
    bool isVowel(char c){
        return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' || 
               c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U';
    }
    string toGoatLatin(string sentence) {
        string ans = "";
        string temp = "";
        int idx = 1;

        for(int i=0;i<sentence.length();i++){
            if(sentence[i] == ' '){
                if(!isVowel(temp[0])){
                    temp += temp[0];
                    temp.erase(0, 1);
                }
                temp += "ma";
                int temp_idx = idx;
                while(temp_idx--) temp += "a";

                ans += temp + " ";

                temp = "";
                idx++;
            }else temp += sentence[i];
        }

        if(temp != ""){
            if(!isVowel(temp[0])){
                temp += temp[0];
                temp.erase(0, 1);
            }
            temp += "ma";
            while(idx--) temp += "a";
            ans += temp;
        }

        return ans;
    }
};