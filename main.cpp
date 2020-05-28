#include <iostream>


#include "nonogram.hpp"
#include "nonogram_csp.hpp"
#include "csp_solver.hpp"

NonoGram create_nonogram();


int
main(int argc, char** argv){
  NonoGram nonogram = create_nonogram();
  NonoGramCSP* csp = new NonoGramCSP(nonogram);
  // csp->display();
  BackTrackingCSPSolver solver(csp);
  if(solver.solve()){
    std::cout << "NonoGram Solved\n";
  }
  else{
    std::cout << "NonoGram Not Solved\n";
  }
  return EXIT_SUCCESS;
}


NonoGram
create_nonogram(){
  NonoGram nonogram;
  nonogram.set_horizontal_constraint({{1,1},{2,1},{1,1,1},{1,2},{1,1}});
  // nonogram.set_horizontal_constraint({{3},{2,2},{1,1},{2,2},{3}});
  nonogram.set_vertical_constraint({{5},{1},{1},{1},{5}});
  // nonogram.set_vertical_constraint({{3},{2,2},{1,1},{2,2},{3}});
  nonogram.display();
  return nonogram;
}

