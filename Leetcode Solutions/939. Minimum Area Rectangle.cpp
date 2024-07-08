/*
Ques to ask : 
    - What if min area doesn't exist?

Sol : 
=> Basic approach : [TIME - O(N^2) SPACE - O(N)]
    - Store all the cordinate freq in a map, then make 2 pair of 
    cordinate considering them as diagonal cordinated & for every pair 
    find if the other vertex of rectangle exist or not, if it exist then 
    record min area and return
*/
class Solution {
public:
    int minAreaRect(vector<vector<int>>& points) {
        //x -> y, freq
        unordered_map<int,unordered_map<int,int>>cordi;
        
        for(int i=0;i<points.size();i++) cordi[points[i][0]][points[i][1]]++;
        
        int min_area = INT_MAX;
        
        for(int i=0;i<points.size();i++){
            for(int j=i+1;j<points.size();j++){
                int x1 = points[i][0], x2 = points[j][0];
                int y1 = points[i][1], y2 = points[j][1];
                
                if(x1 == x2 || y1 == y2) continue;
                if(cordi[x1][y2] > 0 && cordi[x2][y1] > 0) 
                    min_area = min(min_area, abs(x1-x2)*abs(y1-y2));
            }
        }
        
        if(min_area == INT_MAX) return 0;
        
        return min_area;
    }
};