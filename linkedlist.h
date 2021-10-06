#ifndef __LINKEDLIST_H__  
#define __LINKEDLIST_H__ 
#include <cassert>

using namespace std;


template <typename T>
class LinkedList
{
  class Node
  {
    private:
      T      m_data;
      Node  *m_pNext;
    public:
      Node(T data, Node *pNext = nullptr): m_data(data), m_pNext(pNext)
      {};
   
      T           getData()                 {return m_data;    }
      T          &getDataRef()              {   return m_data; }
      void        setpNext(Node *pNext)     { m_pNext = pNext; }
      Node       *getPNext()                {return m_pNext;   }
      Node       *&getPNextRef()            { return m_pNext;  }
 
  };
    private:
    Node *m_pHead = nullptr,
    *m_pTail = nullptr;
    size_t   m_size = 0;


  void internal_insert(Node *&rpPrev, T &temp);
  public:
  void insert_at_head(T elem);
  void insert_at_tail(T elem);
  void insert_2(T elem);

  ostream & print(ostream &os);
  T &operator[](size_t pos); 

  class iterator 
    {private:
        LinkedList<T> *m_pList;
        LinkedList<T>::Node *m_pNode;
    public:
        iterator(LinkedList<T> *pList, LinkedList<T>::Node *pNode)
              : m_pList(pList), m_pNode(pNode) {}
        iterator(iterator &other) 
              : m_pList(other.m_pList), m_pNode(other.m_pNode){}
        iterator(iterator &&other) 
              { 
                m_pList = std::move(other.m_pList); 
                m_pNode = std::move(other.m_pNode); 
              }
        iterator operator=(iterator &iter);
        bool operator==(iterator iter)   { return m_pNode == iter.m_pNode; }
        bool operator!=(iterator iter)   { return m_pNode != iter.m_pNode; }
        T &operator*()                   { return m_pNode->getDataRef();   }
        iterator operator++();
        iterator operator++(int);
    };
    iterator begin() { iterator iter(this, m_pHead);
                      return iter;
                     }
    iterator end()   { iterator iter(this, nullptr);
                        return iter;
                      }

};

template <typename T> 
void LinkedList<T>::insert_at_tail(T elem) 
{
  
  Node *pNew = new Node(elem);
  if(m_pTail)
  {m_pTail->setpNext(pNew); 
  }
  m_pTail = pNew;

  if (!m_pHead)
  {m_pHead = pNew;  } 
  m_size++;
  
}

template <typename T>
void LinkedList<T>::insert_2(T elem)
{
  if(!m_pHead || elem < m_pHead->getData())
  {
    Node *pNew = new Node(elem, m_pHead);
    m_pHead = pNew;
  }
  else{
    Node **pTmp = &m_pHead;
    while(*pTmp && (*pTmp)->getData() < elem)
    {
      pTmp = &(*pTmp)->getPNextRef();
    }
    Node *pNew = new Node(elem, *pTmp);
    *pTmp = pNew;
  }
}

template <typename T>
ostream &LinkedList<T>::print(ostream &os)
{
  Node *pNode = m_pHead;
  while(pNode)
  {
    os << pNode->getData() << ", ";
    pNode = pNode->getPNext();
  }
  return os;
}

template <typename T>
typename LinkedList<T>::iterator LinkedList<T>::iterator::operator++()
{
    m_pNode = m_pNode->getPNext();
    return *this; 
}

#endif
