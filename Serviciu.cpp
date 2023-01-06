#include "Serviciu.h"

const std::string& Serviciu::getDenumire() const {
    return denumire;
}

Serviciu::Serviciu(const std::string& denumire,int pret,const std::shared_ptr<Angajat>& angajat)
{
    this->denumire = denumire;
    this->pret = pret;
    this->angajat = angajat;
}

const std::shared_ptr<Angajat>& Serviciu::getAngajat() const {
    return angajat;
}

Serviciu& Serviciu::operator=(const Serviciu& other)
{
    denumire=other.denumire;
    pret=other.pret;
    angajat=other.angajat;

    return *this;
}

Serviciu::Serviciu(const Serviciu& other) : denumire(other.denumire), pret(other.pret), angajat(other.angajat){}

std::ostream& operator<<(std::ostream& os,const Serviciu& s)
{
    os<<"Serviciu: "<<s.denumire<<"\nPret: "<<s.pret<<" lei\n";

    return os;
}

int Serviciu::getPret() const
{
    return pret;
}

int Serviciu::reducere(int voucher, int p)
{
    p -= voucher;
    return p;
}
