/*
you have a list such as
(a,3) (b,1) , (d, 5) and (c,2)

a batch can contain only those elements whose total count ia less than or 
equal to a total sum

for example - if the tootal sum is 5, there will be three batches
(a,b) , (c) and d

if the sum is 7
(a,b,c) and d
*/

//TIME - O(NlogN) SPACE - O(1)
public int getBatches(List<int[]> list, int sum) {
	int n = list.length();
	list.sort(list, (a, b) => a[1] - b[1]);
	int batches = 0;
	int currentCount = 0;
	for (int i=0;i<n;i++) {
		if (list.get(i)[1] + currentCount > sum){
			batches++;
			currentCount = list.get(i)[1];
			continue;
		}
		else currentCount += list.get(i)[1];
	}

	if (currentCount > 0){
		currentCount = 0;
		batches++;
	}

	return batches;
}