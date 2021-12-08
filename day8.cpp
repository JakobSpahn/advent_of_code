#include <bits/stdc++.h>

using namespace std;

const multimap<int,int> nums{{6,0},{2,1},{5,2},{5,3},{4,4},{5,5},{6,6},{3,7},{7,8},{6,9}};

const map<int,string> goal{{0,"abcefg"},{1,"cf"},{2,"acdeg"},{3,"acdfg"},{4,"bcdf"},
	{5,"abdfg"},{6,"abdefg"},{7,"acf"},{8,"abcdefg"},
	{9,"abcdfg"}};

pair<vector<string>,vector<string>> readl(ifstream& inp)
{
	vector<string> sigs, outs;

	string sig, out;

	getline(inp,sig,'|');
	getline(inp, out);

	stringstream ss(sig);
	for(string i; getline(ss,i,' ');) {
		sigs.push_back(i);
	}

	stringstream ss2(out);
	string tmp;
	getline(ss2,tmp,' ');

	for(string i; getline(ss2,i,' ');) {
		outs.push_back(i);
	}

	return {sigs, outs};

}

pair<map<char,char>,bool> search(vector<string>::iterator beg, 
		vector<string>::iterator end,
		map<char,char> trans)
{
	if(nums.count(beg->size())==1) { //if we are still processing the unique 
		int unique = nums.find(beg->size())->second; //get unique value
		string unique_str = goal.find(unique)->second;
		string missing;
		string target;
		for(char c:*beg){
			if(trans.find(c)==trans.end()) missing.push_back(c);
			else target.push_back(trans.find(c)->second);
		}
		//now start guessing
		sort(missing.begin(),missing.end());
		do {
			//get difference between goal.find(unique) and target
			sort(target.begin(),target.end());
			string temp;

			for(auto itr = unique_str.begin(); itr!=unique_str.end();++itr) {
				if(target.find(*itr)>=target.size()) temp.push_back(*itr); //c++23
			}

			assert(temp.size() == missing.size());
			//assign the chars in difference to the current permutation

			for(size_t i = 0; i!=missing.size(); ++i)
				trans[missing[i]] = temp[i];

			//recursively call seach
			auto ret = search(beg+1,end,trans);
			if(ret.second==true) {return ret;}
		} while(next_permutation(missing.begin(), missing.end()));
		return {trans,false};
	} else {
		//flip goals
		map<string,int> flipped;
		for(auto i=goal.begin(); i!=goal.end();++i)
			flipped[i->second] = i->first;
		//now start trying
		while(beg!=end) {
			string num = *beg;
			//translate
			for(auto &c:num) c = trans[c];
			sort(num.begin(),num.end());
			if(flipped.find(num)==flipped.end())return {trans,false};
			++beg;
		}

	}
	return {trans,true};
}
int main()
{
	ifstream inp("day8.txt");

	int sum = 0;


	while(inp.peek()!=EOF) {
		auto l = readl(inp);
		auto sigs = l.first;
		auto outs = l.second;

		for(auto c:outs) {
			if(nums.count(c.size())==1) {
				auto itr = nums.find(c.size());
				++sum;
			}
		}
	}
	cout << sum << endl;

	sum = 0;

	map<string,int> flipped;
	for(auto i=goal.begin(); i!=goal.end();++i)
		flipped[i->second] = i->first;

	ifstream inp2("day8.txt");
	while(inp2.peek()!=EOF) {
		auto l = readl(inp2);
		auto sigs = l.first;
		auto outs = l.second;
		sort(sigs.begin(),sigs.end(),
				[](const string &a, const string &b){return a.size()>b.size();});
		stable_sort(sigs.begin(), sigs.end(), [](const string &a, const string &b){
				return nums.count(a.size()) <=  nums.count(b.size());});

		map<char,char> trans;
		auto res = search(sigs.begin(),sigs.end(),trans);

		map<string,int> flipped;
		for(auto i=goal.begin(); i!=goal.end();++i)
			flipped[i->second] = i->first;

		string betw;
		for(auto s:outs) {
			string translated;
			for(auto c:s) translated.push_back(res.first[c]);
			sort(translated.begin(),translated.end());
			int eval = flipped[translated];
			betw +=(to_string(eval));
		}
		sum+=stoi(betw);
	}
	cout << sum << endl;
}

