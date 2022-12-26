#ifndef KANA_GENERATOR_H
#define KANA_GENERATOR_H
#include <vector>
#include <map>
#include "kana.h"

class RomajiParser {
    enum StateType {Start, Normal, Accepting};

    struct State {
        StateType type;
        const Kana* output;
        std::map<char, State&> transitions;

        State(StateType type, const Kana* output) : type{type}, output{output} {};
    };

    static std::vector<State> states;
    static void addPath(State&, std::string, const Kana*);

    public:
    static void init();
};

#endif