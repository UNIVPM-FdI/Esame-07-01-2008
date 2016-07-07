#include <iostream>
using namespace std;

struct orario
{ int anno;
short int mese;
short int giorno;
short int ore;
short int min;
};

struct appuntamento{
char titolo[50];
char luogo[30];
orario ora;
appuntamento* succ;
};

typedef appuntamento* lista;

bool anteriore(lista a, appuntamento b);
void inserisci_ordinatamente(lista& inizio, appuntamento e);
void elimina_passati(lista& inizio, appuntamento oggi);
bool uguali(char stringa1[], char stringa2[]);
bool estrai_elem_dato(lista& inizio, appuntamento& e);
void stampaLista(lista inizio);
void leggidati(appuntamento& a);
bool data_meno(lista,appuntamento);

int main()
{
    appuntamento elem;
    lista inizio=0;
    char s;
    do{
        cout<<"i: per inserire un appuntamento"<<endl;
        cout<<"e: per eliminare gli appuntamenti passati"<<endl;
        cout<<"a: per eliminare un particolare appuntamento"<<endl;
        cout<<"s: per stampare la lista degli appuntamenti"<<endl;
        cin>>s;
        switch(s){
        case 'i':{
            leggidati(elem);
            inserisci_ordinatamente(inizio,elem);
        break;
        }
        case 'e':{
            cout<<"inserisci l' anno fin dove eliminare "<<endl;
            cin>>elem.ora.anno;
            elimina_passati(inizio,elem);
        break;
        }
        case 'a':{
            bool risposta;
            cout<<"inserisci il titolo dell appuntamento da eliminare"<<endl;
            cin>>elem.titolo;
            risposta=estrai_elem_dato(inizio,elem);
            if(risposta==true){
                cout<<"appuntamento eliminato"<<endl;
            }
            else cout<<"elemento non presente"<<endl;
        break;
        }
        case 's':{
            stampaLista(inizio);
        break;
        }
        }
    }while(s=='i'||s=='e'||s=='a'||s=='s');
    return 0;
}

void leggidati(appuntamento& a){
cout<<"Titolo: ";
cin>>a.titolo;
cout<<"Luogo: ";
cin>>a.luogo;
cout<<"Anno: ";
cin>>a.ora.anno;
cout<<"Mese: ";
cin>>a.ora.mese;
cout<<"Giorno: ";
cin>>a.ora.giorno;
cout<<"Ora: ";
cin>>a.ora.ore;
cout<<"Minuto: ";
cin>>a.ora.min;
}

void inserisci_ordinatamente(lista& inizio, appuntamento e){
lista p=0,q,r;
for(q=inizio;q!=0&& anteriore(q,e);q=q->succ)
    p=q;
r=new appuntamento;
*r=e;
r->succ=q;
if(q==inizio)inizio=r;
else p->succ=r;
}

bool anteriore(lista a, appuntamento b){
bool flag=false;
if(a->ora.anno<=b.ora.anno)flag=true;{
    if(a->ora.mese<=b.ora.mese) flag=true;{
        if(a->ora.giorno<=b.ora.giorno)flag=true;{
            if(a->ora.ore<=b.ora.ore)flag =true;{
                if(a->ora.min<=b.ora.min)flag=true;{

                }
            }
        }
    }
}
if(flag==true)return true;
else return false;
}

void stampaLista(lista inizio){
if(inizio==0){
    cout<<"lista vuota"<<endl;
}
while(inizio!=0){
    cout<<"Titolo: "<<inizio->titolo<<"\nLuogo: "<<inizio->luogo<<"\nData: "<<inizio->ora.anno<<" "<<inizio->ora.mese<<" "<<inizio->ora.giorno<<" "<<inizio->ora.ore<<":"<<inizio->ora.min<<endl;
    inizio=inizio->succ;
}
}

bool uguali(char stringa1[], char stringa2[]){//questa funzione mi controlla se le due parole sono uguali(serve per eliminare l appuntamento)
bool flag=false;
int i=0;
while(stringa1[i]!='\0'){//scorro il primo vettore fino alla fine
    if(stringa1[i]==stringa2[i]){//controllo se il carattere della stringa1 è uguale al carattere della stringa 2
        flag=true;
        i++;
    }
    else flag=false;
}
if(flag==true)return true;
else return false;
}

bool estrai_elem_dato(lista& inizio, appuntamento& e){//qui uso la procedura di estrazione per togliere l elemento dalla lista in base al nome
    lista p,q;
for (q = inizio; q!=0 && !uguali(q->titolo,e.titolo); q=q->succ)
p = q;
if (q == 0) return false;
if (q == inizio) inizio= q->succ;
else p->succ = q->succ;
e=*q;
delete q;
return true;
}

bool data_meno(lista b,appuntamento f){
bool flag=false;
if(b->ora.anno>=f.ora.anno)flag=true;{
}
if(flag==true)return true;
else return false;
}

void elimina_passati(lista& inizio, appuntamento oggi){
    appuntamento a;
    bool flag=true;
while(inizio!=0&&flag){//scorro la lista dall inizio e la fermo con il flag
if(data_meno(inizio,oggi)){//controllo se le data della lista è minore della data fin dove ho deciso di eliminare epoi faccio l estrazione dalla testa della lista
    lista p=inizio;
    a=*p;
    inizio=p->succ;
    delete p;
    cout<<"ho eliminato " << a.titolo<<endl;
}
else {
    flag=false;
}
inizio=inizio->succ;
}
}

