//in Windows, given a h, w and m. Generate a matrix with height h, 
//width w, and total m mines. It is required that m mines are randomly 
//distributed.

/*
Ques to ask : 
    - Do we need to have different mineswepper every time?
    - Do we need to fill up the adjacent boxes too?

Sol : Take a array of size count (no of mines) which will represent a 2D
array in 1D, it'll have position of mines in a 2D array like cordinate
[(1,2) -> 1*w + 2] in bombloc, and we'll fill it with 0-count-1 then to 
randomize it, we'll run a loop from i = count to w*h, and if we find 
random num < count, then we'll change position of that element in bombloc, 
Now, we'll just go through bombLoc array and find cordinates from it and 
fill it with 1.

TIME - O(N) SPACE - O(N)
N -> no of mines
*/
Time: O(n)

vector<vector<int>> putBomb(int h, int w, int count){
    vector<int>bombLocs(count, 0);
    for(int i=0;i<count;i++) bombLocs[i] = i;

    for(int i=count;i<h*w;i++){
        int j = rand() % (i+1);
        if(j < count) bombLocs[j] = i;
    }

    vector<vector<int>>res(h, vector<int>(w, 0));
    for(int i=0;i<count;i++){
        int x = bombLocs[i] / w;
        int y = bombLocs[i] % w;
        res[x][y] = 1;
    }
    return res;
}