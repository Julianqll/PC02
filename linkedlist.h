#ifndef __LINKEDLIST_H__  
#define __LINKEDLIST_H__ 
#include <cassert>
using namespace std;


template <typename T>
class LinkedList //Esta clase tiene un metodo
{
  class Node
  {
    private:
      T       m_data;//si esto fuera un auto no se puede hacer dentro de {}
      Node *m_pNext;
    public: //esta recibiendo 2 parametros
      Node(T data, Node *pNext = nullptr): m_data(data), m_pNext(pNext)
      {};
      //creamos el setpNext
      T             getData()                       {return m_data; }
      T        &getDataRef()             {   return m_data;    }
      void          setpNext(Node *pNext)      { m_pNext = pNext;  }
      Node       *getPNext()                   {return m_pNext;  }
      Node      *&getPNextRef()      { return m_pNext; }

  //constructor
  //Este null lo agregamos porque al inicio no hay valores
  //inicializamos miembros la buena praxis es hacerlo arriba y no dentro de {}
  };
    private:
    Node *m_pHead = nullptr,*m_pTail = nullptr;
  size_t   m_size = 0;//se coloca el size aqui tambien
  void internal_insert(Node *&rpPrev, T &temp);
  public:
  void            insert_at_head(T elem);//el metodo
  void            insert_at_tail(T elem);//insertamos en la cabeza y cola
  void             insert_2(T elem);
  void            cambiarNodos(T elem);
  T               PopHead();
  size_t        size() const  {  return m_size; }    //para reemplazar el valor del vector y entre otros
  bool empty()  const   {return size() == 0; }//el const es para evitar cambios
  
  ostream & print(ostream &os);
  T &operator[](size_t pos); //agregamos el operator
  //Agregamos clase iterator

  class iterator 
    {private:
        // using Node = typename LinkedList<T>::Node;
        LinkedList<T> *m_pList;
        LinkedList<T>::Node *m_pNode;//llamamos al nodo de la clase list
    public:
        iterator(LinkedList<T> *pList, LinkedList<T>::Node *pNode)
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

};


template <typename T> //se puede implementar afuera como dentro
void LinkedList<T>::insert_at_head(T elem) //el metodo
{
Node *pNew = new Node(elem, m_pHead);
  m_pHead = pNew;
  m_size++;
}


template <typename T> //se puede implementar afuera como dentro
void LinkedList<T>::insert_at_tail(T elem) //el metodo
{
  //Creamos el nuevo Nodo y tiene que estar con su dato el cual es elem porque recibe la T del parametro
  Node *pNew = new Node(elem); //el * es un objeto dinamico
  if(m_pTail)
  {m_pTail->setpNext(pNew); //Cuando tenemos un objeto utilizamos ., si utilizamos -> es para un puntero
  }
  m_pTail = pNew;
    
  if (!m_pHead)
  {m_pHead = pNew;  } //si es que esta vacia se 
  m_size++; //size aqui tambien
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
T LinkedList<T>::PopHead()
{
  if(m_pHead)
  {
    Node *pNode = m_pHead;
    T data = pNode->getData();
    m_pHead = m_pHead->getPNext();
    delete pNode;
    m_size--;//size aqui tambien para ver el pop
    return data;
  }
  throw "Hola excepción";//el throw es lanzado y se llama a otra función. es un return pero de multiples niveles
  //como podemos retornar el valor si es que la lista esta vacia (un catch)
}

template <typename T>
T &LinkedList<T>::operator[](size_t pos)
{
  assert(pos <= size());//assert es una biblioteca
  Node *pTmp = m_pHead;
  for(auto i= 0 ; i < pos ; i++)
    pTmp = pTmp->getPNext();
  return pTmp->getDataRef();
}


template <typename T>
ostream &LinkedList<T>::print(ostream &os) //& referencia significa no recibir una copia si no el mismo objeto
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
typename LinkedList<T>::iterator LinkedList<T>::iterator::operator++()
{
    m_pNode = m_pNode->getPNext();
    return *this; 
}

//Metodo para cambiar los nodos
/*template <typename T>
void LinkedList<T>::cambiar(T elem)
{
  if(m_pHead = m_pNext)
  {return;
  }else(m_pHead==0 || m_pNext==0)
  {return;
  }

  m_pHead=m_pHead<m_pNext m_pHead:m_pNext;
  m_pNext=m_pHead=m_pHead
}*/

#endif

//paso 1 crear Nodo
//paso 2 crear la cola si es que hay
//poner el puntero
