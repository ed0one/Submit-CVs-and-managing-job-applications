#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <conio.h>
#include <bits/stdc++.h>

using namespace std;

struct CV
{
    string nume;
    string prenume;
    string email;
    string telefon;
    string varsta;
    string experienta;
    string educatie;
    string limbi;
    string abilitati;
    string proiecte;
    string hobby;
};

string adminPassword = "admin123";

void salvare_parola_admin(const string &parola)
{
    ofstream fout("parola_admin.txt");
    fout << parola;
    fout.close();
}

void modificare_parola_admin(string &parola)
{
    string parola_veche, parola_noua;
    cout << "Introduceti parola veche: ";
    cin >> parola_veche;
    if (parola_veche == parola)
    {
        cout << "Introduceti parola noua: ";
        cin >> parola_noua;
        parola = parola_noua;
        cout << "Parola a fost schimbata" << endl;
        salvare_parola_admin(parola);
    }
    else
    {
        cout << "Parola incorecta" << endl;
    }
}

void citire_parola_admin(string &parola)
{
    ifstream fin("parola_admin.txt");
    fin >> parola;
    fin.close();
}

void resetare_parola_admin(string &parola)
{
    adminPassword = "admin123";
    parola = adminPassword;
    cout << "Parola a fost resetata" << endl;
    salvare_parola_admin(parola);
}

void citireCV(vector<CV> &cv)
{
    ifstream fin("CV.txt");
    string line;
    while (getline(fin, line))
    {
        CV c;
        c.nume = line;
        getline(fin, c.prenume);
        getline(fin, c.email);
        getline(fin, c.telefon);
        getline(fin, c.varsta);
        getline(fin, c.experienta);
        getline(fin, c.educatie);
        getline(fin, c.limbi);
        getline(fin, c.abilitati);
        getline(fin, c.proiecte);
        getline(fin, c.hobby);
        cv.push_back(c);
    }
    fin.close();
}

void afisareCV(const vector<CV> &cv)
{
    for (const auto &c : cv)
    {
        cout << "Nume: " << c.nume << endl;
        cout << "Prenume: " << c.prenume << endl;
        cout << "E-mail: " << c.email << endl;
        cout << "Nr. de telefon: " << c.telefon << endl;
        cout << "Varsta: " << c.varsta << endl;
        cout << "Experienta: " << c.experienta << endl;
        cout << "Educatie: " << c.educatie << endl;
        cout << "Limbi straine: " << c.limbi << endl;
        cout << "Abilitati: " << c.abilitati << endl;
        cout << "Proiecte: " << c.proiecte << endl;
        cout << "Hobby-uri: " << c.hobby << endl;
    }
}

void modificareCV(vector<CV> &cv, const string &email)
{
    for (auto &c : cv)
    {
        if (c.email == email)
        {
            cout << "Introduceti noile date pentru CV-ul lui " << c.nume << " " << c.prenume << endl;
            cin.ignore();
            cout << "Nume: ";
            getline(cin, c.nume);
            cout << "Prenume: ";
            getline(cin, c.prenume);
            cout << "Email: ";
            getline(cin, c.email);
            cout << "Telefon: ";
            getline(cin, c.telefon);
            cout << "Varsta: ";
            getline(cin, c.varsta);
            cout << "Experienta: ";
            getline(cin, c.experienta);
            cout << "Educatie: ";
            getline(cin, c.educatie);
            cout << "Limbi straine: ";
            getline(cin, c.limbi);
            cout << "Abilitati: ";
            getline(cin, c.abilitati);
            cout << "Proiecte: ";
            getline(cin, c.proiecte);
            cout << "Hobby: ";
            getline(cin, c.hobby);
        }
    }
}

void stergereCV(vector<CV> &cv, const string &email)
{
    for (auto it = cv.begin(); it != cv.end(); ++it)
    {
        if (it->email == email)
        {
            cv.erase(it);
            cout << "CV-ul a fost sters" << endl;
            return;
        }
    }
    cout << "CV-ul nu a fost gasit" << endl;
}

void sortareCV(vector<CV> &cv)
{
    int optiune;
    cout << "Sortare dupa:" << endl;
    cout << "1. Nume" << endl;
    cout << "2. Prenume" << endl;
    cout << "3. Varsta" << endl;
    cout << "4. Experienta" << endl;
    cout << "5. Educatie" << endl;
    cout << "6. Email" << endl;
    cout << "7. Telefon" << endl;
    cout << "8. Limbi straine" << endl;
    cout << "Optiune: ";
    cin >> optiune;
    switch (optiune)
    {
    case 1:
        sort(cv.begin(), cv.end(), [](const CV &a, const CV &b)
             { return a.nume < b.nume; });
        break;
    case 2:
        sort(cv.begin(), cv.end(), [](const CV &a, const CV &b)
             { return a.prenume < b.prenume; });
        break;
    case 3:
        sort(cv.begin(), cv.end(), [](const CV &a, const CV &b)
             { return a.varsta < b.varsta; });
        break;
    case 4:
        sort(cv.begin(), cv.end(), [](const CV &a, const CV &b)
             { return a.experienta < b.experienta; });
        break;
    case 5:
        sort(cv.begin(), cv.end(), [](const CV &a, const CV &b)
             { return a.educatie < b.educatie; });
        break;
    case 6:
        sort(cv.begin(), cv.end(), [](const CV &a, const CV &b)
             { return a.email < b.email; });
        break;
    case 7:
        sort(cv.begin(), cv.end(), [](const CV &a, const CV &b)
             { return a.telefon < b.telefon; });
        break;
    case 8:
        sort(cv.begin(), cv.end(), [](const CV &a, const CV &b)
             { return a.limbi < b.limbi; });
        break;
    default:
        cout << "Optiune invalida" << endl;
        break;
    }
}

