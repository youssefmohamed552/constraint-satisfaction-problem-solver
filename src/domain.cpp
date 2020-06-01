#include <iostream>
#include "domain.hpp"



void
Domain::
add_value(Value* value){
  m_values.push_back(value);
}

void
Domain::
set_values(const std::vector<Value*>& values){
  if(m_values.size() == 0){
    m_values = values;
    return;
  }
  for(int i = 0; i < m_values.size(); i++){
    delete m_values[i];
  }
  m_values.clear();
  m_values = values;
}

void
Domain::
remove_value(const Value* value){
  if(!value) return;
  for(auto it = m_values.begin(); it != m_values.end(); it++){
    if((*it)->token() != value->token()) continue;
    delete (*it);
    m_values.erase(it);
    break;
  }
}


void
Domain::
display(){
  std::cout << "displaying domain \n";
  for(auto v : m_values){
    v->display();
  }
}

