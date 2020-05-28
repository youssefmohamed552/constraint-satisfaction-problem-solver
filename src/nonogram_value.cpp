#include <iostream>

#include "nonogram_value.hpp"


NonoGramValue::
NonoGramValue(NonoGramToken token)
  : m_token(token)
{
}

NonoGramValue::
~NonoGramValue(){
}

void
NonoGramValue::
display(){
  std::cout << "value : \n";
  switch(m_token){
    case BLACK:
      std::cout << "BLACK\n";
      break;
    case WHITE:
      std::cout << "WHITE\n";
  }
}
