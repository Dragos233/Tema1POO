
#include "Doctor.h"
int Doctor::getNrSpecializari() const {
    return nr_specializari;
}
Doctor::Doctor(const std::string &numeDoctor, int nrSpecializari, int salariu) : numeDoctor(numeDoctor),
                                                                         nr_specializari(nrSpecializari),
                                                                         salariu(salariu) {}

Doctor::Doctor(const Doctor& other) : numeDoctor(other.numeDoctor), nr_specializari(other.nr_specializari), salariu(other.salariu) {
    std::cout << "Constr de copiere Doctor\n";
}
std::ostream& operator<<(std::ostream& os, const Doctor& dr)
{
    os<<dr.numeDoctor<<", numar specializari "<<dr.nr_specializari<<", salariu "<<dr.salariu<<"\n";
    return os;
}
void Doctor::marire(int procent)
{
    if (getNrSpecializari() > 1) {
        std::cout << "Doctorul avea un salariu de salariu " << salariu;
        salariu *= procent;
        std::cout << " iar acum are salariul de " << salariu << "\n";
    }
}
Doctor& Doctor::operator=(const Doctor& other)
{
    numeDoctor=other.numeDoctor;
    nr_specializari=other.nr_specializari;
    salariu = other.salariu;
    std::cout << "operator= copiere Doctor\n";
    return *this;
}
