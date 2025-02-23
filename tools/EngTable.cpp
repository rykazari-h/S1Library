#include <iostream>
#include <vector>

using namespace std;

/*
InputFormat -> eng jpn part tips
使いどころは意外とないかもしれない(手動で十分)
*/
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
	string input;
	while(getline(cin, input)){
		auto t = split(input);
		if(t.size() > 4)
			for(int i = 4; i < int(t.size()); i++)
				t[3]+=" "+t[i];
		printf("|**%s**|%s|%s|%s|\n", t[0].c_str(), t[1].c_str(), t[2].c_str(), t[3].c_str());
	}
	return 0;
}
