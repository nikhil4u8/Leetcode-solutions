class Solution {
public:
//TIME - O(N*minSize) SPACE - O(N)
//here if say str of len = l, has max freq, then substring of that str will have >= max freq,
//hence substring of minSize len will have max freq, so simply fix the len of string and find
//the freq
    int maxFreq(string s, int maxLetters, int minSize, int maxSize) {
        int ans = 0;
        unordered_map<string, int>freq;

        for(int i=0;i<s.length()-minSize+1;i++){
            unordered_map<char, int>letters;

            string temp_str = s.substr(i, minSize);

            for(int j=0;j<temp_str.length();j++) letters[temp_str[j]]++;
            if(letters.size() > maxLetters) continue;

            freq[temp_str]++;

            ans = max(ans, freq[temp_str]);
        }
        
        return ans;
    }
};