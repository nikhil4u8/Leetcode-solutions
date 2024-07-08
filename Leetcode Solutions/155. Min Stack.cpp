class MinStack {
public:
    //Approach - 1 
    //uSING 2 STACKS
    stack<int>sta;
    stack<int>min_stack;
    MinStack() {
        sta = stack<int>();
        min_stack = stack<int>();
    }
    
    void push(int val) {
        if(!min_stack.empty() && min_stack.top()>=val) min_stack.push(val);
        else if(min_stack.empty()) min_stack.push(val);
        sta.push(val);
    }
    
    void pop() {
        if(min_stack.top() == sta.top()) min_stack.pop();
        sta.pop();
    }
    
    int top() {
        return sta.top();
    }
    
    int getMin() {
        return min_stack.top();
    }
    
    //APPROACH - 2
    //Using 1 stack
    stack<pair<int,int>>min_stack;
    MinStack() {
        min_stack = stack<pair<int,int>>();
    }
    
    void push(int val) {
        if(!min_stack.empty() && min_stack.top().second<=val) 
            min_stack.push({val,min_stack.top().second});
        else min_stack.push({val,val});
    }
    
    void pop() {
        min_stack.pop();
    }
    
    int top() {
        return min_stack.top().first;
    }
    
    int getMin() {
        return min_stack.top().second;
    }
    
    //APPROACH - 3
    //putting 2*x - mini instead of actual element
    stack<long long int>min_stack;
    long long int mini;
    MinStack() {
        min_stack = stack<long long int>();
        mini = INT_MAX;
    }
    
    void push(int val) {
        long long int temp = val;
        if(val<=mini){
            if(!min_stack.empty()) temp = 2*((long long)val) - mini;
            mini = val;
        }
        min_stack.push(temp);
    }
    
    void pop() {
        if(min_stack.top()<=mini) mini = 2*mini - min_stack.top();
        min_stack.pop();
        if(min_stack.empty()) mini = INT_MAX;
    }
    
    int top(){
        if(min_stack.top()<mini) return mini;
        return min_stack.top();
    }
    
    int getMin() {
        return mini;
    }
    
};
class MinStack {
public:
    vector<pair<int,int>>v;
    int mini;
    MinStack() {
        mini = INT_MAX;
    }
    void push(int val) {
        if(v.size() != 0) mini = min(v[v.size()-1].second,val);
        else mini = val;
        v.push_back({val, mini});   
    }
    void pop() {
        v.pop_back();   
    }
    int top() {
        return v[v.size()-1].first;   
    }
    int getMin() {
        return v[v.size()-1].second;   
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */