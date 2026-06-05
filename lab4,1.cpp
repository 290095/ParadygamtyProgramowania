#include <iostream>
#include <cstdlib>

using namespace std;



class Iprzedstawialny {
    public:
    virtual string przedstawsie() = 0;
    //virtual ~Iprzedstawialny() {};
};

class Osoba : public Iprzedstawialny{
    protected:
    string imie;
    string nazwisko;
    public:
    virtual void setIdentyfikator(string) {} 
    virtual string getIdentyfikator() { return ""; }
    virtual ~Osoba() {};
    virtual string przedstawsie() override {
        return imie + " " + nazwisko;
    }
    void setimie(string);
    string getimie();
    void setnazwisko(string);
    string getnazwisko();
};
void Osoba::setimie(string _imie){
    if (_imie.size() > 2 or _imie==""){
        imie = _imie;
    }
}
void Osoba::setnazwisko(string _nazwisko){
    if (_nazwisko.size() > 2 or _nazwisko == ""){
        nazwisko = _nazwisko;
    }
}
string Osoba::getimie(){
    return imie;
}
string Osoba::getnazwisko(){
    return nazwisko;
}


class Student: public Osoba {
    private:
        string indeks;
    public:
        void setIdentyfikator(string _indeks) override { setindeks(_indeks); }
        string getIdentyfikator() override { return getindeks(); }
        void setindeks(string);
        string getindeks();
        string przedstawsie() override {
        return imie + " " + nazwisko + " [Indeks: " + indeks + "]";
    }
};
string Student::getindeks() {
    return indeks;
}
void Student::setindeks(string _indeks){
    if (_indeks.size() == 6 or _indeks == ""){
        indeks = _indeks;
    }
}


class Pracownik: public Osoba {
    private:
        string id;
    public:
        void setIdentyfikator(string _id) override { setid(_id); }
        string getIdentyfikator() override { return getid(); }
        void setid(string);
        string getid();
        string przedstawsie() override {
        return imie + " " + nazwisko + " [ID Pracownika: " + id + "]";
    }
};
void Pracownik::setid(string _id){
    if (_id.size() == 6 or _id == ""){
        id = _id;
    }
}string Pracownik::getid() {
    return id;
}


class Listaobecnosci{
    private:
        Osoba* os[10];
        bool tabobecnosc[10];
    public:
    Listaobecnosci() {
        for (int i = 0; i < 10; i++) {
            os[i] = nullptr;
            tabobecnosc[i] = false;
        }
    }

    ~Listaobecnosci() {
        for (int i = 0; i < 10; i++) {
            if (os[i] != nullptr) {
                delete os[i];
            }
        }
    }
        void ustawobecnosc(string nazwisko, bool obecnosc){
            bool znaleziono = 0;
            for (int i=0; i<10; i++){   
                if (os[i] != nullptr && os[i]->getnazwisko() == nazwisko){
                tabobecnosc[i] = obecnosc;
                znaleziono = 1;
                break;
                } 
            }
            if(!znaleziono){
                cout << "brak osoby o takim nazwisku na liscie" << endl;
                }
        }
        void dodajosobe(string nazwisko, string imie ,string numer){      
            if (os[9] != nullptr) {
            cout << "lista jest pelna" << endl;
                }else{
                
                for (int i = 0; i<10; i++){
                    if (os[i] == nullptr){
                        Student* nowyStudent = new Student();
                        nowyStudent->setnazwisko(nazwisko);
                        nowyStudent->setimie(imie);
                        nowyStudent->setindeks(numer);
                        os[i] = nowyStudent;
                        tabobecnosc[i] = 0;
                        break;
                    }
                }
            }
        }
        void drukujliste() {
    for (int i = 0; i < 10; i++) {
        if (os[i] != nullptr) {
            cout << os[i]->przedstawsie() << " | " << tabobecnosc[i] << endl;
        }
    }
}
        void edycja(string nowynum, string noweimie, string nowenazwisko,int number){
            if (number < 0 || number >= 10 || os[number] == nullptr) {
                cout << "Blad! Brak osoby pod tym numerem." << endl;
                return;
            }
            if (nowynum!=""){
                os[number]->setIdentyfikator(nowynum);
            }
            else if(noweimie!=""){
                os[number]->setimie(noweimie);
            }
            else if(nowenazwisko!=""){
                os[number]->setnazwisko(nowenazwisko);
         }else{
                cout << "blad edycji" << endl;
            }
        }
        void usuwanie(string nazwusun){
            int j = -1;
            for(int i = 0; i < 10; i++){
                if (os[i] != nullptr && os[i]->getnazwisko() == nazwusun) {
                    j = i;
                    break;
                }
            }   
            if(j!=-1){
                for (j; j < 9; j ++){
                    os[j] = os[j+1];
                    tabobecnosc[j] = tabobecnosc[j+1];
                }
                os[9] = nullptr; 
                tabobecnosc[9] = false;
        }else{
            cout << "nieznaleziono takiej osoby na lisie"<< endl;
        }
        }
};

class interfejs{
public:
    void menu(Listaobecnosci &lista){
            int choice = 1;
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
            string nowenazwisko;
            string noweimie;
            string numer;
            cout << "podaj nazwisko nowej osoby: ";
            cin >> nowenazwisko;
            cout << "podaj imie nowej osoby: ";
            cin >> noweimie;
            cout << "podaj numer indeksu nowej ososby: ";
            cin >> numer;
            lista.dodajosobe(nowenazwisko,noweimie,numer);
            break;
        }
        case 2:{
            string nazwisko;
            bool obecnosc;
            cout << "podaj nazwisko osoby: " << endl;
            cin >> nazwisko;
            cout << "czy jest obecna?" << endl;
            cin >> obecnosc;
            lista.ustawobecnosc(nazwisko, obecnosc);
            break;
        }
        case 3:{
            lista.drukujliste();
            break;
        }
        case 4:{
            int edyt;
            string nowynum = "";
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
            lista.edycja(nowynum,noweimie,nowenazwisko,select);
            break;
        }
        case 5:{
            string nazwisko;
            cout << "podaj nazwisko osoby ktora chcesz usunoc: ";
            cin >> nazwisko;
            lista.usuwanie(nazwisko);
            break;
        }
        default:{
            break;}
        }
        //system("cls");
    }
    }

};


int main() {
    string wybranalista = "";
    Listaobecnosci lista1, lista2;
    interfejs inter;
    cout << "na ktorej liscie chcesz pracowac?" << endl;
    cin >> wybranalista;
if (wybranalista=="1"){
    inter.menu(lista1);
}else if (wybranalista =="2"){
    inter.menu(lista2);
}
}