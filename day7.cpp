#include <bits/stdc++.h>
using namespace std;

int c(int a, int b) 
{
	int n = abs(a-b);
	return (n*(n+1))/2;
}

int main()
{
	vector<int>  p/*{16,1,2,0,4,2,7,1,2,14}*/;
	ifstream inp("day7.txt");
	string buff;

	
	while(getline(inp, buff, ',')) {
		int i;
		stringstream ss(buff);
		ss >> i;
		p.push_back(i);
	}
	

	sort(p.begin(), p.end());
	int lowest_fuel = 0;
	for(int i=p[0]; i<=p.back();++i) {
		int fuel = 0;
		for(auto beg = p.begin(); beg != p.end(); ++beg) {
			fuel += c(*beg, i);
		}
		if(fuel < lowest_fuel || lowest_fuel == 0) lowest_fuel = fuel;

	}	
	cout << lowest_fuel << endl;
}
