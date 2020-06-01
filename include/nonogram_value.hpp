#pragma once

#include "nonogram.hpp"
#include "value.hpp"

class NonoGramValue: public Value{
  private: 
    NonoGramToken m_token;
  public:
    NonoGramValue(NonoGramToken token);
    virtual ~NonoGramValue();
    int token() const { return m_token; }
    void display();
};
