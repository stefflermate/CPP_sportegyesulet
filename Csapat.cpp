#include "Csapat.h"
#include "memtrace.h"

std::ostream &operator<<(std::ostream &os, const Csapat &csap) {
    return os<<"Csapat neve: "<<csap.getNev()<<" | Csapat Letszama: "<<csap.getLetszam()<<"\n";
}

void Csapat::nevModosit(const char *ujNev) {
    csapatNev=ujNev;
}

void Csapat::letszamModosit(const int ujLetszam) {
    csapatLetszam=ujLetszam;
}

void Csapat::csapatAdatKiiras() {
    std::cout<<"Csapat neve: "<<getNev()<<" Csapat Letszama: "<<getLetszam()<<"\n";
}