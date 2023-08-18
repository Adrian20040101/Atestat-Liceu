#include<iostream>
#include<fstream>
#include<iomanip>
#include<conio.h>
#include<string.h>
#include<windows.h>

using namespace std;

struct angajat{
char nume[50];
char prenume[50];
int varsta;
float salariu;
};

struct camera{
int numar;
char tip[10];
float cost;
};

struct client{
char nume2[50];
char prenume2[50];
float recenzie;
char sugestie[200];
char reclamatie[200];
};

    int n;
    int m;
    int p;
    angajat v[100];
    camera c[100];
    client d[100];

void culoare(int culoare)
{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), culoare);
}

void curatare_ecran()
{
    system("cls");
}

void separare(int m)
{
    for (int j=1;j<=m;j++)
            cout<<"=";
            cout<<endl;
            cout<<endl;
}

void afisare_angajat(int i)
    {
        cout<<"Angajatul: "<<i<<endl;
        cout<<"Date personale: "<<endl;
        cout<<"Nume: "<<v[i].nume<<endl;
        cout<<"Prenume: "<<v[i].prenume<<endl;
        if (v[i].varsta>20)
        cout<<"Varsta: "<<v[i].varsta<<" de ani"<<endl;
        else
        cout<<"Varsta: "<<v[i].varsta<<" ani"<<endl;
        cout<<"Salariul: "<<v[i].salariu<<" lei"<<endl;
        separare(30);
    }

void afisare ()
{
    if (n>1)
    {
        cout<<"Aceasta este lista cu cei "<<n<<" angajati"<<endl<<endl;
        for (int i=1;i<=n;i++)
        afisare_angajat(i);
    }
    else if (n==1)
    {
        cout<<"Acesta este angajatul din baza de date"<<endl<<endl;
        for (int i=1;i<=n;i++)
        afisare_angajat(i);
    }
        if (n==0)
            cout<<"Nu exista angajati in baza de date! Adaugati angajati pentru a-i putea afisa!"<<endl<<endl;
}




void cautare()
{
    int sem=0;
    char s[50];
    int ct=0;
    int index_angajat;

    cout<<"Aceasta este lista cu cei "<<n<<" angajati"<<endl<<endl;
    for (int i=1;i<=n;i++)
    {
        afisare_angajat(i);
    }


    cout<<"Introduceti numele angajatului: "<<endl;
    cin>>s;
    for (int i=0;i<strlen(s);i++)
        if (s[i]==s[0])
        if(s[i]>='a' && s[i]<='z')
        s[0]=s[0]-32;
    curatare_ecran();
    for(int i=1;i<=n;i++){
      if (strcmp(v[i].nume,s)==0)
        ct++;
    }
            if (ct==1)
        {
           cout<<"Angajatul cautat se afla in baza de date! Mai jos se gasesc informatiile sale: "<<endl<<endl;
        }

        if (ct >= 2)
        {
            cout<<"Angajatii cautati se afla in baza de date! Mai jos se gasesc informatiile lor: "<<endl<<endl;
        }
    for(int i=1;i<=n;i++)
    {
        if (strcmp(v[i].nume,s)==0)
        {
            afisare_angajat(i);
        }
    }

       for (int i=0;i<strlen(s);i++)
        if (s[i]==s[0])
        if(s[i]>='a' && s[i]<='z')
        s[0]=s[0]-32;

            if (ct==0)
                cout<<"Angajatul cu numele "<<s<<" nu se afla in baza de date"<<endl;
    }


// -------------------------------------------------------------------------------------------------------------------------------------------------
    void adaugare()
    {

                char raspuns[10];
                int ok=0;
                int index_angajat;
                do
                {

        cout<<"Introduceti informatiile noului angajat: "<<endl<<endl;
        cout<<"Nume: ";
        cin>>v[n+1].nume;
        cout<<endl;
        cout<<"Prenume: ";
        cin>>v[n+1].prenume;
        cout<<endl;

         for (int i=1;i<=n;i++)
            for (int i=n;i>=1;i--)
             if (strcmp(v[i].nume,v[n+1].nume)==0)
                if (strcmp(v[i].prenume,v[n+1].prenume)==0)
                {
                    do
                    {
                        ok=1;
                        cout<<"Angajatul se afla deja in baza de date!"<<endl;
                        cout<<"Asigurati-va ca angajatul nu se afla deja in baza de date si introduceti informatiile acestuia!"<<endl<<endl;;
                        cout<<"Nume: ";
                        cin>>v[n+1].nume;
                        cout<<endl;
                        cout<<"Prenume: ";
                        cin>>v[n+1].prenume;
                        cout<<endl;
                    }while (strcmp(v[i].nume,v[n+1].nume)==0 && strcmp(v[i].prenume,v[n+1].prenume)==0);
                    ok=0;
                }
                if (ok==0)
                {
        cout<<"Varsta: ";
        cin>>v[n+1].varsta;
        curatare_ecran();
        cout<<"Introduceti informatiile noului angajat: "<<endl<<endl;
        cout<<"Nume: "<<v[n+1].nume<<endl<<endl;
        cout<<"Prenume: "<<v[n+1].prenume<<endl<<endl;
        if (v[n+1].varsta>19)
        cout<<"Varsta: "<<v[n+1].varsta<<" de ani"<<endl;
        else
        cout<<"Varsta: "<<v[n+1].varsta<<" ani"<<endl;
        if (v[n+1].varsta>69 || v[n+1].varsta<18)
        do
        {
            cout<<"Ati introdus o varsta care nu este eligibila pentru un angajat!"<<endl;
            cout<<"Introduceti varsta noului angajat, care sa fie cuprinsa intre 18-69"<<endl;
            cin>>v[n+1].varsta;
        }while (v[n+1].varsta>69 || v[n+1].varsta<18);
        cout<<endl;
        cout<<"Salariul: ";
        cin>>v[n+1].salariu;
        curatare_ecran();
        cout<<"Introduceti informatiile noului angajat: "<<endl<<endl;
        cout<<"Nume: "<<v[n+1].nume<<endl<<endl;
        cout<<"Prenume: "<<v[n+1].prenume<<endl<<endl;
        if (v[n+1].varsta>19)
        cout<<"Varsta: "<<v[n+1].varsta<<" de ani"<<endl<<endl;
        else
        cout<<"Varsta: "<<v[n+1].varsta<<" ani"<<endl<<endl;
        cout<<"Salariul: "<<v[n+1].salariu<<" lei"<<endl;
        cout<<endl;

            cout<<"Confirmati ca doriti adaugarea angajatului introdus? (da/nu)"<<endl;
                cin>>raspuns;
                cout<<endl;
                if (strcmp(raspuns,"da")==0 || strcmp(raspuns,"Da")==0 || strcmp(raspuns,"DA")==0)
                    ok=0;
                if (strcmp(raspuns,"nu")==0 || strcmp(raspuns,"Nu")==0 || strcmp(raspuns,"NU")==0)
                    ok=1;
                    if (ok==1)
                    {
                     cout<<"Ati renuntat la adaugarea noului angajat!"<<endl;
                     break;

                    }
            if (ok==0)
            {
                n++;
                 curatare_ecran();

                 if (strcmp(raspuns,"da")==0 || strcmp(raspuns,"Da")==0 || strcmp(raspuns,"DA")==0)
                 {
                      cout<<"Aceasta este lista noua cu cei "<<n<<" angajati, iar angajatul nou introdus este evidentiat prin culoare: "<<endl<<endl;
                    for (int i=1;i<n;i++)
                    afisare_angajat(i);
                    for (int i=1;i<=n;i++)
                    if (i==n)
                    {
                        index_angajat=i;
                        culoare(3);
                        afisare_angajat(index_angajat);
                        culoare(7);
                    }
                    cout<<"Doriti sa adaugati alti angajati? (da/nu)"<<endl;
                 cin>>raspuns;
                 cout<<endl;
                 curatare_ecran();
                 if (strcmp(raspuns,"da")==0 || strcmp(raspuns,"Da")==0 || strcmp(raspuns,"DA")==0)
                    ok=0;

                 }

                    if (strcmp(raspuns,"nu")==0 || strcmp(raspuns,"Nu")==0 || strcmp(raspuns,"NU")==0)
                    {

                        cout<<"Aceasta este lista noua cu cei "<<n<<" angajati, iar angajatul nou introdus este evidentiat prin culoare: "<<endl<<endl;
                        for (int i=1;i<n;i++)
                        afisare_angajat(i);
                        for (int i=1;i<=n;i++)
                        if (i==n)
                        {
                        index_angajat=i;
                        culoare(3);
                        afisare_angajat(index_angajat);
                        culoare(7);
                        }
                    }
                }
            }
        }while(strcmp(raspuns,"da")==0 || strcmp(raspuns,"Da")==0 || strcmp(raspuns,"DA")==0);
    }
