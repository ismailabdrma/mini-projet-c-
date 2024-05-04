#include <iostream>
#include <list>
#include <deque>
#include <vector>
#include <algorithm>
#include <string>
#include <iomanip>
//ismailabdrma karim tariq 3IIRG1 
using namespace std;
//class date et 1 fonction date pour gere les date de bail 
class date {
private:
    int ye_date, mo_date, day_date;
public:
    date(int yeinput, int moinput, int dayinput) : ye_date(yeinput), mo_date(moinput), day_date(dayinput) {}

    void display_Date() const {
        cout << setfill('0') << setw(2) << day_date << "/" << setw(2) << mo_date << "/" << ye_date << endl;}}; //fonction tre simple pour display date
 //class locataire simplz class des fonction simple just pour ajoute des locataaire et fonction d affiche and  fonction men 
class locataire {
private:
    static int cptlocat;
    int id_locataire;
    string nom_locataire;
    string prenom_locataire;
    string CIN_locataire;
public:
    locataire(string smiakeray, string kniakerai, string _CIN) : id_locataire(++cptlocat), nom_locataire(smiakeray), prenom_locataire(kniakerai), CIN_locataire(_CIN) {}
//des geters pas de seters 
    int getid_locat() const { return id_locataire; }
    const string& getNom_locat() const { return nom_locataire; }
    const string& getprenom_locat() const { return prenom_locataire; }
      const string&  getCIN_locat() const { return CIN_locataire; }

    static void ajouter_Locataire(deque<locataire>& locataires) { //fonction ajouter input locataires 
        string nom, prenom, CIN;
        cout << "Nom : ";
        cin >> nom;
        cout << "Prenom : ";
        cin >> prenom;
        cout << "CIN : ";
        cin >> CIN;
        locataires.emplace_back(nom, prenom, CIN);
        cout << "Locataire ajoute avec succès !" << endl;
        system("cls"); }
    static void afficher_Locataires(const deque<locataire>& locataires) { //fonction  pour affiche id name prenom cin  de locataire
        cout << "Liste des locataires :" << endl;
        for (const auto& locataire : locataires) {
            cout << "ID locataire :" << locataire.getid_locat() << endl;
             cout << "Nom locataire :" << locataire.getNom_locat() << "  prenom locataire " << locataire.getprenom_locat() <<endl;
            cout << "CIN locataire :" << locataire.getCIN_locat() << endl;  }}
    static void gerer_Menu_Locataires(deque<locataire>& locataires) { // fonction gere menu 
        int choix;
        do {
           
            cout << "\nGestion des locataires\n";
            cout << "1)ajouter un locataire\n";
            cout << "2)afficher la liste des locataires\n";
            cout << "0)Quitter\n";
            cout << "Choix : ";
            cin >> choix;

            switch (choix) {
                case 1:
                  system("cls");
                    ajouter_Locataire(locataires);
                    break;
                case 2:
                system("cls");
                    afficher_Locataires(locataires);
                    break;
                default:
                 system("cls");
                    cout << "Choix invalide. Veuillez reessayer.\n";
                   
                    break;
            }
        } while (choix != 0); }};//fin class locataire 

// class proprietaire just simple one no complex foction
class Proprietaire {
private:
    static int cpt_prop;
    int id_prop;
    string nom_prop;
    string prenom_prop;
    string CIN_propr;
public:
    Proprietaire(string moledare, string kniatempledare,string cinmoledare) : id_prop(++cpt_prop), nom_prop(moledare), prenom_prop(kniatempledare) ,CIN_propr(cinmoledare){}
    int getId_prop() const { return id_prop; }
    const string& getNom_prop() const { return nom_prop ; }
    const string& get_Prenomprop() const { return prenom_prop; }
    const string& get_cinprop() const {return CIN_propr;}//geters de class proprietaire

    static void ajouter_proprietaire(list<Proprietaire>& proprietaires_inp) {
        string nom, prenom,CIN;
        cout << "Nom proprietaire:\n ";
        getline(cin,nom);
        cout << "Prenom proprietaire: \n";
         getline(cin,prenom);
        cout<< "CIN propritaire: ";
        getline(cin, CIN);
        proprietaires_inp.emplace_back(nom, prenom,CIN);
        cout << "proprietaire et ajoute" << endl;
        system("cls");}//fonction ajouter take input list proprietaire pour ajoute proprietaire
    static void afficher_proprietaires(const list<Proprietaire>& proprietaires_input) {
        cout << "liste des proprietaires:\n" << endl;
        for (const auto& proprietaire : proprietaires_input) {
            cout << "id proprietaire : " << proprietaire.getId_prop() ;
           cout  << "  NOM proprietaire: " << proprietaire.getNom_prop() << "\n " << proprietaire.get_Prenomprop() <<"   "<< "CIN :" << proprietaire.get_cinprop() << endl ;   }}// fin fonction aficher pour affiche nom id cin de proprieataire 

