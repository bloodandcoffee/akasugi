#include <string>
#include "kana.h"
#include "kana_generator.h"
using namespace std;

void RomajiParser::addPath(State& state, string str, const Kana* output) {
    // If str is empty, mark as accepting state and return
    if(str.length() == 0) { 
        state.type = Accepting;
        state.output = output;
        return;
    }

    // Checks if transition exists
    if(!state.transitions.contains(str[0])) {
        // Creates new state and adds transition if not
        states.push_back(State(Normal, (Kana*)nullptr));
        state.transitions[str[0]] = states.back();
    } else {
        addPath(state.transitions.at(str[0]), str.substr(1), output);
    }

    return;
}

void RomajiParser::init() {
    // Create start state
    states.push_back(State(Start, (Kana*)nullptr));

    // Add transition states for each kana
    for(int i = 0; i < KANA_COUNT; i++){
        addPath(states[0], kana[i].romaji, kana[i].kana);
    }

    return;
}