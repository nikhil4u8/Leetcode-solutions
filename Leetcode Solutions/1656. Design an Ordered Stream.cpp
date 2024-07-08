/*
Ques to ask? :-
    - Can the input be ""?
    - Is idKey indexed from 0 / 1?
    - do we need to return ans from index 0 - curr idx or from ptr - curr idx

Follow up :-
    - Solve if N is not given?
    - How to make it more space efficient? -> removing previous used keys.
*/

//TIME - O(N) SPACE - O(N), N -> max(idKey - ptr), diff b/w idKey and ptr
//Follow up :- If N is not given
class OrderedStream {
public:
    unordered_map<int, string>vec;
    int ptr = 1;
    OrderedStream() {
    }
    vector<string> insert(int idKey, string value) {
        vector<string>ans;
        vec[idKey] = value;

        while(vec.find(ptr) != vec.end()){
            ans.push_back(vec[ptr++]);
            vec.erase(ptr-1);
        }
        return ans;
    }
};

//TIME - O(N) SPACE - O(N), N -> max(idKey - ptr), diff b/w idKey and ptr
class OrderedStream {
public:
    vector<string>vec;
    int ptr = 0;
    OrderedStream(int n) {
        vec.resize(n, "");
    }
    
    vector<string> insert(int idKey, string value) {
        vec[idKey-1] = value;

        vector<string>ans;
        while(ptr<vec.size() && vec[ptr] != "") ans.push_back(vec[ptr++]);
        //remove used keys as well, so use unordered_map instead of vector
        return ans;
    }
};