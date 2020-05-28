#include <iomanip>
#include <iostream>
#include <algorithm>
#include "nonogram.hpp"


int
get_largest_vector_size(const std::vector<std::vector<int>>& v){
  size_t largest_vector = 0;
  for(int i = 0; i < v.size(); i++){
    largest_vector = std::max(largest_vector, v[i].size());
  }
  return largest_vector;
}


int 
largest_number(const std::vector<std::vector<int>>& v){
  int largest_num = INT_MIN;
  for(auto l : v){
    largest_num = std::max(largest_num, *std::max_element(l.begin(), l.end()));
  }
  return largest_num;
}

int
number_of_digits(int number){
  if(number == 0) return 1;
  int digit = 0;
  while(number){
    number /= 10;
    digit++;
  }
  return digit;
}



NonoGram::
NonoGram()
  : m_length(0), m_width(0), m_tokens({BLACK})
{
  // std::cout << "nonogram created !!\n";
}

NonoGram::
~NonoGram(){
  // std::cout << "nonogram destroyed !!\n";
}

void
NonoGram::
display(){
  int depth = get_largest_vector_size(m_horizontal_constraints);
  int shift = get_largest_vector_size(m_vertical_constraints);
  int max_num = std::max(largest_number(m_horizontal_constraints) , largest_number(m_vertical_constraints));
  int digit_count = number_of_digits(max_num);
  std::cout << std::setw(digit_count);
  // print the horizontal
  for(int i = 0; i < depth; i++){
    for(int j = 0; j < shift+(shift-1); j++){ 
      std::cout << " ";
    }
    std::cout << "|";
    for(int j = 0; j < m_horizontal_constraints.size(); j++){
      if(m_horizontal_constraints[j].size() > (depth-i-1)){
        std::cout << m_horizontal_constraints[j][depth-i-1] << "|";
      }
      else{
        std::cout << " " << "|";
      }
    }
    std::cout << "\n";
  }
  //print the vertical
  for(int i = 0; i < m_vertical_constraints.size(); i++){
    for(int j = 0; j < shift; j++){
      if(m_vertical_constraints[i].size() > (shift-j-1)){
        std::cout << m_vertical_constraints[i][shift-j-1] << "|";
      }
      else{
        std::cout << " " << "|";
      }
    }
    // print the values in the board
    std::cout << "\n";

  }
}




void
NonoGram::
set_horizontal_constraint(std::vector<std::vector<int>> constraints){
  m_horizontal_constraints = constraints; 
  m_width = constraints.size();
}
void
NonoGram::
set_vertical_constraint(std::vector<std::vector<int>> constraints){
  m_vertical_constraints = constraints;
  m_length = constraints.size();
}
