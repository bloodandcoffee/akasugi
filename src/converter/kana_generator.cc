#include <string>
#include "kana.h"
#include "kana_generator.h"
using namespace std;

RomajiParser::State::~State() {
    for(map<char, State&>::iterator it = children.begin(); it != children.end(); it++) {
        delete &it;
    }
}

RomajiParser::State& RomajiParser::addStates(State& state, string transitions, const Kana* value) {
    // Return if transitions string is empty
    if(transitions.length() == 0) return state;
    // Create new state if transition state does not exist
    if(!state.children.contains(transitions[0])) {
        state.children[transitions[0]] = *new State(transitions.length() == 1 ? value : nullptr);
    }

    addStates(state.children[transitions[0]], transitions.substr(1), value);
    return state.children[transitions[0]];
}

void RomajiParser::init() {
    currentState = startState;

    // Create all normal kana
    for(int i = 0; i < (sizeof(kana) / sizeof(Mapping)); i++) {
        addStates(startState, kana[i].romaji, kana[i].kana);
    }

    // Create x/l transitions
    State& x = addStates(startState, "x", nullptr);
    State& l = addStates(startState, "l", nullptr);
    // Create chiisai kana
    for(int i = 0; i < (sizeof(chiisaiKana) / sizeof(Mapping)); i++) {
        addStates(x, chiisaiKana[i].romaji, chiisaiKana[i].kana);
    }
    l.children = x.children;

    return;
}

bool RomajiParser::consumeChar(char c) {
    if(!currentState.children.contains(c)) return false;
    else currentState = currentState.children[c];
    return true;
}

bool RomajiParser::isLeaf() {
    return currentState.value == nullptr ? true : false;
}

const Kana* RomajiParser::getValue() {
    return currentState.value;
}