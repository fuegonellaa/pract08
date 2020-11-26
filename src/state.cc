/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Computabilidad y Algoritmia
 * 2º de Carrera
 * Práctica 8. NFA
 * @author Antonella Sofía García Álvarez
 * Contact: alu0101227610@ull.edu.es */

#include "../include/state.h"

///Constructor by default
State::State() {
  initialstate_ = false;
  finalstate_ = false;
  statelabel_ = -1;
  transitions_.clear();
}

///State constructor
State::State(int statelabel, bool finalstate, bool initialstate) {
  initialstate_ = initialstate;
  statelabel_ = statelabel;
  finalstate_ = finalstate;
  transitions_.clear();
}

///Label getter
int State::getLabel() const {
  return statelabel_;
}

///Final position getter
bool State::getFinal() const {
  return finalstate_;
}

///Initial position getter
bool State::getStart() const {
  return initialstate_;
}

///Sets the label
void State::setLabel(int label) {
  statelabel_ = label;
}

///Sets the final position
void State::setFinal(bool final) {
  finalstate_ = final;
}

///Sets the initial position
void State::setStart(bool start) {
  initialstate_ = start;
}

///Processes an input
void State::ProcessInput(char input, std::queue<int>& inputqueue) {
  for (int i = 0; i < transitions_.size(); i++) {
    int expression = transitions_[i].destiny(input);
    switch (expression) {
    case -1:
      break;
    default:
      inputqueue.push(expression);
      break;
    }
  }
}

///Adds a transition
void State::AddTransition(State* state, char symbol) {
  Transition newtransition(this, state, symbol);
  transitions_.push_back(newtransition);
}

///adds the epsilon transitions to the queue
void State::epsilon(std::queue<int>& currentqueue) {
  for (int i = 0; i < transitions_.size(); i++) {
    if (transitions_[i].getSymbol() == '~') {
      currentqueue.push(transitions_[i].getEnd()->getLabel());
      transitions_[i].getEnd()->epsilon(currentqueue);
    }
  }
}
