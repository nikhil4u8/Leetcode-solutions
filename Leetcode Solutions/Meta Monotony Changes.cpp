Count number of monotony changes in array - for e.g.
[6,5,4,1] -> 0
[2,3,4,5] -> 0
[2,3,4,5,6,5,4,1] -> 1
[2,3,4,1,5,6,5] -> 3

Monotonic change : If we draw this array in graphical format then no of
peeks or sharp corner are counted as 1 monotony change

//TIME : O(N) SPACE - O(1)
public static int countMonotonicChanges(int[] arr) {
    Integer prev = null, current;
    int change = 0;

    for (int i = 1; i < arr.length; i++) {
      if (arr[i - 1] == arr[i]) current = 0;
      else if (arr[i - 1] < arr[i]) current = 1;
      else current = -1;
      
      if (prev == null) prev = current;
      else if (prev.intValue() != current.intValue()) {
        change++;
        prev = current;
      }
    }

    return change;
  }