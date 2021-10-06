#ifndef __RECORRER_H__  
#define __RECORRER_H__ 
void fx(TX &x)
{  cout << x << "  "; }

void inc(TX &x)
{  ++x; }

template <typename Iterator, typename F>
void recorrer(Iterator ItBegin, Iterator ItEnd, F ope)
{
  Iterator iter = ItBegin;
  for(; iter != ItEnd ; ++iter)
      ope(*iter);
}

// #1
template <typename Container, typename F>
void recorrer(Container &container, F ope)
{ recorrer(container.begin(), container.end(), ope);
}


#endif 