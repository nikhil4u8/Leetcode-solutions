/*
Ques to ask:
    - Is words array sorted lexicographically by rule of new language?
    - Can there be cyclic input present? Ex: ["w","x","w"]
    - What to return order can't be found or input is invalid or cyclic?
    - Where to add letters whose position is unknown? In this case there 
    can be multiple order string of new language so which one to return?
    - Can word compare "" or " "? If yes, then what's their priority in 
    order?
    - Does the dict also contains upper case letter? If yes, then who 
    should we give priority to 'a' or 'A'?
    - Can words contains duplicate string?

Sol :
=> Using topological sort : [TIME - O(2*V+E) SPACE - O(V+E)]
-> V : No of vertex i.e nodes i.e char in words array
-> E : No of directed edges in graph

Step 1 : Build graph
    - Traverse the word array, and pick consecutive 2 words to compare, 
    traverse both string until we find a mismatched char which will form 
    a directed edge b/w 2 char & store this in a map. After processing 
    whole string we'll have a DAG, where each nodes points to char coming 
    after it in alien language

Step 2: Topological sort
    - Build a indegree array, where indegree[i] represent how many char 
    are present before current char
    - Now, use a queue to push all nodes having indegree == 0 & do 
    topological sort. And store the order generate from sort in a string.

Step 3 : Check cyclic
    - To check if we don't have cyclic input, in end we'll just check if 
    the order generated from topological sort has length == indegree.len. 
    Since topological sort can't be done if there are cycles, so if 
    cycles are present then order len != indegree.length

Edge case :
    - ["abc","ab"], output - invalid
    - ["w","x","w"], output - invalid (cyclic)

Follow up :
    - If alien order given is correct or not?
        -> Ref : 953. Verifying an Alien Dictionary
*/
class Solution {
public:
    // Finds the topological order of a directed Acyclic graph
    string topologicalSort(unordered_map<char, unordered_set<char>>&charExist){
        unordered_map<char, int> indegree; //SPACE - O(E)
        queue<char> q; //SPACE - O(E)
        // topological order
        string order;

        // Compute the indegree of each node
        for(auto it : charExist){
            char src = it.first;
            for(auto neighbor: charExist[src]) 
                ++indegree[neighbor];
        }

        // if current has no dependency, add and mark as visited
        for(auto it : charExist){
            char src = it.first;
            if(!indegree[it.first]) q.push(src);
        }

        // BFS traversal wrt to indegree of each node
        while(!q.empty()) {
            auto curr = q.front(); q.pop();
            order += curr;
            
            // reduce the indegree of its neighbors
            for(auto neighbor: charExist[curr]) {
                --indegree[neighbor];
                if(!indegree[neighbor]) 
                    q.push(neighbor);
            }
        }

        //reverse topo order & return
        reverse(order.begin(), order.end());
        return order.size() < charExist.size() ? "" : order;
    }
    string alienOrder(vector<string>& words) {
        if(words.size() == 0) return "";

        //SPACE - O(V)
        //curr char -> list of char ahead of curr char
        unordered_map<char, unordered_set<char>>charExist;
        //add all char present in words array
        //TIME - O(V)
        for(auto &word: words)
            for(char &ch: word)
                if(!charExist.count(ch))
                    charExist[ch] = {};
        
        //TIME - O(V)
        for(int i=1;i<words.size();i++){
            string currWord = words[i];
            string prevWord = words[i-1];
            int commonLen = min(currWord.length(), prevWord.length());

            //if curr word is a substr of prev word
            if(currWord.length() < prevWord.length() &&
              prevWord.substr(0, commonLen) == currWord) return "";

            for(int j=0;j<commonLen;j++) {
                // prevent self loop
                char src = currWord[j], dst = prevWord[j];
                // If current pos has diff chars, then make an edge and
                // break since, the current word ordering was due this 
                //positional char
                // change and anything beyond this might not follow 
                //actual order.
                if(src != dst) {
                    charExist[src].insert(dst);
                    break;
                }
            }
        }
        //TIME - O(E)
        return topologicalSort(charExist);
    }
};