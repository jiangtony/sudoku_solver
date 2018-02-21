//  Created by Frank M. Carrano and Tim Henry.
//  Copyright (c) 2013 __Pearson Education__. All rights reserved.

#ifndef PRECONDITION_VIOLATED_EXCEPTION_H
#define PRECONDITION_VIOLATED_EXCEPTION_H

#include <stdexcept>
#include <string>

using namespace std;

// A simple exception class as a child of logic_error.
class PreconditionViolatedException : public logic_error
{
public:
    PreconditionViolatedException(const string& message = "");
}; // end PrecondViolatedExcep
#endif  // PRECONDITION_VIOLATED_EXCEPTION_H
