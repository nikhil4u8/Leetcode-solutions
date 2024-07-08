class Solution {
public:
    int min_diff(string t1, string t2){
        int h1 = 0, h2 = 0, m1 = 0, m2 = 0;
        bool flag = false;
        
        for(int i=0;i<t1.length();i++){
            if(t1[i] == ':'){
                flag = true;
                continue;
            }
            if(flag) m1 = m1*10 + (t1[i] - '0');
            else h1 = h1*10 + (t1[i] - '0');
        }
        
        flag = false;
        
        for(int i=0;i<t2.length();i++){
            if(t2[i] == ':'){
                flag = true;
                continue;
            }
            if(flag) m2 = m2*10 + (t2[i] - '0');
            else h2 = h2*10 + (t2[i] - '0');
        }
        
        int diff_1 = abs(h1 - h2)*60 + m2 - m1;
        int diff_2 = 24*60 - diff_1;
        
        return min(diff_1, diff_2);
    }
    int findMinDifference(vector<string>& timePoints) {
        sort(timePoints.begin(), timePoints.end());
        int ans = INT_MAX;
        int len = timePoints.size();
        
        for(int i = 1;i<len;i++){
            int diff = min_diff(timePoints[i-1], timePoints[i]);
            ans = min(ans, diff);
        }
        
        ans = min(ans, min_diff(timePoints[0], timePoints[len-1]));
        
        return ans;
    }
};