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

int main(int argc,char *argv[]) {
  if(argc == 2) {
    std::string help = "--help";
    std::string help2 = "-h";
    std::cout << "The right way of executing this code is ./nfa_simulation example.nfa input.txt output.txt" << std::endl;
    if (help.compare(argv[1]) == 0 || help2.compare(argv[1]) == 0) {
      std::cout << "Builds a NFA automaton using a .nfa file, read input strings from input.txt and output the results on output.txt" << std::endl;
      return 0;
    }
    return 1;
  } else if (argc != 4) {
    std::cout << "The right way of executing this code is ./nfa_simulation example.nfa input.txt output.txt" << std::endl;
    return 1;
  }

  std::string nfafile = argv[1];
  NFA NFAAuto(nfafile);

  std::ifstream inputfile;
  std::ofstream outputfile;

  inputfile.open(argv[2]);
  outputfile.open(argv[3]);

  std::string charstring;
  while (std::getline(inputfile,charstring)) {
    switch (NFAAuto.Process(charstring)) {
      case 0:
        outputfile << "No\n";
        break;
      case 1:
        outputfile << "Sí\n";
        break;
      default:
        outputfile << "No (Error)\n";
        break;
    }
  }

  inputfile.close();
  outputfile.close();

}