    static void gerer_Menu_Proprietaires(list<Proprietaire>& proprietaires_input) {
        int choix;
        do {
            cout << "\n Gestion des proprietaires option :\n";
            cout << "1)ajouter un proprietaire\n";
            cout << "2)afficher la liste des proprietaires\n";
            cout << "0)Quitter\n";
            cout << "Choix:";
            cin >> choix;
            switch (choix) {
                case 1:
                      system("cls");
                    ajouter_proprietaire(proprietaires_input);
                    break;
                case 2:
                     system("cls");
                    afficher_proprietaires(proprietaires_input);
                    break;
                default:
                      system("cls");
                    cout << "Choix invalide";
                    break; } } while (choix != 0); }};//fonction geremenu focntion qui afiche first et gere tous les fonction de class 
            //fin class proprietaire sa role ajoute et affiche des proprietaires

//class logement class pour gere les logement  pas simple car you need to assure the owenre shipe of the proprietaire for chaque logement that the hard part
class Logement {
private:
    static int cpt_logement;
    int reference_loge;
    int nombrePieces_loge;
    float surface_loge;
    float charges_loge;
    string adresse_loge;
    const Proprietaire* le_proprietaire; //pour assure chaque longement sa propre owner(proprietaire) 

public:
    Logement(int piecesinp, float surfaceinp, float chargesinp, const string& adresseinp, const Proprietaire& proprietaireinp)
        : reference_loge(++cpt_logement), nombrePieces_loge(piecesinp), surface_loge(surfaceinp), charges_loge(chargesinp), adresse_loge(adresseinp), le_proprietaire(&proprietaireinp) {}

    int get_Referencelog() const { return reference_loge; }
    int get_NombrePieceslog() const { return nombrePieces_loge; }
    float get_Surfacelog() const { return surface_loge; }
    float get_Chargeslog() const { return charges_loge; }
    const string& get_Adresselog() const { return adresse_loge; }
    const Proprietaire* get_Proprietairelog() const { return le_proprietaire; }

    void modifier(int newPieces, float newSurface, float newCharges, const string& newAdresse) { // simple fonction modifier 
        nombrePieces_loge= newPieces;
        surface_loge = newSurface;
        charges_loge = newCharges;
        adresse_loge= newAdresse;
    }

    static void ajouterLogement(deque<Logement>& logements, const list<Proprietaire>& proprietairesinpu) { //fonction ajouter pour ajouter les logement et avant that the program give hand to user to pick id the proprietaire pur assure chaque logement par son owner 
        system("cls");
        int pieces;
        float surface, charges;
        string adresse;
        cout << "nombre de pieces: ";
        cin >> pieces;
        cout << "surface: ";
        cin >> surface;
        cout << "charges: ";
        cin >> charges;
        cin.ignore(); 
        cout << "adresse: ";
        std::getline(cin, adresse);
        cout << "pick le proprietaire par son ID:" << endl;
        Proprietaire::afficher_proprietaires(proprietairesinpu); // affiche list the owneners for user to chosi the propritaire 
        int proprietaireID;
        cout << "ID du proprietaire:\n";
        cin >> proprietaireID;

        const Proprietaire* le_proprietaire = nullptr; // check if the user choisi id qui se trouve dans la list 
        for (const auto& proprietaire : proprietairesinpu) {
            if (proprietaire.getId_prop() == proprietaireID) {
                le_proprietaire = &proprietaire;
                break;
            }
        }

        if (le_proprietaire == nullptr) {
            cout << "Aucun proprietaire trouve avec cet ID." << endl;
         
            return;
        }

        logements.emplace_back(pieces, surface, charges, adresse, *le_proprietaire);
        cout << "logement et ajoute" << endl;
       
       }

    static void modifierOuSupprimer(deque<Logement>& logements) { //fonction pour modifier logement user entre reference de logement if si trouver give the access to modifier or delete the longement  else affiche lsg non trouver 
        int referenc;
        cout << "entrez la reference du logement a modifier  ou   supprimer:";
        cin >> referenc;

        bool found = false;
        for (auto it = logements.begin(); it != logements.end(); ++it) {
            if (it->get_Referencelog() == referenc) {
                found = true;
                int choix;
                cout << "Logement trouve. Que voulez-vous faire?\n" << endl;
                cout << "1 modifier le logement\n" << endl;
                cout << "2 supprimer le logement\n" << endl;
                cout << "Choix : ";
                cin >> choix;
                if (choix == 1) {
                    int newPieces;
                    float newSurface, newCharges;
                    string newAdresse;
                    cout << "nouveau nombre de pièces:";
                    cin >> newPieces;
                    cout << "nouvelle surface:";
                    cin >> newSurface;
                    cout << "nouvelles charges:";
                    cin >> newCharges;
                    cin.ignore(); 
                    cout << "Nouvelle adresse:";
                    std::getline(cin, newAdresse);
                    it->modifier(newPieces, newSurface, newCharges, newAdresse);
                    cout << "logement et modifie " << endl;
                    
                    break;
                } else if (choix == 2) {
                    logements.erase(std::remove_if(logements.begin(), logements.end(),
                                                   [&](const Logement& l) { return l.get_Referencelog() == referenc; }),
                                    logements.end());
                    cout << "logement  supprime " << endl;
                   
                    break;
                } else {
                    cout << "Choix invalide" << endl;} } }
        if (!found) {
            cout << "non logement trouve " << endl;   } }

