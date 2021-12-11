#include <bits/stdc++.h>
using namespace std;

void print(const vector<vector<int>> &matrix)
{
	cout << endl;
	for(const auto &i:matrix) {
		for(auto n:i) cout << n;
		cout << endl;
	}
}

void flash(vector<vector<int>> &matrix,int y, int x,set<pair<int,int>> &flashed)
{
	if(x<0 || x>=matrix[0].size()) return;
	if(y<0 || y>=matrix.size()) return;

	if(matrix[y][x]!=0) {
		++matrix[y][x];
		if(matrix[y][x]==10) matrix[y][x]=0;
	}
	if(matrix[y][x] == 0 && flashed.find({y,x})==flashed.end()) {
		flashed.insert({y,x});
		flash(matrix,y-1,x,flashed); //up
		flash(matrix,y+1,x,flashed); //down
		flash(matrix,y,x+1,flashed); //right
		flash(matrix,y,x-1,flashed); //left
		flash(matrix,y-1,x+1,flashed); //
		flash(matrix,y-1,x-1,flashed);
		flash(matrix,y+1,x+1,flashed);
		flash(matrix,y+1,x-1,flashed);
	}
}
int main()
{
	ifstream in("day11.in");
	vector<vector<int>> matrix;
	for(string i; getline(in,i);) {
		vector<int> inner;
		for(char c:i) inner.push_back(c - '0');
		matrix.push_back(inner);
	}

	print(matrix);
	cout << endl;


	int flashes = 0;
	int sync_step = -1;
	for(int s = 0;;++s) {
		set<pair<int,int>> marked, flashed;
		for(int y=0;y!=matrix.size();++y) {
			for(int x=0;x!=matrix[y].size();++x) {
				++ matrix[y][x];

				if(matrix[y][x] == 10) {
					matrix[y][x] = 0;
					marked.insert(make_pair(y,x));
				}
			}
		}
		for(auto itr = marked.begin(); itr!=marked.end();++itr) {
			int y,x;
			y = itr->first;
			x = itr->second;
			flash(matrix,y,x,flashed);
		}
		print(matrix);

		if(s<100) flashes += flashed.size();
		if(flashed.size()==100)  {
			sync_step = s+1;
			break;
		}
	}

	cout << flashes << endl;
	cout << sync_step << endl;
}
