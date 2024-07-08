/*
Ques to ask:
    - Is the graph connected or unconnected?
    
Sol:
=> Using BFS / DFS
    - Make a map and map all the old nodes to their new node and then 
traverse the old graph using BFS/DFS along side connect new node as well
*/
class Solution {
public:
//Using DFS
//TIME - O(N) SPACE - O(N)
    unordered_map<Node*,Node*>mp;
    void solve(Node* node){
        if(!mp[node]) mp[node] = new Node(node->val);
        else return;
        
        for(int i=0;i<node->neighbors.size();i++){
            solve(node->neighbors[i]);
            mp[node]->neighbors.push_back(mp[node->neighbors[i]]);
        }
    }
    Node* cloneGraph(Node* node) {
        if(!node) return NULL;
        solve(node);
        return mp[node];
    }
};
//Using BFS
//TIME - O(N) SPACE - O(N)
class Solution {
public:
    unordered_map<Node*, Node*>mp;
    Node* cloneGraph(Node* node) {
        if(!node) return NULL;
        
        Node* cloneNode = new Node(node->val);
        mp[node] = cloneNode;

        //used to check if a node has ever been in queue
        unordered_map<Node*, bool>inQueue;
        queue<Node*>q;

        q.push(node);
        inQueue[node] = true;

        while(!q.empty()){
            int size = q.size();
            while(size--){
                Node* currNode = q.front(); q.pop();

                //creating neighbor mapping in cloned graph
                for(int i=0;i<currNode->neighbors.size();i++){
                    Node* childNode = currNode->neighbors[i];

                    if(mp.find(childNode) == mp.end())
                        mp[childNode] = new Node(childNode->val);
                    
                    mp[currNode]->neighbors.push_back(mp[childNode]);

                    if(inQueue.find(childNode) == inQueue.end()){
                        q.push(childNode);
                        inQueue[childNode] = true;
                    }
                }
            }
        }

        return mp[node];
    }
};