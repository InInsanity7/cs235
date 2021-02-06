#include <set>
#include <vector>
#include <map>
#include <sstream>
#include <fstream>
#include <iostream>
#include <utility>
using namespace std;
int main(int argc, char *argv[])
{
    list<string> tokens;
    set <string> unique;
    string next_line;  // Each data line
    ifstream in(argv[1]);
    while (getline(in, next_line)) {
        istringstream iss(next_line);
        string token;
        while (iss >> token) {
            string nopunct = "";
            for(auto &c : token) { // Remove Punctuation
                if (isalpha(c)) {
                    nopunct +=c;
                }
            }
	          tokens.push_back(nopunct);
		        unique.insert(nopunct);

	    }
    }

    map<string, string> wordmap;
    string last="";
    for (list<string>::iterator it=tokens.begin(); it!=end(); it++) {
        wordmap[last]=*it;
        last=*it;
    }
    for (int i = 0; i < 100; i++) {
        cout << wordmap[state] << " ";
        state = wordmap[state];
    }
    cout << endl;
}
