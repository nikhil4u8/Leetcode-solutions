/*
Ques to ask :
    - Can n be odd?
    - In pairs can we've a frnd mapped with 2 other frnds, [0,1],[0,2]?
    - Can we've repetative value in preference[i]? Can preference[i] contains i?
    - Can we've self pairing in pairs vector, [0,0]?

Sol :
    -Loop over every friend
    - Check if matched prefrence is lower
    - If not then loop over their preferences and see if the any his/her higher preference is also matched to some lower preference, If yes increment the count unhappy.

TIME - O(N^2) SPACE - O(N)
*/
class Solution {
public:
    int unhappyFriends(int n, vector<vector<int>>& preferences, vector<vector<int>>& pairs) {
        int count = 0;
        unordered_map<int, unordered_map<int, int>>frndMap;
        unordered_map<int, int>pairing;

        for(int i=0;i<preferences.size();i++){
            for(int j=0;j<preferences[i].size();j++)
                frndMap[i][preferences[i][j]] = j;
        }

        for(int i=0;i<pairs.size();i++){
            pairing[pairs[i][0]] = pairs[i][1];
            pairing[pairs[i][1]] = pairs[i][0];
        }

        for(int i=0;i<n;i++){
            int x = i;

            //direct frnd of x
            int y = pairing[x];
            //priority of direct frnd of x
            int y_priority_in_x = frndMap[x][y];

            //if priority of y is first, then move on, everything is perfect
            if(y_priority_in_x == 0) continue;

            //looping through all the frnd whose preference is before y in x, if any one of the frnd fullfil the criteria, then x will be unhappy.
            for(int j=0;j<y_priority_in_x;j++){
                //Frnd whose priority is first in x
                int u = preferences[x][j];
                int u_priority_in_x = frndMap[x][u];

                //direct frnd of u
                int v = pairing[u];
                //priority of direct frnd of u in U preference array
                int v_priority_in_u = frndMap[u][v];
                //prirotiy of x in preference array
                int x_priority_in_u = frndMap[u][x];

                //if x prefers u (another frnd) over y (direct frnd) &&
                //if u (another frnd) prefers x over v (u's direct frnd)
                if(u_priority_in_x < y_priority_in_x && 
                x_priority_in_u < v_priority_in_u){
                    count++;  
                    break;
                }
            }
        }

        return count;
    }
};

//TIME - O(N^2) SPACE - O(N^2)
class Solution {
    //We stere the ranking of person in terms of friendship with every other person
    //positions[i][j] should be read as position of i in the list of j is positions[i][j].
    unordered_map<int, unordered_map<int, int>> positions;
    
    unordered_set<int> unhappy; // Stores unhappy people. In the end, we will return it's size.
public:
    void checkHappiness(int x, int y, int u, int v) {
        if (positions[u][x] < positions[y][x] &&
            positions[x][u] < positions[v][u]) {
            unhappy.insert(x);
            unhappy.insert(u);
        }
    }
    
    int unhappyFriends(int n, vector<vector<int>>& preferences, vector<vector<int>>& pairs) {
        //size of preferences = n
        for (int i=0; i<n; i++) {
            //size of preferences[i] = n-1
            for (int j=0; j<n-1; j++) {
                positions[preferences[i][j]][i] = j;
            }
        }
        n = pairs.size();
        for (int i=0; i<n-1; i++) {
            int x = pairs[i][0], y = pairs[i][1];
            for (int j=i+1; j<n; j++) {
                int u = pairs[j][0], v = pairs[j][1];
                checkHappiness(x, y, u, v); // If x prefers u over y,  and u prefers x over v
                checkHappiness(x, y, v, u); // If x prefers v over y,  and v prefers x over u
                checkHappiness(y, x, u, v); // If y prefers u over x,  and u prefers y over v
                checkHappiness(y, x, v, u); // If y prefers v over x,  and v prefers y over u
            }
        }
        
        return unhappy.size();
    }
};