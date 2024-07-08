class Solution {
public:
    string getHint(string secret, string guess) {
        vector<int>temp(10, 0);
        int bull = 0, cow = 0;
        
        for(int i=0;i<secret.length();i++){
            if(secret[i] == guess[i]) bull++;
            else{
                if(temp[secret[i] - '0'] < 0) cow++;
                if(temp[guess[i] - '0'] > 0) cow++;
                
                temp[secret[i] - '0']++;
                temp[guess[i] - '0']--;
            }
        }
        
        return to_string(bull) + 'A' + to_string(cow) + 'B'; 
    }
//     string getHint(string secret, string guess) {
//         int bull = 0, cow = 0;
        
//         for(int i=0;i<secret.length();i++){
//             if(secret[i] == guess[i]) bull++;
//         }
        
//         sort(secret.begin(), secret.end());
//         sort(guess.begin(), guess.end());
//         int j=0;
        
//         for(int i=0;i<secret.length() && j<guess.length();){
//             if(secret[i] == guess[j]){
//                 cow++;
//                 i++;
//                 j++;
//             }else if(secret[i] < guess[j])
//                 i++;
//             else j++;
//         }
        
//         cow -= bull;
//         return to_string(bull) + 'A' + to_string(cow) + 'B';
//     }
};