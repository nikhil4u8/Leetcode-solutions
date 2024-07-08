/*BrowserHistory(string homepage) Initializes the object with the homepage of the browser.

void visit(string url) Visits url from the current page. It clears up all the forward history.

string back(int steps) Move steps back in history. If you can only 
return x steps in the history and steps > x, you will return only x 
steps. Return the current url after moving back in history at most steps.

string forward(int steps) Move steps forward in history. If you can only 
forward x steps in the history and steps > x, you will forward only x 
steps. Return the current url after forwarding in history at most steps.
*/
class BrowserHistory {
public:
//TIME - O(N) O(1) O(steps) O(steps)
//using 2 stacks
class BrowserHistory {
public:
    //space - o(n)
    stack<string>next;
    stack<string>prev;
    string curr = "";
    
    BrowserHistory(string homepage) {
        curr = homepage;    
    }
    //time - O(1)
    void visit(string url) {
        next = stack<string>();
        prev.push(curr);
        curr = url;
    }
    //time - o(steps)
    string back(int steps) {
        while(steps-- && !prev.empty()){
            next.push(curr);
            curr = prev.top();
            prev.pop();
        }
        return curr;
    }
    //time - o(steps) 
    string forward(int steps) {
        while(steps-- && !next.empty()){
            prev.push(curr);
            curr = next.top();
            next.pop();
        }
        return curr;
    }
};
//TIME - O(1) O(1) O(steps) O(steps)
    //Made using doubly Linked List 
    struct Node{
        string url;
        Node* next;
        Node* prev;
    };
    //time - O(1)
    Node* root,*curr;
    BrowserHistory(string homepage) {
        root = new Node();
        root->url = homepage;
        curr = root;
    }
    //time - O(1)
    void visit(string url) {
        Node* temp = new Node();
        temp->url = url;

        curr->next = temp;
        temp->prev = curr;
        
        curr = temp;
    }
    //time - O(steps)
    string back(int steps) {
        while(steps-- && curr->prev) curr = curr->prev;
        return curr->url;
    }
    //TIME - O(steps)
    string forward(int steps) {
        while(steps-- && curr->next) curr = curr->next;
        return curr->url;
    }
};
//TIME - O(1) O(1) O(1) O(1)
//using single array
class BrowserHistory {
private:
    int pos;
    int end;
    vector<string> history;
public:
    //O(1)
    BrowserHistory(string homepage) {
        history.push_back(homepage);
        pos = 0;
        end = 0;
    }
    //O(1)
    void visit(string url) {
        pos++;
        if (pos == history.size()) history.push_back(url);
        else history[pos] = url;
        
        end = pos;
    }
    //O(1)
    string back(int steps) {
        pos = max(0, pos - steps);
        return history[pos];
    }
    //O(1)
    string forward(int steps) {
        pos = min(end, pos + steps);
        return history[pos];
    }
};
