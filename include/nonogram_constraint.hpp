#pragma once

#include <vector>

#include "nonogram.hpp"
#include "constraint.hpp"
#include "variable.hpp"

class NonoGramConstraint: public Constraint{
  protected:
    std::vector<Variable*> m_variables;
    std::vector<int> m_constraint;

  public:
    void set_variables(const std::vector<Variable*>& variables);
    void add_variable(Variable* variable);
    virtual void display();
    virtual bool apply();
    virtual bool is_valid();
    virtual bool update_domain();
};

class NonoGramColumnConstraint: public NonoGramConstraint{
  public:
    NonoGramColumnConstraint(const std::vector<int>& constriant);
    virtual ~NonoGramColumnConstraint();
    bool apply();
    void display();
};


class NonoGramRowConstraint: public NonoGramConstraint{
  public:
    NonoGramRowConstraint(const std::vector<int>& constraint);
    virtual ~NonoGramRowConstraint();
    bool apply();
    void display();
};
