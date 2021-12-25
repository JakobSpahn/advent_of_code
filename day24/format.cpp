#include <bits/stdc++.h>
using namespace std;

int main()
{
	ifstream in("day24.in");
	ofstream outf("formatted.in");

	for(string i; getline(in,i);) {
		stringstream ss (i);
		string out, a, b;
		ss >> out;
		ss >> a;
		if(ss.peek()!=EOF) ss >> b;

		out.append("(");
		out.append(a);

		if(b.size()!=0) {
			out.append(",");
			out.append(b);
		}
		out.append(");");

		outf << out << '\n';

		
		
	}
}
