//TIME - O(N * M * L * 8^L)
//SPACE - O(N * M + L)
// L -> len of longest word
class Solution {
private:
	vector<pair<int, int>> mover = {{1, 0}, {0, 1}, {-1, 0},
									{0, -1}, {1, 1}, {-1, -1},
									{1, -1}, {-1, 1}};

public:
	bool dfs(int x, int y, string word,
			vector<vector<bool>>& visited,
			vector<vector<char>>& board) {
	
		// If word length becomes 0, the string is found
		if (word.empty()) {
			return true;
		}

		visited[x][y] = true;
		bool sol = false;

		// Making possible moves
		for (auto move : mover) {
			int curr_x = move.first + x;
			int curr_y = move.second + y;

			// Checking for out of bound areas
			if (0 <= curr_x && curr_x < board.size() && 0 <= curr_y && curr_y < board[0].size()) {
				
			// Checking for similarity in the first letter and the visited array
				if (board[curr_x][curr_y] == word[0] && !visited[curr_x][curr_y]) {
					string s = word.substr(1);
					sol |= dfs(curr_x, curr_y, s, visited, board);
				}
			}
		}

		visited[x][y] = false;
		return sol;
	}

	vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
		vector<string> ans;
		vector<vector<bool>> visited(board.size(), vector<bool>(board[0].size(), false));

        //If array of words are given
		for (string word : words) {
			for (int i = 0; i < board.size(); i++) {
				for (int j = 0; j < board[0].size(); j++) {
					if (board[i][j] == word[0]) {
						string s = word.substr(1);
						if (dfs(i, j, s, visited, board)) {
							ans.push_back(word + " -> {" + to_string(i) + "," + to_string(j) + "}");
						}
					}
				}
			}
		}

		return ans;
	}
};

int main() {
	vector<vector<char>> board = {{'o', 'a', 'a', 'n'},
								{'e', 't', 'a', 'e'},
								{'i', 'h', 'k', 'r'},
								{'i', 'f', 'l', 'v'}};
	vector<string> words = {"oath", "pea", "eat", "rain"};
	Solution solver;
	vector<string> result = solver.findWords(board, words);

	for (string str : result) {
		cout << str << endl;
	}

	return 0;
}
