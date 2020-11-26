/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Computabilidad y Algoritmia
 * 2º de Carrera
 * Práctica 8. NFA
 * @author Antonella Sofía García Álvarez
 * Contact: alu0101227610@ull.edu.es */

#ifndef __nfa__
#define __nfa__
#include <vector>
#include <string>
#include <iostream>
#include <queue>
#include <fstream>
#include "set.h"
#include "state.h"

class NFA {
  private:
    ///Attributes
    Set alphabet_;
    Set acceptablestates_;
    std::vector<State> states_;

  public:
    ///Constructors
    NFA();
    /**
    * \brief Tells is the name of the file
    * \param nfafilename
    */
    NFA(const std::string& nfafilename);
    ///Methods
    /**
    * \brief Tells us if the input is valid
    * \param inputs
    */
    bool isInputValid(const std::string& inputs);
    /**
    * \brief Tells us if the file is valid
    * \param nfafile
    */
    bool isFileValid(const std::string& nfafile) const;
    /**
    * \brief Process the input
    * \param input
    */
    int Process(const std::string& input);

  private:
    /**
    * \brief Parses the line and returns the first element
    * \param line
    */
    std::string next(std::string& line) const;
};

#endif