#ifndef __OPERACION_H__  
#define __OPERACION_H__ 

template <typename T>
class OperacionEspecial
{
  public:
      void operator()(T &n)
      {
        n *= n;
      }
};

#endif