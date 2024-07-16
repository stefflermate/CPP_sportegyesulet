#include <iostream>
#include "SportAg.h"
#include "memtrace.h"

std::ostream& operator<<(std::ostream &os, const SportAg &sport){
    return os<<"Sport neve: "<<sport.getSportnev()<<"\n";
}

void SportAg::sportagAdatkiiras() {
    std::cout<<"Sport neve: "<<nev<<"\n";
}