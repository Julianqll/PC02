#ifndef __LINKEDLIST_H__  // # es una DIRECTIVAs al PreCOMPILADOR
#define __LINKEDLIST_H__ 
#include <cassert>//Leonardo
using namespace std;

template <typename T>
class LinkedList
{
  class Node
  { private:
      T       m_data;
      Node   *m_pNext;
    public:
      Node(T data, Node *pNext = nullptr) : m_data(data), m_pNext(pNext)
      {};
      T         getData()                {   return m_data;    }
      T        &getDataRef()             {   return m_data;    }
      void      setpNext(Node *pNext)    {   m_pNext = pNext;  }
      Node     *getpNext()               {   return m_pNext;   }
  };
  private:
    Node    *m_pHead = nullptr, 
            *m_pTail = nullptr;
    size_t   m_size  = 0;
  public:
    // LinkedList() {}
    void    insert_at_head(T elem);
    void    insert_at_tail(T elem);
    void    Intercambio1(T n, T m);
    T       PopHead();
    size_t  size()  const       { return m_size;       }
    bool    empty() const       { return size() == 0;  }

    ostream & print(ostream &os);
    T &operator[](size_t pos); 
    
    //agregar class iterator dentro de linkedlist by jose terrones
    class iterator 
    {private:
        // using Node = typename LinkedList<T>::Node;
        LinkedList<T> *m_pList;
        LinkedList<T>::Node *m_pNode;
    public:
        iterator(LinkedList<T> *pList, LinkedList<T>::Node *pNode)
              : m_pList(pList), m_pNode(pNode) {}
        iterator(iterator &other) 
              : m_pList(other.m_pList), m_pNode(other.m_pNode){}
        iterator(iterator &&other) // Move constructor
              : m_pList(other.m_pList), m_pNode(other.m_pNode)
              { other.m_pList = nullptr; other.m_pNode = nullptr;   }
        iterator operator=(iterator &iter);
        bool operator==(iterator iter)   { return m_pNode == iter.m_pNode; }
        bool operator!=(iterator iter)   { return m_pNode != iter.m_pNode; }
        T &operator*()                   { return m_pNode->getDataRef();   }
        iterator operator++();
        iterator operator++(int );
    };
    iterator begin() { iterator iter(this, m_pHead);
                      return iter;
                     }
    iterator end()   { iterator iter(this, nullptr);
                        return iter;
                      }
};
template <typename T>
void LinkedList<T>::Intercambio1(T n, T m){
  const int nElem = 6;
 TX vect[nElem] = {1,2,3,4,5,6};
 auto a=vect[n-1];
      vect[n-1]=vect[m-1];
      vect[m-1]=a;
 for(auto i=0;i<nElem;i++ ){  
  cout<< vect[i]<<" ";
  
  }cout<<endl;

}

#endif