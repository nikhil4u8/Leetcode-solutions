/*Given an integer array arr, we define value v over a partition of arr as 
sum of maximum of "each part of arr after partition", such that each part
must contain atleast 1 negative number

Eg: [10, -2, 5, -3, 4, -1]
Maximum value is given by partition:
[10, -2] [5, -3] [4, -1]
10 + 5 + 4
19 is the answer

Now we want to find maximum value of arr
O(N*N) approach is straightforward, any better approach?*/

Sol :
TIME - O(nlogn) SPACE - O(1)

Sort the array
count -ve and +ve numbers
if(no +ve number) return maximum of -ve numbers.
if (count(-ve) >= count(+ve)) return sum of all positives.
if (count(-ve) < count(+ve)) return sum of positive numbers from last 
till both +ve count == -ve count.