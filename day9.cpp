#include <bits/stdc++.h>
using namespace std;

bool isMinimum(int num,array<int,4> adj)
{
	for(auto i:adj) if(i<=num && i!=-1) return false;
	return true;
}

int basin(deque<deque<int>> &map, int i, int j)
{
	int size = 0;

	int curr = map[i][j];
	map[i][j]=-1;
	if(curr != 9) {
		size+=1;
		if(map[i][j+1] - curr >= 1) size += basin(map, i,j+1);
		if(map[i][j-1] - curr >= 1) size += basin(map,i,j-1);
		if(map[i-1][j] - curr >= 1) size += basin(map,i-1,j);
		if(map[i+1][j] - curr >= 1) size += basin(map,i+1,j);
	}

	return size;
}

int main()
{
	int sum =0;
	deque<deque<int>> map;

	ifstream inp("day9.txt");

	for(string i; inp>>i;) {
		deque<int> l;
		for(auto itr = i.begin(); itr!=i.end();++itr) {
			int n= *itr - '0';
			l.push_back(n);
		}
		map.push_back(l);
	}

	map.push_front(deque<int>(map[0].size(),-1));
	map.push_back(deque<int>(map[0].size(),-1));

	for(auto &v:map) {
		v.push_front(-1);
		v.push_back(-1);
	}

	auto map_cpy = map;

	int ans[3] = {0};
	
	for(auto i=1;i!=map.size()-1;++i) {
		for(auto j = 1;j!=map[i].size()-1;++j) {
			int num = map[i][j];
			int l = map[i][j-1];
			int r = map[i][j+1];
			int d = map[i+1][j];
			int u = map[i-1][j];
			if(isMinimum(num,{l,r,d,u})) {
				sum += num+1;
				int b = basin(map_cpy,i,j);
				if(b>=ans[2]) {
					ans[0] = ans[1];
					ans[1] = ans[2];
					ans[2] = b;
				} else if (ans[1] <= b) {
					ans[0] = ans[1];
					ans[1] = b;
				} else if (ans[0] < b) {
					ans[0] = b;
				}

			}
		}
	}

	cout << sum << endl;
	cout << ans[0]*ans[1]*ans[2] << endl;
}