     static void afficher__Logements(const deque<Logement>& logements) {  //focntion affiche pour affiche les attribut de longement + the owner the proprietaire de chaque logement 
        cout << "liste des logements" << endl;
        for (const auto& logement : logements) {
            cout << "reference de logemenet et " << logement.get_Referencelog() << " Adresse : " << logement.get_Adresselog()
                 << "\nnombre piece " << logement.get_NombrePieceslog() << ",\n Surface : " << logement.get_Surfacelog()
                 << "charges" << logement.get_Chargeslog() << endl;
                cout<< "proprietaire :\n" << logement.get_Proprietairelog()->getNom_prop() << "  " << logement.get_Proprietairelog()->get_Prenomprop() <<"  CIN" <<logement.get_Proprietairelog()->get_cinprop()<<endl;}}

    static void gerer_Menu_Logements(deque<Logement>& logements, const list<Proprietaire>& proprietairesin) { //focntion menu pour gere les fonction de longement 
        int choix;
        do { 
            
            cout << "gestion des logements\n";
            cout << "1 ajouter un logement\n";
            cout << "2 modifier ou supprimer un logement\n";
            cout << "3 afficher la liste des logements\n";
            cout << "0 quitter\n";
            cout << "Choix:";
            cin >> choix;


            switch (choix) {
                case 1:
                     system("cls"); 
                    ajouterLogement(logements, proprietairesin);
                    break;
                case 2:
                    system("cls");
                    modifierOuSupprimer(logements);
                    break;
                case 3:
                    system("cls");
                    afficher__Logements(logements);
                    break;
               
                default:
                    system("cls");
                    cout << "Choix invalide. Veuillez reessayer.\n";
                    break;
                
}} while (choix != 0 ); system("cls");}}; // fin class logement
//class bais pour ajouter ou suprimer a abail 
class Bail {
private:
    static int cpt_Bail;
    int numero_ba;
    float loyer_ba;
    date debut_ba;
    int dure_ba;
    const locataire* leLocataire_bai;
    const Logement* leLogement_ba;

public:
    Bail(float baloyer, const date& badebut, int baduree, const locataire* locba, const Logement* logba)
        : numero_ba(++cpt_Bail), loyer_ba(baloyer), debut_ba(badebut), dure_ba(baduree), leLocataire_bai(locba), leLogement_ba(logba) {}

    void contratDeBail() const {
        cout << "      numero du bail:" << numero_ba << endl;
        cout << "      date de debut du bail";
        debut_ba.display_Date();
        cout << "      duree du bail (en mois):" << dure_ba << endl;
        cout << "      locataire:" << leLocataire_bai->getNom_locat() << " " << leLocataire_bai->getprenom_locat() << "(CIN:"
             << leLocataire_bai->getCIN_locat() << ")" << endl;
        cout << "      proprietaire:" << leLogement_ba->get_Proprietairelog()->getNom_prop() << " " << leLogement_ba->get_Proprietairelog()->get_Prenomprop() << "(CIN: " << leLogement_ba->get_Proprietairelog()->get_cinprop() <<")"<<endl;
        cout << "      details du logement:" << endl;
        cout << "      reference logement:" << leLogement_ba->get_Referencelog() << endl;
         cout << "     loyer TTC:" << loyer_ba << endl;
        cout << "      adresse:" << leLogement_ba->get_Adresselog() << endl;
        cout << "      surface:" << leLogement_ba->get_Surfacelog() << " m²" << endl;
        cout << "      nombre de pièces:" << leLogement_ba->get_NombrePieceslog() << endl;
        float totalAPayer = 2 * loyer_ba + leLogement_ba->get_Chargeslog();
        cout << "------------------------------------------------------------------------------total a payer:" << totalAPayer << "DH"<<endl;}
 
    static void ajouter_Bail(vector<Bail>& bails, deque<Logement>& logements, deque<locataire>& locatairesin) { //pour ajoute les bails
        cout << "ajout d'un nouveau bail:" << endl;

        cout << "Choisissez le locataire par son ID :" << endl; // choisir id de locataire and afficher list 
        locataire::afficher_Locataires(locatairesin);
        int locataireID;
        cout << "ID du locataire : ";
        cin >> locataireID;

        const locataire* leLocataire = nullptr;
        for (const auto& locataire : locatairesin) {
            if (locataire.getid_locat() == locataireID) {
                leLocataire = &locataire;
                break;
            }
        }

        if (leLocataire == nullptr) { //if the user give id de locataire pas on list
            cout << "aucun locataire trouve" << endl;
            return;
        }
        cout << "Choisissez le logement par sa reference :" << endl; //choix reference de logement and before that the code affiche the list of the logement availebl
        Logement::afficher__Logements(logements);
        int logementRef;
        cout << "reference du logement:";
        cin >> logementRef;

        const Logement* leLogement = nullptr;
        for (const auto& logement : logements) {
            if (logement.get_Referencelog() == logementRef) {
                leLogement = &logement;
                break;
            }
        }

        if (leLogement == nullptr) {
            cout << "Aucun logement trouve avec cette reference." << endl;
            return;
        }

        float loyer;
        cout << "loyer ttc:";
        cin >> loyer;

        int duree;
        cout << "duree du bail (en mois):";
        cin >> duree;

        cout << "date de debut du bail:" << endl;
        int year, month, day;
        cout << "Annee:";
        cin >> year;
        cout << "mois:";
        cin >> month;
        cout << "jour:";
        cin >> day;
        date debutBail(year, month, day);

        bails.emplace_back(loyer, debutBail, duree, leLocataire, leLogement);

        cout << "bail ajoute " << endl;
    }
    

