#include "Kosarlabda.h"
#include "memtrace.h"
std::ostream &operator<<(std::ostream &os, const Kosarlabda& sport){
    return os<<"PomPom letszam: "<<sport.getLetszam()<<"\n";
}

void Kosarlabda::adatModosit(const int ujszam) {
    pomLetszam=ujszam;
}

void Kosarlabda::adatKiiras() {
    std::cout<<"PomPom letszam: "<<getLetszam()<<"\n";
}
/*
void Kosarlabda::sportagAdatkiiras() {
    std::cout<<"Sport neve: "<<this->getSportnev()<<"\n";
}
*/