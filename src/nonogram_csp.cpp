#include <iostream>

#include "nonogram_csp.hpp"
#include "nonogram_value.hpp"
#include "nonogram_variable.hpp"
#include "nonogram_constraint.hpp"
#include "nonogram_domain.hpp"





NonoGramCSP::
NonoGramCSP(NonoGram& nonogram){
  // std::cout << "NonoGram Created!!\n";
  int width = nonogram.width();
  int length = nonogram.length();
  m_length = length;
  m_width = width;
  m_variables = std::vector<Variable*>(width * length);
  std::vector<std::vector<Variable*>> columns(width, std::vector<Variable*>(length));
  std::vector<std::vector<Variable*>> rows(length, std::vector<Variable*>(width));
  for(int i = 0; i < length; i++){
    for(int j = 0; j < width; j++){
      NonoGramDomain* domain = new NonoGramDomain();
      for(int k = 0; k < nonogram.tokens().size();k++){
        domain->add_value(new NonoGramValue(nonogram.tokens()[k]));
      }
      domain->add_value(new NonoGramValue(WHITE));

      Variable* variable = new NonoGramVariable(j,i);
      variable->set_domain(domain);
      m_variables[(i * width) + j] = variable;
      columns[j][i] = variable;
      rows[i][j] = variable;
    }
  }
  for(int i = 0; i < nonogram.horizontal_constraints().size(); i++){
    NonoGramColumnConstraint* constraint = new NonoGramColumnConstraint(nonogram.horizontal_constraints()[i]);
    
    constraint->set_variables(columns[i]);
    m_constraints.push_back(constraint);
  }
  for(int i = 0; i < nonogram.vertical_constraints().size(); i++){
    NonoGramRowConstraint* constraint = new NonoGramRowConstraint(nonogram.vertical_constraints()[i]);
    constraint->set_variables(rows[i]);
    m_constraints.push_back(constraint);
  }
}


NonoGramCSP::
~NonoGramCSP(){
  // std::cout << "Nonoram Destroyed!!\n";
}


void
NonoGramCSP::
display(){
  std::cout << "displaying NonoGramCSP\n";
  for(auto v: m_variables){
    v->display();
  }
  for(auto c: m_constraints){
    c->display();
  }

}


void
NonoGramCSP::
display_values(){
  std::cout << "print the values\n";
  for(int i = 0; i < m_length;i++){
    for(int j = 0; j < m_width;j++){
      Value* v = m_variables[(i*m_width)+j]->value();
      if(v == nullptr){
        std::cout <<  "  ";
        continue;
      }
      NonoGramToken t = (NonoGramToken)v->token();
      switch(t){
        case BLACK:
          std::cout << "B ";
          break;
        case WHITE:
          std::cout << "- ";
          break;
      }
    }
    std::cout << "\n";
  }
}