    static void afficher_Bailsl(const vector<Bail>& bails) {
        cout << "Liste des baux :" << endl;
        for (const auto& bail : bails) {
            bail.contratDeBail();
            cout << "-----------------------------------" << endl;
        }
    }

    static void remplirEnsembleBail(vector<Bail>& ensembleBail, deque<Logement>& logements, deque<locataire>& locataires) {//fonction pour rempire des bail
        int choix;
        do {
            cout << "Ajout d'un nouveau bail :" << endl;
            ajouter_Bail(ensembleBail, logements, locataires);

            cout << "Voulez-vous ajouter un autre bail ? 1 pour Oui, 0 pour Non ";
            cin >> choix; } while (choix != 0);
    }
      static void supprimer_Bail_Choisi(vector<Bail>& ensembleBail, int idBail) {//fonction pour suprimer bail choiw by user input bail and id de bail want to delete 
    auto it = std::find_if(ensembleBail.begin(), ensembleBail.end(),
                           [idBail](const Bail& b) { return b.cpt_Bail == idBail; });
    if (it != ensembleBail.end()) {
        ensembleBail.erase(it);
        cout << "Le bail avec l'ID" << idBail << " a été supprimé avec succès"<< endl;
    } else {
        cout << "Aucun bail trouvé avec l'ID" << idBail  << endl;
    }
}


    static void gerer_Menu_Bailsl(vector<Bail>& bails, deque<Logement>& logements, deque<locataire>& locatairesin) { // fonction gestion menu de bail 
        int choix,id;
        do {
            cout << "\nGestion des bail\n";
            cout << "1. Ajouter un bail\n";
            cout << "2. Afficher la liste des baux\n";
            cout << "3. suprime de bail\n    ";
            cout << "4. deppase 7000 and 3 piece and surface  moin de 80m2\n ";
            cout << "0. Quitter\n";
            cout << "Choix : ";
            cin >> choix;

            switch (choix) {
                case 1:
                    system("cls");
                    remplirEnsembleBail(bails, logements, locatairesin);
                    break;
                case 2:
                    system("cls");
                    afficher_Bailsl(bails);
                    break;
                case 3: 
                      system("cls");
                      cout<<"id de bail pour suprime ";
                      cin >> id;
                    supprimer_Bail_Choisi(bails,id);
                    break;
                case 4:
              
                   break;
                case 0:
                       system("cls");
                    cout << "fin de la gestion des baux.\n";
                    break;
                default:
                    system("cls");
                    cout << "Choix invalide. Veuillez reessayer\n";
                    break;
            }
            

            
        } while (choix != 0); }};//fin class bail

int locataire::cptlocat = 0;//conteur reference  locataire 
int Logement::cpt_logement = 0;//conteur refrence logement 

int Proprietaire::cpt_prop = 0;//conteur refrence proprirtaire
int Bail::cpt_Bail = 0; // conteure refrence bail
//main foocntion declration les class 
int main() {
    list<Proprietaire> proprietaires;
    deque<Logement> logements;
    deque<locataire> locataires;
    vector<Bail> bails;

    int choix;
    do {
        cout << " menu principal \n";
        cout << "1 gestion des locataires \n";
        cout << "2 gestion des proprietaires \n";
        cout << "3 gestion des logements\n ";
        cout << "4 gestion des bais \n";
        cout << "0 quitter \n";
        cout << "Choix : ";
        cin >> choix;

        switch (choix) {
            case 1:
                system("cls");
                locataire::gerer_Menu_Locataires(locataires);
                break;
            case 2:
                system("cls");
                Proprietaire::gerer_Menu_Proprietaires(proprietaires);
                break;
            case 3:
                system("cls");
                Logement::gerer_Menu_Logements(logements, proprietaires);
                break;
            case 4:
                 system("cls");
                Bail::gerer_Menu_Bailsl(bails, logements, locataires);
                break;
            case 0:
                 system("cls");
                cout << "Fin du programme.\n";
                break;
            default:
                  system("cls");
                cout << "Choix invalide. Veuillez reessayer.\n";
                break;
        }} while (choix != 0);

    return 0;}
    // fin program please create 1 ,2,3 before creating any bail 
    //  by ismail abdrma and karim tariq /project N:6/3IIRG1/EMSICASAORANGE//#include <iostream>
