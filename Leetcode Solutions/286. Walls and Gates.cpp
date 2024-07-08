/*
Desc : We use INT_MAX to represent empty room

Ques to ask :
    - What if the distance to gate is actually INT_MAX?
    - What to do when 2 gates are adjacent? can we pass through gates 
    also?

Sol:
SAY THIS FIRST
- There are 2 ways to implement this, first is to do a BFS from each empty 
room until we find a nearest gate. Other is to do a BFS from every gate to 
all reachable rooms.
- In case if we've huge num of empty rooms >>>>>> no of gates, then 
prefer BFS wrt Gates, If no of gates >>>>> no of rooms, then prefer BFS 
wrt empty rooms. General case is rooms >> gates, so using BFS wrt Gates

=> BFS wrt empty rooms : [TIME - O(N^2*M^2) SPACE - O(N*M)]
    - For each BFS, it requires O(N*M) time & there can be N*M empty rooms 
    so TC is O(N*M*N*M)

BEST APPROACH
=> BFS wrt Gates : [TIME - O(N*M) SPACE - O(N*M)]
    - Do a BFS from gate to all the reachable node, here we'll avoid 
    visiting nodes whose distance is less than what the current gate BFS 
    is bringing in.
*/
class Solution {
public:
//BEST APPROACH
//BFS wrt Gates
//TIME - O(N*M) SPACE - O(N*M)
    vector<int>dir_x = {0,0,1,-1};
    vector<int>dir_y = {1,-1,0,0};
    void BFS(vector<vector<int>>&rooms, int row, int col){
        queue<pair<int, int>>q;
        q.push({row, col});
        int steps = 0;

        while(!q.empty()){
            int size = q.size();
            steps++;
            while(size--){
                auto curr = q.front(); q.pop();
                int x0 = curr.first, y0 = curr.second;

                for(int i=0;i<4;i++){
                    int x = x0 + dir_x[i];
                    int y = y0 + dir_y[i];

                    //If room dist is already less, then avoid going on 
                    //that path since a BFS due to some prev gate would've 
                    //optimized that path already
                    if(x >= 0 && y >= 0 && 
                    x < rooms.size() && y < rooms[0].size() && 
                    rooms[x][y] > steps){
                        rooms[x][y] = steps;
                        q.push({x, y});
                    }
                }
            }
        }
    }
    void wallsAndGates(vector<vector<int>>& rooms) {
        int n = rooms.size();
        if(n == 0) return;
        int m = rooms[0].size();

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(rooms[i][j] == 0){
                    BFS(rooms, i, j);
                }
            }
        }
    }
};