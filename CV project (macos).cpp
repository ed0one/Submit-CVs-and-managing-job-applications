#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <termios.h>
#include <unistd.h>

void setEcho(bool enable = true)
{
    struct termios tty;
    tcgetattr(STDIN_FILENO, &tty);
    if (!enable)
        tty.c_lflag &= ~ECHO;
    else
        tty.c_lflag |= ECHO;

    (void)tcsetattr(STDIN_FILENO, TCSANOW, &tty);
}
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
            break;
        }
        else if (it == cv.end())
        {
            cout << "CV-ul nu a fost gasit" << endl;
        }
    }
    cout << "CV-ul a fost sters" << endl;
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
    cin >> job;
    ofstream fout("joburi.txt", ios::app);
    fout << job << endl;
    fout.close();
    cout << "Jobul a fost adaugat" << endl;
}

void admin_modifica_job()
{
    string job_vechi, job_nou;
    cout << "Introduceti jobul pe care doriti sa il modificati: ";
    cin >> job_vechi;
    cout << "Introduceti noul job: ";
    cin >> job_nou;
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
    cin >> job;
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

void admin_afisare_joburi()
{
    ifstream fin("joburi.txt");
    string job;
    cout << "Joburi disponibile:" << endl;
    int i = 1;
    while (getline(fin, job))
    {
        cout << i << ". " << job << endl;
        i++;
        cout << endl;
    }
    fin.close();
}

void admin_afisare_cv()
{
    vector<CV> cv;
    citireCV(cv);
    afisareCV(cv);
    cout << endl;
}

void admin_modificare_cv()
{
    vector<CV> cv;
    citireCV(cv);
    string email;
    cout << "Introduceti E-mail ul CV-ului pe care doriti sa il modificati: ";
    cin >> email;
    modificareCV(cv, email);
    salvareCV(cv);
    cout << "CV-ul a fost modificat cu succes" << endl;
}

void admin_stergere_cv()
{
    vector<CV> cv;
    citireCV(cv);
    string email;
    cout << "Introduceti E-mail ul CV-ului pe care doriti sa il stergeti: ";
    cin >> email;
    stergereCV(cv, email);
    salvareCV(cv);
    cout << "CV-ul a fost sters" << endl;
}

void admin_sortare_cv()
{
    vector<CV> cv;
    citireCV(cv);
    sortareCV(cv);
    salvareCV(cv);
}

void stergere_valori()
{
    cout << "Doriti sa stergeti valorile din fisierele CV.txt, joburi.txt si aplicari.txt? (da/nu): ";
    string raspuns;
    cin >> raspuns;
    if (raspuns == "nu")
    {
        return;
    }
    ofstream fout("CV.txt");
    fout.close();
    ofstream fout2("joburi.txt");
    fout2.close();
    ofstream fout3("aplicari.txt");
    fout3.close();
    cout << "Valorile din fisierele CV.txt, joburi.txt si aplicari.txt au fost sterse" << endl;
}

void admin_cautare_cv()
{
    vector<CV> cv;
    citireCV(cv);
    string email;
    cout << "Introduceti E-mail ul CV-ului pe care doriti sa il cautati: ";
    cin >> email;
    cout << "CV-ul cautat este: " << endl;
    for (const auto &c : cv)
    {
        if (c.email == email)
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
            return;
        }
    }
    cout << "CV-ul nu a fost gasit" << endl;
}

void admin_afisare_aplicari()
{
    ifstream fin("aplicari.txt");
    string aplicare;
    while (getline(fin, aplicare))
    {
        cout << aplicare << endl;
    }
    fin.close();
}