#include <list>
#include <deque>
#include <vector>
#include <algorithm>
#include <string>
#include <iomanip>
//ismailabdrma karim tariq 3IIRG1 
using namespace std;
//class date et 1 fonction date pour gere les date de bail 
class date {
private:
    int ye_date, mo_date, day_date;
public:
    date(int yeinput, int moinput, int dayinput) : ye_date(yeinput), mo_date(moinput), day_date(dayinput) {}

    void display_Date() const {
        cout << setfill('0') << setw(2) << day_date << "/" << setw(2) << mo_date << "/" << ye_date << endl;}}; //fonction tre simple pour display date
 //class locataire simplz class des fonction simple just pour ajoute des locataaire et fonction d affiche and  fonction men 
class locataire {
private:
    static int cptlocat;
    int id_locataire;
    string nom_locataire;
    string prenom_locataire;
    string CIN_locataire;
public:
    locataire(string smiakeray, string kniakerai, string _CIN) : id_locataire(++cptlocat), nom_locataire(smiakeray), prenom_locataire(kniakerai), CIN_locataire(_CIN) {}
//des geters pas de seters 
    int getid_locat() const { return id_locataire; }
    const string& getNom_locat() const { return nom_locataire; }
    const string& getprenom_locat() const { return prenom_locataire; }
      const string&  getCIN_locat() const { return CIN_locataire; }

    static void ajouter_Locataire(deque<locataire>& locataires) { //fonction ajouter input locataires 
        string nom, prenom, CIN;
        cout << "Nom : ";
        cin >> nom;
        cout << "Prenom : ";
        cin >> prenom;
        cout << "CIN : ";
        cin >> CIN;
        locataires.emplace_back(nom, prenom, CIN);
        cout << "Locataire ajoute avec succès !" << endl;
        system("cls"); }
    static void afficher_Locataires(const deque<locataire>& locataires) { //fonction  pour affiche id name prenom cin  de locataire
        cout << "Liste des locataires :" << endl;
        for (const auto& locataire : locataires) {
            cout << "ID locataire :" << locataire.getid_locat() << endl;
             cout << "Nom locataire :" << locataire.getNom_locat() << "  prenom locataire " << locataire.getprenom_locat() <<endl;
            cout << "CIN locataire :" << locataire.getCIN_locat() << endl;  }}
    static void gerer_Menu_Locataires(deque<locataire>& locataires) { // fonction gere menu 
        int choix;
        do {
           
            cout << "\nGestion des locataires\n";
            cout << "1)ajouter un locataire\n";
            cout << "2)afficher la liste des locataires\n";
            cout << "0)Quitter\n";
            cout << "Choix : ";
            cin >> choix;

            switch (choix) {
                case 1:
                  system("cls");
                    ajouter_Locataire(locataires);
                    break;
                case 2:
                system("cls");
                    afficher_Locataires(locataires);
                    break;
                default:
                 system("cls");
                    cout << "Choix invalide. Veuillez reessayer.\n";
                   
                    break;
            }
        } while (choix != 0); }};//fin class locataire 

// class proprietaire just simple one no complex foction
class Proprietaire {
private:
    static int cpt_prop;
    int id_prop;
    string nom_prop;
    string prenom_prop;
    string CIN_propr;
public:
    Proprietaire(string moledare, string kniatempledare,string cinmoledare) : id_prop(++cpt_prop), nom_prop(moledare), prenom_prop(kniatempledare) ,CIN_propr(cinmoledare){}
    int getId_prop() const { return id_prop; }
    const string& getNom_prop() const { return nom_prop ; }
    const string& get_Prenomprop() const { return prenom_prop; }
    const string& get_cinprop() const {return CIN_propr;}//geters de class proprietaire

    static void ajouter_proprietaire(list<Proprietaire>& proprietaires_inp) {
        string nom, prenom,CIN;
        cout << "Nom proprietaire:\n ";
        getline(cin,nom);
        cout << "Prenom proprietaire: \n";
         getline(cin,prenom);
        cout<< "CIN propritaire: ";
        getline(cin, CIN);
        proprietaires_inp.emplace_back(nom, prenom,CIN);
        cout << "proprietaire et ajoute" << endl;
        system("cls");}//fonction ajouter take input list proprietaire pour ajoute proprietaire
    static void afficher_proprietaires(const list<Proprietaire>& proprietaires_input) {
        cout << "liste des proprietaires:\n" << endl;
        for (const auto& proprietaire : proprietaires_input) {
            cout << "id proprietaire : " << proprietaire.getId_prop() ;
           cout  << "  NOM proprietaire: " << proprietaire.getNom_prop() << "\n " << proprietaire.get_Prenomprop() <<"   "<< "CIN :" << proprietaire.get_cinprop() << endl ;   }}// fin fonction aficher pour affiche nom id cin de proprieataire 

