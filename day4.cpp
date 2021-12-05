#include <fstream>
#include <iostream>
#include <vector>
#include <sstream>
#include <algorithm>

using namespace std;



void print_board(const vector<vector<int>> &vec)
{
	cout << endl;
	for(auto l = vec.begin(); l != vec.end(); ++l) {
		for(auto num = l->begin(); num != l->end(); ++num) {
			cout << *num << " ";
		}
		cout << endl;
	}
}

vector<int> read_draws(ifstream& inp)
{
	int i;
	vector<int> vec;
	string line;

	getline(inp,line);
	istringstream iss(line);
	
	for(string s; getline(iss, s, ',');) {
		stringstream ss(s);
		int i;
		ss >> i;
		vec.push_back(i);
	}

	return vec;
}

vector<vector<int>> read_board(ifstream& inp)
{
	vector<vector<int>> board;
	for(int i = 0; i!=5; ++i) {
		vector<int> line;
		int num;
		for(int k = 0; k!=5 && inp >> num; ++k) 
			line.push_back(num);
		board.push_back(line);
	}
	return board;
}

vector<int> get_vertical(const vector<vector<int>> &board, size_t n)
{
	vector<int> v;
	for(auto m = board.begin(); m != board.end(); ++m)
		v.push_back((*m)[n]);
	return v;

}

void print(vector<int> vec) 
{
	for(auto beg = vec.begin(); beg != vec.end(); ++beg) cout << *beg << " ";
	cout << endl;
}
bool isSubsetOrEqual(const vector<int> &a, const vector<int> &b)
{
	for(auto const& el:a) {
		if(find(b.begin(), b.end(), el)==b.end())
			return false;
	}
	return true;
}

int sum(const vector<int> &i)
{
	int sum = 0;
	for(const auto &n:i)
		sum += n;
	return sum;

}

int sum(const vector<vector<int>> &i)
{
	int sum_matrix= 0;
	for(const auto &n:i)
		sum_matrix += sum(n);
	return sum_matrix;
}
vector<vector<int>> mark(vector<vector<int>> board, vector<int> draw)
{
	for(auto beg = board.begin(); beg != board.end(); ++beg) {
		for(auto el = beg->begin(); el !=beg->end(); ++el) {
			if(find(draw.begin(), draw.end(), *el)!=draw.end()) (*el)=0;
		}
	}
	return board;
}
void part1()
{
	ifstream inp1("day4.txt");

	auto draws = read_draws(inp1);
	for(auto beg = draws.begin(); beg!=draws.end();++beg) cout << *beg << ",";
	cout << endl;

	bool found = false;
	for(int l = 5; l!=draws.size()+1 && !found; ++l) {
		ifstream inp("day4.txt");
		string s;
		getline(inp,s);
		vector<int> draw(draws.begin(),draws.begin()+l);
		while(inp.peek()!=EOF && !found) {
			auto board = read_board(inp);
			if(inp.peek()==EOF) break;
			print(draw);
			print_board(board);
			for(int i = 0; i!=5; ++i) {
				auto h = board[i];
				auto v = get_vertical(board, i);
				if(isSubsetOrEqual(h,draw)) {
					cout << "bingo" << endl;
					print(h);
					auto non_marked = mark(board,draw);
					print_board(non_marked);
					cout << sum(non_marked) << endl;
					found = true;
					break;
				}
				if(isSubsetOrEqual(v,draw)) {
					cout << "bingo" << endl;
					print(h);
					//cout << sum(board)-sum(v) << endl;
					auto non_marked = mark(board,draw);
					print_board(non_marked);
					cout << sum(non_marked) << endl;
					found = true;
					break;
				}
			}

		}
	}
}

vector<vector<vector<int>>> build_boards(ifstream& inp)
{
	vector<vector<vector<int>>> ret;
	while(inp.peek()!=EOF) {
		auto board = read_board(inp);
		if(inp.peek()==EOF) break;
		ret.push_back(board);
	}
	return ret;
}

void bingo(vector<vector<int>> &board, vector<int> line, vector<int> draw)
{
	print(draw);
	cout << "bingo" << endl;
	print(line);
	auto non_marked = mark(board,draw);
	print_board(non_marked);
	cout << "sum:" << sum(non_marked) << endl;
	cout << *(draw.end()-1) << endl;
}

void part2()
{
	ifstream inp("day4.txt");
	auto draws = read_draws(inp);

	auto boards = build_boards(inp);

	auto boards_left = boards;
	for(int l = 5; l!=draws.size()+1 && boards_left.size()>0; ++l) {
		vector<int> draw(draws.begin(),draws.begin()+l);
		bool found = false;
		for(auto beg = boards_left.begin(); beg != boards_left.end();) {
			auto board = *beg;
			for(int i = 0; i!=5; ++i) {
				auto h = board[i];
				auto v = get_vertical(board, i);
				if(isSubsetOrEqual(h,draw)) {
					cout << endl;
					bingo(board,h,draw);
					found = true;
					beg = boards_left.erase(beg);
					break;
				} else if(isSubsetOrEqual(v,draw)) {
					cout << endl;
					bingo(board,v,draw);
					found = true;
					beg = boards_left.erase(beg);
					break;
				}
			}
			if(!found) ++beg;
			else found = false;
		}
		cout << "size left: " << boards_left.size() << endl;
	}

}
int main()
{
	part2();
}
