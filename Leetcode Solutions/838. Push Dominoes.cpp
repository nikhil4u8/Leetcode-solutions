class Solution {
public:
//First say expand around the dot approach
//Problem with that approach -> ex. R..L -> according to also,1th index dot will have R =>2nd will 
//remain as dot. =>my algo predict the stage depending upon prev element, but the state of all element
//would be decided at the same time.

    //TIME - O(N) SPACE - O(N)
    //Just keep a track of distance from nearest left in left array and nearest right in right array
    //The one which has smaller dist will have more influence on that point
    //If both are equal it implies no change to that domino
    string pushDominoes(string dominoes) {
        int n = dominoes.length();
        vector<int>left_force(n,0);
        vector<int>right_force(n,0);
        int len = -1;
        char prev = '.';
        
        for(int i=n-1;i>=0;i--){
            if(dominoes[i]=='L'){
                prev = 'L';
                len = 1;
            }else if(dominoes[i]=='.'){
                if(prev == 'L') left_force[i] = len;
                len++;
            }else{
                prev = 'R';
                len = 0;
            }
        }
        
        len = -1;
        prev = '.';
        for(int i=0;i<n;i++){
            if(dominoes[i]=='R'){
                prev = 'R';
                len = 1;
            }else if(dominoes[i]=='.'){
                if(prev == 'R') right_force[i] = len;
                len++;
            }else{
                prev = 'L';
                len = 0;
            }
        }
        
        for(int i=0;i<n;i++){
            if(dominoes[i] == '.'){
                if(right_force[i] == left_force[i]) continue;
                if(right_force[i] == 0 && left_force[i]!=0) dominoes[i] = 'L';
                else if(right_force[i]!=0 && left_force[i]==0) dominoes[i] = 'R';
                else if(right_force[i]>left_force[i]) dominoes[i] = 'L';
                else if(right_force[i]<left_force[i]) dominoes[i] = 'R';
            }
        }
        
        return dominoes;
    }
};