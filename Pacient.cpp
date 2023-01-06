#include "Pacient.h"

const std::string& Pacient::getNume () const
{
    return nume;
}
const std::string& Pacient::getNumarTelefon () const
{
    return numarTelefon;
}
void Pacient::setServiciu(Serviciu* _serviciu, int _zi, int _luna, int _an)
{
    this->serviciu = _serviciu;
    this->zi = _zi;
    this->luna = _luna;
    this->an = _an;
}

int Pacient::getAn() const
{
    return an;
}

int Pacient::getLuna() const
{
    return luna;
}

int Pacient::getZi() const
{
    return zi;
}

Serviciu *Pacient::getServiciu() const {
    return serviciu;
}

void Pacient::setFinalizat(bool _finalizat)
{
    finalizat = _finalizat;
}

int Pacient::getVarsta() const
{
    return varsta;
}
bool Pacient::isFinalizat()
{
    return finalizat;
}
Pacient::Pacient(int varsta, const std::string &nume, const std::string &numarTelefon) : varsta(varsta), nume(nume), numarTelefon(numarTelefon) {}

std::ostream& operator<<(std::ostream& os,const Pacient& p)
{
    os<<"Pacient: "<<p.nume<<"\nVarsta: "<<p.varsta<<"\nTel: "<<p.numarTelefon<<std::endl;
    if(p.serviciu!= nullptr)
    {
        os << "Serviciu: " << p.serviciu->getDenumire();
        if (p.finalizat)
            os << " (Finalizat)";
        os << "\nData: " << p.zi << "." << p.luna << "." << p.an << "\n";
    }
    return os;
}