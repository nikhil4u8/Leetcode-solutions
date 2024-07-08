class Solution {
public:
// TIME - O(N^2) SPACE - O(N)
    int maxPoints(vector<vector<int>>& points) {
        int ans = 0;
        // slope -> count
        for(int i=0;i<points.size();i++){
            unordered_map<double, int>slope;
            for(int j=0;j<points.size();j++){
                if(i == j) continue;

                double slp = ((double)points[j][1] - (double)points[i][1]) / ((double)points[j][0] - (double)points[i][0]);

                slope[slp]++;

                ans = max(ans, slope[slp]);
            }
        }

        return 1 + ans;
    }
};