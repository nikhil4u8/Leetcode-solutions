class Solution {
public:
    //TIME - O(N) SPACE - O(1) 
    bool isVowel(char s){
        return s == 'a' || s == 'e' || s == 'i' || s == 'o' || s == 'u' || s == 'A' || s == 'E' || s == 'I' || s == 'O' || s == 'U';
    }
    bool halvesAreAlike(string s) {
        int vowel = 0;

        for(int i=0;i<s.length();i++){
            if(!isVowel(s[i])) continue;
            if(i>=s.length()/2) vowel--;
            else vowel++;
        }

        return vowel == 0;
    }
};