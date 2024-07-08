class Solution {
public:
    First Approach 
    //create a hashmap for each string and store it's frequency and then for j=i+1;j<word.size();j++
    //traverse the jth string n check if there is any common char or not, if there is then skip else
    //update max
    //TIME - O(N^2)  SPACE - O(N)
    int maxProduct(vector<string>& words) {
        int maxi = 0,n=words.size();
        vector<bitset<26>>mp(n);
        
        for(int i=0;i<words.size();i++){
            string str = words[i];
            for(int j=0;j<str.length();j++) mp[i][str[j]-'a'] = 1;
            
            for(int j=0;j<i;j++){
                bool flag = true;
                for(int k=0;k<26;k++) if(mp[i][k] && mp[j][k]) flag = false;
                if(flag) maxi = max(maxi,(int)words[i].length()*(int)words[j].length());
            }
        }
        
        return maxi;
    }
};