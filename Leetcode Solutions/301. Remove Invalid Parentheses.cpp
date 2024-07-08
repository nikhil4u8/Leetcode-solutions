/*
Ques to ask:
    - Do we have alphabets / number in b/w brackets & do we need to return 
    them too along with bracket string?
    - Is there any specific order of output?
    - Is empty string a valid string?
    - Do we've only 1 type of bracket?

Sol :
=> Backtracking : [TIME - O(n*2^n) SPACE - O(N)]
    - Since we don't know which bracket to remove, so we try all options 
    using recursion. For each bracket, either we keep it or remove it, 
    now recursion will generate all the valid & invalid paranthese string, 
    but we want a string which has valid paranthese & minimum deletion, 
    so in recursive fun we'll keep track of total deletion happened in a 
    particular string, if deletion is minimum then push string in ans 
    vector else ignore it.

BEST APPROACH
=> Improved Backtracking : [TIME - O(N*2^n) SPACE - O(N)]
    - Instead of removing all brackets one by one & generating all 
    possibility of brackets, we can initally check how many minimum 
    removal are required then call a recursive function (pass minRemoval 
    in it) & remove every bracket & if minRemoval reaches 0, then check 
    if the string formed is valid or not, if it is then add it to ans, 
    else ignore

BEST APPROACH [RECOMMENDED]
=> BFS : [TIME - O(N*2^N) SPACE - O(N)]
    - To find valid string with least number of changes, we can use BFS 
    and traverse levels, where each levels represent number of changes / 
    removals in the string then we will be able to find the valid string 
    corresponding to each levels. 
        #Eg.
        # starting = "()())()"
        # Level 0 -> no valid string
        # Level 1 -> "()()()", "(())()"
        # Level 2 -> no valid string
        # Level 3 -> "()()", "(())"
    - Since we want to minimize the change, so we will stop traversing 
    into additional levels whenever we encounter a valid string in a level 
    & just explore that same level to find out more valid strings.

TIME / SPACE COMPLEXITY EXPLANATION : See at last
*/
class Solution {
public:
//BEST APPROACH
//Using BFS
//TIME - O(N*2^N) SPACE - O(N*2^N)
    bool isValid(string str){
        int open = 0, close = 0;
        for(int i=0;i<str.length();i++){
            if(str[i] == '(') open++;
            else if(str[i] == ')') close++;
            if(open < close) return false;
        }
        return open == close;
    }
    vector<string> removeInvalidParentheses(string s) {
        if(s == "") return {};

        vector<string>ans;
        bool levelFound = false;
        queue<string>q;
        unordered_set<string>seen;

        // initialize
        q.push(s);
        seen.insert(s);

        while(!q.empty()){
            string str = q.front(); q.pop();

            if(isValid(str)){
                // found an answer, add to the result
                ans.push_back(str);
                levelFound = true;
            }

            if(levelFound) continue;

            // generate all possible states
            string leftStr = "";
            for(int i=0;i<str.length();i++){
          //remove one char & if it's not seen before then add it to queue
                string tempStr = leftStr + str.substr(i+1);
                leftStr += str[i];
                // we only try to remove left or right paren
                if(!(str[i] == ')' || str[i] == '(')) continue;

             // for each state, if it's not visited, add it to the queue
                if(!seen.contains(tempStr)){
                    seen.insert(tempStr);
                    q.push(tempStr);
                } 
            }
        }

        return ans;
    }
//BEST APPROACH
//optimized Backtracking
//TIME - O(n*2^n) SPACE - O(n*2^n)
    unordered_set<string>memoVisited;
    unordered_set<string>ans;
    int getMinRemoval(string s){
        int open = 0, close = 0, removal = 0;
        for(int i=0;i<s.length();i++){
            if(s[i] == '(') open++;
            else if(s[i] == ')') close++;

            if(open < close){
                removal += close - open;
                open = 0; close = 0;
            }
        }

        removal += open - close;
        return removal;
    }    
    void removeAndCheck(string s, int idx, int totalDeletionLeft){
        if(memoVisited.find(s) != memoVisited.end()) return;
        memoVisited.insert(s);

        if(totalDeletionLeft == 0){
            if(getMinRemoval(s) == 0) ans.insert(s);
            return;
        }

        string leftStr = s.substr(0, idx);
        for(int i=idx;i<s.length();i++){
            string tempStr = leftStr + s.substr(i+1);
            leftStr += s[i];
            if(s[i] == '(' || s[i] == ')')
                removeAndCheck(tempStr, i, totalDeletionLeft-1);
        }
    }
    vector<string> removeInvalidParentheses(string s) {
        int minRemoval = getMinRemoval(s);
        removeAndCheck(s, 0, minRemoval);
        return vector<string>(ans.begin(), ans.end());
    }
};

/*
TC EXPLANATION
Len of string = N, every character have 2 states "keep/remove", that is 
2^n states and for every state we do 2 things -> build the string which 
is O(n) and another O(n) to check if its valid or not. TC will be 
2^n * O(2n) = O(N*2^N)

SPACE EXPLANATION
We have to go to a maximum recursion depth of N before hitting the base 
case. We are not considering the space required to store the valid 
expressions. We only count the intermediate space here.

Since we've 2^n states & to store these states in queue we'd require 
O(N*2^N) space complexity in worst case scenerio
*/