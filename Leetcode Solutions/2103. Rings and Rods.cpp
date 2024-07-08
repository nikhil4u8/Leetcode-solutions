class Solution {
public:
    int countPoints(string rings) {
        vector<set<char>>temp(10);
        int ans = 0;
        
        for(int i=0;i<rings.length();i+=2){
            int ring_num = rings[i+1]-'0';
            temp[ring_num].insert(rings[i]);
        }
        for(int i=0;i<10;i++){
            if(temp[i].size() == 3) ans++;
        }
        return ans;
    }
};