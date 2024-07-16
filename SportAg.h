
#ifndef NAGY_HF_SPORTAG_H
#define NAGY_HF_SPORTAG_H
#include <iostream>
#include "memtrace.h"

class SportAg{
private:
    std::string nev; ///Sportág megnevezése lehet foci röpi vagy kézi
public:
    SportAg(const char* name):nev(std::string(name)){};
    SportAg(std::string name):nev(std::string(name)){};

    std::string getSportnev()const{return nev;};

    //virtual std::ostream& getAdat(std::ostream& os,const SportAg& sport)const;                   ///virtuális fügvény ami leszármazottak adatait írja ki
    virtual void nevModosit(const char* ujnev, const char* ujnev2)=0;                    ///virtuális fügvény ami leszármazottak adatait modosítja
    virtual void adatModosit(const int ujszam)=0;                    ///virtuális fügvény ami leszármazottak adatait modosítja
    virtual void adatKiiras()=0;
    virtual void sportagAdatkiiras();
    virtual int getSzamAdat()=0;
    virtual std::string getStringAdat()=0;
    //virtual std::ostream& operator<<(std::ostream& os)=0;

    virtual ~SportAg(){};
};

//std::ostream& operator<<(std::ostream& os,const SportAg& sport);                               /// Sportág nevének kiirása




#endif //NAGY_HF_SPORTAG_H
