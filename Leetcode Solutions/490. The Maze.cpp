/*
Ques to ask:
    - Are border of maze also walls?
    - Can we modify maze? -> If yes use it instead of visited array

Sol:
=> BFS : [TIME - O(N*M*(N+M)) SPACE - O(N*M) -> visited array]
-> TC EXPLANATION BELOW
    - We'll start traversing in BFS from starting index & we'll go in all 
    4 direction and will move in that direction until we hit a wall.
    - Once we hit a wall, we'll check if this cell is dest or not, if it 
    is then return true, otherwise check if this cell has been visited 
    previously or not, if it's not then mark it as visited and add it to 
    queue & repeat same for next element in queue.
*/
class Solution {
public:
    vector<int>dir_x = {0,0,1,-1};
    vector<int>dir_y = {1,-1,0,0};
    bool hasPath(vector<vector<int>>& maze, vector<int> start, vector<int>& dest) {
        int n = maze.size(), m = maze[0].size();
        int startX = start[0], startY = start[1];
        int destX = dest[0], destY = dest[1];
        //If start or dest is a wall then return false
        if(maze[startX][startY] == 1 || maze[destX][destY] == 1) return false;

        vector<vector<bool>>visited(n, vector<bool>(m, false));
        queue<pair<int, int>>q;

        q.push({startX, startY});
        visited[startX][startY] = true;

        while(!q.empty()){
            int size = q.size();
            while(size--){
                auto curr = q.front(); q.pop();
                int x0 = curr.first, y0 = curr.second;

                //If we reached dest then return it
                if(x0 == destX && y0 == destY) return true;

                for(int i=0;i<4;i++){
                    int row = x0;
                    int col = y0;

            //Move the ball in the chosen direction until it hits a wall
                   while(row>=0 && col>=0 && row<n && col<m && maze[row][col]==0){
                       row += dir_x[i];
                       col += dir_y[i];
                    }

                    //Revert the last move to get the cell to which the 
                    //ball rolls, becoz curr cell is a wall.
                    row -= dir_x[i];
                    col -= dir_y[i];

                    //If curr cell is not visited then add it to array
                    if(!visited[row][col]){
                        if(x0 == destX && y0 == destY) return true;
                        q.push({row, col});
                        visited[row][col] = true;
                    }
                }
            }
        }

        return false;
    }
};

/*
TC EXPLANATION
In BFS we've to visit all nodes at most once so O(N*M), now for each cell 
we've to traverse in 4 direction and will run a while loop for every 
direction until we hit a wall, so we're traversing O(M) steps horizontally 
& O(N) steps vertically in all 4 calls, so O(N*M*(N+M))
*/