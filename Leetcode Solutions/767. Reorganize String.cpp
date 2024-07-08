class Solution {
public:
    string reorganizeString(string s) {
        vector<pair<int,char>>freq(26);
        char x;
        int len = s.length(), maxi = 0;
        
        for(int i=0;i<len;i++){
            freq[s[i] - 'a'].first++;
            freq[s[i] - 'a'].second = s[i];
            
            if(maxi < freq[s[i] - 'a'].first){
                maxi = freq[s[i] - 'a'].first;
                x = s[i];
            }
        }
        if(maxi > len/2 + len%2) return "";
        
        string res(len, x);
        int j = 0;
        
        sort(freq.begin(), freq.end());
        
        for(int i=25;i>=0;i--){
            while(freq[i].first--){
                res[j] = freq[i].second;
                j += 2;
                if(j >= len) j = 1;
            }
        }
        
        return res;
    }
};