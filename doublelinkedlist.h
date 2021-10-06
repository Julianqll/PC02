#ifndef __DOUBLELINKEDLIST_H__  
#define __DOUBLELINKEDLIST_H__ 
//by jose terrones
using namespace std;

template <typename T>
class Node
{private:
  T         m_data;
  Node<T>   *m_pNext;
  Node<T>   *m_pPrev;
  public:
  Node(T data, Node<T> *pNext = nullptr, Node<T> *pPrev = nullptr) : m_data(data), m_pNext(pNext), m_pPrev(pPrev)
  {};
  T         getData()                 {   return m_data;  }
  void      setpNext(Node<T> *pNext)  {   m_pNext = pNext;  }
  Node      *getpNext()               {   return m_pNext;   }
  void      setpPrev(Node<T> *pPrev)  {   m_pPrev = pPrev;  }
  Node      *getpPrev()               {   return m_pPrev;   }
};

template <typename T>
class DoubleLinkedList
{
  private:
    Node<T> *m_pHead = nullptr, 
            *m_pTail = nullptr;
  public:
  void  insert_at_head (T elem);
  void  insert_at_tail(T elem);
  T     PopHead();
  void print(ostream &os);
};


template <typename T>
void DoubleLinkedList<T>::insert_at_head(T elem)
{
  Node<T> *pNew = new Node(elem); 
  if(m_pTail)
  { m_pTail->setpNext(pNew); }
    m_pTail = pNew;

  if (!m_pHead)
  {m_pHead = pNew;  }
}

template <typename T>
void DoubleLinkedList<T>::insert_at_tail(T elem)
{
    Node<T> *pNew = new Node(elem);
    if(m_pTail)
    {
      m_pTail->setpNext(pNew);
    }
    m_pTail = pNew;
    if(!m_pHead)
    {
      m_pHead = pNew;
    }
}


template <typename T>
T DoubleLinkedList<T>::PopHead()
{
  if(m_pHead)
  {
    Node<T> *pNode = m_pHead;
    T data = pNode->getData();
    m_pHead = m_pHead->getpNext();
    delete pNode;
    return data;
  }
  return 0;
}


template <typename T>
void DoubleLinkedList<T>::print(ostream &os)
{
  Node<T> *pNode = m_pHead;
  while(pNode)
  {
    os << pNode->getData() << ", ";
    pNode = pNode->getpNext();
  }
  os <<endl;
}

#endif 