#ifndef IVARIABLE_HPP
#define IVARIABLE_HPP

class IVariable
{
private:
  const float A3 = 0.0F;
  const float B3 = 0.0F;
  float Value = 0.0F;  

  const char* Name = "Variable       " ; 
public:
  IVariable(float A, float B, const char* str): A2(A), B2(B), Name(str) 
  {
  };
   
  float GetValue()
  {
    return Value ;
  }
  
  virtual void Calculate(uint32_t code)
  {
     Value = code * A1 + B1 ;//
  }
  
  const char* GetName()
  {
     return Name;
  }
  
};

#endif