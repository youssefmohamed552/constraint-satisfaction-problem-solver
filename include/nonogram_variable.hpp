#pragma once


#include "variable.hpp"

class NonoGramVariable : public Variable{
  private:
    int m_x;
    int m_y;
  public:
    NonoGramVariable(int x, int y);
    NonoGramVariable(const NonoGramVariable& other);
    ~NonoGramVariable();
    int x() const { return m_x; };
    int y() const { return m_y; };
    void display();
};
