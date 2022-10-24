#include <iostream>
#include <string>
class Doctor{
private:
    std::string numeDoctor="ceva";
    std::string specializare="ceva";
public:
        std::string get_numeDoctor() const {
        return this->numeDoctor;
    }
    std::string get_specializare() const
    {
        return this->specializare;
    }

    Doctor()=default;
    Doctor(const std::string& numeDoctor,const std::string& specializare){
        this->numeDoctor=numeDoctor;
        this->specializare=specializare;
        std::cout<<"Constr de initializare Doctor\n";
    }

    Doctor(const Doctor& other) : numeDoctor(other.numeDoctor), specializare(other.specializare) {
        std::cout << "Constr de copiere Doctor\n";
    }
    friend std::ostream& operator<<(std::ostream& os, const Doctor& dr)
    {
        os<< "Nume "<<dr.numeDoctor<<", specializare "<<dr.specializare<<"\n";
        return os;
    }

    Doctor& operator=(const Doctor& other) {
        numeDoctor=other.numeDoctor;
        specializare=other.specializare;
        std::cout << "operator= copiere Doctor\n";
        return *this;
    }
};

class Pacient
{

    std::string nume= "ceva";
    std::string numarTelefon="ceva";
    std::string dataProgramare="ceva";
    Doctor doctor;
public:

    Pacient()=default;
    Pacient(const std::string& nume, const std::string& numarTelefon, const std::string& dataProgramare, const Doctor& doctor)
    {
        this->nume=nume;
        this->numarTelefon=numarTelefon;
        this->dataProgramare=dataProgramare;
        this->doctor=doctor;
    }
    friend std::ostream& operator<<(std::ostream& os,const Pacient& p)
    {
        os<<"Nume "<<p.nume<<", numar telefon "<<p.numarTelefon<<", data programarii "<<p.dataProgramare<<",doctorul pacientului "<<p.doctor.get_numeDoctor()<<", specializarea "<<p.doctor.get_specializare();
        return os;
    }

};

class Serviciu{
    std::string denumire="ceva";
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
        os<<"Denumirea serviciului "<<s.denumire<<", pretul serviciului "<<s.pret<<"\n";
        return os;
    }
    ~Serviciu() {
        std::cout<<"Destructor serviciu\n";
    }
};


int main() {
    Doctor d("popescu popescu","Chirurg");

    Doctor d2("popescu gigel","ortodont");
    Serviciu s1("extractie",250,d);
    Serviciu s2("detartraj",320,d);
    s1=s2;
    std::cout<<d2<<"\n";
    std::cout<<s2<<" "<<s1<<"\n";
    Pacient p1("Mihai","07123123","11.11.02",d2);
    std::cout<<p1<<"\n";
    std::cout << "Numele doctorului este " << d.get_numeDoctor() << " iar specializarea sa este de " << d.get_specializare() << "\n";
}