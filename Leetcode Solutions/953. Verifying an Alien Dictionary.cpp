/*
Ques to ask :
    - Does Alien dict contains upper case letters?
    - What if order doesn't contain char which are present in words?
    - Compare "" with "a"?
    - Compare " " with "a"?
    - What if we've 2 equal string?

Sol :
    - Create a map with mapping CHAR -> PRIORITY present in order str
    - Compare adjacent words to see if they're in right order using map
    - Traverse adjacent words until different char is found, then compare 
    it's priority using map, if it's higher then return true, else false
    - If latter word is a substr of former word then return true, else 
    false.
*/
class Solution {
public:
//TIME - O(N*max_len_of_word) SPACE - O(1) [since mp if of 26 letters]

    unordered_map<char, int>mp;
    bool compare(string word1, string word2){
        int i = 0, j = 0;
        
        //traverse until we find a different char, then compare priority
        while(i<word1.length() && j<word2.length()){
            if(word1[i] != word2[j]) return mp[word1[i]] < mp[word2[j]];
            
            i++;
            j++;
        }

        //if word1 is a substr of word2, then only it'll come before word2
        return word1.length() < word2.length();
    }
    bool isAlienSorted(vector<string>& words, string order) {
        for(int i=0;i<order.length();i++) mp[order[i]] = i;

        for(int i=1;i<words.size();i++){
            // if both words same, move to next word
            if(words[i-1] == words[i]) continue;
            // if different words, then compare
            if(!compare(words[i-1], words[i])) return false;
        }

        return true;
    }
};