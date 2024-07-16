
#ifndef NAGY_HF_EGYESULET_H
#define NAGY_HF_EGYESULET_H
#include <iostream>
#include "Csapat.h"
#include "memtrace.h"

class Egyesulet{
private:
    int csapatszam;
    Csapat* csapatok;
public:
    Egyesulet() : csapatszam(0), csapatok(nullptr) {};
    void operator+(Csapat& ujCsapat);     /// egy csapatot hozzá ad a listához
    Csapat& keres(const char* nev);       /// adott nevű csapatot keres ki és adja vissza;
    int getCsapatszam()const{ return csapatszam;}; /// csapatok számát adja vissza
    void operator-(const char* nev);      /// egy csapatot elvesz a listából
    void list();              ///Kilistázza a csapatokat
    void fajlIras();
    void fajlBeolvasas();
    //void keziHozzaadas();

    /*


    friend std::ostream& operator<<(std::ostream& os, const Egyesulet& el){};
    void list(){};              ///Kilistázza a csapatokat
    void save(std::ostream& os)const{};     ///kimenti egy fájlba a listánkat
    void load(std::istream& is){};          /// Betölti egy fájlból az adatokat
    */
    ~Egyesulet() {
        for (int i = 0; i < csapatszam; ++i) {
            delete csapatok[i].getSportag();
        }
        delete[] csapatok;
    }

};



#endif //NAGY_HF_EGYESULET_H
