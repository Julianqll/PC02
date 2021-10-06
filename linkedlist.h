#ifndef __LINKEDLIST_H__
#define __LINKEDLIST_H__
#include<cassert>

using namespace std;

template <typename R>
class LinkedList
{
  class Node
  { private:
      R       m_data;
      Node   *m_pNext;
      Node   *m_pAnt;
    public:
      Node(R data, Node *pNext = nullptr) : m_data(data), m_pNext(pNext)
      {};
      R         getData()                {   return m_data;    }
      R        &getDataRef()             {   return m_data;    }
      void      setpNext(Node *pNext)    {   m_pNext = pNext;  }
    //  void      setpAnt(Node  *pAnt)   {   m_pAnt=pAnt;      }
      Node     *getpNext()               {   return m_pNext;   }
  };
  private:
    Node    *m_pHead = nullptr, 
            *m_pTail = nullptr;
           /* *m_int1  = nullptr;
            *m_int2  = nullptr;*/
           
    size_t   m_size  = 0;
  public:
    void    Intercambio(R n);
    
    
  
};


template <typename R>
void LinkedList<R>::Intercambio(R n)
{
  const int cant=6;
  R vect[cant]={1,2,3,4,5,6};
  auto a =vect[n-1];
  auto b =vect[n+1];
  vect[n+1]= a;
  vect[n-1]= b;
  for(auto x=0;x<cant;x++){
 cout<<vect[x];
  }
}


#endif
