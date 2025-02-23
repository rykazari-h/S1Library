#include <iostream>

using namespace std;

vector<string> split(const string &s, char div= ' '){
	vector<string> res;
	string chars;
	for (char ch: s) {
		if (ch == div){
			if (chars.size())
				res.push_back(chars);
			chars.clear();
		}
		else {
			chars+= ch;
		}
	}
	if (chars.size())
		res.push_back(chars);
	return res;
}
int main(){
	string input;
	while(getline(cin, input)){
		auto inputs = split(input);
		printf("|**%s**|%s|%s|%s|\n", 
	}
