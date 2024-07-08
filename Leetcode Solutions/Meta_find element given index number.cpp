/*
Sol : 
    - The brute approach is to actually rotate the array for all given 
    ranges, and finally, return the element at the given index in the 
    modified array.
    -
    Here's a simplified explanation:
    1. Start with the original index K.
    2. Iterate through the queries in reverse order.
    3. If the current query range contains K, adjust K's position within 
    that range based on the rotation direction (left or right).
    4. Continue this process for all queries, and you'll end up with the final position of K.
    5. Return the element at the updated Kth index in the final array.

    Reverse order reason :
    1. It may be possible that we are rotating some overlapped positions repeatedly.
    2. In those cases, we are going deeper into the previous rotations starting from the latest rotation. 
    3. So to get the proper position we are iterating from the reverse direction.
*/

//TIME - O(R) SPACE -O(1)
//R is number of rotations
// given index
int findElement(int arr[], int ranges[][2], int rotations,
				int index)
{
	for (int i = rotations - 1; i >= 0; i--) {

		// Range[left...right]
		int left = ranges[i][0];
		int right = ranges[i][1];

		// Rotation will not have any effect
		if (left <= index && right >= index) {
			if (index == left)
				index = right;
			else
				index--;
		}
	}

	// Returning new element
	return arr[index];
}

// Driver
int main()
{
	int arr[] = { 1, 2, 3, 4, 5 };

	// No. of rotations
	int rotations = 2;

	// Ranges according to 0-based indexing
	int ranges[rotations][2] = { { 0, 2 }, { 0, 3 } };

	int index = 1;

	cout << findElement(arr, ranges, rotations, index);

	return 0;
}
