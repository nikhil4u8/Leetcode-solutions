class Solution {
public:
    //TIME - O(NlogK) SPACE - O(N+K)
   vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        priority_queue<pair<int,int>>pq;
        
        for(int i=0;i<arr.size();i++){
            pq.push({abs(arr[i]-x),i}); 
            if(pq.size()>k) pq.pop();
        }
        
        vector<int>res;
        while(!pq.empty()){
            res.push_back(arr[pq.top().second]);
            pq.pop();
        }
        
        sort(res.begin(),res.end());
        return res;
    }
    //TIME - O(logN + K) SPACE - O(1)
    //EXPANDING ALONG THE CENTER SUCH THAT WINDOW SIZE BECOME K
    vector<int> findClosestElements(vector<int>&arr,int k,int x){
        int l=0,r=arr.size()-1,index=-1,mini=INT_MAX;
        
        while(l<=r){
            int mid = (l+r)/2;
            if(arr[mid]==x){
                index = mid;
                break;
            }else if(arr[mid]>x){
                r=mid-1;
                if(abs(arr[mid]-x)<mini) index = mid;
            }else{
                l=mid+1;
                if(abs(arr[mid]-x)<=mini) index = mid;
            }
            mini = min(mini,abs(arr[mid]-x));
        }
        
        l=index;
        r=index;
        k--;
  
        while(k--){
            if(l==0) r++;
            else if(r==arr.size()-1) l--;
            else if(abs(arr[l-1]-x)<=abs(arr[r+1]-x)) l--;
            else r++;
        }
        
        return vector<int>(arr.begin()+l,arr.begin()+r+1);
    }
};