#pragma once


#include "variable.hpp"

class NonoGramVariable : public Variable{
  private:
    int m_x;
    int m_y;
  public:
    NonoGramVariable(int x, int y);
    ~NonoGramVariable();
    void display();
};
