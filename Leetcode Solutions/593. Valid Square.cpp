class Solution {
public:
    int dist(vector<int>p1, vector<int>p2){
        return (p1[0]-p2[0])*(p1[0]-p2[0]) + (p1[1]-p2[1])*(p1[1]-p2[1]);
    }
    bool isSame(vector<int>p1, vector<int>p2){
        return p1[0] == p2[0] && p1[1] == p2[1];
    }
    bool validSquare(vector<int>& p1, vector<int>& p2, vector<int>& p3, vector<int>& p4) {
        if(isSame(p1,p2) || isSame(p1,p3) || isSame(p1,p4) || isSame(p2,p3) || isSame(p2,p4) || isSame(p3,p4))
            return false;
        
        unordered_map<int,int>mp;
        
        int len1 = dist(p1,p2), len2 = dist(p1,p3), len3 = dist(p1,p4);
        mp[len1]++;
        mp[len2]++;
        mp[len3]++;
        
        len1 = dist(p2,p3);
        len2 = dist(p2,p4);
        mp[len1]++;
        mp[len2]++;
        
        len1 = dist(p3,p4);
        mp[len1]++;
        
        return mp.size() == 2;
    }
};