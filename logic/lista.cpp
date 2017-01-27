#include "lista.h"
#include "impegnolavorativo.h"
//nodo
Lista::Nodo::Nodo():next(0),info(0),riferimenti(0){}
Lista::Nodo::Nodo(Impegno* a,Lista::smartp b):next(b),info(a),riferimenti(0){}
Lista::Nodo::~Nodo(){
    if(info)
        delete info;//cancello l'impegno
}//distruttore

//smartP
Lista::smartp::smartp(Lista::Nodo *p) : Puntatore(p) {if (Puntatore) Puntatore->riferimenti++;} //costruttore 0 1 e convers //s0
Lista::smartp::smartp(const smartp& s) : Puntatore(s.Puntatore) {if (Puntatore) Puntatore->riferimenti++;} //s0 // costruttore di copia //s1
Lista::smartp::~smartp() { //distruttore//s2
    if(Puntatore) {
        Puntatore->riferimenti--;
        if(Puntatore->riferimenti==0) delete Puntatore; // Puntatore Ã¨ un nodo* quindi richiama di nuovo il distruttore di smartp
    }
}
Lista::smartp& Lista::smartp::operator= (const smartp& s) {//s3 pag 114
    if(this!=&s) {
        Lista::Nodo* aux = Puntatore; // aumento di uno i Puntatoreatori a Puntatore momentaneamente per impedire cancellazioni indesiderate
        if (aux) aux->riferimenti++; // e infatti aumento i riferimenti
        if (Puntatore) Puntatore->riferimenti--; //ma io sto per assegnare il primo originario Puntatore quindi mi preparo a spostarlo
        Puntatore = s.Puntatore; // assegnazione effettiva
        if (Puntatore) Puntatore->riferimenti++;
        if (aux) {
            aux->riferimenti--;
            if (!aux->riferimenti) delete aux;
        }
    }
    return *this;
}

Lista::Nodo& Lista::smartp::operator* () const { // s4
    return *Puntatore;
}

Lista::Nodo* Lista::smartp::operator->() const { // s5
    return Puntatore;
}

bool Lista::smartp::operator==(const smartp& s) const { //s6
    return Puntatore == s.Puntatore;
}

bool Lista::smartp::operator!=(const smartp& s) const { //s6
    return Puntatore != s.Puntatore;
}






//-----------------------------------------------------------------
bool Lista::Iteratore::operator==(Lista::Iteratore i_ric) const {return punt == i_ric.punt;} // 6

bool Lista::Iteratore::operator!=(Lista::Iteratore i_ric) const {return punt != i_ric.punt;} // 7

Lista::Iteratore& Lista::Iteratore::operator=(const Lista::Iteratore& i_ric){ punt=i_ric.punt; return *this;}

Lista::Iteratore& Lista::Iteratore::operator++() { // operatore ++ prefisso 8
    if (punt!=0) punt = punt->next;
    return *this;
}

Lista::Iteratore  Lista::Iteratore::operator++(int) {// operatore ++ postfisso 9
    Iteratore aux = *this;
    if (punt!=0) punt = punt->next;
    return aux;
}

Lista::Iteratore Lista::begin() const { // 10
    Iteratore aux;
    aux.punt = first;
    return aux;
}

Lista::Iteratore Lista::end() const { // 11
    Iteratore aux;
    aux.punt = 0;
    return aux;
}

Impegno* Lista::operator[](Lista::Iteratore i) const { //PRE punt != 0 // 12
    return (i.punt)->info;
}

//_--------------------------------------------
float Lista::getMoney(const Cliente& a) const{
    float result=0;
    smartp index(first);
    ImpegnoLavorativo* implav;
    while(index!=0){
        implav=dynamic_cast<ImpegnoLavorativo*>(index->info);
        if(implav)
        {
            if(implav->ClienteMatch(a))
                result=result+implav->getMoney();
        }
        index=index->next;
    }
    return result;
}
void Lista::add(Impegno* a){
    smartp nuovo( new Nodo(a,first));//smartp temporaneo
    first=nuovo;
}
void Lista::remove(const Impegno& a){
    smartp tmp=first ,tmp1;
    while(tmp!=0){
        if((tmp->info)->EqualTo(a)){
            if(tmp==first)
                first=tmp->next;
            else
                tmp1->next=tmp->next;
            //delete &tmp;//al termine della funzione si cancella automaticamente (deallocando tmp se il nodo non haaltri puntatori verrà deaalocto a sua volta)
            return;
        }
        tmp1=tmp;
        tmp=tmp->next;
    }
}

Lista::Lista():first(0){}

void Lista::addList(const Lista& a){
    if(a.first==0)
        return;

    smartp tmp=a.first;

    while(tmp->next!=0)
        tmp=tmp->next;
    tmp->next=first;
    first=a.first;
}

Lista::~Lista(){
    DeleteFromNode(first);
}

void Lista::DeleteFromNode(smartp a){
    if(a!=0){
        DeleteFromNode(a->next);
        delete &a;
    }
    return;
}

bool Lista::remove(int pos){
    smartp tmp=first ,tmp1;
    while(tmp!=0){
        if(pos==0){
            if(tmp==first)
                first=tmp->next;
            else
                tmp1->next=tmp->next;
            //delete &tmp;//al termine della funzione si cancella automaticamente (deallocando tmp se il nodo non haaltri puntatori verrà deaalocto a sua volta)
            return true;
        }
        tmp1=tmp;
        tmp=tmp->next;
        pos--;
    }
    return false;
}
