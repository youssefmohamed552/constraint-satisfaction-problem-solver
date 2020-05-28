#include <iostream>
#include "domain.hpp"



void
Domain::
add_value(Value* value){
  m_values.push_back(value);
}

void
Domain::
display(){
  std::cout << "displaying domain \n";
  for(auto v : m_values){
    v->display();
  }
}

