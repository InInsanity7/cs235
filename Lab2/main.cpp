#include <set>
#include <vector>
#include <map>
#include <list>
#include <sstream>
#include <fstream>
#include <iostream>
#include <utility>
using namespace std;
int main(int argc, char *argv[]) {

	//context wordcount
int context = 3;
    vector<string> tokens;
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
    map<list<string>, vector<string>> wordmap;
    list<string> last;
		for (int i = 0; i < context; i++) {
			last.push_back("");
		}

    for (vector<string>::iterator it=tokens.begin(); it!=tokens.end(); it++) {
        wordmap[last].push_back(*it);
        last.push_back(*it);
				last.pop_front();
    }

		srand(time(NULL));

		last.clear();
		int index = rand() % (tokens.size() - context);
		for (int i = 0; i < context; i++) {
			last.push_back(tokens[index + i]);
		}
		/*
		//working:
		for (int i = 0; i < 100; i++) {
			int ind = rand() % wordmap[last].size();
			cout << wordmap[last][ind] << " ";
			last.push_back(wordmap[last][ind]);
			last.pop_front();
		}

		*/
		set<char> vowel = {'a', 'e', 'i', 'o', 'u', 'y'};
		string currentWord;
		for (int stanzas = 0; stanzas < 14; stanzas++) {
			int syllables = 0;
			bool isVowel = false;
			int ind = 0;
			
			while (syllables < 10) {
				ind = rand() % wordmap[last].size();
				currentWord = wordmap[last][ind];
				int letter = 0;
				
				//condition checks for previous char as vowel, and curr char as consonant. For this code, this constitutes a syllable.
				while (letter < currentWord.size()) {
					set<char>::iterator ot = vowel.find(currentWord[letter]);
					if (isVowel==false && ot != vowel.end()) {
						isVowel = true;
					}					
					else if ((isVowel == true) && (ot ==vowel.end())) {
						isVowel = false;
						++syllables;						
					}
					++letter;
				}
				cout << currentWord << " ";
				last.push_back(currentWord);
				last.pop_front();
			}
			cout << endl;
		}
/*
put wordmap word into buffer
output chars til vowel, TRUE vowel
output til consonant, TRUE consonant
syllable++;
while syllable < 10, cout word,
endl; stanzas++
while stanzas < 14;

*/
		/*
		for (int i = 0; i < wordmap["Nephi"].size(); ++i) {
			cout << wordmap["Nephi"].at(i) << " ";
		}
		*/
    cout << endl;
}
