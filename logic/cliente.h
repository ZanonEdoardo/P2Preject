#ifndef CLIENTE_H
#define CLIENTE_H

#include"persona.h"
class Cliente:public Persona
{
    private:
        float Tassazzione;
        float ExtraAppuntamenti;
    public:
        Cliente();//vorrei poter evitare di metterlo, perchè vorrei che cliente non venga mai costruito così
        //Cliente(int ID);
        Cliente(int IDp,const std::string& Nomep,float Tassazzionep,float ExtraAppuntamentip);
        Cliente(const std::string& Nomep,float Tassazzionep,float ExtraAppuntamentip);
        Cliente(const Cliente&);

        virtual ~Cliente();

        //le seguenti due proprietà servono per la lettura, ma i membri vanno comuqnue privati, perchè non voglio vengano modificati
        virtual float getTassazzione() const ;
        float getExtra()const ;
        void Save(QTextStream& out)const ;
        //void save();
        bool operator==(const Cliente&)const;
};

#endif // CLIENTE_H
