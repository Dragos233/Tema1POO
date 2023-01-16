#include "Stomatologie.h"

void ziua_urmatoare(int& zi, int& luna, int& an)
{
    if (zi < 30)
        zi++;
    else
    {
        zi = 1;
        if (luna < 12)
            luna++;
        else
        {
            luna = 1;
            an++;
        }
    }
}

std::vector<std::shared_ptr<Pacient>> Stomatologie::getPacienti()
{
    std::vector<std::shared_ptr<Pacient>> vector_pacienti;
    for (const auto &pacient: pacienti)
    {
        if (pacient->getZi() == zi && pacient->getLuna() == luna && pacient->getAn() == an)
            vector_pacienti.push_back(pacient);
    }
    return vector_pacienti;
}

Stomatologie::Stomatologie(int _zi, int _luna, int _an): zi(_zi), luna(_luna), an(_an){}

void Stomatologie::addAngajat(const std::shared_ptr<Angajat>& a)
{
   angajati.push_back(a);
   a->setStomatologie(std::shared_ptr<Stomatologie>(this));
}

void Stomatologie::addServiciu(const std::string nume_serviciu, int pret, const std::shared_ptr<Angajat>& a)
{
    servicii.push_back(Serviciu(nume_serviciu, pret, a));
}

bool Stomatologie::programeaza(std::shared_ptr<Pacient> p, const std::string nume_serviciu)
{
    Serviciu* s = nullptr;

    for(auto& serviciu:servicii)
        if(nume_serviciu == serviciu.getDenumire())
        {
            s = &serviciu;
            break;
        }

    if (!s)
        return false;

    int _zi = zi;
    int _luna = luna;
    int _an = an;

    while(true)
    {
        int nr = 0;

        for (const auto &pacient: pacienti)
            if (pacient->getZi() == _zi && pacient->getLuna() == _luna && pacient->getAn() == _an)
                nr++;

        if (nr < 1)
        {
            p->setServiciu(s, _zi, _luna, _an);
            pacienti.push_back(p);
            return true;
        }
        else
            ziua_urmatoare(_zi,_luna,_an);
    }
}

void Stomatologie::addProfit(int suma)
{
    profit += suma;
}

void Stomatologie::lucreaza(int zile)
{
    for(int i = 0; i< zile; i++)
    {
        std::cout<<zi<<"."<<luna<<"."<<an<<":\n";
        for(const auto &angajat: angajati)
        {
            angajat->lucreaza();

            if(zi == 30)
                addProfit(-angajat->getSalariu());
        }
        pacienti.remove_if([](const std::shared_ptr<Pacient>& p){return p->isFinalizat();});
        ziua_urmatoare(zi,luna,an);
    }
}


