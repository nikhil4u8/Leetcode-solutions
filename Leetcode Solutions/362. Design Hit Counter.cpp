class HitCounter {
public:
    //TIME - O(1) O(logN)
    //Space - O(N)
    vector<int>v;
    HitCounter() {
        v = vector<int>();
    }
    void hit(int timestamp) {
        v.push_back(timestamp);
    }
    int getHits(int timestamp) {
        int target = max(0,timestamp - 300 + 1);
        int start = 0, end = v.size()-1, ans = v.size();

        while(start <= end){
            int mid = start + (end - start)/2;
            if(v[mid] < target) start = mid + 1;
            else{
                ans = mid;
                end = mid - 1;
            }
        }

        return  v.size() - ans;
    }
    
    //Time - O(1) O(N)
    //Space - O(N)
    //Expandable for larger scale
    vector<int>times;
    vector<int>hits;
    HitCounter(){
        times = vector<int>(300,0);
        hits = vector<int>(300,0);
    }
    void hit(int timestamp) {
        int temp = timestamp % 300;
        if(times[temp] != timestamp) hits[temp] = 0;
        times[temp] = timestamp;
        hits[temp]++;
    }
    int getHits(int timestamp) {
        int res = 0;
        for(int i=0;i<300;i++){
            if(times[i] > timestamp-300) res += hits[i];
        }
        
        return res;
    }
};

Follow up: What if the number of hits per second could be huge? Does your design scale?
    Basic ideas:
        Rolling Counter
        Staged Aggregator
        Partition

    Here's how to scale up this problem to handle high traffic and concurrency:
    http://blog.gainlo.co/index.php/2016/09/12/dropbox-interview-design-hit-counter/
    https://www.geeksforgeeks.org/design-a-hit-counter/

    The main approaches from simplest to most scalable are:

    Simple table and SQL query O(N)
    LinkedList  
    Circular buffer
    Circular buffer with locks
    Distributed circular buffer - partition the user set by the hash of user id and have circular buffer for each partition. The total count will be the sum of each of the circular buffers
    A distributed circular buffer (#5) could be a scalable approach to handle a high volume of user visits