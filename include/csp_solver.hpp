#pragma once


#include "nonogram_csp.hpp"
#include "csp.hpp"

class CSPSolver{
  protected:
    CSP* m_csp;
  protected:
    virtual bool solve() = 0;
};


class BackTrackingCSPSolver : public CSPSolver{
  private:
    bool solve_helper(std::vector<Variable*>::iterator v_it);
    bool check_consistency();
  public:
    BackTrackingCSPSolver(CSP* csp);
    ~BackTrackingCSPSolver();
    virtual bool solve();
};
