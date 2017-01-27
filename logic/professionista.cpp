#include "professionista.h"

Professionista::Professionista():ID(0),Nome(""){}

Professionista::Professionista(const Professionista& a ):ID(a.ID),Nome(a.Nome){}

Professionista::Professionista(int Idp, const std::string Nomep):ID(Idp),Nome(Nomep){}

std::string Professionista::getNome(){return Nome;}

Professionista::~Professionista(){}
