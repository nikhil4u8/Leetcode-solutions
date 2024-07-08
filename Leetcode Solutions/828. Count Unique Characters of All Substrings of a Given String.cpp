class Solution {
public:
    int uniqueLetterString(string s) {
        //C[i] = L[i]*R[i]
        int n = s.length();
        vector<int>left(n, 0);
        vector<int>right(n, n-1);
        
        unordered_map<char, int>idx;
        
        for(int i=0;i<n;i++){
            if(idx.find(s[i]) != idx.end()){
                right[idx[s[i]]] = i-1;
                left[i] = idx[s[i]]+1;
            }
            idx[s[i]] = i;
        }
        
        int ans = 0;
        for(int i=0;i<n;i++)
            ans += (i - left[i] + 1)*(right[i] - i + 1);
        
        return ans;
    }
};