//------------------------------------------------------------------------------------------------------------------------------------------------------

    void stergere ()
    {
        bool ok=1;
        char raspuns[10];
        int index_angajat=0;

        do
        {
            curatare_ecran();


            if (n==1)
                cout<<"Acesta este angajatul din baza de date:"<<endl<<endl;
            else if (n>1)
                cout<<"Acestia sunt cei "<<n<<" angajati din baza de date"<<endl<<endl;
            else
            {
                 cout<<"Nu exista angajati in baza de date!"<<endl<<endl;
                ok=0;
            }

                if(ok==1)
                {
                    for (int i=1;i<=n;i++)
                    afisare_angajat(i);
                cout<<"Alegeti indexul angajatului care urmeaza sa fie eliminat: "<<endl;

                cin>>index_angajat;

                do
                {
                    if (index_angajat>n)
                    {
                    cout<<"Angajatul nu se afla in baza de date!"<<endl<<endl;
                    cout<<"Alegeti indexul angajatului care urmeaza sa fie eliminat: "<<endl;
                    cin>>index_angajat;
                    }

                }while (index_angajat>n);
                cout<<endl;
                curatare_ecran();
                afisare_angajat(index_angajat);
                cout<<"Confirmati ca doriti stergerea angajatului selectat din baza de date? (da/nu)"<<endl;
                cin>>raspuns;
                if (strcmp(raspuns,"da")==0)
                {
                    for (int i=1;i<=n;i++)
                    {
                        if (index_angajat==i)
                         v[index_angajat]=v[index_angajat+1];
                    }
                    n--;
                }
                    curatare_ecran();
                    cout<<"Doriti sa eliminati alti angajati din lista? (da/nu)"<<endl;
                    cin>>raspuns;
                    if (strcmp(raspuns,"da")==0 || strcmp(raspuns,"Da")==0 || strcmp(raspuns,"DA")==0)
                        {
                            for (int i=1;i<=n;i++)
                            afisare_angajat(i);
                        }
                    if (strcmp(raspuns,"nu")==0 || strcmp(raspuns,"Nu")==0 || strcmp(raspuns,"NU")==0)
                    {
                        curatare_ecran();
                        cout<<"Acestia sunt angajatii ramasi in lista: "<<endl<<endl;
                        for (int i=1;i<=n;i++)
                            afisare_angajat(i);
                    }
                }


        }while(strcmp(raspuns,"da")==0 || strcmp(raspuns,"Da")==0 || strcmp(raspuns,"DA")==0);
        }

        void modificare()
        {
            int ok=1;
            char raspuns[10];
            int index_angajat=0;
            char nume_introdus[50];
            int var_introdus;
            float salariu_introdus;


            do
            {
                if (n==1)
                cout<<"Acesta este angajatul din baza de date:"<<endl<<endl;
            else if (n>1)
                cout<<"Acestia sunt cei "<<n<<" angajati din baza de date"<<endl<<endl;
            else
            {
                 cout<<"Nu exista angajati in baza de date!"<<endl<<endl;
                ok=0;
            }

            if (ok==1)
                for (int i=1;i<=n;i++)
                afisare_angajat(i);
                cout<<"Alegeti indexul angajatului care urmeaza sa fie modificat: "<<endl;
                cin>>index_angajat;
                for (int i=1;i<=n;i++)
                    if (index_angajat==i)
                {
                    curatare_ecran();
                    afisare_angajat(index_angajat);
                    cout<<"Ce doriti sa modificati la acest angajat? (nume/prenume/varsta/salariu)"<<endl;
                }

                    cin>>raspuns;
                    if (strcmp(raspuns,"nume")==0 || strcmp(raspuns,"Nume")==0 || strcmp(raspuns,"NUME")==0)
                    {
                        int sem=0;
                        cout<<endl;
                        cout<<"Introduceti numele nou: "<<endl;
                        cin>>nume_introdus;
                        cout<<endl;
                        for (int i=1;i<=n;i++)
                        if (strcmp(nume_introdus,v[i].nume)==0)
                        {
                            do
                            {
                            sem=1;
                            cout<<"Numele introdus corespunde cu numele angajatului!"<<endl;
                            cout<<"Introduceti numele nou: "<<endl;
                            cin>>nume_introdus;
                            cout<<endl;
                            }while (strcmp(nume_introdus,v[i].nume)==0);
                            sem=0;
                        }
                        if (sem==0)
                        {
                            cout<<"Confirmati ca doriti modificarea numelui a angajatului selectat? (da/nu)"<<endl;
                        cin>>raspuns;

                        if (strcmp(raspuns,"da")==0 || strcmp(raspuns,"Da")==0 || strcmp(raspuns,"DA")==0)
                        {
                            curatare_ecran();
                        cout<<"Numele s-a modificat!"<<endl<<endl;
                        strcpy(v[index_angajat].nume,nume_introdus);
                        afisare_angajat(index_angajat);
                        cout<<"Doriti sa vedeti lista actualizata a angajatilor? (da/nu)"<<endl;
                        cin>>raspuns;
                        cout<<endl;
                        if (strcmp(raspuns,"da")==0 || strcmp(raspuns,"Da")==0 || strcmp(raspuns,"DA")==0)
                        {
                            curatare_ecran();
                            cout<<"Acestia sunt toti cei "<<n<<" angajati, iar angajatul la care s-au efectuat modificari este evidentiat prin culoare"<<endl<<endl;
                        for (int i=1;i<=n;i++)
                        {
                            if (i==index_angajat)
                            {
                                culoare(3);
                                afisare_angajat(i);
                                culoare(7);
                            }
                            else
                            {
                                afisare_angajat(i);
                            cout<<endl;
                            }

                        }

                        }
                         cout<<"Doriti sa efectuati alte modificari? (da/nu)"<<endl;
                        cin>>raspuns;
                        cout<<endl;
                        curatare_ecran();
                        if (strcmp(raspuns,"da")==0 || strcmp(raspuns,"Da")==0 || strcmp(raspuns,"DA")==0)
                        {
                            curatare_ecran();
                        }

                        else //(strcmp(raspuns,"nu")==0 || strcmp(raspuns,"Nu")==0 || strcmp(raspuns,"NU")==0)
                        {
                            cout<<"Acestia sunt toti angajatii dupa efectuarea tutror modificarilor necesare: "<<endl<<endl;
                            for (int i=1;i<=n;i++)
                            afisare_angajat(i);
                        }
                        }
                        else
                        {
                            curatare_ecran();
                            cout<<"Ati renuntat la modificarea numelui!"<<endl<<endl;
                             cout<<"Doriti sa efectuati alte modificari? (da/nu)"<<endl;
                        cin>>raspuns;
                        cout<<endl;
                        curatare_ecran();
                        if (strcmp(raspuns,"da")==0 || strcmp(raspuns,"Da")==0 || strcmp(raspuns,"DA")==0)
                        {
                            curatare_ecran();
                        }

                        if (strcmp(raspuns,"nu")==0 || strcmp(raspuns,"Nu")==0 || strcmp(raspuns,"NU")==0)
                        {
                            cout<<"Acestia sunt toti angajatii dupa efectuarea tuturor modificarilor necesare: "<<endl<<endl;
                            for (int i=1;i<=n;i++)
                            afisare_angajat(i);
                        }
                        }
                        }

                    }
                    if (strcmp(raspuns,"prenume")==0 || strcmp(raspuns,"Prenume")==0 || strcmp(raspuns,"PRENUME")==0)
                    {
                        int sem=0;
                        cout<<endl;
                        cout<<"Introduceti prenumele nou: "<<endl;
                        cin>>nume_introdus;
                        cout<<endl;
                        for (int i=1;i<=n;i++)
                        if (strcmp(nume_introdus,v[i].prenume)==0)
                        {
                            do
                            {
                            sem=1;
                            cout<<"Prenumele introdus corespunde cu prenumele angajatului!"<<endl;
                            cout<<"Introduceti prenumele nou: "<<endl;
                            cin>>nume_introdus;
                            cout<<endl;
                            }while (strcmp(nume_introdus,v[i].prenume)==0);
                            sem=0;
                        }
                        if (sem==0)
                        {
                            cout<<"Confirmati ca doriti modificarea prenumelui a angajatului selectat? (da/nu)"<<endl;
                        cin>>raspuns;

                        if (strcmp(raspuns,"da")==0 || strcmp(raspuns,"Da")==0 || strcmp(raspuns,"DA")==0)
                        {
                            curatare_ecran();
                        cout<<"Prenumele s-a modificat!"<<endl<<endl;
                        strcpy(v[index_angajat].prenume,nume_introdus);
                        afisare_angajat(index_angajat);
                        cout<<"Doriti sa vedeti lista actualizata a angajatilor? (da/nu)"<<endl;
                        cin>>raspuns;
                        cout<<endl;
                        if (strcmp(raspuns,"da")==0 || strcmp(raspuns,"Da")==0 || strcmp(raspuns,"DA")==0)
                        {
                            curatare_ecran();
                             cout<<"Acestia sunt toti cei "<<n<<" angajati, iar angajatul la care s-au efectuat modificari este evidentiat prin culoare"<<endl<<endl;
                        for (int i=1;i<=n;i++)
                        {
                            if (i==index_angajat)
                            {
                                culoare(3);
                                afisare_angajat(i);
                                culoare(7);
                            }
                            else
                            {
                                afisare_angajat(i);
                            cout<<endl;
                            }

                        }
                        }
                        cout<<"Doriti sa efectuati alte modificari? (da/nu)"<<endl;
                        cin>>raspuns;
                        cout<<endl;
                        curatare_ecran();
                        if (strcmp(raspuns,"da")==0 || strcmp(raspuns,"Da")==0 || strcmp(raspuns,"DA")==0)
                        {
                            curatare_ecran();
                        }

                        if (strcmp(raspuns,"nu")==0 || strcmp(raspuns,"Nu")==0 || strcmp(raspuns,"NU")==0)
                        {
                            cout<<"Acestia sunt toti angajatii dupa efectuarea tutror modificarilor necesare: "<<endl<<endl;
                            for (int i=1;i<=n;i++)
                            afisare_angajat(i);
                        }
                        }
                        else
                        {
                            curatare_ecran();
                            cout<<"Ati renuntat la modificarea prenumelui!"<<endl<<endl;
                             cout<<"Doriti sa efectuati alte modificari? (da/nu)"<<endl;
                        cin>>raspuns;
                        cout<<endl;
                        curatare_ecran();
                        if (strcmp(raspuns,"da")==0 || strcmp(raspuns,"Da")==0 || strcmp(raspuns,"DA")==0)
                        {
                            curatare_ecran();
                        }

                        if (strcmp(raspuns,"nu")==0 || strcmp(raspuns,"Nu")==0 || strcmp(raspuns,"NU")==0)
                        {
                            cout<<"Acestia sunt toti angajatii dupa efectuarea tuturor modificarilor necesare: "<<endl<<endl;
                            for (int i=1;i<=n;i++)
                            afisare_angajat(i);
                        }
                        }
                        }

                    }
                    if (strcmp(raspuns,"varsta")==0 || strcmp(raspuns,"Varsta")==0 || strcmp(raspuns,"VARSTA")==0)
                    {
                        int sem=0;
                        cout<<endl;
                        cout<<"Introduceti varsta noua: "<<endl;
                        cin>>var_introdus;
                        cout<<endl;
                        for (int i=1;i<=n;i++)
                        if (var_introdus==v[i].varsta)
                        {
                            do
                            {
                            sem=1;
                            cout<<"Varsta introdusa corespunde cu varsta angajatului!"<<endl;
                            cout<<"Introduceti varsta nou: "<<endl;
                            cin>>var_introdus;
                            cout<<endl;
                            }while (var_introdus==v[i].varsta);
                            sem=0;
                        }

                        if (sem==0)
                        {
                            cout<<"Confirmati ca doriti modificarea varstei a angajatului selectat? (da/nu)"<<endl;
                        cin>>raspuns;

                        if (strcmp(raspuns,"da")==0 || strcmp(raspuns,"Da")==0 || strcmp(raspuns,"DA")==0)
                        {
                            curatare_ecran();
                        cout<<"Varsta s-a modificat!"<<endl<<endl;
                        v[index_angajat].varsta=var_introdus;
                        afisare_angajat(index_angajat);
                        cout<<"Doriti sa vedeti lista actualizata a angajatilor? (da/nu)"<<endl;
                        cin>>raspuns;
                        cout<<endl;
                        if (strcmp(raspuns,"da")==0 || strcmp(raspuns,"Da")==0 || strcmp(raspuns,"DA")==0)
                        {
                            curatare_ecran();
                             cout<<"Acestia sunt toti cei "<<n<<" angajati, iar angajatul la care s-au efectuat modificari este evidentiat prin culoare"<<endl<<endl;
                        for (int i=1;i<=n;i++)
                        {
                           if (i==index_angajat)
                            {
                                culoare(3);
                                afisare_angajat(i);
                                culoare(7);
                            }
                            else
                            {
                                afisare_angajat(i);
                            cout<<endl;
                            }
                        }

                        }
                         cout<<"Doriti sa efectuati alte modificari? (da/nu)"<<endl;
                        cin>>raspuns;
                        cout<<endl;
                        curatare_ecran();
                        if (strcmp(raspuns,"da")==0 || strcmp(raspuns,"Da")==0 || strcmp(raspuns,"DA")==0)
                        {
                            curatare_ecran();
                        }

                        if (strcmp(raspuns,"nu")==0 || strcmp(raspuns,"Nu")==0 || strcmp(raspuns,"NU")==0)
                        {
                            cout<<"Acestia sunt toti angajatii dupa efectuarea tutror modificarilor necesare: "<<endl<<endl;
                            for (int i=1;i<=n;i++)
                            afisare_angajat(i);
                        }
                        }
                        else
                        {
                            curatare_ecran();
                            cout<<"Ati renuntat la modificarea varstei!"<<endl<<endl;
                             cout<<"Doriti sa efectuati alte modificari? (da/nu)"<<endl;
                        cin>>raspuns;
                        cout<<endl;
                        curatare_ecran();
                        if (strcmp(raspuns,"da")==0 || strcmp(raspuns,"Da")==0 || strcmp(raspuns,"DA")==0)
                        {
                            curatare_ecran();
                        }

                        if (strcmp(raspuns,"nu")==0 || strcmp(raspuns,"Nu")==0 || strcmp(raspuns,"NU")==0)
                        {
                            cout<<"Acestia sunt toti angajatii dupa efectuarea tuturor modificarilor necesare: "<<endl<<endl;
                            for (int i=1;i<=n;i++)
                            afisare_angajat(i);
                        }
                        }
                        }

                    }
                    if (strcmp(raspuns,"salariu")==0 || strcmp(raspuns,"Salariu")==0 || strcmp(raspuns,"SALARIU")==0)
                    {
                        int sem=0;
                        cout<<endl;
                        cout<<"Introduceti salariul nou: "<<endl;
                        cin>>salariu_introdus;
                        cout<<endl;
                        for (int i=1;i<=n;i++)
                        if (salariu_introdus==v[i].salariu)
                        {
                            do
                            {
                            sem=1;
                            cout<<"Salariul introdus corespunde cu salariul angajatului!"<<endl;
                            cout<<"Introduceti salariul nou: "<<endl;
                            cin>>salariu_introdus;
                            cout<<endl;
                            }while (salariu_introdus==v[i].salariu);
                            sem=0;
                        }
                        if (sem==0)
                        {
                        cout<<"Confirmati ca doriti modificarea salariului a angajatului selectat? (da/nu)"<<endl;
                        cin>>raspuns;

                        if (strcmp(raspuns,"da")==0 || strcmp(raspuns,"Da")==0 || strcmp(raspuns,"DA")==0)
                        {
                            curatare_ecran();
                        cout<<"Salariul s-a modificat!"<<endl<<endl;
                        v[index_angajat].salariu=salariu_introdus;
                        afisare_angajat(index_angajat);
                        cout<<"Doriti sa vedeti lista actualizata a angajatilor? (da/nu)"<<endl;
                        cin>>raspuns;
                        cout<<endl;
                        if (strcmp(raspuns,"da")==0 || strcmp(raspuns,"Da")==0 || strcmp(raspuns,"DA")==0)
                        {
                            curatare_ecran();
                             cout<<"Acestia sunt toti cei "<<n<<" angajati, iar angajatul la care s-au efectuat modificari este evidentiat prin culoare"<<endl<<endl;
                        for (int i=1;i<=n;i++)
                            {
                                if (i==index_angajat)
                            {
                                culoare(3);
                                afisare_angajat(i);
                                culoare(7);
                            }
                            else
                            {
                                afisare_angajat(i);
                            cout<<endl;
                            }
                            }
                        }
                        cout<<"Doriti sa efectuati alte modificari? (da/nu)"<<endl;
                        cin>>raspuns;
                        cout<<endl;
                        curatare_ecran();
                        if (strcmp(raspuns,"da")==0 || strcmp(raspuns,"Da")==0 || strcmp(raspuns,"DA")==0)
                        {
                            curatare_ecran();
                        }

                        if (strcmp(raspuns,"nu")==0 || strcmp(raspuns,"Nu")==0 || strcmp(raspuns,"NU")==0)
                        {
                            cout<<"Acestia sunt toti angajatii dupa efectuarea tutror modificarilor necesare: "<<endl<<endl;
                            for (int i=1;i<=n;i++)
                            afisare_angajat(i);
                        }
                        }
                        else
                        {
                            curatare_ecran();
                            cout<<"Ati renuntat la modificarea salariului!"<<endl<<endl;
                             cout<<"Doriti sa efectuati alte modificari? (da/nu)"<<endl;
                        cin>>raspuns;
                        cout<<endl;
                        curatare_ecran();
                        if (strcmp(raspuns,"da")==0 || strcmp(raspuns,"Da")==0 || strcmp(raspuns,"DA")==0)
                        {
                            curatare_ecran();
                        }

                        if (strcmp(raspuns,"nu")==0 || strcmp(raspuns,"Nu")==0 || strcmp(raspuns,"NU")==0)
                        {
                            cout<<"Acestia sunt toti angajatii dupa efectuarea tuturor modificarilor necesare: "<<endl<<endl;
                            for (int i=1;i<=n;i++)
                            afisare_angajat(i);
                        }
                        }

                        }


                        }

    }while (strcmp(raspuns,"da")==0 || strcmp(raspuns,"Da")==0 || strcmp(raspuns,"DA")==0);
    }

    void ord_alfabetica_nume(int crescator)
    {
            if (crescator==1)
            {
            for (int i=1;i<=n;i++)
            for (int j=1;j<=n;j++)
            if (strcmp(v[i].nume,v[j].nume)<=0)
            {
            angajat aux=v[i];
            v[i]=v[j];
            v[j]=aux;
            }
            for (int i=1;i<=n;i++)
            afisare_angajat(i);
            }
            else
            {
            for (int i=1;i<=n;i++)
            for (int j=1;j<=n;j++)
            if (strcmp(v[i].nume,v[j].nume)>=0)
            {
            angajat aux=v[i];
            v[i]=v[j];
            v[j]=aux;
            }
            for (int i=1;i<=n;i++)
            afisare_angajat(i);
            }

    }

    void ord_alfabetica_prenume(int crescator)
    {
            if (crescator==1)
            {
            for (int i=1;i<=n;i++)
            for (int j=1;j<=n;j++)
            if (strcmp(v[i].prenume,v[j].prenume)<=0)
            {
            angajat aux=v[i];
            v[i]=v[j];
            v[j]=aux;
            }
            for (int i=1;i<=n;i++)
            afisare_angajat(i);
            }
            else
            {
            for (int i=1;i<=n;i++)
            for (int j=1;j<=n;j++)
            if (strcmp(v[i].prenume,v[j].prenume)>=0)
            {
            angajat aux=v[i];
            v[i]=v[j];
            v[j]=aux;
            }
            for (int i=1;i<=n;i++)
            afisare_angajat(i);
            }
    }

    void ord_varsta(int crescator)
    {
            if (crescator==1)
            {
            for (int i=1;i<=n;i++)
            for (int j=1;j<=n;j++)
            if (v[i].varsta<=v[j].varsta)
            {
            angajat aux=v[i];
            v[i]=v[j];
            v[j]=aux;
            }
            for (int i=1;i<=n;i++)
            afisare_angajat(i);
            }
            else
            {
            for (int i=1;i<=n;i++)
            for (int j=1;j<=n;j++)
            if (v[i].varsta>=v[j].varsta)
            {
            angajat aux=v[i];
            v[i]=v[j];
            v[j]=aux;
            }
            for (int i=1;i<=n;i++)
            afisare_angajat(i);
            }

    }

    void ord_salariu(int crescator)
    {
            if (crescator==1)
            {
            for (int i=1;i<=n;i++)
            for (int j=1;j<=n;j++)
            if (v[i].salariu<=v[j].salariu)
            {
            angajat aux=v[i];
            v[i]=v[j];
            v[j]=aux;
            }
            for (int i=1;i<=n;i++)
            afisare_angajat(i);
            }
            else
            {
            for (int i=1;i<=n;i++)
            for (int j=1;j<=n;j++)
            if (v[i].salariu>=v[j].salariu)
            {
            angajat aux=v[i];
            v[i]=v[j];
            v[j]=aux;
            }
            for (int i=1;i<=n;i++)
            afisare_angajat(i);

            }
    }

    void ordonare()
    {
        int crescator;
        int ok=1;
        char raspuns[15];
        char raspuns2[15];
        do
        {
             if (n==1)
                cout<<"Acesta este angajatul din baza de date:"<<endl<<endl;
            else if (n>1)
                cout<<"Acestia sunt cei "<<n<<" angajati din baza de date"<<endl<<endl;
            else
            {
                 cout<<"Nu exista angajati in baza de date!"<<endl<<endl;
                ok=0;
            }

            if (ok==1)
                for (int i=1;i<=n;i++)
                afisare_angajat(i);
             cout<<"Alegeti dupa ce criteriu doriti sa ordonati angajatii (nume/prenume/varsta/salariu) "<<endl;
        cin>>raspuns;
        cout<<endl;
        cout<<"Doriti sa ordonati crescator sau descrescator? (crescator/descrescator)"<<endl;
        cin>>raspuns2;
        if(strcmp(raspuns2,"crescator")==0 || (raspuns2,"Crescator")==0 || (raspuns2,"CRESCATOR")==0)
            crescator=1;
        else
            crescator=0;

        curatare_ecran();
        if (strcmp(raspuns,"nume")==0 || strcmp(raspuns,"Nume")==0 || strcmp(raspuns,"NUME")==0)
        {
            cout<<"Aceasta este lista angajatilor ordonati dupa nume: "<<endl<<endl;
            ord_alfabetica_nume(crescator);
            cout<<endl;
            cout<<"Doriti sa efectuati alta ordonare? (da/nu)"<<endl;
            cin>>raspuns;
            if (strcmp(raspuns,"da")==0 || strcmp(raspuns,"Da")==0 || strcmp(raspuns,"DA")==0)
            {
                curatare_ecran();
                for (int i=1;i<=n;i++)
                    afisare_angajat(i);
                    curatare_ecran();
            }
            else
            {
                curatare_ecran();
                ok=0;
            }
        }
        if (strcmp(raspuns,"prenume")==0 || strcmp(raspuns,"Prenume")==0 || strcmp(raspuns,"PRENUME")==0)
        {
            cout<<"Aceasta este lista angajatilor ordonati dupa prenume: "<<endl<<endl;
            ord_alfabetica_prenume(crescator);
            cout<<endl;
            cout<<"Doriti sa efectuati alta ordonare? (da/nu)"<<endl;
            cin>>raspuns;
            if (strcmp(raspuns,"da")==0 || strcmp(raspuns,"Da")==0 || strcmp(raspuns,"DA")==0)
            {
                curatare_ecran();
                for (int i=1;i<=n;i++)
                    afisare_angajat(i);
                    curatare_ecran();
            }
            else
            {
                curatare_ecran();
                ok=0;
            }
        }
        if (strcmp(raspuns,"varsta")==0 || strcmp(raspuns,"Varsta")==0 || strcmp(raspuns,"VARSTA")==0)
        {
            cout<<"Aceasta este lista angajatilor ordonati dupa varsta: "<<endl<<endl;
            ord_varsta(crescator);
            cout<<endl;
            cout<<"Doriti sa efectuati alta ordonare? (da/nu)"<<endl;
            cin>>raspuns;
            if (strcmp(raspuns,"da")==0 || strcmp(raspuns,"Da")==0 || strcmp(raspuns,"DA")==0)
            {
                curatare_ecran();
                for (int i=1;i<=n;i++)
                    afisare_angajat(i);
                    curatare_ecran();
            }
            else
            {
                curatare_ecran();
                ok=0;
            }
        }
        if (strcmp(raspuns,"salariu")==0 || strcmp(raspuns,"Salariu")==0 || strcmp(raspuns,"SALARIU")==0)
        {
            cout<<"Aceasta este lista angajatilor ordonati dupa salariu: "<<endl<<endl;
            ord_salariu(crescator);
            cout<<endl;
            cout<<"Doriti sa efectuati alta ordonare? (da/nu)"<<endl;
            cin>>raspuns;
            if (strcmp(raspuns,"da")==0 || strcmp(raspuns,"Da")==0 || strcmp(raspuns,"DA")==0)
            {
                curatare_ecran();
                for (int i=1;i<=n;i++)
                    afisare_angajat(i);
                    curatare_ecran();
            }
            else
            {
                curatare_ecran();
                ok=0;
            }

        }

    }while (ok==1);

    }

    void afisare_camere(int i)
    {
       cout<<"Camera nr. "<<c[i].numar<<endl;
       cout<<"Informatii generale: "<<endl<<"Tip: "<<c[i].tip<<endl<<"Cost: "<<c[i].cost<<" de lei/noapte"<<endl;
        separare(30);
    }

    void camere()
    {
       if (m>1)
    {
        cout<<"Aceasta este lista cu cele "<<m<<" camere"<<endl<<endl;
        for (int i=1;i<=m;i++)
        afisare_camere(i);
    }
    else if (m==1)
    {
        cout<<"Aceasta este camera din baza de date"<<endl<<endl;
        for (int i=1;i<=m;i++)
        afisare_camere(i);
    }
        if (m==0)
            cout<<"Nu exista camere disponibile in baza de date! Adaugati camere pentru a le putea afisa!"<<endl<<endl;
    }

    void adaugare_camere()
    {
        int ok=0;
        char raspuns [20];
        int index_camera=0;
        do
        {
            cout<<"Introduceti informatiile camerei care a fost eliberata si este acum disponibila clientilor: "<<endl<<endl;
            cout<<"Camera nr. ";
            cin>>c[m+1].numar;
            for (int i=1;i<=m;i++)
                for (int i=m;i>=1;i--)
                if (c[m+1].numar==c[i].numar)
                {
                     do
                    {
                        ok=1;
                        cout<<"Camera introdusa este deja disponibila!"<<endl;
                        cout<<"Introduceti informatiile camerei care a fost eliberata si este acum disponibila clientilor!"<<endl<<endl;
                        cout<<"Camera nr.: ";
                        cin>>c[m+1].numar;
                    }while (c[m+1].numar==c[i].numar);
                    ok=0;
                }

            if (ok==0)
            {
            cout<<"Tip: ";
            cin>>c[m+1].tip;
            cout<<"Cost: ";
            cin>>c[m+1].cost;
            curatare_ecran();
            cout<<"Introduceti informatiile camerei care a fost eliberata si este acum disponibila clientilor: "<<endl<<endl;
            cout<<"Camera nr. "<<c[m+1].numar<<endl;
            cout<<"Tip: "<<c[m+1].tip<<endl;
            cout<<"Cost: "<<c[m+1].cost<<" de lei/noapte"<<endl<<endl;

             cout<<"Confirmati ca doriti adaugarea camerei introduse? (da/nu)"<<endl;
                cin>>raspuns;
                cout<<endl;
                if (strcmp(raspuns,"da")==0 || strcmp(raspuns,"Da")==0 || strcmp(raspuns,"DA")==0)
                    ok=0;
                if (strcmp(raspuns,"nu")==0 || strcmp(raspuns,"Nu")==0 || strcmp(raspuns,"NU")==0)
                    ok=1;
                    if (ok==1)
                    {
                     cout<<"Ati renuntat la adaugarea camerei!"<<endl;
                     break;

                    }
            if (ok==0)
            {
                m++;
                 curatare_ecran();

                 if (strcmp(raspuns,"da")==0 || strcmp(raspuns,"Da")==0 || strcmp(raspuns,"DA")==0)
                 {
                      cout<<"Aceasta este lista noua cu cele "<<m<<" camere, iar camera nou introdusa este evidentiata prin culoare: "<<endl<<endl;
                    for (int i=1;i<m;i++)
                    afisare_camere(i);
                    for (int i=1;i<=m;i++)
                    if (i==m)
                    {
                        index_camera=i;
                        culoare(3);
                        afisare_camere(index_camera);
                        culoare(7);
                    }
                    cout<<"Doriti sa adaugati alte camere? (da/nu)"<<endl;
                 cin>>raspuns;
                 cout<<endl;
                 curatare_ecran();
                 if (strcmp(raspuns,"da")==0 || strcmp(raspuns,"Da")==0 || strcmp(raspuns,"DA")==0)
                    ok=0;

                 }

                    if (strcmp(raspuns,"nu")==0 || strcmp(raspuns,"Nu")==0 || strcmp(raspuns,"NU")==0)
                    {

                        cout<<"Aceasta este lista noua cu cele "<<m<<" camere, iar camera nou introdusa este evidentiata prin culoare: "<<endl<<endl;
                        for (int i=1;i<m;i++)
                        afisare_camere(i);
                        for (int i=1;i<=m;i++)
                        if (i==m)
                        {
                        index_camera=i;
                        culoare(3);
                        afisare_camere(index_camera);
                        culoare(7);
                        }
                    }
                }
            }
        }while(strcmp(raspuns,"da")==0 || strcmp(raspuns,"Da")==0 || strcmp(raspuns,"DA")==0);
    }


    void rezervare()
    {
        int numar_camera;
        int index_camera=0;
        int ok=1;
        char raspuns[20];
        do
        {
        if (m==1)
                cout<<"Aceasta este camera disponibila:"<<endl<<endl;
            else if (m>1)
                cout<<"Acestea sunt cele "<<m<<" camere disponibile"<<endl<<endl;
            else
            {
                 cout<<"Nu exista camere disponibile!"<<endl<<endl;
                ok=0;
            }

                if(ok==1)
                {
                    for (int i=1;i<=m;i++)
                    {
                        afisare_camere(i);
                    }

                cout<<"Alegeti numarul camerei care a fost rezervata de catre un client: "<<endl;

                cin>>numar_camera;

                for (int i=1;i<=m;i++)
                    if (numar_camera==c[i].numar)
                        index_camera=i;
                    if (index_camera==0)
                    {
                        do
                        {
                        cout<<"Camera nu este disponibila!"<<endl<<endl;
                        cout<<"Alegeti numarul camerei care a fost rezervata de catre un client: "<<endl;
                        cin>>numar_camera;
                        index_camera=0;
                            for (int i=1;i<=m;i++)
                                if (numar_camera==c[i].numar)
                                    index_camera=i;
                        }while (index_camera==0);

                    }

                cout<<endl;
                curatare_ecran();
                cout<<"Aceasta este camera selectata: "<<endl<<endl;
                afisare_camere(index_camera);
                cout<<"Confirmati ca doriti rezervarea acestei camere pentru un client? (da/nu)"<<endl;
                cin>>raspuns;
                if (strcmp(raspuns,"da")==0 || strcmp(raspuns,"Da")==0 || strcmp(raspuns,"DA")==0)
                {
                    for (int i=1;i<=m;i++)
                    {
                        if (numar_camera==c[i].numar)
                         c[index_camera]=c[index_camera+1];
                         for (i=index_camera;i<=m;i++)
                         c[i]=c[i+1];
                    }
                    m--;
                 }
                    curatare_ecran();
                    cout<<"Doriti sa rezervati alte camere? (da/nu)"<<endl;
                    cin>>raspuns;
                    index_camera=0;
                    curatare_ecran();
                    if (strcmp(raspuns,"da")==0 || strcmp(raspuns,"Da")==0 || strcmp(raspuns,"DA")==0)
                        {
                            for (int i=1;i<=m;i++)
                            afisare_camere(i);
                            curatare_ecran();
                        }
                    if (strcmp(raspuns,"nu")==0 || strcmp(raspuns,"Nu")==0 || strcmp(raspuns,"NU")==0)
                    {
                        curatare_ecran();
                        cout<<"Acestea sunt cele "<<m<<" camere disponibile ramase: "<<endl<<endl;
                        for (int i=1;i<=m;i++)
                            afisare_camere(i);
                    }
                    }



                }while(strcmp(raspuns,"da")==0 || strcmp(raspuns,"Da")==0 || strcmp(raspuns,"DA")==0);


                }

     void ord_nr_camere(int crescator)
    {
            if (crescator==1)
            {
            for (int i=1;i<=m;i++)
            for (int j=1;j<=m;j++)
            if (c[i].numar<c[j].numar)
            {
            camera aux=c[i];
            c[i]=c[j];
            c[j]=aux;
            }
            for (int i=1;i<=m;i++)
            afisare_camere(i);
            }
            else
            {
            for (int i=1;i<=m;i++)
            for (int j=1;j<=m;j++)
            if (c[i].numar>c[j].numar)
            {
            camera aux=c[i];
            c[i]=c[j];
            c[j]=aux;
            }
            for (int i=1;i<=m;i++)
            afisare_camere(i);
            }
    }

     void ord_cost_camere(int crescator)
    {
            if (crescator==1)
            {
            for (int i=1;i<=m;i++)
            for (int j=1;j<=m;j++)
            if (c[i].cost<c[j].cost)
            {
            camera aux=c[i];
            c[i]=c[j];
            c[j]=aux;
            }
            for (int i=1;i<=m;i++)
            afisare_camere(i);
            }
            else
            {
            for (int i=1;i<=m;i++)
            for (int j=1;j<=m;j++)
            if (c[i].cost>c[j].cost)
            {
            camera aux=c[i];
            c[i]=c[j];
            c[j]=aux;
            }
            for (int i=1;i<=m;i++)
            afisare_camere(i);
            }


    }

    void ordonare_camere()
    {
        int crescator;
        int ok=1;
        char raspuns[15];
        char raspuns2[15];
        do
        {
             if (m==1)
                cout<<"Aceasta este camera disponibila:"<<endl<<endl;
            else if (m>1)
                cout<<"Acestea sunt cele "<<m<<" camere disponibile"<<endl<<endl;
            else
            {
                 cout<<"Nu exista camere disponibile!"<<endl<<endl;
                ok=0;
            }

            if (ok==1)
                for (int i=1;i<=m;i++)
                afisare_camere(i);
             cout<<"Alegeti dupa ce criteriu doriti sa ordonati camerele (numar/cost) "<<endl;
        cin>>raspuns;
        cout<<endl;
        cout<<"Doriti sa ordonati crescator sau descrescator? (crescator/descrescator)"<<endl;
        cin>>raspuns2;
        if(strcmp(raspuns2,"crescator")==0 || (raspuns2,"Crescator")==0 || (raspuns2,"CRESCATOR")==0)
            crescator=1;
        else
            crescator=0;

        curatare_ecran();
        if (strcmp(raspuns,"numar")==0 || strcmp(raspuns,"Numar")==0 || strcmp(raspuns,"NUMAR")==0)
        {
            cout<<"Aceasta este lista camerelor disponibile ordonate dupa numar: "<<endl<<endl;
            ord_nr_camere(crescator);
            cout<<endl;
            cout<<"Doriti sa efectuati alta ordonare? (da/nu)"<<endl;
            cin>>raspuns;
            if (strcmp(raspuns,"da")==0 || strcmp(raspuns,"Da")==0 || strcmp(raspuns,"DA")==0)
            {
                curatare_ecran();
                for (int i=1;i<=m;i++)
                    afisare_camere(i);
                    curatare_ecran();
            }
            else
            {
                curatare_ecran();
                ok=0;
            }
        }

        if (strcmp(raspuns,"cost")==0 || strcmp(raspuns,"Cost")==0 || strcmp(raspuns,"COST")==0)
        {
            cout<<"Aceasta este lista camerelor disponibile ordonate dupa cost: "<<endl<<endl;
            ord_cost_camere(crescator);
            cout<<endl;
            cout<<"Doriti sa efectuati alta ordonare? (da/nu)"<<endl;
            cin>>raspuns;
            if (strcmp(raspuns,"da")==0 || strcmp(raspuns,"Da")==0 || strcmp(raspuns,"DA")==0)
            {
                curatare_ecran();
                for (int i=1;i<=m;i++)
                    afisare_camere(i);
                    curatare_ecran();
            }
            else
            {
                curatare_ecran();
                ok=0;
            }
        }

        }while (strcmp(raspuns,"da")==0 || strcmp(raspuns,"Da")==0 || strcmp(raspuns,"DA")==0);
    }

    void afisare_clienti(int i)
    {
        cout<<"Clientul: "<<i<<endl;
        cout<<"Date personale: "<<endl<<"Nume: "<<d[i].nume2<<endl<<"Prenume: "<<d[i].prenume2<<endl<<"Recenzia acordata: "<<d[i].recenzie<<" stele"<<endl<<"Sugestia: "<<d[i].sugestie<<endl<<"Reclamatia: "<<d[i].reclamatie<<endl;
        separare(30);
    }

    void afisare_recenzii_clienti(int i)
    {
        cout<<"Clientul: "<<i<<endl;
        cout<<"Date personale: "<<endl<<"Nume: "<<d[i].nume2<<endl<<"Prenume: "<<d[i].prenume2<<endl<<"Recenzia acordata: "<<d[i].recenzie<<" stele"<<endl;
        separare(30);
    }

    void clienti()
    {
           if (p>1)
    {
        cout<<"Aceasta este lista cu cei "<<p<<" clienti"<<endl<<endl;
        for (int i=1;i<=p;i++)
        afisare_clienti(i);
    }
    else if (p==1)
    {
        cout<<"Acesta este clientul din baza de date"<<endl<<endl;
        for (int i=1;i<=p;i++)
        afisare_clienti(i);
    }
        if (p==0)
            cout<<"Nu exista clienti in baza de date! Adaugati recenzii ale clientilor pentru a le putea afisa!"<<endl<<endl;
    }

    void adaugare_clienti()
    {
        char raspuns[10];
        int ok=0;
        int index_client;
            do
            {

        cout<<"Introduceti informatiile noului client: "<<endl<<endl;
        cout<<"Nume: ";
        cin>>d[p+1].nume2;
        cout<<endl;
        cout<<"Prenume: ";
        cin>>d[p+1].prenume2;
        cout<<endl;

         for (int i=1;i<=p;i++)
            for (int i=p;i>=1;i--)
             if (strcmp(d[i].nume2,d[p+1].nume2)==0)
                if (strcmp(d[i].prenume2,d[p+1].prenume2)==0)
                {
                   do
                {
                   ok=1;
                   cout<<"Clientul introdus a distribuit deja recenzia sa!"<<endl;
                   cout<<"Introduceti informatiile noului client: "<<endl<<endl;
                   cout<<"Nume: ";
                   cin>>d[p+1].nume2;
                   cout<<endl;
                   cout<<"Prenume: ";
                   cin>>d[p+1].prenume2;
                   cout<<endl;

                }while(strcmp(d[i].nume2,d[p+1].nume2)==0 && strcmp(d[i].prenume2,d[p+1].prenume2)==0);
                    ok=0;
                }

                if (ok==0)
                {
        cout<<"Recenzia: ";
        cin>>d[p+1].recenzie;
        if (d[p+1].recenzie > 5 || d[p+1].recenzie <= 0)
            do
        {
            cout<<"Recenzia distribuita trebuie sa fie cuprinsa intre 1 si 5 stele!"<<endl;
            cout<<"Recenzia: ";
            cin>>d[p+1].recenzie;
        }while (d[p+1].recenzie > 5 || d[p+1].recenzie < 0);

        curatare_ecran();
        cout<<"Introduceti informatiile noului client: "<<endl<<endl;
        cout<<"Nume: "<<d[p+1].nume2<<endl<<endl;
        cout<<"Prenume: "<<d[p+1].prenume2<<endl<<endl;
        cout<<"Recenzia: "<<d[p+1].recenzie<<" stele"<<endl;
        cout<<endl;
        cout<<"Sugestia: ";
        cin.getline(d[p+1].sugestie,100);
        cin.getline(d[p+1].sugestie,100);
        cout<<endl;
        cout<<"Reclamatia: ";
        cin.getline(d[p+1].reclamatie,100);
        cout<<endl;

         cout<<"Confirmati ca doriti adaugarea recenziei introduse? (da/nu)"<<endl;
                cin>>raspuns;
                cout<<endl;
                if (strcmp(raspuns,"da")==0 || strcmp(raspuns,"Da")==0 || strcmp(raspuns,"DA")==0)
                    ok=0;
                if (strcmp(raspuns,"nu")==0 || strcmp(raspuns,"Nu")==0 || strcmp(raspuns,"NU")==0)
                    ok=1;
                    if (ok==1)
                    {
                     cout<<"Ati renuntat la adaugarea recenziei clientului!"<<endl;
                     break;

                    }
            if (ok==0)
            {
                p++;
                 curatare_ecran();

                 if (strcmp(raspuns,"da")==0 || strcmp(raspuns,"Da")==0 || strcmp(raspuns,"DA")==0)
                 {
                      cout<<"Aceasta este lista noua cu cei "<<p<<" clienti, iar clientul nou introdus este evidentiat prin culoare: "<<endl<<endl;
                    for (int i=1;i<p;i++)
                    afisare_clienti(i);
                    for (int i=1;i<=p;i++)
                    if (i==p)
                    {
                        index_client=i;
                        culoare(3);
                        afisare_clienti(index_client);
                        culoare(7);
                    }
                    cout<<"Doriti sa adaugati alte recenzii ale clientilor? (da/nu)"<<endl;
                 cin>>raspuns;
                 cout<<endl;
                 curatare_ecran();
                 if (strcmp(raspuns,"da")==0 || strcmp(raspuns,"Da")==0 || strcmp(raspuns,"DA")==0)
                    ok=0;

                 }

                    if (strcmp(raspuns,"nu")==0 || strcmp(raspuns,"Nu")==0 || strcmp(raspuns,"NU")==0)
                    {

                        cout<<"Aceasta este lista noua cu cei "<<p<<" clienti, iar clientul nou introdus este evidentiat prin culoare: "<<endl<<endl;
                        for (int i=1;i<p;i++)
                        afisare_clienti(i);
                        for (int i=1;i<=p;i++)
                        if (i==p)
                        {
                        index_client=i;
                        culoare(3);
                        afisare_clienti(index_client);
                        culoare(7);
                        }
                    }
                }
            }
        }while(strcmp(raspuns,"da")==0 || strcmp(raspuns,"Da")==0 || strcmp(raspuns,"DA")==0);
    }


    void sugestie()
    {
        int m=0;
        cout<<"Sugestiile clientilor: "<<endl<<endl;
        for (int i=1;i<=p;i++)
        {
            if (strlen(d[i].sugestie) + strlen(d[i].nume2) + strlen(d[i].prenume2)>m)
            m=(strlen(d[i].sugestie) + strlen(d[i].nume2) + strlen(d[i].prenume2));
            if (m>120)
            m=113;
        }

        for (int i=1;i<=p;i++)
        {
             cout<<d[i].nume2<<" "<<d[i].prenume2<<" : \""<<d[i].sugestie<<" \""<<endl;
             separare(m+7);
        }

        cout<<endl;
        cout<<"Multumim tuturor pentru sugestiile dumneavoastra, care ne ajuta sa ne imbunatatim serviciile!"<<endl<<endl;
    }

    void reclamatie()
    {
        cout<<"Reclamatiile clientilor: "<<endl<<endl;
        int m=0;
        for (int i=1;i<=p;i++)
        {
            if (strlen(d[i].reclamatie) + strlen(d[i].nume2) + strlen(d[i].prenume2)>m)
            m=(strlen(d[i].reclamatie) + strlen(d[i].nume2) + strlen(d[i].prenume2));
            if(m>120)
            m=113;
        }

        for (int i=1;i<=p;i++)
        {
            cout<<d[i].nume2<<" "<<d[i].prenume2<<" : \""<<d[i].reclamatie<<" \""<<endl;
            separare(m+7);
        }

        cout<<endl;
        cout<<"Ne cerem scuze pentru aceste inconveniente si ne straduim sa efectuam schimbarile necesare!"<<endl<<endl;
    }