    static void gerer_Menu_Proprietaires(list<Proprietaire>& proprietaires_input) {
        int choix;
        do {
            cout << "\n Gestion des proprietaires option :\n";
            cout << "1)ajouter un proprietaire\n";
            cout << "2)afficher la liste des proprietaires\n";
            cout << "0)Quitter\n";
            cout << "Choix:";
            cin >> choix;
            switch (choix) {
                case 1:
                      system("cls");
                    ajouter_proprietaire(proprietaires_input);
                    break;
                case 2:
                     system("cls");
                    afficher_proprietaires(proprietaires_input);
                    break;
                default:
                      system("cls");
                    cout << "Choix invalide";
                    break; } } while (choix != 0); }};//fonction geremenu focntion qui afiche first et gere tous les fonction de class 
            //fin class proprietaire sa role ajoute et affiche des proprietaires

//class logement class pour gere les logement  pas simple car you need to assure the owenre shipe of the proprietaire for chaque logement that the hard part
class Logement {
private:
    static int cpt_logement;
    int reference_loge;
    int nombrePieces_loge;
    float surface_loge;
    float charges_loge;
    string adresse_loge;
    const Proprietaire* le_proprietaire; //pour assure chaque longement sa propre owner(proprietaire) 

public:
    Logement(int piecesinp, float surfaceinp, float chargesinp, const string& adresseinp, const Proprietaire& proprietaireinp)
        : reference_loge(++cpt_logement), nombrePieces_loge(piecesinp), surface_loge(surfaceinp), charges_loge(chargesinp), adresse_loge(adresseinp), le_proprietaire(&proprietaireinp) {}

    int get_Referencelog() const { return reference_loge; }
    int get_NombrePieceslog() const { return nombrePieces_loge; }
    float get_Surfacelog() const { return surface_loge; }
    float get_Chargeslog() const { return charges_loge; }
    const string& get_Adresselog() const { return adresse_loge; }
    const Proprietaire* get_Proprietairelog() const { return le_proprietaire; }

    void modifier(int newPieces, float newSurface, float newCharges, const string& newAdresse) { // simple fonction modifier 
        nombrePieces_loge= newPieces;
        surface_loge = newSurface;
        charges_loge = newCharges;
        adresse_loge= newAdresse;
    }

    static void ajouterLogement(deque<Logement>& logements, const list<Proprietaire>& proprietairesinpu) { //fonction ajouter pour ajouter les logement et avant that the program give hand to user to pick id the proprietaire pur assure chaque logement par son owner 
        system("cls");
        int pieces;
        float surface, charges;
        string adresse;
        cout << "nombre de pieces: ";
        cin >> pieces;
        cout << "surface: ";
        cin >> surface;
        cout << "charges: ";
        cin >> charges;
        cin.ignore(); 
        cout << "adresse: ";
        std::getline(cin, adresse);
        cout << "pick le proprietaire par son ID:" << endl;
        Proprietaire::afficher_proprietaires(proprietairesinpu); // affiche list the owneners for user to chosi the propritaire 
        int proprietaireID;
        cout << "ID du proprietaire:\n";
        cin >> proprietaireID;

        const Proprietaire* le_proprietaire = nullptr; // check if the user choisi id qui se trouve dans la list 
        for (const auto& proprietaire : proprietairesinpu) {
            if (proprietaire.getId_prop() == proprietaireID) {
                le_proprietaire = &proprietaire;
                break;
            }
        }

        if (le_proprietaire == nullptr) {
            cout << "Aucun proprietaire trouve avec cet ID." << endl;
         
            return;
        }

        logements.emplace_back(pieces, surface, charges, adresse, *le_proprietaire);
        cout << "logement et ajoute" << endl;
       
       }

    static void modifierOuSupprimer(deque<Logement>& logements) { //fonction pour modifier logement user entre reference de logement if si trouver give the access to modifier or delete the longement  else affiche lsg non trouver 
        int referenc;
        cout << "entrez la reference du logement a modifier  ou   supprimer:";
        cin >> referenc;

        bool found = false;
        for (auto it = logements.begin(); it != logements.end(); ++it) {
            if (it->get_Referencelog() == referenc) {
                found = true;
                int choix;
                cout << "Logement trouve. Que voulez-vous faire?\n" << endl;
                cout << "1 modifier le logement\n" << endl;
                cout << "2 supprimer le logement\n" << endl;
                cout << "Choix : ";
                cin >> choix;
                if (choix == 1) {
                    int newPieces;
                    float newSurface, newCharges;
                    string newAdresse;
                    cout << "nouveau nombre de pièces:";
                    cin >> newPieces;
                    cout << "nouvelle surface:";
                    cin >> newSurface;
                    cout << "nouvelles charges:";
                    cin >> newCharges;
                    cin.ignore(); 
                    cout << "Nouvelle adresse:";
                    std::getline(cin, newAdresse);
                    it->modifier(newPieces, newSurface, newCharges, newAdresse);
                    cout << "logement et modifie " << endl;
                    
                    break;
                } else if (choix == 2) {
                    logements.erase(std::remove_if(logements.begin(), logements.end(),
                                                   [&](const Logement& l) { return l.get_Referencelog() == referenc; }),
                                    logements.end());
                    cout << "logement  supprime " << endl;
                   
                    break;
                } else {
                    cout << "Choix invalide" << endl;} } }
        if (!found) {
            cout << "non logement trouve " << endl;   } }

