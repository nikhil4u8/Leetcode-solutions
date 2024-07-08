class Solution {
public:
    //wrong approach but say it
    //Time - O(N*M) SPACE - O(N*M)
   int leastBricks(vector<vector<int>>& wall) {
       //storing all the position where a gap lies in ith row
        unordered_map<int,unordered_map<int,bool>>mp;
       //store where the gap lies
        unordered_map<int,bool>gap;
        int total = 0;
        
        for(int i=0;i<wall.size();i++){
            int sum = 0,m=wall[i].size();
            for(int j=0;j<m-1;j++){
                sum += wall[i][j];
                mp[i][sum] = true;
                gap[sum] = true;
            }
            total = sum + wall[i][m-1];
        }
        
        int ans = wall.size();
        
       //instead of traversing all the gap from 1 to width_of_brick, we stored all gap in a map and 
       //traversing it, for each gap we traverse each row to see if a gap lies or not at ith 
       //position
        for(auto g:gap){
            int count = 0;
            int i = g.first;
            for(auto it:mp){
                if(!it.second[i]) count++;
            }
            ans = min(ans,count);
        }
        
        return ans;
    }
    //Counting the gap
    //Time - O(no_of_bricks) Space - O(width_of_brick)
    int leastBricks(vector<vector<int>>& wall) {
        unordered_map<int,int>gap;
        int maxi = 0;
        
        for(int i=0;i<wall.size();i++){
            int sum = 0;
            for(int j=0;j<wall[i].size()-1;j++){
                sum += wall[i][j];
                gap[sum]++;
                maxi = max(maxi,gap[sum]);
            }
        }
        
        return wall.size()-maxi;
    }
};