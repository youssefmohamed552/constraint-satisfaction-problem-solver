#pragma once

class Value{
  public:
    virtual ~Value(){}
    virtual void display() = 0;
    virtual int token() const = 0;
};
