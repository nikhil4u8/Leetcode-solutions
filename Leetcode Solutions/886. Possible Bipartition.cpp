class Solution {
public:
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        unordered_map<int, vector<int>>mp;
        
        for(int i=0;i<dislikes.size();i++){
            mp[dislikes[i][0]].push_back(dislikes[i][1]);
            mp[dislikes[i][1]].push_back(dislikes[i][0]);
        }

        vector<int>visited(n, false);
        vector<int>color(n, 0);

        bool once = true;
        queue<int>q;
        color[0] = 1;
        visited[0] = true;
        q.push(1);

        //A normal BFS
        while(!q.empty()){
            int size = q.size();
            while(size--){
                int curr = q.front();
                q.pop();

                int c = color[curr-1];

                //coloring children of curr with opposite color
                for(int i = 0;i<mp[curr].size();i++){
                    if(!visited[mp[curr][i]-1]){
                        visited[mp[curr][i]-1] = true;
                        color[mp[curr][i]-1] = 0 - c;
                        q.push(mp[curr][i]);
                    }else if(color[mp[curr][i]-1] + c != 0) //if they're of different color then sum is 0 
                        return false;
                }
            }

            //If there are left over elements who are not colored
            if(q.empty()){
                for(int i=0;i<n;i++){
                    if(!visited[i]){
                        visited[i] = true;
                        color[i] = 1;
                        q.push(i+1);
                        break;
                    }
                }
            }
        }

        return true;
    }
};