#include <iostream>


#include "nonogram.hpp"
#include "nonogram_csp.hpp"
#include "csp_solver.hpp"

NonoGram create_nonogram();


int
main(int argc, char** argv){
  NonoGram nonogram = create_nonogram();
  NonoGramCSP csp(nonogram);
  // NonoGramCSP ncsp = csp;
  AC1CSPSolver solver(&csp);
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
  nonogram.set_horizontal_constraint({{4},{7},{8},{9},{10},{1,10},{2,10},{15},{2,10},{1,10},{10},{9},{8},{7},{4}});
  // nonogram.set_horizontal_constraint({{3},{2,2},{1,1},{2,2},{3}});
  // nonogram.set_horizontal_constraint({{1,2},{4},{1,1},{4},{2,1}});
  nonogram.set_vertical_constraint({{1},{3},{5},{7},{9},{11},{13},{13},{15},{15},{15},{6,1,6},{4,1,4},{3},{5}});
  // nonogram.set_vertical_constraint({{3},{2,2},{1,1},{2,2},{3}});
  // nonogram.set_vertical_constraint({{2,1},{4},{1,1},{4},{1,2}});
  nonogram.display();
  return nonogram;
}

