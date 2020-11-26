/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Computabilidad y Algoritmia
 * 2º de Carrera
 * Práctica 8. NFA
 * @author Antonella Sofía García Álvarez
 * Contact: alu0101227610@ull.edu.es */

#include "../include/set.h"

///Default constructor
Set::Set() {
  Set_.resize(1, 0);
}

///Constructor per size
Set::Set(int size) {
  int sizeneeded = (size / sizeof(Set_[0]));
  if (size % sizeof(Set_[0]) != 0) {
    sizeneeded++;
  }
  Set_.resize(sizeneeded, 0);
}

///Default destroyer
Set::~Set() { }

///Checks if the number is in the set
bool Set::isInSet(int pos) {
  if (BelongsToSet(pos)) {
    int vectorpos = (pos / sizeof(Set_[0]));
    int relativepos = (pos - (sizeof(Set_[0]) * vectorpos));
    return (Set_[vectorpos] & (1 << relativepos));
  } else {
    return false;
  }
}

///Adds a number to the set, if possible
void Set::AddToSet(int pos) {
  if (BelongsToSet(pos)) {
    int vectorpos = (pos / sizeof(Set_[0]));
    int relativepos = (pos - (sizeof(Set_[0]) * vectorpos));
    Set_[vectorpos] |= 1UL << relativepos;
  } else {
    std::cerr << "You can't add this element to the set. There's not enough space.";
  }
}

///Erases a number from the set, if possible
void Set::RemoveFromSet(int pos) {
  if (isInSet(pos)) {
    int vectorpos = (pos / sizeof(Set_[0]));
    int relativepos = (pos - (sizeof(Set_[0]) * vectorpos));
    Set_[vectorpos] &= ~(1UL << relativepos);
  } else {
    std::cerr << "You can't erase this element of the set, it doesn't belong to this set.";
  }
}

///Clears the set entirely
void Set::ClearSet() {
  for (int i = 0; i < Set_.size(); i++) {
    Set_[i] = 0;
  }
}

///Checks if the set is empty
bool Set::IsEmpty() {
  for (int i = 0; i < Set_.size(); i++) {
    if (Set_[i] != 0) {
      return false;
    }
  }
  return true;
}

///Checks if the number belongs to the set
bool Set::BelongsToSet(int number) {
  int maxsize = 8 * Set_.size() * sizeof(Set_[0]);
  if (number < maxsize) {
    return true;
  } else {
    return false;
  }
}