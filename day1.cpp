#include <vector>
#include <iostream>
#include <fstream>
#include <string>

using std::cout;
using std::endl;


std::vector<long int> read(std::ifstream &input)
{
	long int store;
	std::vector<long int> vec;
	while(input >> store) vec.push_back(store);
	return vec;
}

int single_increases(std::vector<long int>::iterator beg, std::vector<long int>::iterator end)
{
	auto current = *beg;
	cout << current << endl;
	++beg;
	auto last = current;
	int increases=0;
	while(beg!=end) {
		current = *beg;
		cout << current;
		if(current>last) {
			++increases;
			cout << " (increase)" << endl;
		} else
			cout << endl;
		last = current;
		++beg;
	}
	cout << "total: " << increases << endl;

	return increases;
}

long int sliding_window(std::vector<long int>::iterator beg, std::vector<long int>::iterator end, int size=1)
{
	long int sum=0;
	auto window_end = beg+size+1;
	while(beg != window_end && beg != end) {
		sum += *beg;
		++beg;
	}
	return sum;
}

int window_increases(std::vector<long int>::iterator beg, std::vector<long int>::iterator end)
{
	int sz=3;
	auto current = sliding_window(beg, end, sz);
	++beg;
	auto last = current;
	int increases = 0;
	while(beg!=end) {
		if(end-beg<3) break;
		current = sliding_window(beg, end, sz);
		cout << current;
		if(current>last) {
			++increases;
			cout << " (increase)" << endl;
		} else
			cout << endl;
		last = current;
		++beg;
	}
	cout << "total: " << increases << endl;
	return increases;

}


int main()
{
	std::ifstream myfile("day1.txt");
	auto vec = read(myfile);

	//single_increases(vec.begin(), vec.end());
	window_increases(vec.begin(), vec.end());
}
