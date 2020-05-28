#pragma once

#include "value.hpp"
#include "domain.hpp"

class Variable{
  protected:
    Value* m_value;
    Domain* m_domain;
  public:
    void set_value(Value* value){ m_value = value; }
    void set_domain(Domain* domain){ m_domain = domain; }
    Value* value() const { return m_value; }
    Domain* domain() const { return m_domain; }
    virtual void display() = 0;
};
