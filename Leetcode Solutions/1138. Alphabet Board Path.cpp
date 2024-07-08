class Solution {
public:
    string alphabetBoardPath(string target) {
        unordered_map<char, pair<int, int>>mp;
        for(int i=0;i<=5;i++){
            for(int j=0;j<5;j++){
                mp['a'+i*5+j] = {i, j};
                if(i*5 + j == 25) break;
            }
        }
        
        int curr_x = 0, curr_y = 0;
        string res = "";
        
        for(int i=0;i<target.length();i++){
            char x = target[i];
            int x_diff = mp[x].first - curr_x;
            int y_diff = mp[x].second - curr_y;
            
            if(x == 'z' && curr_y > 0) x_diff--;
            
            if(x_diff > 0){
                while(x_diff-- > 0) res += 'D';
            }else{
                while(x_diff++ < 0) res += 'U';
            }
            
            if(y_diff > 0){
                while(y_diff-- > 0) res += 'R';
            }else{
                while(y_diff++ < 0) res += 'L';
            } 
            
            if(x == 'z' && curr_y > 0) res += 'D';
            res += '!';
            curr_x = mp[x].first;
            curr_y = mp[x].second;
        }
        
        return res;
    }
};