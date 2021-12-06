#include <bits/stdc++.h>

using namespace std;
array<ulong,9> f2(int n, array<ulong,9> s)
{

	if(n==0) return s;
	ulong buff = s[0];

	for(int i = 1; i!=9;++i) {
		s[i-1]=s[i];
	}
	s[8]=buff;
	s[6]+=buff;
	
	return f2(--n,s);
}

int main()
{
	ifstream inp("day6.txt");
	string buff;

	vector<int> init;
	while(getline(inp, buff, ',')) {
		int i;
		stringstream ss(buff);
		ss >> i;
		init.push_back(i);
	}

	array<ulong,9> trans = {0};
	for(auto c:init) ++trans[c];

	auto res = f2(256,trans);
	ulong sum = 0;
	for(auto c:res) sum+=c;
	cout << sum << endl;
}
