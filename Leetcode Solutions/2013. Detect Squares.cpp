class DetectSquares {
public:
    unordered_map<int,unordered_map<int,int>>cordi;
    vector<pair<int,int>>all_point;
    DetectSquares() {
        
    }
    
    void add(vector<int> point) {
        cordi[point[0]][point[1]]++;
        all_point.push_back({point[0],point[1]});
    }
    
    int count(vector<int> point) {
        int count_sqr = 0;
        
        for(int i=0;i<all_point.size();i++){
            int x = all_point[i].first;
            int y = all_point[i].second;
            
            if(cordi[x][point[1]] > 0 && cordi[point[0]][y] > 0 && 
               x != point[0] && y != point[1] && abs(x-point[0]) == abs(y-point[1])){
                count_sqr += cordi[x][point[1]] * cordi[point[0]][y];
            }
        }
        
        return count_sqr;
    }
};

/**
 * Your DetectSquares object will be instantiated and called as such:
 * DetectSquares* obj = new DetectSquares();
 * obj->add(point);
 * int param_2 = obj->count(point);
 */