#pragma once 


#include "csp.hpp"
#include "nonogram.hpp"

class NonoGramCSP: public CSP{
  private:
    int m_width;
    int m_length;
  public:
    NonoGramCSP(NonoGram& nonogram);
    ~NonoGramCSP();
    void display();
    void display_values();
};
