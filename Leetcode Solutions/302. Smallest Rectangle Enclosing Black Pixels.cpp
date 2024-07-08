class Solution {
public:
    int max_x = INT_MIN, min_x = INT_MAX, max_y = INT_MIN, min_y = INT_MAX;
    void DFS(vector<vector<char>>& image, int x, int y){
        if(x<0 || y<0 || x>=image.size() || y>=image[0].size() || image[x][y] == '0') return;
        
        image[x][y] = '0';
        
        max_x = max(max_x, x);
        min_x = min(min_x, x);
        max_y = max(max_y, y);
        min_y = min(min_y, y);
        
        DFS(image, x+1, y);
        DFS(image, x-1, y);
        DFS(image, x, y+1);
        DFS(image, x, y-1);
    }
    int minArea(vector<vector<char>>& image, int x, int y) {        
        DFS(image, x, y);
        
        return (max_x-min_x+1)*(max_y-min_y+1);
    }
};