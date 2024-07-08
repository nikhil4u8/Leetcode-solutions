class Solution {
public:
    //Recursive
    //Time - O(N^2)  Space - O(N)
    map<string,int>decode(string formula,int &index){
        map<string,int>mp;
        int len = formula.length();
        
        while(index<len && formula[index]!=')'){
            if(formula[index]=='('){
                map<string,int>temp = decode(formula,++index);
                for(auto it:temp) mp[it.first] += it.second;
            }else{
                string atom = "";
                atom += formula[index++];
                
                while(index<len && formula[index]>='a' && formula[index]<='z') atom += formula[index++];
                
                int num = 0;
                while(index<len && formula[index]>='0' && formula[index]<='9') 
                    num = num*10 + (formula[index++]-'0');
                
                num = max(1,num);
                mp[atom] += num;
            }
        }
        
        if(index<len && formula[index]==')'){
            int num = 0;
            index++;
            
            while(index<len && formula[index]>='0' && formula[index]<='9') 
                num = num*10+(formula[index++]-'0');
            num = max(1,num);
            
            for(auto it:mp) mp[it.first] = it.second*num;
        }
        
        return mp;
    }
    string countOfAtoms(string formula) {
        string res = "";
        int index = 0;
        
        map<string,int>mp = decode(formula,index);
        
        for(auto it:mp){
            res += it.first;
            if(it.second>1) res += to_string(it.second);
        }
        
        return res;
    }
    //Iterative
    //Time - O(N^2) SPACE - O(N)
    //O(N) to parse formula but after each bracket we need to traverse string again which leads to N^2 in worst case 
    string countOfAtoms(string formula) {
        string res = "";
        int len = formula.length(),i=0;
        
        stack<map<string,int>>sta;
        map<string,int>mp;
        
        while(i<len){
            if(formula[i] == '('){
                sta.push(mp);
                mp = map<string,int>();
                i++;
            }else if(formula[i] == ')'){
                int num = 0;
                i++;
                
                while(i<len && formula[i]>='0' && formula[i]<='9') num = num*10 + (formula[i++]-'0');
                num = max(1,num);
                
                for(auto it:mp) sta.top()[it.first] += (num * it.second);
                
                mp = sta.top();
                sta.pop();
            }else{
                string atom = "";
                atom += formula[i];
                i++;
                
                while(i<len && formula[i]>='a' && formula[i]<='z') atom += formula[i++];
                
                int num = 0;                
                while(i<len && formula[i]>='0' && formula[i]<='9') num = num*10 + (formula[i++]-'0');

                num = max(1,num);
                mp[atom] += num;
            }
        }
        
        for(auto it:mp){
            res += it.first;
            if(it.second>1) res += to_string(it.second);
        }
        
        return res;
    }
};