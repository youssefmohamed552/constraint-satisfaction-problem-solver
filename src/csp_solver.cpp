#include <iostream>
#include <exception>

#include "csp_solver.hpp"

/*void
pause(){
  char c;
  std::cin >> c;
}
*/

BackTrackingCSPSolver::
BackTrackingCSPSolver(CSP* csp){
  // std::cout << "backtraking is created!!\n";
  m_csp = csp;
}



BackTrackingCSPSolver::
~BackTrackingCSPSolver(){
  // std::cout << "backtracking is destroyed!!\n";
}

bool
BackTrackingCSPSolver::
solve(){
  std::cout << "Solving CSP using BackTracking\n";
  
  return solve_helper(m_csp->variables().begin());
}


bool
BackTrackingCSPSolver::
solve_helper(std::vector<Variable*>::iterator v_it){
  // std::cout << "solve_helper\n";
  // pause();
  if(v_it == m_csp->variables().end()) {
    // std::cout << "pause in the end\n";
    return check_consistency();
  }
  Variable* v = *(v_it);
  // try{
    // std::cout << "geting domain\n";
    // Domain* d = v->domain();
    // std::cout << "got domain\n";
// 
  // }catch(std::exception& e){
    // std::cerr << "error : " << e.what() << "\n";
  // }
  bool valid_solution;
  // std::cout << "check is fine\n";
  auto next_it = ++v_it;
  for(auto value : v->domain()->values()){
    // std::cout << "val\n";
    v->set_value(value);
    // v->display();
    valid_solution = solve_helper(next_it);
    // std::cout << "here\n";
    if(valid_solution) return true;
  }
  return false;
}


bool
BackTrackingCSPSolver::
check_consistency(){
  // std::cout << "check_consistency\n";
  // char x;
  // std::cin >> x;
  bool a_test_passed = false;
  for(auto c: m_csp->constraints()){
    if(!c->apply()) return false;
  }
  static_cast<NonoGramCSP*>(m_csp)->display_values();
  std::cout << "passed\n";
  return true;
}




