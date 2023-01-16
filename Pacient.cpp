#include "Pacient.h"

const std::string& Pacient::getNume () const
{
    return nume;
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

bool Pacient::isFinalizat () const
{
    return finalizat;
}

int Pacient::id_max = 0;
Pacient::Pacient(int _varsta, const std::string& _nume, const std::string& _numarTelefon) :  id(++id_max), varsta(_varsta), nume(_nume), numarTelefon(_numarTelefon)  {}

std::ostream& operator<<(std::ostream& os,const Pacient& p)
{
    os<<"Pacient: "<<p.nume<<"\nID: "<<p.id<<" Varsta: "<<p.varsta<<"\nTel: "<<p.numarTelefon<<std::endl;
    if(p.serviciu!= nullptr)
    {
        os << "Serviciu: " << p.serviciu->getDenumire();
        if (p.finalizat)
            os << " (Finalizat)";
        os << "\nData: " << p.zi << "." << p.luna << "." << p.an << "\n";
    }
    return os;
}