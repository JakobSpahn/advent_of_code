#include <vector>
#include <string>
#include <fstream>
#include <iostream>
#include <bitset>

using namespace std;

struct bit_field
{
	unsigned x: 12;
};

vector<string> read(ifstream& input)
{
	string line;
	vector<string> vec;
	while(input >> line) vec.push_back(line);
	return vec;
}

int part1(ifstream& input)
{
	auto lines = read(input);

	bit_field gamma, epsilon;
	//vector<int> g_vec;
	gamma.x = epsilon.x = 0;
	for(auto w_size = 0; w_size != lines[0].size(); ++w_size) {
		//cout << lines[0].size();
		int ones, zeroes;
		ones = zeroes = 0;

		for(auto beg = lines.begin(); beg != lines.end(); ++beg) {
			if((*beg)[w_size] == '0')
				++zeroes;
			else 
				++ones;
		}
		gamma.x = gamma.x << 1;
		cout << zeroes << " " << ones << endl;
		if(zeroes > ones) {
			gamma.x |= 0UL;
		}

		else {
			gamma.x |= 1UL;
		}
		bitset<16> bitset_g{gamma.x};
		cout << bitset_g << endl;

	}
	epsilon.x = ~gamma.x;

	bitset<12> bitset_g{gamma.x};
	bitset<12> bitset_e{epsilon.x};
	cout << "final:" << endl;
	cout << bitset_g << endl;
	cout << bitset_e << endl;
	return gamma.x * epsilon.x;
}

int part2(ifstream& input)
{
	int oxy, co2;
	oxy = co2 = 0;

	auto lines = read(input);
	vector<string> oxy_lines, co2_lines;

	oxy_lines = lines;
	for(auto w_size = 0; w_size!=lines[0].size(); ++w_size) { 
		vector<string> ones, zeroes;

		for(auto beg = oxy_lines.begin(); beg != oxy_lines.end(); ++beg) {
			if((*beg)[w_size] == '0') zeroes.push_back(*beg);
			else ones.push_back(*beg);
		}
		if(ones.size() >= zeroes.size()) {
			oxy_lines = ones;
		} else {
			oxy_lines = zeroes;
		}
	}

	co2_lines = lines;
	for(auto w_size = 0; w_size!=lines[0].size(); ++w_size) { 
		vector<string> ones, zeroes;

		for(auto beg = co2_lines.begin(); beg != co2_lines.end(); ++beg) {
			if((*beg)[w_size] == '0') zeroes.push_back(*beg);
			else ones.push_back(*beg);
		}
		if(co2_lines.size() == 1) break;
		if(ones.size() >= zeroes.size()) {
			co2_lines = zeroes;
		} else {
			co2_lines = ones;
		}
	}

	cout << oxy_lines.size() << endl;
	cout << co2_lines.size() << endl;
	cout << lines.size() << endl;

	oxy = std::stoi(oxy_lines[0], nullptr, 2);
	co2 = std::stoi(co2_lines[0], nullptr, 2);

	bitset<12> bitset_g{oxy};
	bitset<12> bitset_e{co2};

	cout << oxy_lines[0] << endl;
	cout << bitset_g << endl;

	cout << co2_lines[0] << endl;
	cout << bitset_e << endl;




	return oxy * co2;
}



int main()
{
	ifstream input("day3.txt");
	//int p1 = part1(input);
	//cout << p1 << endl;
	int p2 = part2(input);
	cout << p2 << endl;
}
