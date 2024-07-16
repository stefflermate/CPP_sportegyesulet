#include <iostream>
#include "Egyesulet.h"
#include "Csapat.h"
#include "Labdarugas.h"
#include "Kosarlabda.h"
#include "Kezilabda.h"
#include "memtrace.h"

int main() {

    Egyesulet ujEgyesulet;              // Egyesület létrehozása, de itt még üres
    ujEgyesulet.fajlBeolvasas();        // Külső fájlból beolvasás
/*
    Kezilabda ujcsapat1("Kezi",12000000); // Létrehozzuk a foci csapat sportágát
    Csapat ujKezicsapat("Uj kezi", 8, ujcsapat1); // Létrehozunk egy új foci csapatott
    ujEgyesulet+ujKezicsapat;

    Kosarlabda ujcsapat2("kosar",10);
    Csapat ujKosarcsapat("Uj kosar",12,ujcsapat2);
    ujEgyesulet+ujKosarcsapat;

    Labdarugas ujcsapat3("foci", "lajos", "bela");
    Csapat ujFocicsapat("Uj foci", 14, ujcsapat3); // Létrehozunk egy új foci csapatott
    ujEgyesulet + ujFocicsapat; // Hozzáadjuk a az új csapatot az egyesülethez
*/

    std::cout<<"-----------------Csapatok listazasa-----------------"<<std::endl;
    ujEgyesulet.list();                 // Kilistázom az eddig csapatokat


// Teszt:
    //csapat keres és kiirás
    try {
        std::cout<<"-----------------Kezi csapatra rakereses es kiras-----------------"<<std::endl;

        Csapat uj = ujEgyesulet.keres("Kezi Csapat");
        uj.csapatAdatKiiras();
        uj.getSportag()->sportagAdatkiiras();
        uj.getSportag()->adatKiiras();
    } catch (const std::runtime_error& e) {
        std::cerr << "Hiba: " << e.what() << std::endl;
    }

    std::cout<<"\n";

    //csapat adatmodosítás
    try {
        std::cout<<"-----------------Kezi csapatra rakeresas es atnevezes valamint adat modositas-----------------"<<std::endl;

        ujEgyesulet.keres("Kezi Csapat").nevModosit("Regi kezi");
        ujEgyesulet.keres("Regi kezi").letszamModosit(30);
        Csapat uj = ujEgyesulet.keres("Regi kezi");
        uj.getSportag()->adatModosit(44);
        uj.csapatAdatKiiras();
        uj.getSportag()->sportagAdatkiiras();
        uj.getSportag()->adatKiiras();
    } catch (const std::runtime_error& e) {
        std::cerr << "Hiba: " << e.what() << std::endl;
    }

    std::cout<<"\n";

    //csapat törlés
    std::cout<<"-----------------Kezi csapat torlese es maradek kilistazasa-----------------"<<std::endl;
    ujEgyesulet-("Regi kezi");
    ujEgyesulet.list();

    std::cout<<"\n";

    //Manuálisan csapat felvétel
    try {
        std::cout<<"-----------------Manualisan Kezi csapat felvetel -----------------"<<std::endl;
        Kezilabda *ujcsapat= new Kezilabda("kezi",120); // Létrehozzuk a foci csapat sportágát
        Csapat ujKeziCsapat("Kezi Csapat", 8, *ujcsapat); // Létrehozunk egy új foci csapatott
        ujEgyesulet+ujKeziCsapat;


        ujEgyesulet.list();        //Egyesület listázás
    } catch (const std::runtime_error& e) {
        std::cerr << "Hiba: " << e.what() << std::endl;
    }

    //fajl iras
    ujEgyesulet.fajlIras();
    return 0;
}
