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
    bool is_valid_for_search();
  public:
    BackTrackingCSPSolver(CSP* csp);
    virtual ~BackTrackingCSPSolver();
    virtual bool solve();
};

class AC1CSPSolver : public BackTrackingCSPSolver{
  private:
    bool update_domain();
  public:
    AC1CSPSolver(CSP* csp);
    virtual ~AC1CSPSolver();
    virtual bool solve();
};
