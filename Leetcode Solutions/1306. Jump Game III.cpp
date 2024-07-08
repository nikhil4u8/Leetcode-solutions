class Solution {
public:
    bool canReach(vector<int>& arr, int start) {
        if(arr[start] == 0) return true;
        
        int n = arr.size();
        queue<int>q;
        q.push(start);
        
        while(!q.empty()){
            int size = q.size();
            while(size--){
                int top = q.front(); q.pop();
                
                if(arr[top] == 0) return true;

                if(top + abs(arr[top]) < n && arr[top + abs(arr[top])] >= 0){
                    if(arr[top + abs(arr[top])] == 0) return true;
                    q.push(top+abs(arr[top]));
                    arr[top + abs(arr[top])] *= -1;
                }
                if(top - abs(arr[top]) >= 0 && arr[top - abs(arr[top])] >= 0){
                    if(arr[top - abs(arr[top])] == 0) return true;
                    q.push(top-abs(arr[top]));
                    arr[top - abs(arr[top])] *= -1;
                }
            }
        }
        
        return false;
    }
};