void meniu_angajati()
{
    char a;

    do
    {
        curatare_ecran();
        cout<<"Aceasta este sectiunea de gestiune a angajatilor!"<<endl;
        cout<<"Apasati tasta corespunzatoare numarului de ordine a actiunii pe care doriti sa o efectuati! "<<endl<<endl;
        cout<<"1. Prezentarea angajatilor"<<endl;
        cout<<"2. Cautarea angajatilor dupa nume "<<endl;
        cout<<"3. Adaugarea unui nou angajat"<<endl;
        cout<<"4. Stergerea unui angajat"<<endl;
        cout<<"5. Modificarea datelor a unui angajat"<<endl;
        cout<<"6. Ordonarea angajatilor"<<endl;
        cout<<"0. Iesire din sectiunea angajati"<<endl;
        do
           {
               a=getch();
           } while (a<'0' || a>='7');
           curatare_ecran();
           switch (a)
           {
               case '0':break;
               case '1':afisare();system ("pause");break;
               case '2':cautare();system ("pause");break;
               case '3':adaugare();system ("pause");break;
               case '4':stergere();system ("pause");break;
               case '5':modificare();system ("pause");break;
               case '6':ordonare();system("pause");break;
           }
    }while (a!='0');
}
void meniu_camere()
{
    char a;

    do
    {
        curatare_ecran();
        cout<<"Aceasta este sectiunea de gestiune a camerelor!"<<endl;
        cout<<"Apasati tasta corespunzatoare numarului de ordine a actiunii pe care doriti sa o efectuati! "<<endl<<endl;
        cout<<"1. Afisarea camerelor disponibile"<<endl;
        cout<<"2. Adaugarea unei camere"<<endl;
        cout<<"3. Rezervarea unei camere"<<endl;
        cout<<"4. Ordonarea camerelor"<<endl;
        cout<<"0. Iesire din sectiuena camere"<<endl;
        do
           {
               a=getch();
           } while (a<'0' || a>='5');
           curatare_ecran();
           switch (a)
           {
               case '0':break;
               case '1':camere();system ("pause");break;
               case '2':adaugare_camere();system ("pause");break;
               case '3':rezervare();system ("pause");break;
               case '4':ordonare_camere();system ("pause");break;
           }
    }while (a!='0');
}

