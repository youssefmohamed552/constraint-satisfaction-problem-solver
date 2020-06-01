#pragma once


#include <vector>
#include "value.hpp"

class Domain{
  protected:
    std::vector<Value*> m_values;

  public:
    void add_value(Value* value);
    void set_values(const std::vector<Value*>& values);
    void remove_value(const Value* value);
    std::vector<Value*>& values() { return m_values; }
    void display();

};
