class Solution {
public:
//Storing freq of char in s1 and taking a fix window of len s1.length
//creating another duplicate map to store freq of char in that window
//if freq matched then we've a permutation of s1 in s2

//TIME - O(N*M) SPACE - O(M)
//M -> len of s1
//N -> len of s2 
    bool checkInclusion(string s1, string s2) {
        unordered_map<char, int>mp;
        for(int i=0;i<s1.length();i++) mp[s1[i]]++;

        int i = 0, j = s1.length()-1;
        while(j < s2.length()){
            while(mp.find(s2[i]) == mp.end() && j<s2.length()){
                i++;
                j++;
            }

            unordered_map<char, int>dupli_mp = mp;
            bool found = true;

            for(int k = i;k<=j;k++){
                if(mp.find(s2[k]) == mp.end()){
                    i++; j++;
                    found = false;
                    break;
                }else{
                    mp[s2[k]]--;
                    if(mp[s2[k]] == 0) mp.erase(s2[k]);
                }
            }

            if(found && mp.empty()) return true;

            mp = dupli_mp;
        }

        return false;
    }
};