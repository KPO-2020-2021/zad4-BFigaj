#ifndef PROSTOKAT_HH
#define PROSTOKAT_HH

#include <iostream>
#include "Wektor3D.hh"

#define X_bok 100
#define Y_bok 50
#define Z_bok 50
/*!
 *  \file 
 *  \brief Ten plik zawiera diefinicje klasy Prostopadłościan
 *   
 *  Klasa składa się z 8 punktów które są traktowane jako zmienne
 *  Wektor3D dzieki czemu łatwo można tymi punktami manipulować
 *  dodatkowo przetrzymywana jest Macierz3x3 do operacji takich jak
 *  rotacja
 */
class Prostopadloscian {
  Macierz3x3 mtx;
  Wektor3D p[8];
  public:
  Prostopadloscian();
  Prostopadloscian(double x,double y,double z);
  Wektor3D operator[](unsigned int i)const;
  void rotacja(double angle,unsigned int opt);
  void przesunieciewektor(Wektor3D vec);
  bool sprawdzeniebok() const;
  
  
};


/*!
 *  \brief Funkcja potrzebna do zapisu współrzędnych do pliku
 */
std::ostream& printtofile ( std::ostream       &Strm, 
                            const Prostopadloscian    &Pr);
/*!
 *  \brief Przeciążenie operatora << by wypisywał Prostopadłościan
 */
std::ostream& operator << ( std::ostream       &Strm, 
                            const Prostopadloscian    &Pr);
/*!
 *  \brief Funkcja zapisująca współrzędne Prostopadłoscianu do pliku
 */
bool filesave(const char *filename,const Prostopadloscian &Pr );
#endif