void salvareCV(const vector<CV> &cv)
{
    ofstream fout("CV.txt");
    for (const auto &c : cv)
    {
        fout << c.nume << endl;
        fout << c.prenume << endl;
        fout << c.email << endl;
        fout << c.telefon << endl;
        fout << c.varsta << endl;
        fout << c.experienta << endl;
        fout << c.educatie << endl;
        fout << c.limbi << endl;
        fout << c.abilitati << endl;
        fout << c.proiecte << endl;
        fout << c.hobby << endl;
    }
    fout.close();
}

void admin_adauga_job()
{
    string job;
    cout << "Introduceti jobul pe care doriti sa il adaugati: ";
    cin.ignore();
    getline(cin, job);
    ofstream fout("joburi.txt", ios::app);
    fout << job << endl;
    fout.close();
    cout << "Jobul a fost adaugat" << endl;
}

void admin_modifica_job()
{
    string job_vechi, job_nou;
    cout << "Introduceti jobul pe care doriti sa il modificati: ";
    cin.ignore();
    getline(cin, job_vechi);
    cout << "Introduceti noul job: ";
    getline(cin, job_nou);
    ifstream fin("joburi.txt");
    ofstream fout("joburi_temp.txt");
    string job;
    while (getline(fin, job))
    {
        if (job == job_vechi)
        {
            fout << job_nou << endl;
        }
        else
        {
            fout << job << endl;
        }
    }
    fin.close();
    fout.close();
    remove("joburi.txt");
    rename("joburi_temp.txt", "joburi.txt");
    cout << "Jobul a fost modificat" << endl;
}

void admin_sterge_job()
{
    string job;
    cout << "Introduceti jobul pe care doriti sa il stergeti: ";
    cin.ignore();
    getline(cin, job);
    ifstream fin("joburi.txt");
    ofstream fout("joburi_temp.txt");
    string j;
    while (getline(fin, j))
    {
        if (j != job)
        {
            fout << j << endl;
        }
    }
    fin.close();
    fout.close();
    remove("joburi.txt");
    rename("joburi_temp.txt", "joburi.txt");
    cout << "Jobul a fost sters" << endl;
}

void admin_optiuni()
{
    int optiune;
    string parola_admin;
    citire_parola_admin(parola_admin);
    cout << "Introduceti parola de admin: ";
    cin.ignore();
    cin >> parola_admin;
    if (parola_admin == adminPassword)
    {
        cout << "1. Adaugare job" << endl;
        cout << "2. Modificare job" << endl;
        cout << "3. Stergere job" << endl;
        cout << "4. Schimbare parola" << endl;
        cout << "5. Resetare parola" << endl;
        cout << "Optiune: ";
        cin >> optiune;
        switch (optiune)
        {
        case 1:
            admin_adauga_job();
            break;
        case 2:
            admin_modifica_job();
            break;
        case 3:
            admin_sterge_job();
            break;
        case 4:
            modificare_parola_admin(parola_admin);
            break;
        case 5:
            resetare_parola_admin(parola_admin);
            break;
        default:
            cout << "Optiune invalida" << endl;
            break;
        }
    }
    else
    {
        cout << "Parola incorecta" << endl;
    }
}

void adaugareCV(vector<CV> &cv)
{
    CV c;
    cout << "Nume: ";
    cin.ignore();
    getline(cin, c.nume);
    cout << "Prenume: ";
    getline(cin, c.prenume);
    cout << "Email: ";
    getline(cin, c.email);
    cout << "Telefon: ";
    getline(cin, c.telefon);
    cout << "Varsta: ";
    getline(cin, c.varsta);
    cout << "Experienta: ";
    getline(cin, c.experienta);
    cout << "Educatie: ";
    getline(cin, c.educatie);
    cout << "Limbi straine: ";
    getline(cin, c.limbi);
    cout << "Abilitati: ";
    getline(cin, c.abilitati);
    cout << "Proiecte: ";
    getline(cin, c.proiecte);
    cout << "Hobby: ";
    getline(cin, c.hobby);
    cv.push_back(c);
    cout << "CV-ul a fost adaugat" << endl;
}

int main()
{
    vector<CV> cv;
    citireCV(cv);
    int optiune;
    do
    {
        cout << "1. Adaugare CV" << endl;
        cout << "2. Afisare CV-uri" << endl;
        cout << "3. Modificare CV" << endl;
        cout << "4. Stergere CV" << endl;
        cout << "5. Sortare CV-uri" << endl;
        cout << "6. Salvare CV-uri" << endl;
        cout << "7. Optiuni admin" << endl;
        cout << "0. Iesire" << endl;
        cout << "Optiune: ";
        cin >> optiune;
        switch (optiune)
        {
        case 1:
            adaugareCV(cv);
            break;
        case 2:
            afisareCV(cv);
            break;
        case 3:
        {
            string email;
            cout << "Introduceti emailul CV-ului de modificat: ";
            cin >> email;
            modificareCV(cv, email);
            break;
        }
        case 4:
        {
            string email;
            cout << "Introduceti emailul CV-ului de sters: ";
            cin >> email;
            stergereCV(cv, email);
            break;
        }
        case 5:
            sortareCV(cv);
            break;
        case 6:
            salvareCV(cv);
            break;
        case 7:
            admin_optiuni();
            break;
        case 0:
            break;
        default:
            cout << "Optiune invalida" << endl;
            break;
        }
    } while (optiune != 0);
    return 0;
}
