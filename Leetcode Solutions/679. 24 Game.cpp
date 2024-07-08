class Solution {
public:
    //TIME - O(4! * 6^3) in case of 4 card
    //TIME - O(n! * 6^(n-1)). in case of n cards
    //Self-explanatory
    //dont write in interview
    bool judgePoint24(vector& nums) {

        sort(nums.begin(), nums.end());
         do {
             if (valid(nums)) return true;
          } while(next_permutation(nums.begin(), nums.end()));
        return false;
    }

    bool valid(vector<int>& nums) {
          double a = nums[0], b = nums[1], c = nums[2], d = nums[3];
          if (valid(a+b, c, d) || valid(a-b, c, d) || valid(a*b, c, d) ||b&& valid(a/b, c, d)) return true;
          if (valid(a, b+c, d) || valid(a, b-c, d) || valid(a, b*c, d) || c&&valid(a, b/c, d)) return true;
          if (valid(a, b, c+d) || valid(a, b, c-d) || valid(a, b, c*d) || d&& valid(a, b, c/d)) return true;
          
        return false;
     }
    bool valid(double a, double b, double c) {
        if (valid(a+b, c) || valid(a-b, c) || valid(a*b, c) || b&&valid(a/b, c)) return true;
        if (valid(a, b+c) || valid(a, b-c) || valid(a, b*c) || c&&valid(a, b/c)) return true;
    
        return false;
    }
    bool valid(double a, double b) {
        if (abs(a+b-24.0) < 0.0001 || abs(a-b-24.0) < 0.0001 || 
            abs(a*b-24.0) < 0.0001 || b&&abs(a/b-24.0) < 0.0001)  return true;
   
        return false;
    }
    //INTERVIEW SOLUTION
    bool is24(vector<double>nums){
        //write nums[0] == 24 in interview, if asked further then write 0.1
        //0.1 is done for test cases like  8/(3 - 8/3) = 24, who don't exactly evaluate to 24 but are approx
        if(nums.size()==1)  return abs(nums[0]-24)<=0.1;
        
        for(int i=0;i<nums.size();i++){
            for(int j=0;j<i;j++){
                double a = nums[i];
                double b = nums[j];
                
                vector<double>possible_operation = {a+b,a-b,b-a,a*b,a/b,b/a};
                
                vector<double>temp;
                //generate a copy of nums
                for(int k=0;k<nums.size();k++) temp.push_back(nums[k]);
                
                //delete a and b from temp i.e copy of nums
                auto it1 = find(temp.begin(),temp.end(),a);
                temp.erase(it1);
                auto it2 = find(temp.begin(),temp.end(),b);
                temp.erase(it2);
                
                //trying all possible combination
                for(int k=0;k<possible_operation.size();k++){
                    temp.push_back(possible_operation[k]);
                    if(is24(temp)) return true;
                    temp.pop_back();
                }
            }
        }
        
        return false;
    }
    bool judgePoint24(vector<int>& cards) {
        vector<double>nums;
        
        for(int i=0;i<cards.size();i++) nums.push_back((double)cards[i]);
        
        return is24(nums);
    }
};