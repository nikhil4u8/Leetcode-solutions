/*
Approach should be discussed in interview :-
1. Converting encoding array to a single array and traversing it
2. Using a last_idx pointer and traversing the arrya until our next "n" is reached
3. Using Binary Search
*/
//Approach - 2
//TIME - O(1) O(N)
//SPACE - O(N)
// class RLEIterator {
// public:
//     int last_idx;
//     vector<int>arr;
//     RLEIterator(vector<int>& encoding) {
//         last_idx = 0;
//         arr = encoding;
//     }
    
//     int next(int n) {
//         while(last_idx < arr.size() && n > arr[last_idx]){
//             n -= arr[last_idx];
//             last_idx += 2;
//         }
        
//         if(last_idx == arr.size()) return -1;
        
//         arr[last_idx] -= n;
        
//         if(arr[last_idx] == 0){
//             last_idx += 2;
//             return arr[last_idx - 1];
//         }
//         return arr[last_idx + 1];
//     }
// };
//Approach - 3
class RLEIterator {
public:
    vector<long>arr;
    long total, limit;
    RLEIterator(vector<int>& encoding){
        total = 0;
        for(int i=0;i<encoding.size();i++){
            arr.push_back(encoding[i]);
            if(i % 2 == 0 && i != 0) arr[i] += arr[i-2];
        }
        limit = arr[arr.size()-2];
    }
    int next(int n) {
        total += (long)n;
        if(total > limit) return -1;
        
        long i = 0, j = arr.size()-2;
        while(i < j){
            long mid = (i+j)/2;
            if(mid % 2 != 0) mid--;
            
            if(total <= arr[mid]) j = mid;
            else i = mid + 2;
        }
        
        return arr[j+1]; 
    }
};