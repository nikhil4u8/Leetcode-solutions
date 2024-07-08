/*
Ques to ask:
    - Will the resultant expression follow BODMAS?
    - What to return when an expression can't be formed?
    - Does str contains '0', If input is "105", can we break it as "1*05"?
    - Is there any division too?
    - Can we return exp as "+3+5" or "-3+5"?
    - Do we've paranthese in string?

Sol :
=> Backtracking & Evaluate Expression : [TIME - O(4^N)]
    - Use Backtracking to generate all possible expression by adding 
    '+','-','*' in b/w the digits of s. We've to add a condition to avoid 
    leading '0'.
    - We'll create a fun evalute(string exp) to evalute a string exp when 
    we reach at the end of the string, if the evaluted result is equal to 
    target, we add that exp to our ans otherwise ignor

BEST APPROACH
=> Backtracking & Evaluate on the fly : [TIME - O(4^N) SPACE - O(N)]
-> TC EXPLANATION BELOW
    - Traverse the string & after every digit added to tempNum, add a 
    operator (+,-,*) & pass the resultant so far & curr digit in recursive 
    fun
    - There is no priority since there are no parenthese '(' or ')' in 
    string, so we can evalute the exp on fly to save some time.
    - We've to maintain 2 variable while string traversal.
    resSoFar : the value of exp until index i
    prevNum : the last number use in exp (already added to resSoFar)
    There are total 3 operators:
        1. '+' operator: newResult = resSoFar + num
        2. '-' operator: newResult = resSoFar - num.
        3. '*' operator: We need to keep the prevNum so that to calculate 
        newResult we need to minus prevNum from resSoFar since we already 
        added this in last iteration then plus with prevNum * num. So 
        newResult = resSoFar - prevNum + prevNum * num.
    
Follow up:
    - When string contains '+', '-', '*', '/'?
        -> Ref : 227. Basic Calculator II
    - When string contains Brackets, '+', '-'?
        -> Ref : 224. Basic Calculator
    - When string contains brackets, '+', '-', '*', '/'?
        -> Ref : 772. Basic Calculator III
    - A num is given in form of string, add operator in it st it evalutate
    to target?
        -> Ref : 282. Expression Add Operators
    - You're given a single digit & asked to find minimum number of 
    operations to get the target number using a single digit multiple time?
        -> See below
*/
class Solution {
public:
    vector<string>ans;
    void expressionList(string num, int idx, int target, string tempExp, long resSoFar, long prevNum){
        if(idx == num.length()){
            if(resSoFar == target) ans.push_back(tempExp);
            return;
        }
        
        string tempStr = "";
        long tempNum = 0;
        //Traversing string
        for(int i=idx;i<num.length();i++){
            // Skip leading zero number
            if(i > idx & num[idx] == '0') break;

            tempStr += num[i];
            tempNum = tempNum*10 + (num[i] - '0');

             // First num, pick it without adding any operator!
            if(idx == 0)
                expressionList(num, i+1, target, tempExp + tempStr, tempNum, tempNum);
            else{
                //adding curr Num
                expressionList(num, i+1, target, tempExp + "+" + tempStr, resSoFar + tempNum, tempNum);
                //subtracting curr Num
                expressionList(num, i+1, target, tempExp + "-" + tempStr, resSoFar - tempNum, -tempNum);
                //Multiplying curr Num
                expressionList(num, i+1, target, tempExp + "*" + tempStr, resSoFar - prevNum + prevNum * tempNum, prevNum * tempNum);
            }
        }
    }
    vector<string> addOperators(string num, int target) {
        expressionList(num, 0, target, "", 0, 0);
        return ans;
    }
};

/*
SPACE - Space used up by the recursion stack would also be O(N) since it's 
size is determined by value of index & it goes from 0 all the way to N.

TIME : 
T(N) = Total Number of Valid Expressions
T(N) = 3T(N - 1) + 3T(N - 2) + 3T(N - 3) + .... 3T(0)
Now T(N - 1) = 3T(N - 2) + 3T(N - 3) + 3T(N - 4) + .... 3T(0)
T(N) = 3T(N-1) + T(N-1) = 4T(N-1)

If we put T(N - 2) in T(N) we'll get
T(N) = 3 x 4^2 ( T(N - 3) + T(N - 4) + T(N - 5) + .... T(0) )

If we generalize it, we'll get
T(N) = 3 x 4^k ( T(N - (k + 1)) + T(N - (k + 2)) + .... T(0))

If we put k = N - 1, we'll get
T(N) = 3 x 4^(N - 1) (T(0)) = O(4^N)
For the worst case of an array of 0s and target 0, length of our output 
would be O(4^N).
*/

/*
Follow up :
Ques : - You're given a single digit & asked to find minimum number of 
operations to get the target number using a single digit multiple time?
Ex : 
1. str = "1", target = 1
    -> Number of operations: 0. Since can be represented with 1.
2. str = "1", target = 11
    -> Number of operations: 0.Since 11 can be represented by using two 
    1s from the digit array.
3. str = "1", target = 21
    -> Number of operations: 2. 11+11-1 =21. So two operations

Valid target is from [0,99999]


SOl :
1. create a list that includes all of numbers which consists of the given 
digits - [0,99999]
setting initial values into Queue, {1,11,111,1111, ....} - 0 steps

2. Then use BFS - to find out new numbers (using +,-,* with precalculated 
numbers) which possible to reach this time with steps + 1/Not visited 
before.
...
then repeats the previous step until find the target value.

Time: O(n*n - worst case), n - illustrates range of numbers - for example - 99999
*/

from collections import deque
def findMinOper(digits, target):
    pool = set()
    q = deque(digits)
    //inserting all combination of digits in queue
    while q:
        curr = q.popleft()
        if curr in pool:
            continue
        pool.add(int(curr))
        for digit in digits:
            new = curr + digit
            if int(new) < 100000:
                q.append(new)

    q = deque([int(n) for n in pool])
    step = 0
    seen = set();
    //Processing every combination in queue & marking it as visited
    //and for every candidate in the pool we're applying every operator
    //b/w then until we reach target
    while q:
        for _ in range(len(q)):
            curr = q.popleft()
            if curr == target:
                return step
            if curr in seen or curr > 99999:
                continue
            seen.add(curr)
            for candidate in pool:
                q.append(curr + candidate)
                q.append(curr - candidate)
                q.append(curr * candidate)
        step += 1
    return -1