     static void afficher__Logements(const deque<Logement>& logements) {  //focntion affiche pour affiche les attribut de longement + the owner the proprietaire de chaque logement 
        cout << "liste des logements" << endl;
        for (const auto& logement : logements) {
            cout << "reference de logemenet et " << logement.get_Referencelog() << " Adresse : " << logement.get_Adresselog()
                 << "\nnombre piece " << logement.get_NombrePieceslog() << ",\n Surface : " << logement.get_Surfacelog()
                 << "charges" << logement.get_Chargeslog() << endl;
                cout<< "proprietaire :\n" << logement.get_Proprietairelog()->getNom_prop() << "  " << logement.get_Proprietairelog()->get_Prenomprop() <<"  CIN" <<logement.get_Proprietairelog()->get_cinprop()<<endl;}}

    static void gerer_Menu_Logements(deque<Logement>& logements, const list<Proprietaire>& proprietairesin) { //focntion menu pour gere les fonction de longement 
        int choix;
        do { 
            
            cout << "gestion des logements\n";
            cout << "1 ajouter un logement\n";
            cout << "2 modifier ou supprimer un logement\n";
            cout << "3 afficher la liste des logements\n";
            cout << "0 quitter\n";
            cout << "Choix:";
            cin >> choix;


            switch (choix) {
                case 1:
                     system("cls"); 
                    ajouterLogement(logements, proprietairesin);
                    break;
                case 2:
                    system("cls");
                    modifierOuSupprimer(logements);
                    break;
                case 3:
                    system("cls");
                    afficher__Logements(logements);
                    break;
               
                default:
                    system("cls");
                    cout << "Choix invalide. Veuillez reessayer.\n";
                    break;
                
}} while (choix != 0 ); system("cls");}}; // fin class logement
//class bais pour ajouter ou suprimer a abail 
class Bail {
private:
    static int cpt_Bail;
    int numero_ba;
    float loyer_ba;
    date debut_ba;
    int dure_ba;
    const locataire* leLocataire_bai;
    const Logement* leLogement_ba;

public:
    Bail(float baloyer, const date& badebut, int baduree, const locataire* locba, const Logement* logba)
        : numero_ba(++cpt_Bail), loyer_ba(baloyer), debut_ba(badebut), dure_ba(baduree), leLocataire_bai(locba), leLogement_ba(logba) {}

    void contratDeBail() const {
        cout << "      numero du bail:" << numero_ba << endl;
        cout << "      date de debut du bail";
        debut_ba.display_Date();
        cout << "      duree du bail (en mois):" << dure_ba << endl;
        cout << "      locataire:" << leLocataire_bai->getNom_locat() << " " << leLocataire_bai->getprenom_locat() << "(CIN:"
             << leLocataire_bai->getCIN_locat() << ")" << endl;
        cout << "      proprietaire:" << leLogement_ba->get_Proprietairelog()->getNom_prop() << " " << leLogement_ba->get_Proprietairelog()->get_Prenomprop() << "(CIN: " << leLogement_ba->get_Proprietairelog()->get_cinprop() <<")"<<endl;
        cout << "      details du logement:" << endl;
        cout << "      reference logement:" << leLogement_ba->get_Referencelog() << endl;
         cout << "     loyer TTC:" << loyer_ba << endl;
        cout << "      adresse:" << leLogement_ba->get_Adresselog() << endl;
        cout << "      surface:" << leLogement_ba->get_Surfacelog() << " m²" << endl;
        cout << "      nombre de pièces:" << leLogement_ba->get_NombrePieceslog() << endl;
        float totalAPayer = 2 * loyer_ba + leLogement_ba->get_Chargeslog();
        cout << "------------------------------------------------------------------------------total a payer:" << totalAPayer << "DH"<<endl;}
 
    static void ajouter_Bail(vector<Bail>& bails, deque<Logement>& logements, deque<locataire>& locatairesin) { //pour ajoute les bails
        cout << "ajout d'un nouveau bail:" << endl;

        cout << "Choisissez le locataire par son ID :" << endl; // choisir id de locataire and afficher list 
        locataire::afficher_Locataires(locatairesin);
        int locataireID;
        cout << "ID du locataire : ";
        cin >> locataireID;

        const locataire* leLocataire = nullptr;
        for (const auto& locataire : locatairesin) {
            if (locataire.getid_locat() == locataireID) {
                leLocataire = &locataire;
                break;
            }
        }

        if (leLocataire == nullptr) { //if the user give id de locataire pas on list
            cout << "aucun locataire trouve" << endl;
            return;
        }
        cout << "Choisissez le logement par sa reference :" << endl; //choix reference de logement and before that the code affiche the list of the logement availebl
        Logement::afficher__Logements(logements);
        int logementRef;
        cout << "reference du logement:";
        cin >> logementRef;

        const Logement* leLogement = nullptr;
        for (const auto& logement : logements) {
            if (logement.get_Referencelog() == logementRef) {
                leLogement = &logement;
                break;
            }
        }

        if (leLogement == nullptr) {
            cout << "Aucun logement trouve avec cette reference." << endl;
            return;
        }

        float loyer;
        cout << "loyer ttc:";
        cin >> loyer;

        int duree;
        cout << "duree du bail (en mois):";
        cin >> duree;

        cout << "date de debut du bail:" << endl;
        int year, month, day;
        cout << "Annee:";
        cin >> year;
        cout << "mois:";
        cin >> month;
        cout << "jour:";
        cin >> day;
        date debutBail(year, month, day);

        bails.emplace_back(loyer, debutBail, duree, leLocataire, leLogement);

        cout << "bail ajoute " << endl;
    }
    