void meniu_recenzii()
{
    char a;

    do
    {
        curatare_ecran();
        cout<<"Aceasta este sectiunea de gestiune a recenzilor oferite de clientii care au folosit serviciile noastre!"<<endl;
        cout<<"Apasati tasta corespunzatoare numarului de ordine a actiunii pe care doriti sa o efectuati! "<<endl<<endl;
        cout<<"1. Prezentarea recenziilor clientilor"<<endl;
        cout<<"2. Adaugarea recenziei unui client"<<endl;
        cout<<"3. Sugestiile clientilor"<<endl;
        cout<<"4. Reclamatiile clientilor"<<endl;
        cout<<"0. Iesire din sectiunea clienti"<<endl;
        do
           {
               a=getch();
           } while (a<'0' || a>='5');
           curatare_ecran();
           switch (a)
           {
               case '0':break;
               case '1':clienti();system ("pause");break;
               case '2':adaugare_clienti();system ("pause");break;
               case '3':sugestie();system ("pause");break;
               case '4':reclamatie();system ("pause");break;
           }
    }while (a!='0');
}

void meniu_principal()
{
    char a;
    do
    {
        curatare_ecran();
        cout<<"Bine ati venit in zona de gestiune a hotelului!"<<endl;
        cout<<"Apasati tasta corespunzatoare numarului de ordine a sectiunii pe care doriti sa o accesati! "<<endl<<endl;
        cout<<"1. Sectiunea angajati"<<endl;
        cout<<"2. Sectiunea camere"<<endl;
        cout<<"3. Sectiunea clienti"<<endl;
        cout<<"0. Iesire din aplicatie"<<endl;
        do
           {
               a=getch();
           } while (a<'0' || a>='4');
           curatare_ecran();
           switch (a)
           {
               case '0':cout<<"Ati parasit zona de gestiune a hotelului nostru. Pentru mai multe detalii nu ezitati sa ne contactati! "<<endl;break;
               case '1':meniu_angajati();system ("pause");break;
               case '2':meniu_camere();system ("pause");break;
               case '3':meniu_recenzii();system ("pause");break;
           }
    }while (a!='0');
}



int main()
{
ifstream in ("angajati.in");
in>>n;
 for (int i=1;i<=n;i++)
    in>>v[i].nume>>v[i].prenume>>v[i].varsta>>v[i].salariu;
    in.close();

ifstream f ("camere.in");
f>>m;
for (int i=1;i<=m;i++)
    f>>c[i].numar>>c[i].tip>>c[i].cost;
    in.close();

ifstream g ("clienti.in");
g>>p;
for (int i=1;i<=p;i++)
{
    g>>d[i].nume2>>d[i].prenume2>>d[i].recenzie;
    g.getline(d[i].sugestie,200);
    g.getline(d[i].reclamatie,200);
}

    in.close();

        meniu_principal();

    return 0;
}
