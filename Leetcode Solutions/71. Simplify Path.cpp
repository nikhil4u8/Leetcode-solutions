/*
Ques to ask :
    - What to do when "...." comes?
    - What to return when str = "/" or empty?
Sol :
BEST APPROACH
=> Using Stack : [TIME - O(N) SPACE - O(N)]
    - If we break down the path into "tokens" by spliting string by "/", 
    valid "tokens" are ".", "..", "fileName"
    - If we encounter tokens :
        - "." -> ignore it
        - ".." -> remove last token which is some fileName
        - "fileName" -> append it to path
    - We can store these tokens in a stack, for easy removal & addition. 
    In end append all elements present in stack to a string & return.

=> Without using Stack : [TIME - O(2*N) SPACE - O(1)]
-> Implementation give below
    - Maintain a path string to store simplified path & traverse the string
    & whenever we encounter :
        - "." -> ignore it
        - ".." -> traverse path str in backward dir & remove last file
        - "FileName" -> add it to path string
*/
class Solution {
public:
//BEST APPROACH
//Using Stack
//TIME - O(N) SPACE - O(N)
    void doOperation(string fileName, stack<string>&sta){
        //pop the last fileName if exist
        if(fileName == ".."){
            if(!sta.empty()) sta.pop();
        }else if(fileName != "." && fileName != "") 
            sta.push(fileName); //If it's a fileName then push
    }
    string simplifyPath(string path) {
        stack<string>sta;
        string fileName = "";
        int n = path.length();

        //looping through string
        for(int i=0;i<n;i++){
            //process the file, weather to go back / push it in stack
            if(path[i] == '/'){
                doOperation(fileName, sta);
                fileName = ""; //reset fileName
            }else{
                fileName += path[i];
                
                //After last char for loop will stop, and fileName won't
                //be processed, so processing it
                if(i == n-1) doOperation(fileName, sta);
            }
        }

        string ans = "";
        //adding all the elements in stack to ans
        while(!sta.empty()){
            ans = "/" + sta.top() + ans;
            sta.pop();
        }

        // if no directory or file is present
        if(ans == "") return "/";
        return ans;
    }
};

//WITHOUT USING STACK
class Solution {
public:
//TIME - O(2*N) SPACE - O(1)
    void addFile(string &path, string fileName){
        path += "/" + fileName;
    }
    void removeFile(string &path){
        int lastIdx = path.length()-1;
        while(lastIdx >= 0){
            char lastChar = path[lastIdx];
            path.pop_back();
            if(lastChar == '/') return;
            lastIdx--;
        }
    }
    void doOperation(string fileName, string &pathStr){
        //pop the last fileName if exist
        if(fileName == "..") removeFile(pathStr);
        else if(fileName != "." && fileName != "")
            addFile(pathStr, fileName); //If it's a fileName then push
    }
    string simplifyPath(string path) {
        string fileName = "", pathStr = "";
        int n = path.length();

        for(int i=0;i<n;i++){
            if(path[i] == '/'){
                doOperation(fileName, pathStr);
                fileName = "";
            }else{
                fileName += path[i];
                
                if(i == n-1) doOperation(fileName, pathStr);
            }
        }

        return pathStr == "" ? "/" : pathStr;
    }
};