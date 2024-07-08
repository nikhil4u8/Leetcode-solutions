/*
Desc :-
    - If amt > 1000 -> invalid trans
    - If other trans occured within 60 min with same name / different city -> invalid trans

Ques to ask :-
    - What to return in duplicate input?
    - if a trans amt > 1000, then the trans occured before (within 60 min) and are valid should be remarked as invalid?
*/
class Solution {
public:
    //TIME - O(N^2) SPACE - O(N)
    //storing every transaction in map and then for every i visiting every
    //previous transaction whose user name is same and if city name is different
    //and time b/w transaction is less than 60 then mark current and prev trans as
    //invalid
    vector<string> invalidTransactions(vector<string>& transactions) {
        //Represents :- Name -> {city,{time,index_of_transaction}}
        unordered_map<string,vector<pair<string,pair<int,int>>>>mp;
        
        int n = transactions.size();
        vector<bool>isvalid(n,false);
        int j=0;
        
        for(string str:transactions){
            string user_name = "",city_name="";
            int time=0,amount=0,i=0,count=0;
            bool flag = true;
            
            //seperating user_name,city_name,time,amount from str
            while(i<str.length()){
                if(str[i]==',') count++;
                else if(count==0) user_name+=str[i];
                else if(count==1) time = time*10 + (str[i]-'0');
                else if(count==2) amount = amount*10 + (str[i]-'0');
                else city_name += str[i];
                i++;
            }
            //if amount>1000 then invalid transaction
            if(amount>1000) flag = false;
            
            //finding which transaction are invalid wrt current transaction and then 
            //marking those transaction as false
            for(int i=0;i<mp[user_name].size();i++){
                  auto temp = mp[user_name][i];
                  
                  if(temp.first != city_name && abs(temp.second.first-time)<=60){
                      flag = false;
                      isvalid[temp.second.second] = false;
                  }
             }
            
        
            isvalid[j] = flag;
            //storing every transaction in map to compare to future transaction
            mp[user_name].push_back({city_name,{time,j}});
            
            j++;
        }
        
        //storing all transaction which are invalid
        vector<string>res;
        for(int i=0;i<n;i++) if(!isvalid[i]) res.push_back(transactions[i]);
        
        return res;
    }
    
    //TIME - O(N^2) SPACE - O(N)
    //store user_name,city_name,time,amount in different array and then 
    //traverse these array using 2 for loop 
    // for(int i=0;i<n;i++){
    //   for(int j=i-1;i>=0;j--)
    // }
    //and if current transaction amount>1000 then it's invalid otherwise by
    //using 2 for loop compare if city_name is different and difference b/w trans 
    //time is <=60 if it is then mark the previous one as false and current too as 
    //false
};