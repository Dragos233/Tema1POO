#ifndef MAIN_CPP_DOCTOR_H
#define MAIN_CPP_DOCTOR_H
#include <string>
#include <iostream>
class Doctor {
private:
    std::string numeDoctor = " ";
    int nr_specializari = 0;
    int salariu = 0;
public:
    int getNrSpecializari() const;

    Doctor() = default;

    Doctor(const std::string &numeDoctor, int nrSpecializari, int salariu);

    Doctor(const Doctor &other);

    friend std::ostream &operator<<(std::ostream &os, const Doctor &dr);

    void marire(int procent);

    Doctor &operator=(const Doctor &other);
};
#endif //MAIN_CPP_DOCTOR_H
