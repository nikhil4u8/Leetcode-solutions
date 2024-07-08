#define ppi pair<int,pair<int,int>>
class Solution {
public:
    //Approach - 1
    //Find the minimum value for each element in all 4 dir then do water += min_among_all_dir - height[i][j]
    //Problem is that for each index, I didn't considered the min_among_all value of other indexes, I 
    //just calculated min_among_all_value according to state 0 of matrix & ignoring min value at 
    //suorronded index
    /*Example - [9,9,9,9]
                [9,6,7,9]   => according to my algo, 6 will update first to 7 n 7->5 so ideally 6 should
                [9,9,5,9]      be 5 but it updated before 7, so wrong approach
    */
//     int trapRainWater(vector<vector<int>>& heightMap) {
//         vector<vector<int>>left;
//         vector<vector<int>>right;
//         vector<vector<int>>up;
//         vector<vector<int>>down;
        
//         int n = heightMap.size();
//         int m = heightMap[0].size();
        
//         for(int i=0;i<n;i++){
//             vector<int>v(m,0);
//             v[0] = heightMap[i][0];
//             for(int j=1;j<m;j++)  v[j] = max(v[j-1],heightMap[i][j]);
//             left.push_back(v);
//         }
        
//         for(int i=0;i<n;i++){
//             vector<int>v(m);
//             v[m-1] = heightMap[i][m-1];
//             for(int j=m-2;j>=0;j--) v[j] = max(v[j+1],heightMap[i][j]);
//             right.push_back(v);
//         }
        
//         for(int i=0;i<m;i++){
//             vector<int>v(n);
//             v[0] = heightMap[0][i];
//             for(int j=1;j<n;j++) v[j] = max(v[j-1],heightMap[j][i]);
//             up.push_back(v);
//         }
        
//         for(int i=0;i<m;i++){
//             vector<int>v(n);
//             v[n-1] = heightMap[n-1][i];
//             for(int j=n-2;j>=0;j--) v[j] = max(v[j+1],heightMap[j][i]);
//             down.push_back(v);
//         }
        
//         int ans = 0;
//         vector<vector<int>>water(n,vector<int>(m,0));
//         for(int i=0;i<n;i++){
//             for(int j=0;j<m;j++)
//                 water[i][j] = min(left[i][j],min(right[i][j],min(up[j][i],down[j][i])));
//         }
        
//         for(int i=n-2;i>=1;i--){
//           for(int j=m-2;j>=1;j--)
//             water[i][j]=min(water[i+1][j],min(water[i-1][j],min(water[i][j-1],water[i][j+1])));
//         }
        
//         for(int i=1;i<n-1;i++){
//             for(int j=1;j<m-1;j++){
//                 int t = min(water[i+1][j],min(water[i-1][j],min(water[i][j-1],water[i][j+1])));
//                 ans += t<=heightMap[i][j] ? 0 : t - heightMap[i][j];
//             }
//         }
        
//         return ans;
//     }
    //Time - O(MNlog(MN))  SPACE - O(M*N)
    //Approach - Insert all boundary height into queue, then pop least height and if 
    //poped_height<neighbour_height, neighbour height wont store water, else neighbour will store 
    //poped_height-negihbour_height amount, now push max(neighbour_height,poped_height), since if 
    //neighbour height will be less then it will update it's sourrounding else it will act as a 
    //barrier for sourrounding to store water.
    
    //Why prioirty_queue is used?
    //becoz we need to update every element according to sourrounding element, and hence each elements 
    //depends upon each other so we can't fix a absoulte state according to which changes are done, so 
    //we can pick the boundary element and update it's sourrounding, and in those element too, we need 
    //min_height element since becoz of them only water spill is causing
     int trapRainWater(vector<vector<int>>& heightMap) {
         priority_queue<ppi,vector<ppi>,greater<ppi>>pq;
         
         int n = heightMap.size();
         int m = heightMap[0].size();
         int water_total = 0;
         
         int dir_x[4] = {0,0,1,-1};
         int dir_y[4] = {1,-1,0,0};
         
         vector<vector<bool>>visited(n,vector<bool>(m,false));
         
         for(int i=0;i<m;i++){
             visited[n-1][i] = true;
             visited[0][i] = true;
             pq.push({heightMap[n-1][i],{n-1,i}});
             pq.push({heightMap[0][i],{0,i}});
         }
         for(int i=0;i<n;i++){
             visited[i][0] = true;
             visited[i][m-1] = true;
             pq.push({heightMap[i][0],{i,0}});
             pq.push({heightMap[i][m-1],{i,m-1}});
         }
         
         while(!pq.empty()){
             auto temp = pq.top();
             int new_level = temp.first;
             int x = temp.second.first;
             int y = temp.second.second;
             pq.pop();
             
             for(int i=0;i<4;i++){
                 int x0 = x + dir_x[i];
                 int y0 = y + dir_y[i];
                 
                 if(x0>=0 && y0>=0 && x0<n && y0<m && !visited[x0][y0]){
                     visited[x0][y0] = true;
                     pq.push({max(heightMap[x0][y0],new_level),{x0,y0}});
                     water_total += max(0,new_level - heightMap[x0][y0]);
                 }
             }
         }
         
         return water_total;
     }
};

**FOLLOW-UP
    1.In case of 3D heightMap
        only width factor would be extra so while storing water just multiply each value by width at
        that point