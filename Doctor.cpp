#include "Doctor.h"

Doctor::Doctor(const std::string & _nume, int _salariu, int _nr_specializari) : Angajat(_nume, _salariu)
{
    if(nr_specializari < 1)
       throw Eroare_specializari("Eroare specializare");

    this->nr_specializari = _nr_specializari;
}



void Doctor::print(std::ostream& out) const
{
    Angajat::print(out);
    out<<"Numar specializari: "<<nr_specializari<<"\n";
}

Doctor& Doctor::operator=(const Doctor &other)
{
    nume = other.nume;
    salariu = other.salariu;
    nr_specializari = other.nr_specializari;
    return *this;
}



void Doctor::marire(int procent)
{
    salariu += (salariu * procent) / 100;
}

