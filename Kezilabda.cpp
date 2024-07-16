#include "Kezilabda.h"
#include "memtrace.h"
std::ostream &operator<<(std::ostream &os, const Kezilabda& sport){
    return os<<"Eves tamogatas: "<<sport.getLetszam()<<"\n";
}

void Kezilabda::adatModosit(const int ujszam) {
    tamogatas=ujszam;
}

void Kezilabda::adatKiiras() {
    std::cout<<"Eves tamogatas: "<<getLetszam()<<"\n";
}
/*
void Kezilabda::sportagAdatkiiras() {
    std::cout<<"Sport neve: "<<this->getSportnev()<<"\n";
}
*/
