class Solution {
public:
    //TIME - O(N) SPACE - O(1)->becoz size of mp is fixed ie 60
    int numPairsDivisibleBy60(vector<int>& time) {
        unordered_map<int,int>mp;
        int count = 0;
        
        for(int i=0;i<time.size();i++){
            count += mp[(60-(time[i]%60))%60];
            mp[(time[i]%60)]++;
        }
        
        return count;
    }
};