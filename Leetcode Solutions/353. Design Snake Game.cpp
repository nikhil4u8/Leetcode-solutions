class SnakeGame {
public:
    vector<vector<int>>matrix;
    deque<pair<int,int>>q;
    int w,h,c_x,c_y,next_food;
    
    SnakeGame(int width, int height, vector<vector<int>>& food) {
        matrix = vector<vector<int>>(height,vector<int>(width,0));
        q = deque<pair<int,int>>();
        q.push_back({0,0});
        
        int count = 1;
        w = width,h = height,c_x=0,c_y=0,next_food=1;
        
        for(int i=0;i<food.size();i++){
            matrix[food[i][0]][food[i][1]] = count++;
        }
    }
    int move(string direction) { 
       if(direction == "R") c_y++;
       else if(direction == "D") c_x++;
       else if(direction == "L") c_y--;
       else if(direction == "U") c_x--;
          
       if(!(c_x>=0 && c_y>=0 && c_x<h && c_y<w)) return -1;
       auto temp = make_pair(c_x,c_y);
       deque<pair<int,int>>::iterator it = find(q.begin(),q.end(),temp);
        
       if(it!=q.end()){
           if(temp == q.front() && matrix[c_x][c_y] == next_food) return -1;
           if(temp != q.front()) return -1;
       }

       if(matrix[c_x][c_y] == next_food) next_food++;
       else q.pop_front();
       q.push_back({c_x,c_y});
        
       return next_food-1;
    }
};

/**
 * Your SnakeGame object will be instantiated and called as such:
 * SnakeGame* obj = new SnakeGame(width, height, food);
 * int param_1 = obj->move(direction);
 */