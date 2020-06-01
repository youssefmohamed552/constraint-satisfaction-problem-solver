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
    // static_cast<NonoGramCSP*>(m_csp)->display_values();
    // char ch;
    // std::cin >> ch;
    if(!is_valid_for_search()) {
      // std::cout << "have to leave\n";
      v->set_value(nullptr);

      continue;
    }
    // std::cout << "keep going\n";
    
    // static_cast<NonoGramCSP*>(m_csp)->display_values();
    valid_solution = solve_helper(next_it);
    // std::cout << "here\n";
    if(valid_solution) return true;
  }
  v->set_value(nullptr);

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



bool
BackTrackingCSPSolver::
is_valid_for_search(){
  // static_cast<NonoGramCSP*>(m_csp)->display_values();
  // char c;
  // std::cin >> c;
  for(auto c: m_csp->constraints()){
    if(!c->is_valid()) return false;
  }
  // std::cout << "valid for search\n";
  return true;
}

AC1CSPSolver::
AC1CSPSolver(CSP* csp)
  : BackTrackingCSPSolver(csp)
{
}

AC1CSPSolver::
~AC1CSPSolver(){
}


bool
AC1CSPSolver::
solve(){
  if(!update_domain()) return false;
  return BackTrackingCSPSolver::solve(); 
}


bool
AC1CSPSolver::
update_domain(){
  std::cout << "updating domin\n";
  for(auto it_c = m_csp->constraints().begin(); it_c != m_csp->constraints().end(); ++it_c){
    if(!(*it_c)->update_domain()) return false;
  }
  return true;
}
