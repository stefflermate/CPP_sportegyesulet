
#ifndef NAGY_HF_KOSARLABDA_H
#define NAGY_HF_KOSARLABDA_H

#include <iostream>
#include "SportAg.h"
#include "memtrace.h"


class Kosarlabda:public SportAg {
private:
    int pomLetszam;
public:
    Kosarlabda(const char *nev, int letszam) : SportAg(nev), pomLetszam(letszam){};   ///létrehozza a sportágat
    Kosarlabda(std::string nev, int letszam) : SportAg(nev), pomLetszam(letszam){};   ///létrehozza a sportágat


    int getLetszam()const{return pomLetszam;}
    void adatModosit(const int ujszam)override;
    void nevModosit(const char* ujnev, const char* ujnev2)override{};
    virtual void adatKiiras()override;
    //virtual void sportagAdatkiiras()override;
    virtual int getSzamAdat()override{return pomLetszam;};
    virtual std::string getStringAdat()override{return 0;};
    //std::ostream& operator<<(std::ostream& os)override;

    ~Kosarlabda(){};
};

//std::ostream& operator<<(std::ostream& os,const Kosarlabda& sport);     ///Kiirja a sportág adatait
#endif //NAGY_HF_KOSARLABDA_H
