#pragma once


#include <vector>

#include "variable.hpp"
#include "constraint.hpp"


class CSP{
  protected:
    std::vector<Variable*> m_variables;
    std::vector<Constraint*> m_constraints;
  public:
    std::vector<Variable*>& variables() { return m_variables; }
    std::vector<Constraint*>& constraints() { return m_constraints; }
};
