def findTwoEqualSub(array):
    # Find sum of whole array

    total = 0
    for x in array:
        total += x

    //check if current position is pivot
    leftTotal = 0
    pivot = None
    for i in range(len(array)):
        leftTotal += array[i]
        if leftTotal == total - leftTotal:
            pivot = i
            break

    if pivot is None:
    print('No pivot found')
    else:
    print('array 1 : {} & array 2 : {}'.format( array[:i+1], array[i+1:]))

//Coding round: split array in such a way that their sum is same
//TIME - O(N) SPACE - O(1)
int findTwoEqualSum(vector<int>array){
    int total = 0;
    for(int i=0;i<array.size();i++) total += array[i];

    int leftTotal = 0, pivot = -1;

    for(int i=0;i<array.size();i++){
        leftTotal += array[i];
        if(leftTotal == total - leftTotal){
            pivot = i;
            break;
        }
    }

    if(pivot == -1) return -1;
    return leftTotal;
}