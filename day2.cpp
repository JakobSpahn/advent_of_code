#include <iostream>
#include <fstream>
#include <string>
#include <utility>
#include <vector>

using std::cout;
using std::endl;
using std::ifstream;
using std::make_pair;


std::pair<int,int> delta(std::string &a, int b)
{
	if(a == "up")
		return make_pair(0,-b);
	else if(a == "forward")
		return make_pair(b,0);
	else if(a == "down")
		return make_pair(0,b);

	return make_pair(0,0);
}

int part1(ifstream& myfile)
{
	std::string a;
	int b;
	int x = 0;
	int y = 0;

	while(myfile >> a >> b) {
		cout << a << " " << b << endl;
		auto delta_coord = delta(a,b);
		x += delta_coord.first;
		y += delta_coord.second;

	}
	return x*y; 
}

std::vector<int> delta_aim(std::string& a, int b, int aim)
{
	if(a == "up")
		return {0,0,-b};
	else if(a == "forward") {
		return {b,aim*b,0}; 
	}
	else if(a == "down")
		return {0,0,b};

	return {0,0,0};

}

int part2(ifstream& myfile)
{
	std::string a;
	int b;
	int x = 0;
	int y = 0;
	int aim = 0;

	while(myfile >> a >> b) {
		cout << a << " " << b << endl;
		auto delta_coord = delta_aim(a,b,aim);
		x += delta_coord[0];
		y += delta_coord[1];
		aim += delta_coord[2];

	}
	return x*y; 
}


int main()
{
	ifstream myfile("day2.txt");
	auto p1 = part1(myfile);
	cout << p1 << endl;
	ifstream myfile2("day2.txt");
	auto p2 = part2(myfile2);
	cout << p2 << endl;

}
