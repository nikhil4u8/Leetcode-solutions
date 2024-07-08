/*
QUes to ask :
    - In which order should we return the accounts?
    - What if a email is mapped to 2 account with different name

Sol
We need a mechanism that somehow merges accounts together: if 2 accounts 
have even one same email, we basically merge them. If there are no same 
emails, then those are different accounts.

=> DFS : [TIME - O((N*M*L)^2)]
-> N : no of accounts | M : no of emails per account
-> L : len of each email
    - Iterate over 2 accounts having same name & check if they've a email 
    in common or not, if they've then merge these 2 account & move on to 
    another account having similar name. This could be costly as we've to 
    traverse every email of every other account.

BEST APPROACH
=> Union Find : [TIME - O(NMLlog(NM)) SPACE - O(NML)]
    - We'll maintain a mapping of {EMAIL -> Account Id} & a parent vector 
    (storing parent of every account). Start traversing over each account 
    & map every email in that account to it's accountId, now if a email is 
    already been mapped to another accountId (0), then in parent array set 
    the parent of current accountId (1) to alreay mapped accountId (0).
    - Now after traversing every email, in end traverse every email again 
    & find their parent account after merging and map those email id 
    according to their accountId & return ans vector

Edge case :
    - When accouts[i] len == 1
*/
class Solution {
public:
    int find(vector<int>& parent, int i) {
        if (parent[i] == i) return i;
        return parent[i] = find(parent, parent[i]);
    }
	vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        vector<int> parent(accounts.size(), 0);
        //{email_id : account_id}
        unordered_map<string, int> email_id;
        
        // We gather all the e-mails and the group in which thet belong
        // We make groups for the case that one e-mail has multiple accounts
        for (int i = 0; i < accounts.size(); i++) {
            // Initialize the parent vector
            parent[i] = i;
            for (int j = 1; j < accounts[i].size(); j++) {
                // If this e-mail has been found again then union-find in order 
                // to add under the same group the current e-mail and the 
                // already stored e-mail
                if (email_id.find(accounts[i][j]) != email_id.end()) {
                    int f1 = find(parent, i);
                    int f2 = find(parent, email_id[accounts[i][j]]);
                    // Union
                    parent[f1] = f2;
                } else {
                    // If this e-mail is found for the first time then add it to the map
                    email_id[accounts[i][j]] = i;
                }
            }
        }
        // We make a new map in order to store for every group the e-mails it 
        //contains
        unordered_map<int,vector<string>> mres;
        for (auto it : email_id) {
            int f = find(parent, it.second);
            mres[f].push_back(it.first);
        }
        
        // In the previous (mres) map we have our answer but we must give the 
        // proper structure We add the name of the account (we retieve it from 
        // the initial vector since we have the number of the group) and we sort 
        // the e-mails.
        vector<vector<string>> res;
        for (auto it : mres) {
            sort(it.second.begin(), it.second.end());
            vector<string> tmp = {accounts[it.first][0]};
            for (auto i : it.second) tmp.push_back(i);
            res.push_back(tmp);
        }
        return res;
    }
};