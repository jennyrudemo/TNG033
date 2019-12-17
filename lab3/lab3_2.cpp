//
//  main.cpp
//  Lab3_ex2
//
//  Created by Jenny Rudemo on 2019-12-13.
//  Copyright © 2019 Jenny Rudemo. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <iomanip>
#include <iterator>
#include <set>

void displayVec (std::set<std::string> vec) {
    std::for_each(vec.begin(), vec.end(), [](auto& w){
        std::cout << w << " ";
    });
}

void displayAnagrams(std::map<std::string, std::set<std::string>> m) {
    std::for_each(m.begin(), m.end(), [](auto& s){
        if(s.second.size() >=2) {
            std::cout << "Subject: " << std::left << std::setw(15) << s.first;
            std::cout << "Anagrams: ";
            displayVec(s.second);
            std::cout << "--> " << s.second.size() << " anagrams" << std::endl;
        }
    });
}

int main() {
    //Läs in fil
    std::ifstream inFil ("//ad.liu.se/home/jesch310/Desktop/lab3 tng033/uppgift2_kort.txt");
    
    //Testa fil
    if(!inFil) {
        std::cout << "Filen kunde inte läsas in. Avslutar programmet." << std::endl;
        
        return 1;
    }
    
    //Program
    
    std::istream_iterator<std::string> start(inFil); //constructor gör att den pekar i början
    std::istream_iterator<std::string> end; //Vad blir end? Vad pekar den på? Fejkiterator
    
    //std::map<std::string, std::vector<std::string>> anagrams; ///<subject, anagrams(vektor)>
	std::map<std::string, std::set<std::string>> anagrams;

    int numberOfWords = 0;
    
	auto createSubject=[](std::string word) {
		std::sort(word.begin(), word.end());
		return word;
	};

    //Lägg till ord i map
    //Hoppar automatiskt över white spaces (eftersom start och end är iterators för string)
    std::for_each(start, end, [&anagrams, &numberOfWords](auto& word){
        std::string subject = createSubject(word); //skapa subject av word (alfabetsordna bokstäver)

		anagrams[subject].insert(word);

        
        /*auto it = anagrams.find(subject); //pekar på subject alt. efter anagrams
        
         //kolla om subject finns i anagrams
        if(it != anagrams.end()) {
            //om ja: lägg till i vektor för dess subject
            auto it2 = std::find(anagrams[subject].begin(), anagrams[subject].end(), word);
            
            //Lägg endast till ord om de inte redan finns i listan
            //Dvs lägger ej till dubbletter
            if(it2 == anagrams[subject].end()) {
                std::back_inserter(anagrams[subject]) = word;
            }
        }
        else{
            //om nej: lägg till nytt subject i anagram
            std::vector<std::string> wordVec(1,word); //skapar vektor med 1 slot och värdet word
            anagrams.insert({subject, wordVec}); //lägger till subject och anagram till vår map
        }*/
        numberOfWords++;
    });
    
    std::cout << "Number of words: " << numberOfWords << std::endl << std::endl;
    
    //Skriv ut subject och anagram
    displayAnagrams(anagrams);
    
    return 0;
}