void admin()
{
    cout << "Pentru a intra in meniul de admin, introduceti parola mai jos" << endl;
    setEcho(false);
    string parola;
    cout << "Parola: ";
    char ch;
    cin.ignore();
    while (read(STDIN_FILENO, &ch, 1) && ch != '\n')
    {
        parola.push_back(ch);
        cout << '*';
        cout.flush();
    }
    setEcho(true);
    std::cout << "\nParola introdusă: " << parola << std::endl;
    if (parola != adminPassword)
    {
        cout << "Parola incorecta" << endl;
        return;
    }
    system("clear");
    cout << "                       ========= MENIU ADMIN =========" << endl;
    cout << endl;
    cout << "-------------------------------" << endl;
    cout << endl;
    while (true)
    {
        int optiune;
        cout << "1. Adauga job" << endl;
        cout << "2. Modifica job" << endl;
        cout << "3. Sterge job" << endl;
        cout << "4. Afisare joburi" << endl;
        cout << "5. Afisare CV-uri" << endl;
        cout << "6. Afisare aplicari" << endl;
        cout << "7. Modificare CV" << endl;
        cout << "8. Stergere CV" << endl;
        cout << "9. Sortare CV" << endl;
        cout << "10. Cautare CV" << endl;
        cout << "11. Stergere valori" << endl;
        cout << "12. Revenire la meniul principal" << endl;
        cout << endl;
        cout << "-------------------------------" << endl;
        cout << endl;
        cout << "Optiune: ";
        cin >> optiune;
        system("clear");
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
            admin_afisare_joburi();
            break;
        case 5:
            admin_afisare_cv();
            break;
        case 6:
            admin_afisare_aplicari();
            break;
        case 7:
            admin_modificare_cv();
            break;
        case 8:
            admin_stergere_cv();
            break;
        case 9:
            admin_sortare_cv();
            break;
        case 10:
            admin_cautare_cv();
            break;
        case 11:
            stergere_valori();
            break;
        case 12:
            return;
            break;
        default:
            cout << "Optiune invalida" << endl;
            break;
        }
    }
}

void user_afisare_joburi()
{
    ifstream fin("joburi.txt");
    string job;
    cout << "Joburi disponibile:" << endl;
    int i = 1;
    while (getline(fin, job))
    {
        cout << i << ". " << job << endl;
        i++;
        cout << endl;
    }
    fin.close();
}

void user_adauga_cv()
{
    CV c;
    cin.ignore();
    cout << "Introduceti datele pentru CV" << endl;
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
    ofstream fout("CV.txt", ios::app);
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
    fout.close();
    cout << "CV-ul a fost adaugat" << endl;
}

void user_modifica_cv()
{
    vector<CV> cv;
    citireCV(cv);
    string email;
    cout << "Introduceti E-mail ul CV-ului pe care doriti sa il modificati: ";
    cin >> email;
    modificareCV(cv, email);
    salvareCV(cv);
    cout << "CV-ul a fost modificat cu succes" << endl;
}

void user_sterge_cv()
{
    vector<CV> cv;
    citireCV(cv);
    string email;
    cout << "Introduceti E-mail ul CV-ului pe care doriti sa il stergeti: ";
    cin >> email;
    stergereCV(cv, email);
    salvareCV(cv);
    cout << "CV-ul a fost sters" << endl;
}

void user_aplica_job()
{
    CV c;
    ifstream fin("joburi.txt");
    string job;
    while (getline(fin, job))
    {
        cout << job << endl;
    }
    string job_ales;
    cout << "Introduceti jobul la care doriti sa aplicati: ";
    cin >> job_ales;
    ifstream fin1("joburi.txt");
    string j;
    while (getline(fin1, j))
    {
        if (j == job_ales)
        {
            break;
        }
        else if (j != job_ales)
        {
            cout << "Jobul nu exista" << endl;
            return;
        }
    }
    fin1.close();
    string email;
    cout << "Introduceti E-mail ul CV-ului: ";
    cin >> email;
    ifstream fin2("CV.txt");
    string line;
    while (getline(fin2, line))
    {
        if (line == email)
        {
            ofstream fout("aplicari.txt", ios::app);
            fout << "Utilizatorul cu E-mail ul " << email << " a aplicat la jobul " << job_ales << endl;
            fout.close();
            cout << "Aplicarea a fost trimisa" << endl;
            return;
        }
    }
    cout << "CV-ul nu a fost gasit" << endl;
    fin2.close();
    fin.close();
}

