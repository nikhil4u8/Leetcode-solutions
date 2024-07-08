#define PI 3.14159265
class Solution {
public:
    double get_angle(int x_diff, int y_diff){
        return atan2(y_diff, x_diff) * 180 / PI;
    }
    int binary_search_angle(int start, int end, double end_angle, vector<double>&slope){
        int j = start,k = end, index = -1;
        while(j<=k){
            int mid = (j+k)/2;
            if(slope[mid] == end_angle || slope[mid] < end_angle){
                index = mid;
                j = mid+1;
            }else k = mid-1;
        }
        if(index == -1) return start-1;
        
        return index;
    }
    int visiblePoints(vector<vector<int>>& points, int angle, vector<int>& location) {
        vector<double>slope;
        int common = 0;
        
        for(int i=0;i<points.size();i++){
            int x_diff = points[i][0] - location[0];
            int y_diff = points[i][1] - location[1];
            
            if(x_diff == 0 && y_diff == 0) common++;
            else{
                double temp_angle = get_angle(x_diff, y_diff);
                if(temp_angle < 0) temp_angle += 360;
                slope.push_back(temp_angle);
            }
        }
        
        sort(slope.begin(), slope.end());
        int len = slope.size();
                
        int count_max_point = 0;
        
        for(int i=0;i<len;i++){
            if(i != 0 && slope[i] == slope[i-1]) continue;
            double location_start_angle = slope[i];
            double location_end_angle = slope[i] + angle;

            if(location_end_angle >= 360) location_end_angle -= 360;

            if(location_end_angle >= location_start_angle){
                //normal binary search to find element with slope between end and start angle
                int index = binary_search_angle(i, len-1, location_end_angle, slope);
                count_max_point = max(count_max_point, index - i + 1);
            }else{
                //binary search to find element with angle between (0-end_angle) and (start_angle-360)
                int index_start = binary_search_angle(i, len-1, 360, slope);
                int index_end = binary_search_angle(0, len-1, location_end_angle, slope);
                
                count_max_point = max(count_max_point, index_start+index_end-i+2);
            }
        }
        
        return common + count_max_point;
    }
};