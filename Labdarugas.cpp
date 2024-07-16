#include "Labdarugas.h"
#include "SportAg.h"
#include "memtrace.h"

void Labdarugas::nevModosit(const char *ujnev, const char *ujnev2) {
    edzo1=ujnev;
    edzo2=ujnev2;
}

std::ostream &operator<<(std::ostream &os, const Labdarugas& sport){
    return os<<"Elso edzo: "<<sport.getEdzo1()<<" Masodik Edzo: "<<sport.getEdzo2()<<"\n";
}

void Labdarugas::adatKiiras() {
    std::cout<<"Elso edzo: "<<getEdzo1()<<" Masodik Edzo: "<<getEdzo2()<<"\n";
}
/*
void Labdarugas::sportagAdatkiiras() {
    std::cout<<"Sport neve: "<<this->getSportnev()<<"\n";
}

*/