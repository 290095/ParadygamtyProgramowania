#include <iostream>
#include <cstdlib>

using namespace std;

class Osoba{
    private:
    string imie;
    string nazwisko;
    string indeks;
    public:
    void setimie(string);
    string getimie();
    void setnazwisko(string);
    string getnazwisko();
    void setindeks(string);
    string getindeks();
};
void Osoba::setimie(string _imie){
    if (imie.size() > 2){
        imie = _imie;
    }
}
void Osoba::setnazwisko(string _nazwisko){
    if (nazwisko.size() > 2){
        nazwisko = _nazwisko;
    }
}
void Osoba::setindeks(string _indeks){
    if (indeks.size() == 6){
        indeks = _indeks;
    }
}
string Osoba::getimie(){
    return imie;
}
string Osoba::getnazwisko(){
    return nazwisko;
}
string Osoba::getindeks(){
    return indeks;
}

/*void wypelnijbosmiecisiedrukujo (string*tabnazwiska, string*tabimie, int*tabnum, bool*tabobec){
    for (int i=0; i<10; i++){
        tabnum[i] = 0;
    }
    for (int i=0; i<10; i++){
        tabimie[i] = "";
    }
    for (int i=0; i<10; i++){
        tabnazwiska[i] = "";
    }
    for (int i=0; i<10; i++){
        tabobec[i] = 0;
    }
}*/

void ustawobecnosc(Osoba*os, bool*tabobecnosc, string nazwisko, bool obecnosc){
    for (int i=0; i<10; i++){
        if (os[i].getnazwisko() == nazwisko){
            tabobecnosc[i] = obecnosc;
            break;
        }else{
            cout << "brak osoby o takim nazwisku na liscie" << endl;
            break;
        }
    }
}

void dodajosobe(Osoba*os, string nazwisko, string imie ,string numer){
    for (int i = 0; i<10; i++){
        if (os[i].getimie() == ""){
            os[i].setnazwisko(nazwisko);
            os[i].setimie(imie);
            os[i].setindeks(numer);
            break;
        }
    }
}

void drukujliste(Osoba*os, bool*tabobecnosc){
    for (int i=0; i<10; i++){
        cout << os[i].getimie() << " ";
        cout << os[i].getnazwisko()<< " ";
        cout << os[i].getindeks() << " ";
        cout << tabobecnosc[i] << " ";
        cout << endl;
    }
}

void edycja(Osoba*os, string nowynum, string noweimie, string nowenazwisko,int number){
    if (nowynum!=""){
        os[number].setindeks(nowynum);
    }
    else if(noweimie!=""){
        os[number].getimie() = noweimie;
    }
    else if(nowenazwisko!=""){
        os[number].getnazwisko() = nowenazwisko;
    }else{
        cout << "blad edycji" << endl;
    }
}

void usuwanie(Osoba*os, bool*tabobecnosc,string nazwusun){
    int j = 0;
    for(int i = 0; i < 10; i++){
        if (os[i].getnazwisko() == nazwusun){
        j = i;
        }
    }
        for (j; j < 9 ; j ++){
            os[j].setimie(os[j+1].getimie());
        os[j].setindeks(os[j+1].getindeks());
        os[j].setnazwisko(os[j+1].getnazwisko());
        }
}

int main() {
    Osoba os[10];
    int choice = 1;
//    string tabnazwiska[10];
//    string tabimie[10];
//    int tabnum[10];
    bool tabobecnosc[10];
//    wypelnijbosmiecisiedrukujo(tabnazwiska,tabimie,tabnum,tabobecnosc);
    while (choice !=0){
        cout << "wybierz akcje"<< endl;
        cout << "1 - dodaj ososbe" << endl;
        cout << "2 - ustaw obecnosc"  << endl;
        cout << "3 - wydrukuj liste" << endl;
        cout << "4 - zedytuj liste" << endl;
        cout << "5 - usun osobe z listy" << endl;
        cout << "0 - zakoncz program" << endl;
        cin >> choice;
        switch (choice)
        {
        case 1:{
            if (os[9].getimie()!=""){
                cout << "lista jest pelna" << endl;
                break;
            }
            string nowenazwisko;
            string noweimie;
            string numer;
            cout << "podaj nazwisko nowej osoby: ";
            cin >> nowenazwisko;
            cout << "podaj imie nowej osoby: ";
            cin >> noweimie;
            cout << "podaj numer indeksu nowej ososby: ";
            cin >> numer;
            dodajosobe(os,nowenazwisko,noweimie,numer);
            break;
        }
        case 2:{
            string nazwisko;
            bool obeecnosc;
            cout << "podaj nazwisko osoby: " << endl;
            cin >> nazwisko;
            cout << "czy jest obecna?" << endl;
            cin >> obeecnosc;
            ustawobecnosc(os, tabobecnosc, nazwisko, obeecnosc);
            break;
        }
        case 3:{
            drukujliste(os,tabobecnosc);
            break;
        }
        case 4:{
            int edyt;
            string nowynum = 0;
            int select = 0;
            string nowenazwisko = "";
            string noweimie = "";
            cout << "co chcesz zedytowac?: " << endl;
            cout << "1 - numer inedksu" << endl;
            cout << "2 - imie" << endl;
            cout << "3 - nazwisko" << endl;
            cin >> edyt;
            cout << "podaj numer osoby(od gory od 0) ktora chcesz zedytowac: ";
            cin >> select;
            switch (edyt)
            {
            case 1:{
                cout << "podaj nowy numer: ";
                cin >> nowynum;
                break;
            }
            case 2:{
                cout << "podaj nowe imie: ";
                cin >> noweimie;
                break; 
            }
            case 3:{
                cout << "podaj nowe nazwisko: ";
                cin >> nowenazwisko;
                break;
            }
            default:
                break;
            }
            edycja(os,nowynum,noweimie,nowenazwisko,select);
        }
        case 5:{
            string nazwisko;
            cout << "podaj nazwisko osoby ktora chcesz usunoc: ";
            cin >> nazwisko;
            usuwanie(os,tabobecnosc,nazwisko);
            break;
        }
        default:{
            break;}
        }
        //system("cls");
    }
}