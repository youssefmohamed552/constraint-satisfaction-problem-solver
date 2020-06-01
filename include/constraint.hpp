#pragma once

class Constraint{
  public:
    virtual bool apply() = 0;
    virtual bool is_valid() = 0;
    virtual void display() = 0;
    virtual bool update_domain() = 0;
};
