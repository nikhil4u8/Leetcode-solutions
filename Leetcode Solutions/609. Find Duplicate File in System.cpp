class Solution {
public:
    vector<vector<string>> findDuplicate(vector<string>& paths) {
        vector<vector<string>>ans;
        //file_content -> file_path
        unordered_map<string, vector<string>>mp;
        
        for(int i=0;i<paths.size();i++){
            string temp_str = paths[i];
            int index = 0;
            vector<string>temp_res;
            
            string path = "", txt_file = "", content = "";
            while(index < temp_str.length() && temp_str[index] != ' ') path += temp_str[index++];
            index++;
            
            int flag = 1;
            
            while(index < temp_str.length()){
                if(temp_str[index] == ' '){
                    string temp_path = path + "/" + txt_file;
                    mp[content].push_back(temp_path);    
                    
                    txt_file = "";
                    content = "";
                    flag = 1;
                }else if(temp_str[index] == '(') flag = 2;
                else if(temp_str[index] == ')') flag = 0;
                else if(flag == 1) txt_file += temp_str[index];
                else if(flag == 2) content += temp_str[index];
                index++;
            }
            
            if(txt_file != "" || content != "") mp[content].push_back(path + '/' + txt_file);
        }
        
        for(auto it : mp){
            if(it.second.size() > 1)  
                ans.push_back(it.second);
        }
        return ans;
    }
};