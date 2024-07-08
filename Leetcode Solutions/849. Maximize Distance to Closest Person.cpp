class Solution {
public:
//finding mid between 2 elements and then maximizing the
//min distance between 2 closest person.
//TIME - O(N) SPACE - O(1)
    int maxDistToClosest(vector<int>& seats) {
        int last = -1, ans = INT_MIN, n = seats.size();

        for(int i=0;i<n;i++){
            if(seats[i] == 1){
                if(last == -1){
                    if(seats[0] == 0) ans = max(ans, i);
                    last = i;
                    continue;
                }
                int mid = (last + i)/2;
                ans = max(ans, min(abs(mid - last),abs(mid - i)));
                last = i;
            }
        }

        if(seats[n-1] == 0) ans = max(ans, abs(n - 1 - last));
        return ans;
    }
};