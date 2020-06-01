#include <iostream>

#include "nonogram_variable.hpp"


NonoGramVariable::
NonoGramVariable(int x, int y)
  : m_x(x), m_y(y)
{
  m_value = nullptr;
  m_domain = nullptr;
}

NonoGramVariable::
NonoGramVariable(const NonoGramVariable& other){
  m_value = other.value();
  *m_domain = *other.domain();
  m_x = other.x();
  m_y = other.y();
}


void
NonoGramVariable::
display(){
  std::cout << "display variable (" << m_x << "," << m_y << ")\n";
  if(!m_value){
    std::cout << "Value : EMPTY\n";
  }else{
    m_value->display();
  }
  if(!m_domain){
    std::cout << "Domain : Empty\n";
  }else{
    m_domain->display();
  }
}
