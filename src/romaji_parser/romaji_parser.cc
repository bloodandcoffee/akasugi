#include <string>

#include "romaji_parser.h"
using namespace std;

RomajiParser::State RomajiParser::startState;
RomajiParser::State* RomajiParser::currentState;

RomajiParser::State::~State() {

    for(map<char, State*>::iterator it = children.begin(); it != children.end(); it++) {
        delete &it;
    }

}

RomajiParser::State* RomajiParser::addStates(State* state, string transitions, const Kana* value) {

    // Return if transitions string is empty
    if(transitions.length() == 0) return nullptr;

    // Create new state if transition state does not exist
    if(!state->children.contains(transitions[0])) {
        state->children[transitions[0]] = new State();
    }

    // Recurse and set value if appropriate
    if(addStates(state->children[transitions[0]], transitions.substr(1), value) == nullptr) {
        state->children[transitions[0]]->value = value;
    }

    return state->children[transitions[0]];

}

void RomajiParser::init() {

    currentState = &startState;

    // Create all normal kana
    for(int i = 0; i < (sizeof(kana) / sizeof(Mapping)); i++) {
        addStates(&startState, kana[i].romaji, kana[i].kana);
    }

    // Create x/l transitions
    State* x = addStates(&startState, "x", nullptr);
    State* l = addStates(&startState, "l", nullptr);

    // Create chiisai kana
    for(int i = 0; i < (sizeof(chiisaiKana) / sizeof(Mapping)); i++) {
        addStates(x, chiisaiKana[i].romaji, chiisaiKana[i].kana);
    }

    // Allow for l-prefixed chiisai kana
    l->children = x->children;

    return;

}

bool RomajiParser::consumeChar(char c) {

    if(!currentState->children.contains(c)) return false;
    else currentState = currentState->children[c];
    return true;

}

bool RomajiParser::isLeaf() {

    return RomajiParser::currentState->value != nullptr;

}

const Kana* RomajiParser::getValue() {

    return RomajiParser::currentState->value;

}

void RomajiParser::reset() {

    RomajiParser::currentState = &RomajiParser::startState;

}