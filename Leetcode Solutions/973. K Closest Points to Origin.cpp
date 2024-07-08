/*
Ques to ask ?
    - When dist of 2 points are similar, but we can take only 1?
    - In what order to return?

Sol : 
=> Brute Force - [TIME - O(NlogN) SPACE - O(N)]
    - Store dist of all points in array mapped to their idx & sort the 
    array & return first K elements

=> BEST APPROACH - Heap Sort - [TIME - O(NlogK) SPACE - O(K)]
    - Use max heap to store all elements & find K closest.
   
BEST APPROACH : [If asked to optimize more]
=> Quick Select : [TIME - O(N) SPACE - O(N)]
    - Firstly, we select a pivot (last element of array) then traverse the
    array & swap all elements one by one & find a position for pivot such
    that elements before pivot are < pivot & element after pivot are > pivot
    - We'll stop our search if pivot idx == k, if pivot_idx > k then we
    reduce search space to second half of array, if pivot_idx < k then we
    reduce search space to first half of array.
    - Once we find pivot with idx == k, then we'll return element of first
    half of array in sorted manner.

NOTE : The avg time complexity of Quick select is O(N), since we're reducing
search space after every pivot is placed, but in worst cast time complexity
is O(N^2) i.e in case of constantly bad chosen pivot, the search space is
not divided in half at each step, it just become one element less this leads
to O(N^2)
*/
class Solution {
public:
//BEST APPROACH
//  TIME - O(NlogK) SPACE - O(K)
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<double, pair<int, int>>>pq;
        for(int i=0;i<points.size();i++){
            int x = points[i][0];
            int y = points[i][1];

            double dist = sqrt(x*x + y*y);

            pq.push({dist, {x, y}});
            if(pq.size() > k) pq.pop();
        }

        vector<vector<int>>ans;
        while(!pq.empty()){
            ans.push_back({pq.top().second.first, pq.top().second.second});
            pq.pop();
        }

        return ans;
    }
};

//QUICK SELECT
//TIME - O(N) 
//SPACE - O(N) -> for using duplicate dist array
    public int[][] kClosest(int[][] points, int K) {
        int pointsLen = points.length;
        // distances[i][0] is distance, distances[i][1] is index in points
        int[][] distances = new int[pointsLen][2];
        
        // Get all distances
        for (int i = 0; i < pointsLen; i++) {
            int distance = getDistance(points[i]);
            distances[i][0] = distance;
            distances[i][1] = i;
        }
        
        quickSelect(K, distances, 0, pointsLen - 1);
        
        // Get first K
        int[][] result = new int[K][2];
        for (int i = 0; i < K; i++) {
            result[i] = points[distances[i][1]];
        }
        
        return result;
    }
    
    // Find smallest K distances
    private void quickSelect(int K, int[][] distances, int start, int end) {
        if (start >= end) return;
        
        // Choose the element at start as pivot.
        int pivot = distances[start][0];
        // Put pivot into right position wall
        int wall = end + 1;
        for (int i = end; i > start; i--) {
            if (distances[i][0] >= pivot) {
                wall--;
                swap(i, wall, distances);
            }
        }
        wall--;
        swap(start, wall, distances);
        
        if (wall + 1 == K) return;
        else if (wall + 1 < K) quickSelect(K, distances, wall + 1, end);
        else quickSelect(K, distances, start, wall - 1);
    }
    
    private int getDistance(int[] point) {
        return point[0] * point[0] + point[1] * point[1];
    }
    
    private void swap(int i, int j, int[][] distances) {
        int[] temp = distances[i];
        distances[i] = distances[j];
        distances[j] = temp;
    }