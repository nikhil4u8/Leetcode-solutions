/*
Desc : When parent pointer is given

Ques to ask :-
    - Parent pointer of root node?
    - What if p or q doesn't exist in tree?
    - Can a node be descendant of itself i.e p = q?

Sol : 
=> Brute force by storing path from node -> root [TIME - O(N) SPACE - O(H)]
    - Store the path from p -> root node in vector, and do a traversal 
    from q to root, and check if there is a node which is already present 
    in vector, if it is then return that node. 

BEST APPROACH - 1 (SAY THIS ONE)
=> Making level same then looping for parent until they become same
[TIME - O(H1 + H2) SPACE - O(1)]
    - Get the depth of the node & traverse upwards from the deeper node 
    to make sure we start our search at same level for both the nodes. 
    Then the search step is pretty simple - traverse upwards till we meet.

BEST APPROACH - 2
=> Treating path from node -> root as Linked List 
[TIME - O(H1 + H2) SPACE - O(1)]
    - Can be reduced to find intersection of 2 linkedlists. When either of 
    them reach root node then make them pointe to other start node.

    A---x----I-----y-----Dest
    B---z----I-----y-----Dest

    A will travel x + y + z
    B will travel z + y + x
    The will eventually intersect at I. 

Follow ups:
    - Find LCA of multiple nodes
    - Find path between p / q
        -> For all Ref : 236. Lowest Common Ancestor of a Binary Tree
    - What if tree doesn't contain p / q ? 
        -> before recursion check if P/Q are present, if not present then 
        return Null, otherwise recrusion
        -> 1644. Lowest Common Ancestor of a Binary Tree II

Similar ques : 
    - Ref 236. Lowest Common Ancestor of a Binary Tree
    - Ref 1123. Lowest Common Ancestor of Deepest Leaves
    - Ref 1650. Lowest Common Ancestor of a Binary Tree III
    - Ref 235. Lowest Common Ancestor of a Binary Search Tree
    - Ref 1644. Lowest Common Ancestor of a Binary Tree II
*/
class Solution {
public:
    //Approach 2
    //BEST APPROACH
    //TIME - O(H1 + H2) SPACE - O(1)
    int getHeight(Node node) {
        int height = 0;
        while (node != null) {
            node = node.parent;
            height++;
        }
        return height;
    }

    Node lowestCommonAncestor(Node p, Node q) {
	    // Calculate height of both of the nodes
        int height1 = getHeight(p);
        int height2 = getHeight(q);
        
        // Make sure "p" always points to deeper node (for less code duplication)
		if (height1 < height2) swap(p, q);
        
        // Move up to ensure the we start our search from same level for both the nodes
        int heightDiff = abs(height1 - height2);
        while(heightDiff > 0) {
            p = p.parent;
            heightDiff--;
        }
        
		// Search upwards till the paths intersect
        while (p != q) {
            p = p.parent;
            q = q.parent;
        }
        
        return p;
    }

    //Approach 3 
    //TIME - O(H1 + H2) SPACE - O(1)
    Node* lowestCommonAncestor(Node* p, Node * q) {
        Node* temp_p = p, *temp_q = q;
        while(p != q){
            p = p->parent;
            q = q->parent;
            if(!p) p = temp_q;
            if(!q) q = temp_p;
        }
        return p;
    }
    //Approach - 1
    //TIME - O(H) SPACE - O(H)
    Node* lowestCommonAncestor(Node* p, Node * q) {
        vector<Node*>vec;
        while(p != NULL){
            vec.push_back(p);
            p = p->parent;
        }

        while(q != NULL){
            if(find(vec.begin(), vec.end(), q) != vec.end()) return q;
            q = q->parent;
        }

        return NULL;
    }
};