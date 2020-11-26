/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Computabilidad y Algoritmia
 * 2º de Carrera
 * Práctica 8. NFA
 * @author Antonella Sofía García Álvarez
 * Contact: alu0101227610@ull.edu.es */

#ifndef __state__
#define __state__
#include <vector>
#include <iostream>
#include <queue>
#include "transition.h"

class Transition;
class State {
  private:
    ///Attributes
    std::vector<Transition> transitions_;
    int statelabel_;
    bool finalstate_;
    bool initialstate_;

  public:
    ///Constructor
    State();
    /**
    * \brief states contructor
    * \param statelabel
    * \param finalstate
    * \param initialstate
    */
    State(int statelabel, bool finalstate, bool initialstate);
    /**
    * \brief gets the label
    */
    int getLabel() const;
      /**
    * \brief Gets the final position
    */
    bool getFinal() const;
      /**
    * \brief Gets the initial position
    */
    bool getStart() const;
    /**
    * \brief Sets the label
    * \param label
    */
    void setLabel(int label);
    /**
    * \brief Sets the final position
    * \param final
    */
    void setFinal(bool final);
    /**
    * \brief Sets the starting position
    * \param start
    */
    void setStart(bool start);
    /**
    * \brief Processes the input and uses the queue
    * \param input
    * \param inputqueue
    */
    void ProcessInput(char input, std::queue<int>& inputqueue);
    /**
    * \brief Adds a transition
    * \param state
    * \param symbol
    */
    void AddTransition(State* state, char symbol);
    /**
    * \brief adds the epsilon transitions to the queue
    * \param nfafilename
    */
    void epsilon(std::queue<int>& currentqueue);
};

#endif