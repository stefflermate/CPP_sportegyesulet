
#ifndef NAGY_HF_CSAPAT_H
#define NAGY_HF_CSAPAT_H
#include "SportAg.h"
#include "memtrace.h"

class Csapat{
private:
    std::string csapatNev;
    int csapatLetszam;
    SportAg* csapatSportAg;
public:
    Csapat(){};
    Csapat(const char* csapatnev, const int csapatletszam, SportAg& sport): csapatNev(csapatnev), csapatLetszam(csapatletszam),
                                                                           csapatSportAg(&sport){};
    Csapat(std::string csapatnev, const int csapatletszam, SportAg& sport): csapatNev(csapatnev), csapatLetszam(csapatletszam),
                                                                            csapatSportAg(&sport){};

    std::string getNev()const{return csapatNev;};
    int getLetszam()const{return csapatLetszam;};
    SportAg* getSportag()const{return csapatSportAg;};
    void csapatAdatKiiras();
    void nevModosit(const char* ujNev);
    void letszamModosit(const int ujLetszam);


    ~Csapat() {

    }
};

std::ostream& operator<<(std::ostream& os, const Csapat& csap);


#endif //NAGY_HF_CSAPAT_H
