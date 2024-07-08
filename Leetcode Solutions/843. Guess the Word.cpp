/**
 * // This is the Master's API interface.
 * // You should not implement it, or speculate about its implementation
 * class Master {
 *   public:
 *     int guess(string word);
 * };
 */
class Solution {
public:
    int countMatches(string t1, string t2){
        int count = 0;
        for(int i=0;i<t1.length() && i<t2.length();i++){
            if(t1[i] == t2[i]) count++;
        }
        return count;
    }
    void modifyList(string word, vector<string>&list, int matches){
        int j = 0;
        for(int i=0;i<list.size();i++){
            if(countMatches(word, list[i]) == matches)
                list[j++] = list[i];
        }
        list.resize(j);
    }
    void findSecretWord(vector<string>& wordlist, Master& master){
        for(int i=0;i<10 && !wordlist.empty();i++){
            int len = wordlist.size();
            int rand_num = rand()%len;
            string guess_word = wordlist[rand_num];
            
            int matches = master.guess(guess_word);
            
            modifyList(guess_word, wordlist, matches);
        }
    }
};