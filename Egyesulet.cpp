#include <iostream>
#include "Egyesulet.h"
#include "Csapat.h"
#include "Labdarugas.h"
#include "Kosarlabda.h"
#include "Kezilabda.h"

#include "memtrace.h"

Csapat& Egyesulet::keres(const char *nev) {
    std::string n = nev;
    for (int i = 0; i < this->csapatszam; ++i) {
        if (csapatok[i].getNev() == n)
            return csapatok[i];
    }
    throw std::runtime_error("Csapat nem inhalator");
}

void Egyesulet::operator+(Csapat& ujCsapat) {
    Csapat* temp = new Csapat[csapatszam + 1];
    for (int i = 0; i < csapatszam; ++i) {
        temp[i] = csapatok[i];
    }

    temp[csapatszam] = ujCsapat;
    delete[] csapatok;
    csapatok = temp;
    csapatszam++;
}

void Egyesulet::operator-(const char *nev) {
    bool letezik_e = false;
    std::string n = nev;

    // Ellenőrizzük, hogy a törlendő csapat létezik-e
    for (int i = 0; i < csapatszam; ++i) {
        if (csapatok[i].getNev() == n) {
            letezik_e = true;
            break;
        }
    }

    if (letezik_e) {
        Csapat* temp = new Csapat[csapatszam - 1];
        int j = 0; // Segédváltozó a temp tömb indexeléséhez
        for (int i = 0; i < csapatszam; ++i) {
            if (!(csapatok[i].getNev() == n)) {
                temp[j] = csapatok[i]; // Csapat másolása, ha nem kell törölni
                j++;
            }
        }
        delete this->keres(nev).getSportag();
        delete[] csapatok; // Törlünk a régi tömböt
        csapatok = temp; // Az új tömbre állítjuk a csapatokat
        csapatszam--; // Csökkentjük a csapatok számát
        std::cout << "Sikeresen torolve a " << nev << " nevu csapatot\n";
    } else {
        std::cout << "Nem volt ilyen csapat\n";
    }
}

void Egyesulet::list() {
    for (int i = 0; i < csapatszam; ++i) {
        std::cout<<csapatok[i];
    }
    std::cout<<"\n";
}

void Egyesulet::fajlIras() {
    std::ofstream fajl("adat.txt");
    if (!fajl.is_open()) throw std::runtime_error("nem nyilt meg a fajl");

    for (int i = 0; i < csapatszam; ++i) {
        fajl<<csapatok[i].getNev()<<";"<<csapatok[i].getLetszam()<<";"<<csapatok[i].getSportag()->getSportnev()<<";";
        if (csapatok[i].getSportag()->getSportnev()=="foci") fajl<<"1;"<<csapatok[i].getSportag()->getStringAdat();
        else if(csapatok[i].getSportag()->getSportnev()=="kezi"){fajl<<"3;"<<csapatok[i].getSportag()->getSzamAdat();}
        else{fajl<<"2;"<<csapatok[i].getSportag()->getSzamAdat();}
        fajl<<"\n";
    }

    fajl.close();

}

void Egyesulet::fajlBeolvasas() {
    std::ifstream fajl("adat.txt");
    if (!fajl.is_open()) throw std::runtime_error("nem nyilt meg a fajl");

    std::string line;
    std::string csapatnev, sportag, edzo1, edzo2, letszamString, pompomString, tamogatasString, id;
    int letszam;

    while (std::getline(fajl, line)) {
        std::istringstream iss(line);
        //std::cout << line << std::endl;

        if (std::getline(iss, csapatnev, ';'))  //std::cout << csapatnev << " ";
        if (std::getline(iss, letszamString, ';')){
            letszam = std::stoi(letszamString);
            //std::cout << letszamString << " ";
        }
        if (std::getline(iss, sportag, ';')) //std::cout << sportag << " ";
        if (std::getline(iss, id, ';')){
            int kod = std::stoi(id);

            if(kod == 1){
                std::getline(iss, edzo1, ';');
                std::getline(iss, edzo2, ';');
                //std::cout << edzo1 << " " << edzo2 << " ";

                Labdarugas* ujcsapat3 = new Labdarugas(sportag, edzo1, edzo2);
                Csapat ujFocicsapat(csapatnev, letszam, *ujcsapat3); // Létrehozunk egy új foci csapatott
                *this + ujFocicsapat;
            }
            if(kod == 2){
                std::getline(iss, pompomString, ';');
                int pompom = std::stoi(pompomString);
                //std::cout << pompom;

                Kosarlabda* ujcsapat2 = new Kosarlabda(sportag, pompom);
                Csapat ujKosarcsapat(csapatnev, letszam, *ujcsapat2);
                *this + ujKosarcsapat;
            }
            if(kod == 3){
                std::getline(iss, tamogatasString, ';');
                int tamogatas = std::stoi(tamogatasString);
                //std::cout << tamogatas;

                Kezilabda* ujcsapat1 = new Kezilabda(sportag, tamogatas); // Létrehozzuk a foci csapat sportágát
                Csapat ujKezicsapat(csapatnev, letszam, *ujcsapat1); // Létrehozunk egy új foci csapatott
                *this + ujKezicsapat;
            }

            std::cout << std::endl;
        }
    }
    fajl.close();
}
