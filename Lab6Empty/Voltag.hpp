#include "IVariable.hpp"

class Voltage : public IVariable
{
public:
  Voltage(float A2, float B): IVariable(A, B, "Voltage") {} ;
};