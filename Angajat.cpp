#include "Angajat.h"
int Angajat::getSalariu() const
{
    return salariu;
}

Angajat::Angajat(const std::string &_nume, int _salariu) {
    this->nume = _nume;
    this->salariu = _salariu;

}

void Angajat::print(std::ostream &out) const
{
    out<<"Nume: "<<nume<<"\n";
    out<<"Salariu: "<<salariu<<"\n";
}

Angajat::Angajat(const Angajat& other)
{
    nume=other.nume;
    salariu=other.salariu;
}

void Angajat::lucreaza()
{
    std::vector<std::shared_ptr<Pacient>> p = stomatologie->getPacienti();
    for(auto& pacient:p)

        if(pacient->getServiciu()->getAngajat().get() == this )
        {
            stomatologie->addProfit(pacient->getServiciu()->getPret());
            std::cout << nume << " lucreaza pe " << pacient->getNume() << "\n";
            pacient->setFinalizat(true);
        }
}

std::ostream &operator<<(std::ostream &os, const Angajat &a)
{
    os<<"Angajat: "<<a.nume<<"\nSalariu: "<<a.salariu<<" lei\n";
    return os;
}

Angajat& Angajat::operator=(const Angajat &other)
{
    nume=other.nume;
    salariu=other.salariu;

    return *this;
}
