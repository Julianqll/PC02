#ifndef __DOUBLELINKEDLIST_H__  
#define __DOUBLELINKEDLIST_H__ 
#include <cassert>
using namespace std;


template <typename T>
class DoubleLinkedList //Esta clase tiene un metodo
{
  class Node
  {
    private:
      T       m_data;//si esto fuera un auto no se puede hacer dentro de {}
      Node *m_pNext, *m_pPrev;
    public: //esta recibiendo 2 parametros
      Node(T data, Node *pNext = nullptr, Node *pPrev = nullptr): m_data(data), m_pNext(pNext),m_pPrev(pPrev)
      {};
      T             getData()                       {return m_data; }
      T        &getDataRef()             {   return m_data;    }
      void          setpNext(Node *pNext)      { m_pNext = pNext;  }
      Node       *getPNext()                   {return m_pNext;  }
      Node      *&getPNextRef()      { return m_pNext; }
      void          setpPrev(Node *pPrev)      { m_pPrev = pPrev;  }

      Node *getpPrev()      { return m_pPrev; }
      Node    *&getpPrevRef()   { return m_pPrev;   }
  };
    private:
    Node *m_pHead = nullptr,
          *m_pTail = nullptr;
  size_t   m_size = 0;//se coloca el size aqui tambien
  void internal_insert(Node *&rpPrev, T &elem);
  public:
  void            push_front(T elem);//push_front
  void            push_back(T elem);//push_back
  void             insert_2(T elem);
  void insert(T elem)
  { internal_insert(m_pHead, elem); }
  T               PopHead();
  size_t        size() const  {  return m_size; }    
  bool empty()  const   {return size() == 0; }
  
  ostream & print(ostream &os);
  T &operator[](size_t pos); 

  class iterator 
    {private:
        // using Node = typename LinkedList<T>::Node;
        DoubleLinkedList<T> *m_pList;
        DoubleLinkedList<T>::Node *m_pNode;//llamamos al nodo de la clase list
    public:
        iterator(DoubleLinkedList<T> *pList, DoubleLinkedList<T>::Node *pNode)
              : m_pList(pList), m_pNode(pNode) {}
        iterator(iterator &other) 
              : m_pList(other.m_pList), m_pNode(other.m_pNode){}
        iterator(iterator &&other) // Move constructor
              { m_pList = std::move(other.m_pList); //other.m_pList = nullptr; 
                m_pNode = std::move(other.m_pNode); //other.m_pNode = nullptr;
              }
        iterator operator=(iterator &iter);
        bool operator==(iterator iter)   { return m_pNode == iter.m_pNode; }
        bool operator!=(iterator iter)   { return m_pNode != iter.m_pNode; }
        T &operator*()                   { return m_pNode->getDataRef();   }//el * a la izquierda significa dame el contenido de ese puntero
        iterator operator++();//para que vaya recorriendo al siguiente y sobrecargando
        iterator operator++(int );
    };
    iterator begin() { iterator iter(this, m_pHead);
                      return iter;
                     }
    iterator end()   { iterator iter(this, nullptr);
                        return iter;
                      }
    class reverse_iterator
    {private:
        DoubleLinkedList<T> *m_pList;
        DoubleLinkedList<T>::Node *m_pNode;
    public:
        reverse_iterator(DoubleLinkedList<T> *pList, DoubleLinkedList<T>::Node *pNode)
              : m_pList(pList), m_pNode(pNode) {}
        reverse_iterator(reverse_iterator &other) 
              : m_pList(other.m_pList), m_pNode(other.m_pNode){}
        reverse_iterator(reverse_iterator &&other) 
              { m_pList = move(other.m_pList); ; 
                m_pNode = move(other.m_pNode); 
              }
        reverse_iterator operator=(reverse_iterator &iter);
        bool operator==(reverse_iterator iter)   { return m_pNode == iter.m_pNode; }
        bool operator!=(reverse_iterator iter)   { return m_pNode != iter.m_pNode; }
        T &operator*()                   { return m_pNode->getDataRef();   }
        reverse_iterator operator++();
    };
    reverse_iterator rbegin(){  reverse_iterator iter(this, m_pTail);
                                return iter;
                                }
    reverse_iterator rend()   { reverse_iterator iter(this, nullptr);
                              return iter;
                              }

};


template <typename T> //se puede implementar afuera como dentro
void DoubleLinkedList<T>::push_front(T elem) //el metodo
{
Node *pNew = new Node(elem, m_pHead);
if(m_pHead)
{
  m_pHead->setpPrev(pNew);
}
  m_pHead = pNew;
  m_size++;
}


template <typename T> 
void DoubleLinkedList<T>::push_back(T elem) 
{
  
  Node *pNew = new Node(elem, nullptr, m_pTail); 
  if(m_pTail)
  {m_pTail->setpNext(pNew); 
  }
  m_pTail = pNew;
    
  if (!m_pHead)
  {m_pHead = pNew;  } 
  m_size++; 
}

template <typename T>
void DoubleLinkedList<T>::insert_2(T elem)
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
void DoubleLinkedList<T>::internal_insert(Node *&rpPrev, T &elem)
{
  if(!rpPrev || rpPrev->getData() > elem)
  {
    Node *pNew =new Node(elem, rpPrev);
    if(rpPrev){
      pNew->setpPrev(rpPrev->getpPrev());
      rpPrev->setpPrev(pNew);
    }
    rpPrev = pNew;
    m_size++;
  }
  else
  internal_insert(rpPrev->getPNextRef(), elem);
}

template <typename T>
T DoubleLinkedList<T>::PopHead() 
{
  if(m_pHead)
  {
    Node *pNode = m_pHead;
    T data = pNode->getData();
    m_pHead = m_pHead->getPNext();
    m_pHead->setpPrev(nullptr);
    delete pNode;
    m_size--;//size aqui tambien para ver el pop
    return data;
  }
  throw "Hola excepción";//el throw es lanzado y se llama a otra función. es un return pero de multiples niveles
  //como podemos retornar el valor si es que la lista esta vacia (un catch)
}

template <typename T>
T &DoubleLinkedList<T>::operator[](size_t pos)
{
  assert(pos <= size());//assert es una biblioteca
  Node *pTmp = m_pHead;
  for(auto i= 0 ; i < pos ; i++)
    pTmp = pTmp->getPNext();
  return pTmp->getDataRef();
}


template <typename T>
ostream &DoubleLinkedList<T>::print(ostream &os) //& referencia significa no recibir una copia si no el mismo objeto
{
  Node *pNode = m_pHead;
  while(pNode)
  {
    os << pNode->getData() << ", "; //cout
    pNode = pNode->getPNext();//debemos separar los dos conceptos
  }
  return os;
}


template <typename T>
typename DoubleLinkedList<T>::iterator DoubleLinkedList<T>::iterator::operator++()
{
    m_pNode = m_pNode->getPNext();
    return *this; 
}

template <typename T>
typename DoubleLinkedList<T>::reverse_iterator DoubleLinkedList<T>::reverse_iterator::operator++()
{
    m_pNode = m_pNode->getpPrev();
    return *this; 
}
#endif
