class MyStack {
public:
    //Using 2 queue
    queue<int>q1,q2;
    int last;
    MyStack() {
        q1 = queue<int>();
        q2 = queue<int>();
        last = -1;
    }
    
    void push(int x) {
        q1.push(x);
        last = x;
    }
    
    int pop() {
        while(q1.size()!=1){
            q2.push(q1.front());
            q1.pop();
        }
        int ans = q1.front();
        q1.pop();
        while(!q2.empty()){
            q1.push(q2.front());
            last = q2.front();
            q2.pop();
        }
        return ans;
    }
    
    int top(){
        return last;
    }
    
    bool empty(){
        return q1.empty();
    }
    
    //FOllow up
    //do using one queue
    queue<int>q;
    MyStack(){
        q = queue<int>();
    }
    void push(int x){
        q.push(x);
        int size = q.size();
        while(size>1){
            q.push(q.front());
            q.pop();
            size--;
        }
    }
    int pop(){
        int ans = q.front();
        q.pop();
        return ans;
    }
    int top(){
        return q.front();
    }
    bool empty(){
        return q.empty();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */