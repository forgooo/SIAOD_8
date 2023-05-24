#ifndef INC_8_FIRST_H
#define INC_8_FIRST_H
#include <vector>
#include <string>
#include <iostream>
#include <ctime>
#include <random>
#include <chrono>
using std::string, std::cout, std::vector;

vector<string> getWordsWithSubstring(string data, string substring){
    long long Cf = 0;
    vector<string> result;
    string word;
    int pos = 0;

    while ((pos = data.find(' ')) != string::npos) {
        Cf+=2;
        word = data.substr(0, pos);
        if (word.find(substring) != string::npos) {
            Cf++;
            result.push_back(word);
        }
        data.erase(0, pos + 1);
    }

    if (!data.empty() && data.find(substring) != string::npos) {
        Cf++;
        result.push_back(data);
    }
    if(!result.empty()) cout << Cf << "   ";
    return result;
}

string random_string( std::size_t length )
{
    static const std::string alphabet = "abcdefghijklmnopqrstuvwxyz" ;
    static std::default_random_engine rng( std::time(nullptr) ) ;
    static std::uniform_int_distribution<std::size_t> distribution( 0, alphabet.size() - 1 ) ;

    std::string str ;
    while( str.size() < length ) str += alphabet[ distribution(rng) ] ;
    return str ;
}

#endif //INC_8_FIRST_H