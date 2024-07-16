
#ifndef NAGY_HF_KEZILABDA_H
#define NAGY_HF_KEZILABDA_H
#include <iostream>
#include "SportAg.h"
#include "memtrace.h"


class Kezilabda:public SportAg {
private:
    int tamogatas;
public:
    Kezilabda(const char *nev, int evesTamogatas) : SportAg(nev), tamogatas(evesTamogatas){};   ///létrehozza a sportágat
    Kezilabda(std::string n, int evesTamogatas) : SportAg(n), tamogatas(evesTamogatas){};   ///létrehozza a sportágat

    int getLetszam()const{return tamogatas;}
    void adatModosit(const int ujszam)override;
    void nevModosit(const char* ujnev, const char* ujnev2)override{};
    virtual void adatKiiras()override;
    //virtual void sportagAdatkiiras()override;
    virtual int getSzamAdat()override{return tamogatas;};
    virtual std::string getStringAdat()override{return 0;};
    //std::ostream& operator<<(std::ostream& os)override;

    ~Kezilabda(){};
};

//std::ostream& operator<<(std::ostream& os,const Kezilabda& sport);     ///Kiirja a sportág adatait
#endif //NAGY_HF_KEZILABDA_H
