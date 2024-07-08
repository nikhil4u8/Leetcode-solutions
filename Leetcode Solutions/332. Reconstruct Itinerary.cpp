/*
Return path with smallest lexical order.

Ques to ask : 
    - Can there be self loops? When from = to i.e flight starting from 
    airport 1 and landing on airport 1 itself?
    - Can there be multiple similar link from one airport to another?
    - What to return when multiple valid iternary?
        -> smallest lexical order when read as a string
    - What is the starting point of flights?
        -> "JFK"

Sol : 
=> DFS : [TIME - O(NlogN) SPACE - O(N)]
-> N : number of flights
    - Build a graph which store mapping of all the tickets in lexicographical 
    order, and perform a DFS with source as "JFK" and while traversing we'll 
    remove the visited ticket from graph and do this until all the tickets 
    are visited, if not visited then revert changes and try another ticket &
    in end record ans vector.
*/
class Solution {
public:
    vector<string>ans;
    string min_order = "";
    bool DFS(unordered_map<string, multiset<string>>& graph, string src, vector<string>temp, int totalTicket){
        temp.push_back(src);

        if(temp.size() == totalTicket + 1){
            ans = temp;
            return true;
        }

        // visiting all tickets whose starting point is src and removing them 
        //one by one and checking if we're able to visit all tickets or not.
        for(auto it = graph[src].begin();it != graph[src].end();it++){
            string city = *it;
            
            graph[src].erase(it);
            if(DFS(graph, city, temp, totalTicket)) return true;
            it = graph[src].insert(city);
        }

        return false;
    }
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        int totalTicket = tickets.size();
        string src = "JFK";
        // Each node (airport) contains a set of outgoing edges (destination).
        unordered_map<string, multiset<string>>graph;
        // Construct the node and assign outgoing edges
        //TIME - O(NlogN)
        for(int i=0;i<totalTicket;i++)
            graph[tickets[i][0]].insert(tickets[i][1]);
        //TIME - O(N)
        DFS(graph, src, {}, totalTicket);
        return ans;
    }
};