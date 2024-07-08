/*
Ques to ask :
    - How robot will move 90 degree?
    - Can we modify cells in grid?
    - Initially in what direction robo is facing?
    - If facing upwards then called turnLeft fun then in which direction 
    it'll go?
    - How to identify obstacle?

Sol :
BEST APPROACH
=> Using DFS : [TIME - O(N-M) SPACE - O(N-M)]
-> N : no of cells
-> M : no of obstacles
    - We'll do a normal DFS, for all the cells in grid.
    - Since we're not having access to grid cordinates, so we can use 
    relative coordinates i.e first cell of robot can be marked as {0,0} & 
    we'll keep track of visited cordinates using a hash set.
    - To change direction or move back (when a obstacle is hit), we can 
    use .topLeft() or topRight() fun
*/
class Solution {
public:
    vector<int>dir_x = {-1,0,1,0};
    vector<int>dir_y = {0,1,0,-1};
    unordered_set<string>visited; // store visited coordinates
    //used to move back to prev cell
    void moveBack(Robot &robot){
        robot.turnRight();
        robot.turnRight();
        robot.move();
        robot.turnRight();
        robot.turnRight();
    }
    void cleanALl(Robot &robot, int row, int col, int dir){
        string key = to_string(row) + "," + to_string(col);
        if(visited.count(key)) return;

        //mark curr cell as visited & clean
        visited.insert(key);
        robot.clean();

        // try out 4 differnt directions
        // i = 0: keep moving towards the current direction that we're facing
        // i = 1: make 1 right turn already, and try that new direction
        // i = 2: make 2 right turns already, and try that new direction
        // i = 3: make 3 right turns already, and try that new direction
        for(int i=0;i<4;i++){
            int nextFaceDir = (dir + i)%4;
            int x = row + dir_x[nextFaceDir];
            int y = col + dir_y[nextFaceDir];

            // next cell is accessible
            if(robot.move()){
                cleanALl(robot, x, y, nextFaceDir);
                // come back from the above recursive call, and the robot 
                //is currently at (x, y) we should do a backtracking here 
                //to ask the robot to return back to (row, col)
                moveBack(robot);
            }
            // the current direction has been explored so we should make 
            //a right turn, and try to explore another direction
            robot.turnRight();
        }
    }
    void cleanRoom(Robot& robot) {
        cleanALl(robot, 0, 0, 0);
    }
};