#include <bits/stdc++.h>

using namespace std;

vector alphabet = {"a", "b", "c", "ch", "d", "dd", "e", "f", "ff", "g", "ng", "h", "i", "l", "ll", "m", "n", "o", "p", "ph", "r", "rh", "s", "t", "th", "u", "w", "y"};
vector input = {"ddr", "nah", "dea", "dd", "ngah"};

int main() {

unordered_map<string,int> mp;
for(int i=0; i<alphabet.size();i++)
	mp[alphabet[i]] = i;

vector<vector<int>> temp(input.size());
for(int i=0; i<input.size();i++)
{
	int n = input[i].size();
	int j = 0;
	while(j<n)
	{
		if(j<n-1)
		{
			string p = input[i].substr(j,2);
			if(mp.find(p)!=mp.end())
			{
				temp[i].push_back(mp[p]);
				j=j+2;
			}
			else
			{
				string k = input[i].substr(j,1);
				temp[i].push_back(mp[k]);
				j++;
			}
		}
		else {
			string k = input[i].substr(j,1);
			temp[i].push_back(mp[k]);
			j++;
		}
	}
}
sort(temp.begin(),temp.end());
vector<string> output(input.size());
for(int i=0; i<temp.size();i++)
{
	output[i] = "";
	for(int j=0; j<temp[i].size();j++)
	{
		output[i] += alphabet[temp[i][j]];
	}
}
for (auto& x : output)
		cout << x << ' ';
	
return 0;
}

#include <bits/stdc++.h>

using namespace std;

vector<string> alphabet = {"a", "b", "c", "ch", "d", "dd", "e", "f", "ff", "g", "ng", "h", "i", "l", "ll", "m", "n", "o", "p", "ph", "r", "rh", "s", "t", "th", "u", "w", "y"};
vector<string> input = {"ddr",  "nah", "dea", "dd", "ngah"};

int main() {

	unordered_map<string,int> mp;
	for(int i=0; i<alphabet.size();i++)
		mp[alphabet[i]] = i;

	vector<vector<int>> temp(input.size());
	for(int i=0; i<input.size();i++)
	{
		int n = input[i].size();
		int j = 0;
		while(j<n)
		{
			if(j<n-1)
			{
				string p = input[i].substr(j,2);
				if(mp.find(p)!=mp.end())
				{
					temp[i].push_back(mp[p]);
					j=j+2;
				}
				else
				{
					string k = input[i].substr(j,1);
					temp[i].push_back(mp[k]);
					j++;
				}
			}
			else {
				string k = input[i].substr(j,1);
				temp[i].push_back(mp[k]);
				j++;
			}
		}
	}
    sort(temp.begin(),temp.end());
    vector<string> output(input.size());
	for(int i=0; i<temp.size();i++)
	{
		output[i] = "";
		for(int j=0; j<temp[i].size();j++)
		{
			output[i] += alphabet[temp[i][j]];
		}
	}
	for (auto& x : output)
    		cout << x << ' ';
		
	return 0;
}
