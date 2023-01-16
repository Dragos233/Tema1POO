#include <iostream>
#include "Angajat.h"
#include "Pacient.h"
#include "Stomatologie.h"
#include "Doctor.h"

using namespace std;

int main()
{
    Stomatologie s(6,1,2023);
    shared_ptr<Pacient> p = make_shared<Pacient>(25,"Andrei","072391248");
    shared_ptr<Pacient> p1 = make_shared<Pacient>(20,"Mihai","0769696969");
    shared_ptr<Angajat> a = make_shared<Angajat>("Marian",420);
    Doctor d("Nume", 420, 3);
    d.marire(30);
    s.addAngajat(a);
    s.addServiciu("extractie",250, a);
    Angajat* a2 = dynamic_cast<Doctor*>(&d);
    cout<<*a2;
    cout<<*p<<"\n";
    s.programeaza(p,"extractie");
    cout<<*p1<<"\n";
    s.programeaza(p1,"extractie");
    s.lucreaza(2);
    ///cout<<*p<<"\n";

    return 0;
}