#include "persona.h"

Persona::Persona():ID(0),Nome(""){}
Persona::Persona(const std::string& Nomep):ID(0),Nome(Nomep){}
Persona::Persona(int IDp ,const std::string& Nomep):ID(IDp),Nome(Nomep){}

std::string Persona::getNome() const {return Nome;}
int Persona::getID()const{return ID;}
Persona::~Persona(){}
