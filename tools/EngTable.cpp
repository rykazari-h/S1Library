#include <iostream>
#include <vector>

using namespace std;

vector<string> split(const string &s, char div= ' '){
	vector<string> res;
	string parts;
	for (char ch: s) {
		if (ch == div){
			if (parts.size())
				res.push_back(parts);
			parts.clear();
		}
		else {
			parts+= ch;
		}
	}
	if (parts.size())
		res.push_back(parts);
	return res;
}

int main(){
	string s;
	while(getline(cin,s)){
		auto inputs = split(s);
		if(inputs.size()>4)
			for(int i = 4 ; i < int(inputs.size()); i++)
				inputs[3]+=" "+inputs[i];
		printf("|**%s**|%s|%s|%s|\n", inputs[0].c_str(), inputs[1].c_str(), inputs[2].c_str(), inputs[3].c_str());
	}
	return 0;
}
