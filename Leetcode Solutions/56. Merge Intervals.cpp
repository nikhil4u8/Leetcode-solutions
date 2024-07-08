Intuition
    Consider all the intervals in a number line, then sort intervals and 
    check if second.start <= first.end if it is then merge both else add 
    second to array
class Solution {
public:
//TIME - O(NlogN) -> sorting
//SPACE - O(1) 
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        int start = 0, end = 0;

        while(start < intervals.size()){
            if(intervals[start][0] <= intervals[end][1])
                intervals[end][1] = max(intervals[end][1], intervals[start][1]);
            else intervals[++end] = intervals[start];

            start++;
        }

        intervals.resize(end+1);

        return intervals;
    }
};

**FOLLOW-UP
    1.If stream of intervals are provided -> see at last too
    2.Solve without sorting
    3.Two non-overlapping list of intervals are given merge two interval list.
    4.Do it in-place -> main solution


1.Stream of intervals 
vector<vector<int>> sol4(vector<vector<int>>& intervals) {
	set<pair<int, int>> merged_intervals;
	stack<pair<int, int>> interval_to_remove;

	for (int i = 0; i < intervals.size(); i++) {
		int start = intervals[i][0];
		int end = intervals[i][1];

		auto iter = merged_intervals.lower_bound({end, INT_MAX});

		int new_begin = start, new_end = end;
		while (iter != merged_intervals.begin()) {
			iter--;
			if (iter->second < new_begin) break;

			new_begin = min(new_begin, iter->first);
			new_end = max(new_end, iter->second);
			interval_to_remove.push(*iter);
		}

		while(!interval_to_remove.empty()) {
			merged_intervals.erase(interval_to_remove.top());
			interval_to_remove.pop();
		}
		merged_intervals.insert({new_begin, new_end});
	}


	vector<vector<int>> result;
	for (auto& interval : merged_intervals) {
		int begin = interval.first;
		int end = interval.second;
		result.push_back(vector<int>({begin, end}));
	}
	return result;
}


2.Solve without Sorting
//Using priority_queue -> pushing all elements, then extracting 2 elements
//and arranging them.

//Using 2 for loops

//Time - O(nlogn)
 vector<vector<int>> merge(vector<vector<int>>& intervals) {
        priority_queue<pair<int,int>, vector<pair<int,int>> ,greater<pair<int,int>>> pq;
        int sz = intervals.size();
        for(int i  = 0 ; i < sz; i++)
            pq.push(make_pair(intervals[i][0], intervals[i][1]));
        
        vector<vector<int>>  result;       
        while(!pq.empty() && pq.size() != 1)
        {
            pair<int, int> Int1 = pq.top();
            pq.pop();
                
            pair<int, int> Int2 = pq.top();
            pq.pop();
            
            if(Int1.second >= Int2.first)
                pq.push(make_pair(min(Int1.first, Int2.first), max(Int1.second, Int2.second)));
            else
            {
                result.push_back({Int1.first, Int1.second});
                pq.push(Int2);
            }
        }
        if(pq.size() == 1)
            result.push_back({pq.top().first, pq.top().second});
        return result;
}
//Time - O(n^2)
vector merge(vector& intervals)
{
vector result;

    if(intervals.empty())
        return result;

    for(int i=0; i<intervals.size(); i++)
    {
        Interval one = intervals[i];
        if(one.start > one.end)
        {
            int tmp = one.start;
            one.start = one.end;
            one.end = tmp;
        }

        for(int j=result.size()-1; j>=0; j--)
        {        
            if(result[j].start > one.end || result[j].end < one.start)
                continue;
            else
            {
                one.start = min(result[j].start, one.start);
                one.end = max(result[j].end, one.end);
                result.erase(result.begin()+j);
            }
        }

        result.push_back(one);
    }
    
    return result;
}

