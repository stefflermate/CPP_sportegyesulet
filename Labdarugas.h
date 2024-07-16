
#ifndef NAGY_HF_LABDARUGAS_H
#define NAGY_HF_LABDARUGAS_H
#include <iostream>
#include "SportAg.h"
#include "memtrace.h"


class Labdarugas:public SportAg {
private:
    std::string edzo1, edzo2;
public:
    Labdarugas(const char *nev, const char *edzok, const char *edzok2) : SportAg(nev), edzo1(edzok),edzo2(edzok2) {};   ///létrehozza a sportágat
    Labdarugas(std::string nev,std::string edzok, std::string edzok2) : SportAg(nev), edzo1(edzok),edzo2(edzok2) {};   ///létrehozza a sportágat

    std::string getEdzo1()const{return edzo1;};
    std::string getEdzo2()const{return edzo2;};
    void adatModosit(const int ujszam)override{};
    void nevModosit(const char* ujnev, const char* ujnev2)override;
    virtual void adatKiiras()override;
    //virtual void sportagAdatkiiras()override;
    virtual int getSzamAdat()override{return 0;};
    virtual std::string getStringAdat(){return edzo1+";"+edzo2;};
    //std::ostream& operator<<(std::ostream& os)override;

    ~Labdarugas(){};
};

//std::ostream& operator<<(std::ostream& os,const Labdarugas& sport);     ///Kiirja a sportág adatait
#endif //NAGY_HF_LABDARUGAS_H
