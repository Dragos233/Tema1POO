#ifndef MAIN_CPP_PACIENT_H
#define MAIN_CPP_PACIENT_H

#include "Angajat.h"
#include "Serviciu.h"
#include <string>
#include <iostream>

class Serviciu;
class Stomatologie;

class Pacient
{
    int varsta = 0;
    std::string nume = "";
    std::string numarTelefon ="";

    int an = 0 ;
    int luna = 0;
    int zi = 0;
    Serviciu* serviciu = nullptr;
    bool finalizat = 0;

public:

    Serviciu *getServiciu() const;
    void setServiciu(Serviciu* serviciu, int zi, int luna, int an);
    const std::string &getNume() const;
    const std::string &getNumarTelefon() const;
    int getVarsta() const;
    int getAn() const;
    int getLuna() const;
    int getZi() const;
    Pacient(int varsta, const std::string &nume, const std::string &numarTelefon);
    void setFinalizat(bool _finalizat);
    bool isFinalizat();
    friend std::ostream& operator<<(std::ostream& os,const Pacient& p);

};

#endif //MAIN_CPP_PACIENT_H
