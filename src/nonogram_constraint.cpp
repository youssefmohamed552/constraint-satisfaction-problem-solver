#include <iostream>

#include "nonogram_constraint.hpp"


void
pause(){
  char c;
  std::cin >> c;
}

void
NonoGramConstraint::
set_variables(const std::vector<Variable*>& variables){
  m_variables = variables;
}


void
NonoGramConstraint::
add_variable(Variable* variable){
  m_variables.push_back(variable);
}

void 
NonoGramConstraint::
display(){
  for(auto c: m_constraint){
    std::cout << c << " ";
  }
  std::cout << "\n";
}



// bool
// NonoGramConstraint::
// apply(){
  // int count = 0;
  // int constraint_number = 0;
  // for(auto v : m_variables){
    // if(count > m_constraint[constraint_number]) return false;
    // // if(constraint_number >= m_constraint.size()) break;
    // Value* value = v->value();
    // if(!value || value->token() == WHITE){ // hasn't been occupied
      // if(count == 0) continue;
      // if(count > 0 && count < m_constraint[constraint_number]) return false;
      // count = 0;
      // constraint_number++;
    // }
    // if(value->token() == BLACK){
      // if(count >= m_constraint[constraint_number]) return false;
      // if(constraint_number >= m_constraint.size()) return false;
      // count++;
    // }
  // }
  // return true;
// }

bool
NonoGramConstraint::
apply(){
  auto constraint = m_constraint.begin();
  int count = 0;
  int i = 0;
  while(i < m_variables.size()){
    count = 0;
    // count white
    while(i < m_variables.size() &&  (m_variables[i]->value() == nullptr || m_variables[i]->value()->token() == WHITE)) { i++; }

    // count black
    while(i < m_variables.size() && m_variables[i]->value()->token() == BLACK){ count++; i++; }

    if(i >= m_variables.size()) break;
    if(count != *constraint) return false;
    constraint++;
    if(constraint == m_constraint.end()) break;
  }
  // ran out of constraints
  if(constraint == m_constraint.end()){
    // find a black spot after 
    while(i < m_variables.size()){
      // if there is black then return false
      if(m_variables[i]->value()->token() == BLACK) return false; 
      i++; 
    }
    return true;
  }
  int c = *constraint;
  constraint++;
  if(constraint == m_constraint.end() && c == count) return true;
  return false;
}


NonoGramColumnConstraint::
NonoGramColumnConstraint(const std::vector<int>& constraint){
  m_constraint = constraint;
  std::reverse(m_constraint.begin(), m_constraint.end());
}

NonoGramColumnConstraint::
~NonoGramColumnConstraint(){
}

bool
NonoGramColumnConstraint::
apply(){
  // std::cout << "appying column constraint\n";
  return NonoGramConstraint::apply();
}

void
NonoGramColumnConstraint::
display(){
  std::cout << "display column constraint\n";
  NonoGramConstraint::display();
}



NonoGramRowConstraint::
NonoGramRowConstraint(const std::vector<int>& constraint){
  m_constraint = constraint;
  std::reverse(m_constraint.begin(), m_constraint.end());
}


NonoGramRowConstraint::
~NonoGramRowConstraint(){
}

bool
NonoGramRowConstraint::
apply(){
  // std::cout << "appying row constraint\n";
  return NonoGramConstraint::apply();
}



void
NonoGramRowConstraint::
display(){
  std::cout << "display row constraint\n";
  NonoGramConstraint::display();
}

