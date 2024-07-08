class MyQueue {
public:
    //using 2 stack
    //Time - O(1) O(N) O(1) O(1)
    //Space - O(2*N)
    stack<int>s1,s2;
    int last = -1;
    MyQueue() {
        s1 = stack<int>();
        s2 = stack<int>();
    }
    void push(int x){
        if(s1.empty()) last = x;
        s1.push(x);   
    }
    int pop(){
        int size = s1.size()-1;
        while(size--){
            s2.push(s1.top());
            s1.pop();
        }
        int temp = s1.top();
        s1.pop();
        size = s2.size();
        
        if(size == 0) last = -1;
        else last = s2.top();
        
        while(size--){
            s1.push(s2.top());
            s2.pop();
        }
        return temp;
    }
    int peek() {
        return last;
    }
    bool empty() {
        return s1.empty();   
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */