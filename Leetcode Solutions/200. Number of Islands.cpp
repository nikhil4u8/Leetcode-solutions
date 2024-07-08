/*
Sol :
BEST APPROACH
=> Using DFS : [TIME - O(N*M) SPACE - O(1)]
    - Iterate through each of the cell and if it is an island, do dfs to 
    mark all adjacent islands, then increase the counter by 1.

Follow up :
    - Find size of maximum island
        use a global varibale to find max,and pass a varibale count into 
        the function to track number of 1
    - what if the input data is too big (and sparse) such that we can only 
    load data of one row?
        -> Sol given below
*/
class Solution {
public:
//BEST APPROACH
//TIME - O(N*M) SPACE - O(1)
    vector<int>dir_x = {1,-1,0,0};
    vector<int>dir_y = {0,0,1,-1};
    void DFS(vector<vector<char>>&grid, int x, int y){
        grid[x][y] = '#';
        for(int i=0;i<4;i++){
            int x0 = x + dir_x[i];
            int y0 = y + dir_y[i];

            if(x0 >= 0 && y0 >= 0 && x0 < grid.size() && y0 < grid[0].size() &&
            grid[x0][y0] == '1') DFS(grid, x0, y0);
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        if(n == 0) return 0;

        int count = 0, m = grid[0].size();

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j] == '1'){
                    DFS(grid, i, j);
                    count++;
                }
            }
        }

        return count;
    }
};

//FOLLOW UP : 3
/*
Say currLine is a row we are checking, prevLine - one before it;
Now we can read line-by-line and follow these rules:

1. if currLine[i-1] && prevLine[i] are not set, we consider i as a start 
of the new island;
2. if currLine[i-1] is set but prevLine[i] is not we consider i belongs 
to island currLine[i-1]
3. if prevLine[i] is set but currLine[i-1] is not we consider i belongs 
to island prevLine[i]
4. if both currLine[i-1] && prevLine[i] are set, we conider i belongs to 
currLine[i-1] AND we update prevLine[i] island to be currLine[i-1].

For keeping track / updating indices of islands we use Union-Find: keep a 
map(k,v) where island k is considered connected to island v. When we 
create a new island, we create k->k record, when updating k, we 
recursively traverse through all connected islands and update their values 
to the new one;
*/


public int numIslands(char[][] grid) {
        if (grid.length < 1) return 0;
        int[] firstR = readFirtsR(grid);
        Map<Integer, Integer> sets = new HashMap<>();
        int count = 0;
        // read first row and create first islands:
		// [0 1 0 0 1 0 1] => [0 1 0 0 2 0 3]
		for (int n: firstR) if (n != 0) {
            sets.put(n, n);
            count = n;
        }
        int r = 1;
        while (r < grid.length) {
            char[] line = readR(r, grid);
            int[] secondR = new int[line.length];
            for (int i = 0; i < line.length; i++) {
                if (line[i] == '1') {
                    if (i != 0 && secondR[i - 1] != 0) {
                        secondR[i] = getRoot(secondR[i - 1],sets);
                    }
                    else if (firstR[i] != 0) {
                        secondR[i] = getRoot(firstR[i], sets);
                    }
                    else {
                        count++;
                        secondR[i] = count;
                        sets.put(count, count);
                    }
                    if (firstR[i] != secondR[i] && firstR[i] != 0) {
                        updateRoots(sets.get(firstR[i]), secondR[i], sets);
                    }
                }
            }
            firstR = secondR;
            r++;
        }
        int res = 0;
        for (int k : sets.keySet()) if (sets.get(k) == k) res++;
        return res;
    }
	
    // union-find "find" part
    private int getRoot(int v, Map<Integer, Integer> sets) {
        int k = v;
        while (k != sets.get(k)) k = sets.get(k);
        return k;
    }

    // connect island k to island newVal
    private void updateRoots(int k, int newVal, Map<Integer, Integer> sets) {
        while (k != newVal) {
            int v = sets.get(k);
            sets.put(k, newVal);
            k = v;
        }
    }

    private char[] readR(int i, char[][] grid) {
        return grid[i];
    }

    //  this is ugly and probably can be done better:
	// read first line and connect adjusted '1' 
    private int[] readFirtsR(char[][] grid) {
        int[] first = new int[grid[0].length];
        char[] r = readR(0, grid);
        int count = 1;
        int start = 0;

        while (start < first.length) {
            if (r[start] == '1' &&
                    (start == 0 || r[start - 1] != '1')) first[start] = count++;
            if (start != 0 && r[start] == '1' && r[start - 1] == '1') first[start] = first[start - 1];
            start++;
        }
        return first;
    }