#include <iostream>

#include "Cell.h"

// Constructor to initialize a Cell with a given value and modifiability status
Cell::Cell(int value, bool modifiable) : value{value}, modifiable{modifiable} {}

// Assignment operator to set a new value for the Cell
Cell &Cell::operator=(int new_val) {
    value = new_val;
    return *this;
}

// Equality comparison operator between two Cell objects
bool Cell::operator==(Cell &right) const {
    return this->value == right.value;
}

// Equality comparison operator between a Cell and an integer
bool Cell::operator==(int right) const {
    return this->value == right;
}

// Conversion operator to implicitly convert a Cell to an integer
Cell::operator int() const {
    return this->value;
}

// Conversion operator to implicitly convert a Cell to a boolean (modifiable status)
Cell::operator bool() const {
    return this->modifiable;
}

// Output stream operator to enable printing a Cell to the standard output
std::ostream &operator<<(std::ostream &out, Cell &item) {
    return out << item.toStr();
}

// Function to convert the Cell to a string representation
std::string Cell::toStr() const {
    return std::to_string(value) + (modifiable ? "+" : "-");
}

// Function to toggle the modifiability status of the Cell
void Cell::switchMod() {
    modifiable = !modifiable;
}

// Input stream operator to enable reading a Cell from the standard input
std::istream &operator>>(std::istream &in, Cell &item) {
    char state;
    in >> item.value >> state;
    item.modifiable = state == '+';
    return in;
}
