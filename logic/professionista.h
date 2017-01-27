#ifndef PROFESSIONISTA_H
#define PROFESSIONISTA_H

#include <string>

class Professionista{
    private:
    int ID;
    std::string Nome;

    public:
        Professionista();
        Professionista(const Professionista &);
        Professionista(int , const std::string);
        std::string getNome();
        virtual ~Professionista();
};

#endif // PROFESSIONISTA_H
