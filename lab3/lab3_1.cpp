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

//to do:
//fixa blankspacet som läses in i slutet
//para ihop orden med sorterad vector

 //to lowercase
void toLower(std::string& word) {
	std::for_each(word.begin(), word.end(), [](char& c) {
		c = ::tolower(c);
	});
}

//kollar spec tecken
bool isSpecChar(char& c) {
	switch (c) {
	case '.':
	case ',':
	case '!':
	case '?':
	case ':':
	case '/':
	case '"':
	case '(':
	case ')':
	case ';':
	case '\n':
		return true;
	default:
		return false;
	}
}

//ta bort spec tecken
void removeSpecChar(std::string& word) {
	word.erase(std::remove_if(word.begin(), word.end(), &isSpecChar), word.end());
}

void print(std::map<std::string, int> &map) {
	std::for_each(map.cbegin(), map.cend(), [](const std::pair<std::string, int> &m) {
		std::cout << std::left << std::setw(15) << m.first << m.second << std::endl;
	});
}

void printVec(std::vector<int> &v) {
	std::copy(v.begin(), v.end(), std::ostream_iterator<int>(std::cout, "  "));
}

bool largestFirst(int i, int j) {
	return i > j;
}

int main() {
	std::map<std::string, int> frequencyTable;
	std::vector<int> sortedFrequency;
	std::string word;
	int numberOfWords = 0;
	int numberUniqueOfWords = 0;

	std::ifstream inFil("C:/Users/jx/Documents/Uni/TNG033/lab3/lab3_1/uppgift1_kort.txt"); 

	if (!inFil) {
		std::cout << "File could not be opened!!";
		return 0;	//quit if file could not be opened
	}

	std::getline(inFil, word, ' ');		

	while (inFil) {
		toLower(word);
		removeSpecChar(word);

		auto it = frequencyTable.find(word);

		if (it != frequencyTable.end()) {
			frequencyTable[word]++;
		}
		else {
			frequencyTable.insert({ word, 1 });
			numberUniqueOfWords++;
		}

		//std::cout << "hej" << word << std::endl;
	
		numberOfWords++;
		getline(inFil, word, ' ');		//read next word
	}

	std::cout << "Number of words in the file = " << numberOfWords << std::endl;
	std::cout << "Number unique words in the file = " << numberUniqueOfWords << std::endl << std::endl;
	
	std::cout <<  "Frequency table sorted alphabetically..." << std::endl;
	print(frequencyTable);

	//gör till funktion? 
	std::transform(frequencyTable.begin(), frequencyTable.end(), std::back_inserter(sortedFrequency),
		[](const std::pair<std::string, int> &map) {
		return map.second;
	});
	
	std::sort(sortedFrequency.begin(), sortedFrequency.end(), largestFirst);
	
	std::cout << std::endl << std::endl << "Frequency table sorted by frequency..." << std::endl;
	printVec(sortedFrequency);
	

	return 0;
}