#include "Angajat.h"

const std::string& Angajat::getNume() const
{
    return nume;
}


void Angajat::setStomatologie(const std::shared_ptr<Stomatologie>& _stomatologie)
{
    stomatologie = _stomatologie;
}
int Angajat::getSalariu() const
{
    return salariu;
}
Angajat::Angajat(const std::string &_nume, int _salariu): nume(_nume), salariu(_salariu){}

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

void Angajat::marire(int procent)
{
    salariu += (salariu * procent) / 100;
}

Angajat& Angajat::operator=(const Angajat &other)
{
    nume=other.nume;
    salariu=other.salariu;

    return *this;
}
