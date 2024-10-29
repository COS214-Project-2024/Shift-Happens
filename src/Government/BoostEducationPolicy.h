#ifndef BOOSTEDUCATIONPOLICY
#define BOOSTEDUCATIONPOLICY

#include "Policy.h"
// this policy will rearrange the budget given to the public services so that education will receive the most
// invoker is the government
// receiver is education

class BoostEducationPolicy : public Policy {
  private:

  public:
    void executePolicy();
};

#endif