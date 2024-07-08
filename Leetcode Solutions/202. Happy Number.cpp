class Solution {
public:
    //USING HASH-MAP
    bool isHappy(int n) {
        unordered_map<int,int> tmp;
        
        while(n != 1)
        {
            if(tmp[n] == 0)
                tmp[n]++;
            else
                return false;
            
            int sum = 0;
            while(n != 0)
            {
                sum += pow(n % 10,2);
                n = n / 10;
            }
            
            n = sum;
        }
        
        return true;
    }
    
    //fLOYD'S CYCLE
    int sumofsquare(int n){
        int sum=0;
        while(n>0){
            sum=sum+(n%10)*(n%10);
            n=n/10;
        }
      return sum;
    }
    public:
    bool isHappy(int n){
        int f = n;
        int s = n;
        do{
            f=sumofsquare(f);
            s=sumofsquare(sumofsquare(s));
        }while(f!=s);
        
      return f==1;
    }
};