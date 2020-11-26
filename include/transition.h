/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Computabilidad y Algoritmia
 * 2º de Carrera
 * Práctica 8. NFA
 * @author Antonella Sofía García Álvarez
 * Contact: alu0101227610@ull.edu.es */

#ifndef __transition__
#define __transition__
#include <vector>
#include <iostream>
#include "state.h"

class State;
class Transition {
  private:
    ///Atributtes
    State* origin_;
    State* end_;
    char symbol_;

  public:
    ///Constructor
    Transition();
    /**
    * \brief Transition constructor
    * \param origin
    * \param end
    * \param symbol
    */
    Transition(State* origin, State* end, char symbol);
    /**
    * \brief a state pointer who gets the ending position
    */
    State* getEnd();
    /**
    * \brief gets the symbol
    */
    char getSymbol();
    /**
    * \brief gets the label from the final position
    * \param symbol
    */
    int destiny(char symbol);
};
#endif