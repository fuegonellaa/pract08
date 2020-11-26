/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Computabilidad y Algoritmia
 * 2º de Carrera
 * Práctica 8. NFA
 * @author Antonella Sofía García Álvarez
 * Contact: alu0101227610@ull.edu.es */


#include <vector>
#include <iostream>

class Set {
  private:
  std::vector<unsigned long> Set_;
  
  public:
  ///Default constructor
  Set();

  /**
    * \brief Constructor per size
    * \param size Values that can be stored as a minimum
  */
  Set(int);
  ~Set();

  /**
    * \brief Checks if the number is in the set
    * \param pos Value to check
  */
  bool isInSet(int);

  /**
    * \brief Adds a number to the set if possible
    * \param pos Value to add
  */
  void AddToSet(int);

  /**
    * \brief Erases a value from the set if possible
    * \param pos Value to erase
  */
  void RemoveFromSet(int);

  /**
    * \brief Clears the set
  */
  void ClearSet();

  /**
    * \brief  Checks if the set is empty
  */
  bool IsEmpty();

  private:
  bool BelongsToSet(int);

};