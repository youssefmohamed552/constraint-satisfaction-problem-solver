#pragma once 

#include <vector>

enum NonoGramToken{
  BLACK,
  WHITE
};

class NonoGram{
  private:
    int m_length, m_width;
    std::vector<NonoGramToken> m_tokens;
    std::vector<std::vector<int>> m_horizontal_constraints;
    std::vector<std::vector<int>> m_vertical_constraints;
  public:
    NonoGram();
    NonoGram(const std::vector<std::vector<NonoGramToken>>& v);
    ~NonoGram();
    void set_horizontal_constraint(std::vector<std::vector<int>> constraints);
    void set_vertical_constraint(std::vector<std::vector<int>> constraints);
    std::vector<std::vector<int>>& horizontal_constraints() { return m_horizontal_constraints; }
    std::vector<std::vector<int>>& vertical_constraints() { return m_vertical_constraints; }
    void display();
    int length() const {return m_length;}
    int width() const {return m_width;}
    std::vector<NonoGramToken>& tokens() { return m_tokens; }
};
