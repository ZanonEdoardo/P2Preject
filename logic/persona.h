#ifndef PERSONA_H
#define PERSONA_H

#include<string>
#include<QTextStream>
class Persona{
    protected:
        int ID;
        std::string Nome;
    public:
        //costruttori
        Persona();
        Persona(int,const std::string&);
        Persona(const std::string&);
        virtual ~Persona();

        //metodi di classe
        std::string getNome()const ;
        int getID()const;
        virtual void Save(QTextStream& out) const=0;//viruale puro, che confema che la classe effettivamente non può esistere, perchè non mi serve salvarla
};

#endif // PERSONA_H
