#ifndef MAIN_CPP_SERVICIU_H
#define MAIN_CPP_SERVICIU_H
#include "Angajat.h"
#include <string>
#include <iostream>
#include <memory>

class Angajat;

class Serviciu
{
    std::string denumire = "";
    int pret = 0;
    std::shared_ptr<Angajat> angajat;

public:

    const std::shared_ptr<Angajat>& getAngajat() const;

    const std::string& getDenumire() const;
    Serviciu(const std::string &denumire, int pret, const std::shared_ptr<Angajat>& Angajat);

    Serviciu &operator=(const Serviciu &other);

    Serviciu(const Serviciu &other);

    int getPret() const;

    int reducere(int voucher, int p);

    friend std::ostream &operator<<(std::ostream &os, const Serviciu &s);


};

#endif //MAIN_CPP_SERVICIU_H
