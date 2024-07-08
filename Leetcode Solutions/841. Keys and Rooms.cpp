class Solution {
public:
    //time - o(room+key) space-o(rooms)
    void canvisit(vector<vector<int>>&room,vector<bool>&visited,int index){
        if(visited[index]) return;
        
        visited[index] = true;
        
        for(int i=0;i<room[index].size();i++){
            canvisit(room,visited,room[index][i]);
        }
    }
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n=rooms.size();
        vector<bool>visited(n,false);
        
        canvisit(rooms,visited,0);
        
        for(int i=0;i<n;i++) if(!visited[i]) return false;
        
        return true;
    }
};