class Solution {
public:
//TIME - O(NlogN) SPACE - O(N)
    bool isReflected(vector<vector<int>>& points) {
        unordered_map<int, multiset<double>>y_cord;
        //TIME - O(N*logN)
        for(int i=0;i<points.size();i++)
            y_cord[points[i][1]].insert((double)points[i][0]);

        auto it = y_cord.begin();
        double start = (double)*it->second.begin();
        double end = (double)*it->second.rbegin();

        double mid_x = (start + end)/2;
        
        //TIME - O(N*logN)
        for(int i=0;i<points.size();i++){
            double temp_x = 2*mid_x - points[i][0];
            if(y_cord[points[i][1]].find(temp_x) == y_cord[points[i][1]].end()) 
                return false;
        }
        
        return true;
    }
};