    static void afficher_Bailsl(const vector<Bail>& bails) {
        cout << "Liste des baux :" << endl;
        for (const auto& bail : bails) {
            bail.contratDeBail();
            cout << "-----------------------------------" << endl;
        }
    }

    static void remplirEnsembleBail(vector<Bail>& ensembleBail, deque<Logement>& logements, deque<locataire>& locataires) {//fonction pour rempire des bail
        int choix;
        do {
            cout << "Ajout d'un nouveau bail :" << endl;
            ajouter_Bail(ensembleBail, logements, locataires);

            cout << "Voulez-vous ajouter un autre bail ? 1 pour Oui, 0 pour Non ";
            cin >> choix; } while (choix != 0);
    }
      static void supprimer_Bail_Choisi(vector<Bail>& ensembleBail, int idBail) {//fonction pour suprimer bail choiw by user input bail and id de bail want to delete 
    auto it = std::find_if(ensembleBail.begin(), ensembleBail.end(),
                           [idBail](const Bail& b) { return b.cpt_Bail == idBail; });
    if (it != ensembleBail.end()) {
        ensembleBail.erase(it);
        cout << "Le bail avec l'ID" << idBail << " a été supprimé avec succès"<< endl;
    } else {
        cout << "Aucun bail trouvé avec l'ID" << idBail  << endl;
    }
}


    static void gerer_Menu_Bailsl(vector<Bail>& bails, deque<Logement>& logements, deque<locataire>& locatairesin) { // fonction gestion menu de bail 
        int choix,id;
        do {
            cout << "\nGestion des bail\n";
            cout << "1. Ajouter un bail\n";
            cout << "2. Afficher la liste des baux\n";
            cout << "3. suprime de bail\n    ";
            cout << "4. deppase 7000 and 3 piece and surface  moin de 80m2\n ";
            cout << "0. Quitter\n";
            cout << "Choix : ";
            cin >> choix;

            switch (choix) {
                case 1:
                    system("cls");
                    remplirEnsembleBail(bails, logements, locatairesin);
                    break;
                case 2:
                    system("cls");
                    afficher_Bailsl(bails);
                    break;
                case 3: 
                      system("cls");
                      cout<<"id de bail pour suprime ";
                      cin >> id;
                    supprimer_Bail_Choisi(bails,id);
                    break;
                case 4:
              
                   break;
                case 0:
                       system("cls");
                    cout << "fin de la gestion des baux.\n";
                    break;
                default:
                    system("cls");
                    cout << "Choix invalide. Veuillez reessayer\n";
                    break;
            }
            

            
        } while (choix != 0); }};//fin class bail

int locataire::cptlocat = 0;//conteur reference  locataire 
int Logement::cpt_logement = 0;//conteur refrence logement 

int Proprietaire::cpt_prop = 0;//conteur refrence proprirtaire
int Bail::cpt_Bail = 0; // conteure refrence bail
//main foocntion declration les class 
int main() {
    list<Proprietaire> proprietaires;
    deque<Logement> logements;
    deque<locataire> locataires;
    vector<Bail> bails;

    int choix;
    do {
        cout << " menu principal \n";
        cout << "1 gestion des locataires \n";
        cout << "2 gestion des proprietaires \n";
        cout << "3 gestion des logements\n ";
        cout << "4 gestion des bais \n";
        cout << "0 quitter \n";
        cout << "Choix : ";
        cin >> choix;

        switch (choix) {
            case 1:
                system("cls");
                locataire::gerer_Menu_Locataires(locataires);
                break;
            case 2:
                system("cls");
                Proprietaire::gerer_Menu_Proprietaires(proprietaires);
                break;
            case 3:
                system("cls");
                Logement::gerer_Menu_Logements(logements, proprietaires);
                break;
            case 4:
                 system("cls");
                Bail::gerer_Menu_Bailsl(bails, logements, locataires);
                break;
            case 0:
                 system("cls");
                cout << "Fin du programme.\n";
                break;
            default:
                  system("cls");
                cout << "Choix invalide. Veuillez reessayer.\n";
                break;
        }} while (choix != 0);

    return 0;}
    // fin program please create 1 ,2,3 before creating any bail 
    //  by ismail abdrma and karim tariq /project N:6/3IIRG1/EMSICASAORANGE//
