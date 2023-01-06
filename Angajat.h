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
    std::string nume = "";
    int salariu = 0;
    std::shared_ptr<Stomatologie> stomatologie = nullptr;


public:


    void setStomatologie(const std::shared_ptr<Stomatologie>& _stomatologie);

    const std::string& getNume() const;

    int getSalariu() const;

    Angajat(const std::string &nume, int salariu);

    Angajat(const Angajat &other);

    friend std::ostream &operator<<(std::ostream &os, const Angajat &a);

    void marire(int procent);

    void lucreaza();

    Angajat &operator=(const Angajat &other);

    const std::shared_ptr<Stomatologie> &getStomatologie() const;


};

#endif //MAIN_CPP_ANGAJAT_H
