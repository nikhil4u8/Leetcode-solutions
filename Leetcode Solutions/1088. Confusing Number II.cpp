class Solution {
public:
    int count = 0;
    unordered_map<char, char>mp;
    bool isConfusing(long long int n){
        long long int rev_n = 0, temp_n = n;
        while(n){
            rev_n = rev_n*10 + mp[n%10];
            n /= 10;
        }
        return rev_n != temp_n;
    }
    void DFS(long long int temp, int n){
        if(temp > n) return;
        if(temp <= n && isConfusing(temp))
            count++;
        for(auto it : mp){
            if(temp*10 + it.first > n) continue;
            DFS(temp*10 + it.first, n);
        }
    }
    int confusingNumberII(int n) {
        int d = to_string(n).length();
        mp[0] = 0;
        mp[1] = 1;
        mp[6] = 9;
        mp[8] = 8;
        mp[9] = 6;
        
        for(auto x : {1, 6, 8, 9})
            DFS(x, n);
        
        return count;
    }
};