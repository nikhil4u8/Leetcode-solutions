class Solution {
public:
    //TIME - O(N) SPACE - O(1)
    //TWO PASS SOL
//     bool canTransform(string start, string end){
//         int len = start.length();
        
//         for(int i=0;i<len;i++){
//             if(end[i] == 'R' && start[i] != 'R'){
//                 int j = i;
//                 while(j>=0 && (start[j] != 'R' || (start[j] == 'R' && end[j] == 'R'))){ 
//                     if(start[j] == 'L') return false;
//                     j--;
//                 }
//                 if(j == -1) return false;
//                 swap(start[i], start[j]);
//             }   
//         }
        
//         for(int i=len-1;i>=0;i--){
//             if(end[i] == 'L' && start[i] != 'L'){
//                 int j = i;
//                 while(j<len && (start[j] != 'L' || (start[j] == 'L' && end[j] == 'L'))){
//                     if(start[j] == 'R') return false;
//                     j++;
//                 }
//                 if(j == len) return false;
//                 swap(start[i], start[j]);
//             }
//         }
        
//         return start == end;
//     }
    //TIME - O(N) SPACE - O(1)
    //ONE PASS SOL
    bool canTransform(string start, string end){
        int i = 0, j = 0;
        while(i < start.length() && j < end.length()){
            while(i<start.length() && start[i] == 'X') i++;
            while(j<end.length() && end[j] == 'X') j++;
            
            if(i == start.length() || j == end.length()) break;
            
            if(start[i] != end[j]) return false;
            if(start[i] == 'R' && i>j) return false;
            if(start[i] == 'L' && i<j) return false;
            
            i++;
            j++;
        }
        
        while(i<start.length() && start[i] == 'X') i++;
        while(j<end.length() && end[j] == 'X') j++;
        
        return i == start.length() && j == end.length();
    }
};