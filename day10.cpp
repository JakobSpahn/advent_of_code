#include <bits/stdc++.h>
using namespace std;

const map<char,char> match{{'(',')'},{'[',']'},{'{','}'},{'<','>'}};

const map<char,int> score{{')',3},{']',57},{'}',1197},{'>',25137}};
const map<char,int> clscore{{')',1},{']',2},{'}',3},{'>',4}};



int main()
{
	ifstream in("day10.in");


	stack<string> lines;
	vector<string> incomp;

	map<char,int> cscore{{')',0},{']',0},{'}',0},{'>',0}};


	for(string l; getline(in,l);) {

		stringstream ss(l);
		char c;
		lines.push(l);

		stack<char> open;
		while(ss >> c) {
			cout << c;
			if(match.find(c)!=match.end()) { //if opening
				open.push(c);
			} else { //if c is closing
				char opening = open.top();
				auto closing = match.find(opening)->second;
				open.pop();
				if(c!=closing) {
					++cscore[c];
					lines.pop();
					break;
				}

			}
		}
		cout << endl;


	}

	int sum = 0;

	for(auto itr = cscore.begin(); itr!=cscore.end();++itr) {
		char c = itr->first;
		int t = itr->second;
		int mul = t * score.find(c)->second;
		sum+=mul;

		cout << c << ":" << t << " - " << 
			mul << endl;
	}
	cout << sum << endl;

	vector<ulong> points;

	while(!lines.empty()) {
		stringstream ss(lines.top());
		char c;
		stack<char> open;
		while(ss >> c) {
			if(match.find(c)!=match.end()) { //if opening
				open.push(match.find(c)->second);
			} else { //if c is closing
				open.pop();
			}

		}
		ulong tmp = 0;
		while(!open.empty()) {
			tmp = 5*tmp + clscore.find(open.top())->second;
			cout << open.top();
			open.pop();
		}
		cout << " - " << tmp << endl;
		points.push_back(tmp);
		lines.pop();
	}

	sort(points.begin(),points.end());
	cout << points[points.size()/2] << endl;

}
