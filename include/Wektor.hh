#ifndef WEKTOR_HH
#define WEKTOR_HH

#include <iostream>


/*!
 * \file
 * \brief Ten plik zawiera definicję szablonu Wektor<>
 */


/*!
 * \brief Ogólny szablon Wektor<>
 * 
 *  Modeluje pojęcie wektora o dowolnej wielkości
 *  i jakie ma glowne cechy.
 */
template <int Wymiar>
class Wektor {
   double _Wsp[Wymiar]; 
  public:
   Wektor()
   {
    int i;
    for(i=0;i<Wymiar;++i)
      _Wsp[i]=0;
   }
   Wektor(double x)
   {
    int i;
    for(i=0;i<Wymiar;++i)
      _Wsp[i]=x;
   }
   double operator [](unsigned int index) const
   {
    if(index>=Wymiar)
    {
      std::cerr << "Zly wybor parametrow" << std::endl;
      //assert(index>=Wymiar);
      return _Wsp[index];
    }
    else
      return _Wsp[index];
   }
   double& operator [](unsigned int index)
   {
    if(index>=Wymiar)
    {
      //std::cerr << "Zly wybor parametrow" << std::endl;
      //assert(index>=Wymiar);
      return _Wsp[index];
    }
    else
      return _Wsp[index];
   }
   Wektor operator+ (Wektor vec) const;
   Wektor operator- (Wektor vec) const;
   bool operator== (Wektor vec) const;   
};

template <int Wymiar>
Wektor<Wymiar> Wektor<Wymiar>::operator+ (Wektor<Wymiar> vec) const
{
  int i;
  Wektor<Wymiar> newvec;
  for(i=0;i<Wymiar;++i)
  {
    newvec._Wsp[i]=vec._Wsp[i]+this->_Wsp[i];
  }
  return newvec;
}

template <int Wymiar>
Wektor<Wymiar> Wektor<Wymiar>::operator- (Wektor<Wymiar> vec) const
{
  int i;
  Wektor<Wymiar> newvec;
  for(i=0;i<Wymiar;++i)
  {
    newvec._Wsp[i]=this->_Wsp[i]-vec._Wsp[i];
  }
  return newvec;
}

template <int Wymiar>
bool Wektor<Wymiar>::operator== (Wektor<Wymiar> vec) const
{
  int i;
  for(i=0;i<Wymiar;++i)
  {
    if(this->_Wsp[i]!=vec[i])
      return false;
  }
  return true;
}

/*!
 * \brief Przeciążenie dla wyjścia musi także być szablonem
 *
 * To przeciazenie trzeba opisac. Co ono robi. Jaki format
 * danych akceptuje. Jakie jest znaczenie parametrow itd.
 * Szczegoly dotyczace zalecen realizacji opisow mozna
 * znalezc w pliku:
 *    ~bk/edu/kpo/zalecenia.txt 
 */
template <int Wymiar>
inline
std::istream& operator >> (std::istream &Strm, Wektor<Wymiar> &Wek)
{
  int i;
  i=0;
  while(i!=Wymiar)
  {
    Strm >> Wek[i];
    i=i+1;
  }
  return Strm;
}

/*!
 * \brief Przeciążenie dla wejścia musi także być szablonem
 * 
 * To przeciazenie trzeba opisac. Co ono robi. Jaki format
 * danych akceptuje. Jakie jest znaczenie parametrow itd.
 * Szczegoly dotyczace zalecen realizacji opisow mozna
 * znalezc w pliku:
 *    ~bk/edu/kpo/zalecenia.txt 
 */
template <int Wymiar>
inline
std::ostream& operator << (std::ostream &Strm, const Wektor<Wymiar> &Wek)
{
  int i;
  i=0;
  while(i!=Wymiar)
  {
    Strm << Wek[i];
    i=i+1;
  }
  return Strm;  
}

#endif
