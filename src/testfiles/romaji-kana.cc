// g++ -std=c++20 romaji-kana.cc converter/kana-generator.cc -o romaji-kana.out
#include <iostream>
#include <sstream>
#include <string>
#include "converter/kana_generator.h"
using namespace std;

int main() {

    string input;
    RomajiParser::init();

    getline(cin, input);

    for(int i = 0; i < input.length(); i++) {
        bool isl = RomajiParser::isLeaf();
        const Kana* uwu = RomajiParser::getValue();

        cout << "Char consumed: " << input[i] << "; Status: " << (RomajiParser::consumeChar(input[i]) ? "Valid;" : "Invalid;") << endl;
        cout << (isl ? "Is Leaf" : "Not Leaf") << endl;
        cout << (uwu == nullptr ? "nullptr" : uwu->hiragana) << endl;

        if(isl) RomajiParser::reset();
    }

    return 0;
}