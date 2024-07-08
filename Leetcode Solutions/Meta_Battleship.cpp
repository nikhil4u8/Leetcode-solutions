/*
Ques to ask : 
    - What happens in T or L shape of battleship?
    - Is the board valid?
    - Case when no ship is present?

Sol : 
    Case 1 : X has no X on top and left i.e it's the starting point.
    Case 2 : X is already present on left i.e not the starting point.
    Case 3 : X is already present on top i.e not the starting point.
    Case 4 : X is already present on top / left both i.e not the starting point.

    Only Case 1 should be counted, that only indicates the starting point of any
    battleship.

Edge case :
    - If starting point of ship is (0,0)
    - ship starting point is in first row or first col

Follow up :
    - Return all coordinates of those ships as well
    - write a function to randomly place a battleship of size n on board.
*/
class Solution {
public:
//TIME - O(N*M) SPACE - O(1)
    int countBattleships(vector<vector<char>>& board) {
        int n = board.size(), m = board[0].size(), count = 0;

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(board[i][j] == 'X'){
                    if(i == 0 && j == 0) count++;
                    else if(i == 0 && board[i][j-1] == '.') count++;
                    else if(j == 0 && board[i-1][j] == '.') count++;
                    else if(i>0 && j>0 && 
                    board[i-1][j] == '.' && board[i][j-1] == '.') count++;

                    /*
                    Or 
                    if(!((i>0 && board[i-1][j] == 'X') || 
                       (j>0 && board[i][j-1] == 'X'))) count++;
                    */
                }
            }
        }

        return count;
    }
};

//Follow up
//Assuming input is given correct i.e no T or L shape
//TIME - O(N*M) SPACE - O(total ships)
int countBattleships(vector<vector<char>>& board) {
    int n = board.size(), m = board[0].size(), count = 0;
    vector<vector<pair<int, int>>>cordinates;
    //maintain mapping of ship starting point and ship ID
    unordered_map<int, int>mp;
    //count ship ID
    int ships = 0;

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(board[i][j] == 'X'){
                if(i>0 && board[i-1][j] == 'X'){
                    //extract ship ID from map
                    int shipId = mp[(i-1)*n + j];
                    coordinates[shipId].push_back({i, j});
                    //removing last entry since it's redundant and updating current element with shipId since now it can be used in future
                    mp[i*n + j] = shipId;
                    mp.erase((i-1)*n + j);
                }
                else if(j>0 && board[i][j-1] == 'X'){
                    int shipId = mp[i*n + (j-1)];
                    coordinates[shipId].push_back({i, j});
                    mp[i*n + j] = shipId;
                    mp.erase(i*n + j-1);
                }else{
                    //Case when starting point of a ship is encountered.
                    coordinates.push_back({{i, j}});
                    //increment ship ID
                    ships++;
                    //map the starting point with ship id
                    mp[i*n + j] = ships;
                }
            }
        }
    }

    return cordinates;
}