3.
//Sort both list
//Sort both list & take 2 pointer and choose the smallest first element 
// among both list then choose which one to pick next, i+1 or j+1 -> and 
// modify the last index accordingly
int[][] merge2IntervalList(int[][] intervals1, int[][] intervals2) {
    if (intervals1.length == 0) return intervals2;
    if (intervals2.length == 0) return intervals1;

    sort(intervals1.begin(),intervals1.end());
    sort(intervals2.begin(),intervals2.end());

    int i = 0, j = 0;
    int[] toAdd;
    if (intervals1[0][0] <= intervals2[0][0]) {
        i = 1;
        toAdd = intervals1[0];
    } else {
        j = 1;
        toAdd = intervals2[0];
    }

    List<int[]> result = new ArrayList<>();

    while (i < intervals1.length || j < intervals2.length) {
        int[] current = null;
        if (i < intervals1.length && j < intervals2.length) {
            if (j < i) current = intervals2[j++];
            else if (i < j) current = intervals1[i++];
            else{
                if (intervals1[i][0] < intervals2[j][0]) current = intervals1[i++];
                else current = intervals2[j++]; 
            }
        }else if (i < intervals1.length) current = intervals1[i++];
        else current = intervals2[j++];
        

        if (toAdd[1] < current[0]) {
            result.add(toAdd);
            toAdd = current;
        } else if (current[1] < toAdd[0]) result.add(current);
        } else {
            toAdd = new int[] {
                    Math.min(toAdd[0], current[0]),
                    Math.max(toAdd[1], current[1])
            };
        }
    }

    result.add(toAdd);
    return result.toArray(new int[result.size()][2]);
}


/*
Question: How do you add intervals and merge them for a large stream of 
intervals? (Facebook Follow-up Question)

We need to have two functions for the tree (add interval and query tree).

Implementation Details
TreeNode - On top of the left child, right child, start boundary, and end 
boundary, we have a middle field that determines whether a new interval 
goes to the left child, right right or merged with the current node.

ADD - If the new interval touches or crosses the middle of the current 
node, we update the current node. Otherwise, we put the new interval into 
the left subtree or right subtree.

Why do we use middle for comparison and not start or end boundaries?
-> Middle is the pivot we used to decide where the interval should go to.
Left or right subtree. Also, we can use merge-sort technique to query the 
merged intervals result when the left subtree does not overlap with the 
right subtree.

QUERY - Use merge-sort technique by retrieving the merged intervals of 
the left subtree (i.e. left_intervals) and those of the right subtree 
(i.e. right_intervals). Because of the implementation of add, we can 
guarantee that

if there's an interval in the left_intervals that overlaps with the 
current node, then we know that all the intervals after that interval 
overlaps with the current node.
The first few intervals or zero intervals in the right_intervals overlap 
with the current node.
*/

//TIME - Add : O(N), Query : O(N)
//SPACE - O(N)
class TreeNode {
public:
    int start;
    int end;
    int middle;
    TreeNode* left;
    TreeNode* right;
};

class Solution {    
public:
    TreeNode* root;    
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        if (intervals.empty()) return {};
        
        for (vector<int> interval : intervals) {
            if (!root) 
                root = new TreeNode(interval[0], interval[1], (interval[0] + interval[1]) / 2);
            else add(root, interval[0], interval[1]);
        }
        
        return query(root);
    }
    
    void add(TreeNode* node, int start, int end) {
        if (end < node->middle) {
            if (node->left) add(node->left, start, end);
            else node->left = new TreeNode(start, end, (start + end) / 2);
        } else if (start > node->middle) {
            if (node->right) add(node->right, start, end);
            else node->right = new TreeNode(start, end, (start + end) / 2);
        } else {
            node->start = min(node->start, start);
            node->end = max(node->end, end);
        }
    }
    
    vector<vector<int>> query(TreeNode* node) {
        if (!node) return {};
        
        // Merge-sort divide and conquer
        vector<vector<int>> left_intervals = query(node->left);
        vector<vector<int>> right_intervals = query(node->right);
        vector<vector<int>> res;
        
        bool inserted = false;
        
        for (vector<int> lres : left_intervals) {
            if (lres[1] < node->start) res.push_back(lres);
            else {
                res.push_back({std::min(lres[0], node->start), node->end});
                inserted = true;
                break;
            }
        }
        
        if (!inserted) res.push_back({node->start, node->end});
        
        for (const std::vector<int>& rres : right_intervals) {
            if (rres[0] <= node->end) res.back()[1] = max(node->end, rres[1]);
            else res.push_back(rres);
        }
        
        return res;
    }
};
