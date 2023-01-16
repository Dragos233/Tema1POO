#ifndef MAIN_CPP_DOCTOR_H
#define MAIN_CPP_DOCTOR_H
#include <string>
#include <iostream>
#include "Eroare_specializari.h"
#include "Angajat.h"
class Doctor : public Angajat
{
    int nr_specializari{0};
public:

    Doctor() = default;
    ~Doctor() override = default;
    Doctor(const std::string &nume, int salariu, int nr_specializari);

    //bool ok = false;

    void marire(int procent);

    void print(std::ostream& out) const override;

    Doctor &operator=(const Doctor &other);
};
#endif //MAIN_CPP_DOCTOR_H
