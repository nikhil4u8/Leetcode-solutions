class Solution {
public:
    string tictactoe(vector<vector<int>>& moves) {
        vector<int>row(3,0);
        vector<int>col(3,0);
        int diagonal=0,anti_diagonal=0,len=3;
        int flag = 1;
        
        for(int i=0;i<moves.size();i++){
            row[moves[i][1]] += flag;
            if(row[moves[i][1]] == len || row[moves[i][1]] == -len) return i%2 == 0 ? "A" : "B";
            
            col[moves[i][0]] += flag;
            if(col[moves[i][0]] == len || col[moves[i][1]] == -len) return i%2 == 0 ? "A" : "B";
            
            if(moves[i][0] == moves[i][1]) diagonal += flag;
            if(diagonal == len || diagonal == -len) return i%2 == 0 ? "A" : "B";
            
            if(abs(moves[i][0]+moves[i][1]) == len-1) anti_diagonal += flag;
            if(anti_diagonal == len || anti_diagonal == -len) return i%2 == 0 ? "A" : "B";
            
            if(flag == 1) flag = -1;
            else flag = 1;
        }
        
        if(moves.size() != 9) return "Pending";
        
        return "Draw";
    }
};