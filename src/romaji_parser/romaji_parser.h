#ifndef KANA_GENERATOR_H
#define KANA_GENERATOR_H
#include <vector>
#include <map>
#include "kana_mapping.h"

class RomajiParser {

    struct State {

        const Kana* value;
        std::map<char, State*> children;

        State() : value{nullptr} {};
        State(const Kana* value) : value{value} {};
        ~State();

    };

    static State startState;
    static State* currentState;
    static State* addStates(State* state, std::string transitions, const Kana* value);

    public:
    static void init();
    static bool consumeChar(char c);
    static bool isLeaf();
    static const Kana* getValue();
    static void reset();
    
};

#endif