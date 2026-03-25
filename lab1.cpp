#include <iostream>
#include <cstdlib>

using namespace std;

void wypelnijbosmiecisiedrukujo (string*tabnazwiska, string*tabimie, int*tabnum, bool*tabobec){
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
}

void ustawobecnosc(string*tabnazwiska, bool*tabobecnosc, string nazwisko, bool obecnosc){
    for (int i=0; i<10; i++){
        if (tabnazwiska[i] == nazwisko){
            tabobecnosc[i] = obecnosc;
            break;
        }else{
            cout << "brak osoby o takim nazwisku na liscie" << endl;
            break;
        }
    }
}

void dodajosobe(string*tabnazwiska, string*tabimie,int*tabnum , string nazwisko, string imie ,int numer){
    for (int i = 0; i<10; i++){
        if (tabnazwiska[i] == ""){
            tabnazwiska[i] = nazwisko;
            tabimie[i] = imie;
            tabnum[i] = numer;
            break;
        }
    }
}

void drukujliste(string*tabnazwiska, string*tabimie, int*tabnum, bool*tabobecnosc){
    for (int i=0; i<10; i++){
        cout << tabnum[i] << " ";
        cout << tabnazwiska[i]<< " ";
        cout << tabimie[i] << " ";
        cout << tabobecnosc[i] << " ";
        cout << endl;
    }
}

void edycja(string*tabnazwiska, string*tabimie, int*tabnum, int nowynum, string noweimie, string nowenazwisko,int number){
    if (nowynum!=0){
        tabnum[number] = nowynum;
    }
    else if(noweimie!=""){
        tabimie[number] = noweimie;
    }
    else if(nowenazwisko!=""){
        tabnazwiska[number] = nowenazwisko;
    }else{
        cout << "blad edycji" << endl;
    }
}

void usuwanie(string*tabnazwiska, string*tabimie, int*tabnum, bool*tabobecnosc,string nazwusun){
    int j = 0;
    for(int i = 0; i < 10; i++){
        if (tabnazwiska[i] == nazwusun){
        j = i;
        }
    }
        for (j; j < 9 ; j ++){
            tabimie[j] = tabimie[j+1];
        tabnum[j] = tabnum[j+1];
        tabnazwiska[j] = tabnazwiska[j+1];
        }
}

int main() {
    int choice = 1;
    string tabnazwiska[10];
    string tabimie[10];
    int tabnum[10];
    bool tabobecnosc[10];
    wypelnijbosmiecisiedrukujo(tabnazwiska,tabimie,tabnum,tabobecnosc);
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
            if (tabnazwiska[9]!=""){
                cout << "lista jest pelna" << endl;
                break;
            }
            string nowenazwisko;
            string noweimie;
            int numer;
            cout << "podaj nazwisko nowej osoby: ";
            cin >> nowenazwisko;
            cout << "podaj imie nowej osoby: ";
            cin >> noweimie;
            cout << "podaj numer indeksu nowej ososby: ";
            cin >> numer;
            dodajosobe(tabnazwiska,tabimie,tabnum,nowenazwisko,noweimie,numer);
            break;
        }
        case 2:{
            string nazwisko;
            bool obeecnosc;
            cout << "podaj nazwisko osoby: " << endl;
            cin >> nazwisko;
            cout << "czy jest obecna?" << endl;
            cin >> obeecnosc;
            ustawobecnosc(tabnazwiska, tabobecnosc, nazwisko, obeecnosc);
            break;
        }
        case 3:{
            drukujliste(tabnazwiska,tabimie,tabnum,tabobecnosc);
            break;
        }
        case 4:{
            int edyt;
            int nowynum = 0;
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
            edycja(tabnazwiska,tabimie,tabnum,nowynum,noweimie,nowenazwisko,select);
        }
        case 5:{
            string nazwisko;
            cout << "podaj nazwisko osoby ktora chcesz usunoc: ";
            cin >> nazwisko;
            usuwanie(tabnazwiska,tabimie,tabnum,tabobecnosc,nazwisko);
            break;
        }
        default:{
            break;}
        }
        //system("cls");
    }
}