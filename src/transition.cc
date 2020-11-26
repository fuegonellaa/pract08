/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Computabilidad y Algoritmia
 * 2º de Carrera
 * Práctica 8. NFA
 * @author Antonella Sofía García Álvarez
 * Contact: alu0101227610@ull.edu.es */

#include "../include/transition.h"

///Constructor by default
Transition::Transition() { }

///Transition constructor
Transition::Transition(State* origin, State* end, char symbol) {
 origin_ = origin;
 end_ = end;
 symbol_ = symbol;
}

///gets the end of the transition
State* Transition::getEnd() {
  return end_;
}

///gets the label from the final position
int Transition::destiny(char symbol) {
  if (symbol == symbol_) {
    return end_->getLabel();
  }
  return -1;
}

///Gets the symbol
char Transition::getSymbol() {
  return symbol_;
}