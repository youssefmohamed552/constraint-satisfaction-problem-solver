#pragma once


#include <vector>
#include "value.hpp"

class Domain{
  protected:
    std::vector<Value*> m_values;

  public:
    void add_value(Value* value);
    std::vector<Value*>& values() { return m_values; }
    void display();
};
