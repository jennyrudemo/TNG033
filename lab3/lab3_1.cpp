/********************************
 * TNG033 : lab3				*
 * Exercise 1	                *
 *******************************/

#include<iostream>
#include<fstream>
#include<string>
#include<map>
#include<algorithm>
#include<vector>
#include<iomanip>
#include<cctype>
#include<iterator>

using pair = std::pair<std::string, int>;

 //to lowercase
void toLower(std::string& word) {
	std::for_each(word.begin(), word.end(), [](char& c) {
		c = ::tolower(c);
	});
}

//kollar spec tecken
struct isNotSpecChar {
	bool operator()(char& c) {

		std::string specChar = ".,!?:/();\"";

		if (specChar.find(c) != std::string::npos) {
			return false;
		}
		else {
			return true;
		}
	}
};

//ta bort spec tecken
std::string removeSpecChar(std::string& word) {
	std::string temp;
	std::copy_if(word.begin(), word.end(), std::back_inserter(temp), isNotSpecChar());
	return temp;
}

struct displayWord {
	void operator()(pair w) {
		std::cout << std::left << std::setw(25) << w.first << w.second << std::endl;
	}
};

template <class T>
void print (T table) {
	std::for_each(table.begin(), table.end(), displayWord());
}

bool sortByFreq(const pair &a, const pair &b) {
	return a.second > b.second;
}

int main() {
	std::map<std::string, int> frequencyTable;
	std::string word;
	std::string wordNoSpec;
	int numberOfWords = 0;

	//std::ifstream inFil("C:/Users/jx/Documents/Uni/TNG033/lab3/lab3_1/uppgift1_kort.txt"); 
	std::ifstream inFil("C:/Users/jx/Documents/Uni/TNG033/lab3/lab3_1/uppgift1.txt");

	if (!inFil) {
		std::cout << "File could not be opened!!";
		return 0;	//quit if file could not be opened
	}	

	//read words
	while (inFil >> word) {
		toLower(word);
		word = removeSpecChar(word);

		auto it = frequencyTable.find(word);

		if (it != frequencyTable.end()) {
			frequencyTable[word]++;
		}
		else {
			frequencyTable.insert({ word, 1 });
		}
		
		numberOfWords++;
	}

	std::cout << "Number of words in the file = " << numberOfWords << std::endl;
	std::cout << "Number of unique words in the file = " << frequencyTable.size() << std::endl << std::endl;
	
	std::cout <<  "Frequency table sorted alphabetically..." << std::endl;
	print(frequencyTable);

	//vector sort by frequency
	std::vector<pair> sortedFrequency(frequencyTable.size());

	std::copy(frequencyTable.begin(), frequencyTable.end(), sortedFrequency.begin());
	std::sort(sortedFrequency.begin(), sortedFrequency.end(), sortByFreq);

	std::cout << std::endl << std::endl << "Frequency table sorted by frequency..." << std::endl;
	print(sortedFrequency);

	return 0;
}