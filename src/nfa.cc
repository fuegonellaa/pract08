/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Computabilidad y Algoritmia
 * 2º de Carrera
 * Práctica 8. NFA
 * @author Antonella Sofía García Álvarez
 * Contact: alu0101227610@ull.edu.es */

#include "../include/nfa.h"

const int kCharacters = 256;
///Constructor por defecto
NFA::NFA() : alphabet_(kCharacters) { }

///Constructor que pide el nombre
NFA::NFA(const std::string& nfafilename) : NFA() {
  std::ifstream inputfile;
  inputfile.open(nfafilename);
  std::string line;
  if(!isFileValid(nfafilename)) {
    exit(1);
  }
  std::getline(inputfile,line);                          ///first line
  int states = std::stoi(line);
  for (int i = 0; i < states; i++) {
    State newstate(i,false,false);
    states_.push_back(newstate);
  }
  std::getline(inputfile,line);                         ///second line
  int startingstate = std::stoi(line);
  while (std::getline(inputfile,line)) {                ///third line and further
    int currentstate = std::stoi(next(line));
    bool final = std::stoi(next(line));
    bool initial = (currentstate == startingstate);
    states_[currentstate].setFinal(final); 
    states_[currentstate].setStart(initial);
    int ntransition = std::stoi(next(line));
    for (int i = 0; i < ntransition; i++) {
      std::string symbol = next(line);
      alphabet_.AddToSet((int)symbol[0]);
      int transitionstate = std::stoi(next(line));
      states_[currentstate].AddTransition(&states_[transitionstate],symbol[0]);
    }
  }
  inputfile.close();
}

///it processes an input, returns different values depending of it's acceptance
int NFA::Process(const std::string& input) {
  if(!isInputValid(input)) {
    return -1; 
  }
  std::queue<int> currentqueue;
  std::queue<int> nextqueue;
  for (int i = 0; i < states_.size(); i++) {
    if (states_[i].getStart()) {
      currentqueue.push(i);
      break;
    }
  }
  states_[currentqueue.front()].epsilon(currentqueue);
  for (int i = 0; i < input.length(); i++) {
    while (!currentqueue.empty()) {
      states_[currentqueue.front()].ProcessInput(input[i], nextqueue);
      currentqueue.pop();
    }
    while (!nextqueue.empty()) {
      currentqueue.push(nextqueue.front());
      states_[nextqueue.front()].epsilon(currentqueue);
      nextqueue.pop();
    }
  }
  while(!currentqueue.empty()) {
    if (states_[currentqueue.front()].getFinal()) {
      return 1;
    }
    currentqueue.pop();
  }
  return 0;
}

///Tells us if the input line is valid
bool NFA::isInputValid(const std::string& inputs) {
  for (int i = 0; i < inputs.length();i++) {
    if (alphabet_.isInSet((int)inputs[i])) {
      continue;
    } else {
      return false;
    }
  }
  return true;
}

///Tells us if the file is valid
bool NFA::isFileValid(const std::string& nfafile) const {
  std::ifstream filetotest;
  filetotest.open(nfafile);
  bool accept = true;
  if (nfafile.length() < 5) {
    std::cerr << "El fichero " << nfafile << " no cumple con el tamaño mínimo (5) ej: a.nfa" << std::endl;
    accept = false;
  } else if (!(nfafile.substr(nfafile.length() - 4) == ".nfa")) {
    std::cerr << "El fichero " << nfafile << " no es un fichero .nfa, por favor utilize un fichero .nfa" << std::endl;
    accept = false;
  } else if (filetotest.fail()) {
    std::cerr << "Hubo un error al abrir el fichero " << nfafile << std::endl;
    accept = false;
  }
  filetotest.close();
  return accept;
}

///Parses the line and returns the first element
std::string NFA::next(std::string& line) const {
  std::string fragment = line.substr(0,line.find_first_of(" "));
  line = line.substr(line.find_first_of(" ") + 1, std::string::npos);
  return fragment;
}