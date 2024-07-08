class Solution {
public:
    Node* constructQuadTree(vector<vector<int>>& grid, int x, int y, int len){
        if(len < 0 || len > grid.size()) return NULL;
        if(len == 1) return new Node(grid[x][y] != 0, true, NULL, NULL, NULL, NULL);
        
        int reduced_len = len/2;
        
        Node* node = new Node();
        
        Node* top_left = constructQuadTree(grid, x, y, reduced_len);
        Node* top_right = constructQuadTree(grid, x, y+reduced_len, reduced_len);
        Node* bottom_left = constructQuadTree(grid, x+reduced_len, y, reduced_len);
        Node* bottom_right = constructQuadTree(grid, x+reduced_len, y+reduced_len, reduced_len);
        
        if(top_left->isLeaf && top_right->isLeaf && bottom_left->isLeaf && bottom_right->isLeaf &&
           top_left->val == top_right->val && top_right->val == bottom_left->val && 
           bottom_left->val == bottom_right->val)
        {
            node->isLeaf = true;
            node->val = top_left->val;
        }else{
            node->isLeaf = false;
            node->topLeft = top_left;
            node->topRight = top_right;
            node->bottomLeft = bottom_left;
            node->bottomRight = bottom_right;
        }
        
        return node;
    }
    Node* construct(vector<vector<int>>& grid) {
        int n = grid.size();
        return constructQuadTree(grid, 0, 0, n);
    }
};