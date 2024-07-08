/*
Ques to ask:
    - Window size = 0?
    - What if when we don't have enough element in window, in initially 
    processing?

Sol :
=> Linearly calculating sum : [TIME - O(1) O(size) SPACE - O(size)]
    - Maintain a queue of size = window size, whenever next() is called 
    traverse queue and find the sum then divide by total elements in 
    queue & return avg

BEST APPROACH
=> Using queue & Mainting prev Sum : [TIME - O(1) O(1) SPACE - O(size)]
    - We use queue to maintain the num inside of the window. We'll also
    maintain sum until now in a variable, when size of queue become equal 
    to window size then we pop out first element from queue & subtract it 
    from sum and push the new element & add it sum, if in case queue size 
    is not same as window size then keep on adding sum and dividing by 
    queue.size()

Edge case :
    - Actual Window size < window size
    - Window size == 0
    - When sum of queue overflow INT val?
        -> our code covers all edge case
*/
class MovingAverage {
public:
//BEST APPROACH
//TIME - O(1) O(1) SPACE - O(size)
    double maxWindowSize, currAvg;
    queue<int>window;
    MovingAverage(int size) {
        maxWindowSize = size;
        currAvg = 0;
    }
    
    double next(int val) {
        if(window.size() == maxWindowSize){
            currAvg = (val + currAvg*window.size()-window.front())/window.size();
            window.pop();
        }else currAvg = (val + currAvg*window.size())/(window.size() + 1);

        window.push(val);
        return currAvg;
    }
};