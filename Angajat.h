#ifndef MAIN_CPP_ANGAJAT_H
#define MAIN_CPP_ANGAJAT_H

#include <string>
#include <iostream>
#include <memory>
#include <vector>

#include "Pacient.h"
#include "Stomatologie.h"
class Stomatologie;

class Angajat
{
protected:
    std::string nume = "";
    int salariu = 0;
    std::shared_ptr<Stomatologie> stomatologie = nullptr;
public:

    int getSalariu() const;

    void Angajat::setStomatologie(const std::shared_ptr<Stomatologie>& _stomatologie);

    const std::shared_ptr<Stomatologie> &Angajat::getStomatologie() const;

    Angajat(const std::string &_nume, int _salariu);

    Angajat(const Angajat &other);

    friend std::ostream &operator<<(std::ostream &os, const Angajat &a);

    void lucreaza();

    Angajat &operator=(const Angajat &other);

    Angajat() = default;

    virtual ~Angajat() = default;

    virtual void print(std::ostream& out) const;

};

#endif //MAIN_CPP_ANGAJAT_H