void inregistrare_user()
{
    string nume, prenume, email, parola;
    cin.ignore();
    cout << "Introduceti numele: ";
    getline(cin, nume);
    cout << "Introduceti prenumele: ";
    getline(cin, prenume);
    cout << "Introduceti E-mail ul: ";
    cin >> email;
    cout << "Introduceti parola: ";
    cin >> parola;
    ofstream fout("useri.txt", ios::app);
    fout << nume << endl;
    fout << prenume << endl;
    fout << email << endl;
    fout << parola << endl;
    fout.close();
    cout << "Utilizatorul a fost inregistrat" << endl;
}

void user()
{

    cout << "                      ========= MENIU USER =========" << endl;
    cout << endl;
    cout << "-------------------------------" << endl;
    cout << endl;
    while (true)
    {
        int optiune;
        cout << "1. Afisare joburi" << endl;
        cout << "2. Adauga CV" << endl;
        cout << "3. Modificare CV" << endl;
        cout << "4. Stergere CV" << endl;
        cout << "5. Aplica la un job" << endl;
        cout << "6. Revenire la meniul principal" << endl;
        cout << endl;
        cout << "-------------------------------" << endl;
        cout << endl;
        cout << "Optiune: ";
        cin >> optiune;
        system("clear");
        switch (optiune)
        {
        case 1:
            user_afisare_joburi();
            break;
        case 2:
            user_adauga_cv();
            break;
        case 3:
            user_modifica_cv();
            break;
        case 4:
            user_sterge_cv();
            break;
        case 5:
            user_aplica_job();
            break;
        case 6:
            return;
            break;
        default:
            cout << "Optiune invalida" << endl;
            break;
        }
    }
}

void logare_user()
{
    string email, parola;
    cout << "Introduceti E-mail ul: ";
    cin >> email;
    cout << "Introduceti parola: ";
    cin >> parola;
    ifstream fin("useri.txt");
    string line;
    while (getline(fin, line))
    {
        if (line == email)
        {
            getline(fin, line);
            if (line == parola)
            {
                cout << "Logare reusita" << endl;
                system("clear");
                cout << "Salut, " << email << "! Bine ai venit in meniul user" << endl;
                cout << endl;
                user();
                return;
            }
            else
            {
                cout << "Parola incorecta" << endl;
                return;
            }
        }
    }
    cout << "Utilizatorul nu a fost gasit" << endl;
}

void meniu_principal()
{
    cout << "                      ========= MENIU PRINCIPAL =========" << endl;
    cout << endl;
    cout << "-------------------------------------" << endl;
    cout << endl;
    cout << "                           Bine ati venit!" << endl;
    cout << endl;
    cout << "                   Alegeti una din optiunile de mai jos:" << endl;
    cout << endl;
    cout << "-------------------------------------" << endl;
    cout << endl;
    int optiune;
    cout << "1. Admin login" << endl;
    cout << "2. User signup" << endl;
    cout << "3. User login" << endl;
    cout << "4. Schimbare parola admin" << endl;
    cout << "5. Resetare parola admin" << endl;
    cout << "6. Exit" << endl;
    cout << endl;
    cout << "-------------------------------------" << endl;
    cout << endl;
    cout << "Optiune: ";

    cin >> optiune;

    system("clear");
    switch (optiune)
    {
    case 1:
        admin();
        break;
    case 2:
        inregistrare_user();
        break;
    case 3:
        logare_user();
        break;
    case 4:
        modificare_parola_admin(adminPassword);
        break;
    case 5:
        resetare_parola_admin(adminPassword);
        break;
    case 6:
        exit(0);
        break;
    default:
        cout << "Optiune invalida" << endl;
        break;
    }
}

int main()
{
    string parola;
    citire_parola_admin(parola);
    adminPassword = parola;
    while (true)
    {
        meniu_principal();
        cout << "Apasati tasta ENTER pentru a va intoarce la meniul principal" << endl;
        cin.get();
        cin.get();
        system("clear");
    }
    return 0;
}