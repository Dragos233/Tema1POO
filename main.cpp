#include <iostream>
#include <string>
class Doctor{
private:
    std::string numeDoctor=" ";
    int nr_specializari = 0;
    int salariu = 0;
public:
    int getNrSpecializari() const {
        return nr_specializari;
    }
    Doctor()=default;
    Doctor(const std::string &numeDoctor, int nrSpecializari, int salariu) : numeDoctor(numeDoctor),
                                                                             nr_specializari(nrSpecializari),
                                                                             salariu(salariu) {}

    Doctor(const Doctor& other) : numeDoctor(other.numeDoctor), nr_specializari(other.nr_specializari), salariu(other.salariu) {
        std::cout << "Constr de copiere Doctor\n";
    }
    friend std::ostream& operator<<(std::ostream& os, const Doctor& dr)
    {
        os<<dr.numeDoctor<<", numar specializari "<<dr.nr_specializari<<", salariu "<<dr.salariu<<"\n";
        return os;
    }
    void marire(int procent)
    {
        if (getNrSpecializari() > 1) {
            std::cout << "Doctorul avea un salariu de salariu " << salariu;
            salariu *= procent;
            std::cout << " iar acum are salariul de " << salariu << "\n";
        }
    }
    Doctor& operator=(const Doctor& other)
            {
        numeDoctor=other.numeDoctor;
        nr_specializari=other.nr_specializari;
        salariu = other.salariu;
        std::cout << "operator= copiere Doctor\n";
        return *this;
    }
};

class Serviciu{
    std::string denumire=" ";
    int pret=0;
    Doctor doctor;

public:
    Serviciu()=default;
    Serviciu(const std::string& denumire,int pret,const Doctor& doctor) {
        this->denumire=denumire;
        this->pret=pret;
        this->doctor=doctor;
        std::cout<<"Constr de initializare Serviciu\n";
    }
    Serviciu& operator=(const Serviciu& other) {
        denumire=other.denumire;
        pret=other.pret;
        doctor=other.doctor;
        std::cout << "operator= copiere Serviciu\n";
        return *this;
    }
    Serviciu(const Serviciu& other) : denumire(other.denumire), pret(other.pret), doctor(other.doctor) {
        std::cout << "Constr de copiere Serviciu\n";
    }
    friend std::ostream& operator<<(std::ostream& os,const Serviciu& s)
    {
        os<<s.denumire<<", pretul serviciului "<<s.pret<<" lei\n";
        return os;
    }
    ~Serviciu() {
        std::cout<<"Destructor serviciu\n";
    }

    int getPret() const {
        return pret;
    }


    int reducere(int voucher, int p)
    {
        p -= voucher;
        return p;
    }

};
class Pacient
{
    int varsta = 0;
    std::string nume = " ";
    std::string numarTelefon =" ";
    int an = 0 ;
    int luna = 0;
    int zi = 0;
    Serviciu serviciu;

public:
    const std::string &getNume() const {
        return nume;
    }

    const std::string &getNumarTelefon() const {
        return numarTelefon;
    }

    int getAn() const {
        return an;
    }

    int getLuna() const {
        return luna;
    }

    int getZi() const {
        return zi;
    }


    void verif_data(const int& an_prezent, const int& luna_prezent , const int& zi_prezent)
    {
        if(an_prezent > getAn())
            std::cout<<"Pacientul nu a fost inca operat!\n";
        else if(luna_prezent > getLuna())
            std::cout<<"Pacientul nu a fost inca operat!\n";
        else if(zi_prezent > getZi())
            std::cout<<"Pacientul nu a fost inca operat!\n";
        else
            std::cout<<"Pacientul a fost operat!\n";
    }

    void data_valida(const int& an_p, const int& luna_p, const int& zi_p)
    {
        if (getAn() == an_p && getLuna() == luna_p && getZi() == zi_p)
        {
            if (getZi() + 7 <= 30)
                 zi = getZi() + 7;
            else if (getLuna() + 1 <= 12)
                 luna = getLuna() + 1;
            else {
                 an = getAn() + 1;
                 luna = 1;
            }
        }
        std::cout<<"Pacientul "<<getNume()<<" trebuie anuntat in legatura cu decalajul programarii sale la numarul de telefon "<<getNumarTelefon()<<"\n";
    }
    Pacient()=default;

    Pacient(int varsta, const std::string &nume, const std::string &numarTelefon, int an, int luna, int zi,const Serviciu &serviciu) : varsta(varsta), nume(nume), numarTelefon(numarTelefon), an(an), luna(luna), zi(zi),
                                        serviciu(serviciu) {}

    int getVarsta() const {
        return varsta;
    }

    friend std::ostream& operator<<(std::ostream& os,const Pacient& p)
    {
        os<<"Varsta:"<<p.varsta<<" Nume "<<p.nume<<", numar telefon "<<p.numarTelefon<<std::endl;
        return os;

    }

};
int main()
{
   Doctor d("popescu popescu",1, 2000);
   Doctor d2("popescu gigel",4, 3000);
   Serviciu s1("extractie",250,d);
   Pacient p( 3, "ababei", "0712129", 2022 , 12, 13,s1);
    Pacient p1(20,"Mihai","07123123",2022, 11, 11, s1);
    Pacient p2(25,"Andrei","072391248",2022,11,11,s1);
    std::cout<<"Pretul serviciului s1 este "<<s1.getPret()<<"\n";
    p.verif_data(2023,11,13);

    if (p.getVarsta()  < 18)
   {
       int pretRedus = s1.reducere(30, s1.getPret());
       std::cout <<"Pretul redus al serviciului este "<<pretRedus << "\n";
   }
   else {
       std::cout<<s1.getPret();
   }
    Serviciu s2("detartraj",320,d);
    d2.marire(20);
    s1=s2;
    std::cout<<d2<<"\n";
    std::cout<<s2<<" "<<s1<<"\n";
   p2.data_valida(p1.getAn(),p1.getLuna(),p1.getZi());
   Doctor d3 = d;
   std::cout<<"p2="<<p2<<"\n";
   std::cout<<p1<<"\n";
   std::cout<<d3;
}