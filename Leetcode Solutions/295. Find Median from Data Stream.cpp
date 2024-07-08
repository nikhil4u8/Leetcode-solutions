class MedianFinder {
public:
    //Approach-1
    //while finding median sort the array and return middle element
    
    //Approach - 2
    //Using 2 heaps
    //TIME - O(logN) Space - O(N)
    priority_queue<int>max_heap;
    priority_queue<int,vector<int>,greater<int>>min_heap;
    MedianFinder() {
        max_heap = priority_queue<int>();
        min_heap = priority_queue<int,vector<int>,greater<int>>();
    }
    void addNum(int num) {
        if(max_heap.size() == min_heap.size()){
            if(max_heap.size() == 0) max_heap.push(num);
            else{
                if(num >= max_heap.top()){
                    min_heap.push(num);
                    max_heap.push(min_heap.top());
                    min_heap.pop();
                }else max_heap.push(num);
            }
        }else{
            if(num >= max_heap.top()) min_heap.push(num);
            else{
                max_heap.push(num);
                min_heap.push(max_heap.top());
                max_heap.pop();
            }
        } 
    }
    double findMedian() {
        if(max_heap.size() == min_heap.size()) return ((double)(min_heap.top()+max_heap.top()))/2;
        return max_heap.top();
    }
};