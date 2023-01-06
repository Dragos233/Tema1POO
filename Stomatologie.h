#ifndef MAIN_CPP_STOMATOLOGIE_H
#define MAIN_CPP_STOMATOLOGIE_H

#include <vector>
#include <memory>
#include <list>
#include "Angajat.h"
#include "Pacient.h"
class Angajat;
class Pacient;
class Serviciu;
class Stomatologie
{
    int zi;
    int luna;
    int an;
    int profit = 0;
    std::vector<std::shared_ptr<Angajat>> angajati;
    std::vector<Serviciu> servicii;
public:

    std::list<std::shared_ptr<Pacient>> pacienti;

    Stomatologie(int _zi, int _luna, int _an);
    void addProfit(int suma);
    void addAngajat(const std::shared_ptr<Angajat>& a);
    void addServiciu(const std::string nume_serviciu, int pret, const std::shared_ptr<Angajat>& a);
    bool programeaza(std::shared_ptr<Pacient> p, const std::string serviciu);
    std::vector<std::shared_ptr<Pacient>> getPacienti();
    void lucreaza(int zile = 1);
};

#endif //MAIN_CPP_STOMATOLOGIE_H