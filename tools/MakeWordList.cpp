#include <iostream>
#include<vector>

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
		if(inputs.size() > 4)
			for(int i = 4; i < int(inputs.size()); i++)
				inputs[3]+= " " + inputs[i];
		printf("|**%s**|%s|%s|%s|\n", inputs[0].c_str(), inputs[1].c_str(), inputs[2].c_str(), inputs[3].c_str());
	}
}
