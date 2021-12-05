#include<bits/stdc++.h>
using namespace std;

using range = pair<pair<int,int>,pair<int,int>>;
range read_line(ifstream& inp)
{
	string line;
	getline(inp,line);
	istringstream iss(line);

	int coord[4];
	int curr = 0;
	for(string buffer;getline(iss,buffer,' '); ){
		if(buffer=="->") continue;
		stringstream ss(buffer);
		for(string buf;getline(ss,buf,',');) {
			stringstream temp(buf);
			int i;
			temp >> i;
			coord[curr++]=i;			
		}	
	}


	return {make_pair(coord[0],coord[1]), make_pair(coord[2],coord[3])};

}
int main()
{
	ifstream inp("day5.txt");

	vector<array<int,3>> vertical;
	vector<array<int,3>> horizontal;
	vector<vector<pair<int,int>>> diagonal;

	int max_x, max_y;

	for(int i = 0; inp.peek()!=EOF;++i) {
		auto coord = read_line(inp);
		int x1 = coord.first.first;
		int x2 = coord.second.first;
		int y1 = coord.first.second;
		int y2 = coord.second.second;
		
		if(max(x1,x2) > max_x) max_x = max(x1,x2);
		if(max(y1,y2) > max_y) max_y = max(y1,y2);
		array<int,3> tmp;
		if(coord.first.first == coord.second.first) { //vertical: x stays the same
			tmp[0]=coord.first.first;
			//determine the delta
			if(coord.first.second > coord.second.second) { //put in right order
				tmp[1] = coord.second.second;
				tmp[2] = coord.first.second;
			} else {
				tmp[1] = coord.first.second;
				tmp[2] = coord.second.second;
			}
			//cout << "fixed x: " << tmp[0] << ",y: " << tmp[1] << "->"<<tmp[2] << endl;
			vertical.push_back(tmp);
		} else if(coord.first.second == coord.second.second) { //horizontal: y stays fixed
			tmp[0]=coord.first.second;
			//determine the delta
			if(coord.first.first > coord.second.first) { //put in right order
				tmp[1] = coord.second.first;
				tmp[2] = coord.first.first;
			} else {
				tmp[1] = coord.first.first;
				tmp[2] = coord.second.first;
			}
			//cout << "fixed y: " << tmp[0] << ",x: " << tmp[1] << "->"<<tmp[2] << endl;
			horizontal.push_back(tmp);
		} else { //diagonal lines
			vector<pair<int,int>> range;

			if(coord.first.first < coord.second.first && coord.first.second <coord.second.second) {
				cout << "case 1" << endl;
				int k = coord.first.second;
				for(int i = coord.first.first; i<=coord.second.first && k<=coord.second.second;) {
					range.push_back({i,k});
					++i;
					++k;
				}
			}else if(coord.first.first > coord.second.first && coord.first.second > coord.second.second) {
				cout << "case 2" << endl;
				int k = coord.first.second;
				for(int i = coord.first.first; i>=coord.second.first && k>=coord.second.second;) {
					range.push_back({i,k});
					--i;
					--k;
				}

			}
			else {

				if(coord.first.first > coord.second.first && coord.first.second < coord.second.second) { //x gets smaller
					cout << "case 3" << endl;
					int k = coord.first.second;
					for(int i = coord.first.first; i>=coord.second.first && k<=coord.second.second;) {
						range.push_back({i,k});
						--i;
						++k;
					}
				} else  { //y gets smaller
					cout << "case 4" << endl;
					int k = coord.first.second;
					for(int i = coord.first.first; i<=coord.second.first && k>=coord.second.second;) {
						range.push_back({i,k});
						++i;
						--k;
					}

				}

			}
			diagonal.push_back(range);
		}
		//cout << coord.first.first << "," << coord.first.second << " ->  ";
		//cout << coord.second.first << "," << coord.second.second << endl;

	}

	int field[max_x][max_y] = {0};

	int overlaps = 0;
	for(int i = 0; i!=vertical.size();++i) {
		for(int k=vertical[i][1]; k<=vertical[i][2];++k) {
			int &val = field[vertical[i][0]][k];
			if(val==1) ++overlaps;
			++val;
		}
	}

	for(int i = 0; i!=horizontal.size();++i) {
		for(int k=horizontal[i][1]; k<=horizontal[i][2];++k) {
			int &val = field[k][horizontal[i][0]];
			if(val==1) ++overlaps;
			++val;
		}
	}

	/*
	   for(const auto& i:field) {
	   for(const auto& k:i)
	   cout << k << " ";
	   cout << endl;
	   }*/

	cout << "overlaps in part1: " << overlaps << endl;

	cout << diagonal.size() << endl;
	int reached = 0;
	for(auto beg = diagonal.begin(); beg!=diagonal.end(); ++beg) {
		cout << reached++ << endl;
		for(auto i = beg->begin(); i != beg->end(); ++i) {
			int x = i->first;
			int y = i->second;
			int &val = field[x][y];
			if(val==1) ++overlaps;
			++val;
		}
	}


	for(const auto& i:field) {
		for(const auto& k:i)
			cout << k << " ";
		cout << endl;
	}
	cout << "overlaps in part2: " << overlaps << endl;








}
