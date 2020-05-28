#pragma once

class Constraint{
  public:
    virtual bool apply() = 0;
    virtual void display() = 0;
};
