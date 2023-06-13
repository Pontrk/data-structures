#include <iostream>
#include <chrono>
#include <stdexcept>
#include <fstream>
using namespace std;
using namespace std::chrono;
class Tablica {
private:
    int* tablica;
    int rozmiar;

public:
    Tablica(int r) {
            int x;
            ifstream dane ("/Users/useruser/CLionProjects/ProjektSDIZO/tekst.txt");
            dane >> rozmiar;
            tablica = new int[rozmiar];
            for(int i = 0; i < rozmiar; i++){
                dane >> x;
                tablica[i]=x;
            }
            dane.close();
    }
    ~Tablica() {
        delete[] tablica;
    }
    void wyswietl_tablice()
    {
        cout << "Zawartosc tablicy:" << endl;
        for (int i = 0; i < rozmiar; i++) {
            cout << tablica[i] << " ";
        }
        cout << endl;
    }
    void dodaj_do_tablicy_poczatek(int wartosc) {
        rozmiar++;
        // tworzymy nową tablicę o rozmiarze większym o 1 od oryginalnej tablicy
        int* nowa_tablica = new int[rozmiar];
        // dodajemy nową wartość na poczatek nowej tablicy
        nowa_tablica[0] = wartosc;
        // kopiujemy oryginalną tablicę do nowej tablicy
        for (int i = 1; i < rozmiar; i++) {
            nowa_tablica[i] = tablica[i-1];
        }
        // usuwamy oryginalną tablicę
        delete[] tablica;
        // ustawiamy wskaźnik na początek nowej tablicy
        tablica = nowa_tablica;
    }
    void dodaj_do_tablicy_koniec(int wartosc) {
        // tworzymy nową tablicę o rozmiarze większym o 1 od oryginalnej tablicy
        int* nowa_tablica = new int[rozmiar + 1];
        // kopiujemy oryginalną tablicę do nowej tablicy
        for (int i = 0; i < rozmiar; i++) {
            nowa_tablica[i] = tablica[i];
        }
        // dodajemy nową wartość na koniec nowej tablicy
        nowa_tablica[rozmiar] = wartosc;
        // zwiększamy rozmiar tablicy
        rozmiar++;
        // usuwamy oryginalną tablicę
        delete[] tablica;
        // ustawiamy wskaźnik na początek nowej tablicy
        tablica = nowa_tablica;
    }
    void dodaj_do_tablicy_dowolnie(int wartosc, int indeks){
        // zwiększamy rozmiar tablicy
        rozmiar++;
        if (indeks<=rozmiar){
            // tworzymy nową tablicę o rozmiarze większym o 1 od oryginalnej tablicy
            int* nowa_tablica = new int[rozmiar];
            int j = 0;
            // kopiujemy oryginalną tablicę do nowej tablicy
            for (int i = 0; i < rozmiar; i++) {
                if(i==indeks)
                    nowa_tablica[i] = wartosc;
                else {
                    nowa_tablica[i] = tablica[j];
                    j++;
                }
            }
            // usuwamy oryginalną tablicę
            delete[] tablica;
            // ustawiamy wskaźnik na początek nowej tablicy
            tablica = nowa_tablica;
        }
        else cout<<"Niepoprawny indeks, wykracza poza rozmiar tabeli";
    }
    void usun_pierwszy_element()
    {
        if(rozmiar>=1) {
            // tworzymy nową tablicę o jeden element mniejszą
            int *nowa_tablica = new int[rozmiar - 1];
            // kopiujemy wszystkie elementy z wyjątkiem pierwszego
            for (int i = 1; i < rozmiar; i++) {
                nowa_tablica[i - 1] = tablica[i];
            }
            // zwalniamy pamięć zaalokowaną na pierwotną tablicę
            delete[] tablica;
            // przypisujemy wskaźnikowi tablica adres nowej tablicy
            tablica = nowa_tablica;
        }
        // zmniejszamy rozmiar tablicy o jeden
        rozmiar--;
        if(rozmiar<=0)
            rozmiar=1;
    }
    void usun_ostatni_element(){
        if(rozmiar>=1){
        // tworzymy nową tablicę o jeden element mniejszą
        int* nowa_tablica = new int[rozmiar - 1];
        // kopiujemy wszystkie elementy z wyjątkiem ostatniego
        for (int i = 0; i < rozmiar-1; i++) {
            nowa_tablica[i] = tablica[i];
        }
        // zwalniamy pamięć zaalokowaną na pierwotną tablicę
        delete[] tablica;
        // przypisujemy wskaźnikowi tablica adres nowej tablicy
        tablica = nowa_tablica;}
        // zmniejszamy rozmiar tablicy o jeden
        rozmiar--;
        if(rozmiar<=0)
            rozmiar=1;
    }
    void usun_dowolny_element( int indeks){
        if(rozmiar>=1){
        // tworzymy nową tablicę o jeden element mniejszą
        int* nowa_tablica = new int[rozmiar - 1];
        int j=0;
        // kopiujemy wszystkie elementy z wyjątkiem wybranego
        for (int i = 0; i < rozmiar; i++) {
            if(i!=indeks) {
                nowa_tablica[j] = tablica[i];
                j++;
            }
        }
        // zwalniamy pamięć zaalokowaną na pierwotną tablicę
        delete[] tablica;
        // przypisujemy wskaźnikowi tablica adres nowej tablicy
        tablica = nowa_tablica;}
        // zmniejszamy rozmiar tablicy o jeden
        rozmiar--;
        if(rozmiar<=0)
            rozmiar=1;
    }
    void znajdz_element(int element) {
        int czy_znaleziono = -1;
        for (int i = 0; i < rozmiar; i++) {
            if (tablica[i] == element) {
                cout << i << endl;
                czy_znaleziono = 1;
            }
        }
        if(czy_znaleziono==-1)
            cout << czy_znaleziono << endl;
    }
    void zapisz_do_pliku() {
        // otwieramy plik do zapisu
        ofstream dane("/Users/useruser/CLionProjects/ProjektSDIZO/tekst.txt");
        dane << rozmiar << endl;
        // zapisujemy zawartość tablicy do pliku
        for (int i = 0; i < rozmiar; i++) {
            dane << tablica[i] << endl;
        }
        dane.close();
    }
};
// struktura reprezentująca pojedynczy element listy
struct ElementListy {
    int wartosc;
    ElementListy *poprzedni;
    ElementListy *nastepny;
};
class ListaDwukierunkowa {
private:
    ElementListy *poczatek;
    ElementListy *koniec;
public:
    ListaDwukierunkowa() {
        poczatek = nullptr;
        koniec = nullptr;
    }
    void dodajNaPoczatek(int wartosc) {
        ElementListy *nowyElement = new ElementListy; // utworzenie nowego elementu listy
        nowyElement->wartosc = wartosc; // przypisanie wartości pola 'wartosc' dla nowego elementu
        nowyElement->poprzedni = nullptr;// ustawienie wskaźnika 'poprzedni' na nullptr
        nowyElement->nastepny = poczatek; // ustawienie wskaźnika 'nastepny' na dotychczasowy początek listy
        if (poczatek != nullptr) {  // jeśli lista nie jest pusta
            poczatek->poprzedni = nowyElement;// ustawienie wskaźnika 'poprzedni' dla dotychczasowego początku listy na nowy element
        } else {
            koniec = nowyElement;// jesli lista byla pusta, ustawienie wskaźnika 'koniec' na nowy element, ponieważ jest to jedyny element na liście
        }
        poczatek = nowyElement; // ustawienie wskaźnika 'poczatek' na nowy element
    }
    void dodajNaKoniec(int wartosc) {
        ElementListy *nowyElement = new ElementListy;
        nowyElement->wartosc = wartosc;
        nowyElement->poprzedni = koniec;
        nowyElement->nastepny = nullptr;
        if (koniec != nullptr) {
            koniec->nastepny = nowyElement;
        } else {
            poczatek = nowyElement;
        }
        koniec = nowyElement;
    }
    void dodajNaPozycje(int pozycja, int wartosc) {
        ElementListy *nowyElement = new ElementListy; //Tworzenie nowego elementu listy
        nowyElement->wartosc = wartosc;
        if (poczatek == nullptr || pozycja == 0) { //Jeśli lista jest pusta lub element ma być dodany na początek, wywołaj funkcję dodajNaPoczatek i przerwij działanie funkcji
            dodajNaPoczatek(wartosc);
            return;
        }
        ElementListy *aktualny = poczatek; //Ustawienie wskaźnika aktualny na początek listy
        int indeks = 0;
        while (aktualny != nullptr && indeks < pozycja - 1) { //Przesunięcie wskaźnika aktualny o (pozycja-1) elementów
            aktualny = aktualny->nastepny;
            indeks++;
        }
        if (aktualny == nullptr) { //Jeśli wskaźnik aktualny wskazuje na nullptr, to element zostaje dodany na koniec listy, a funkcja zostaje przerwana
            dodajNaKoniec(wartosc);
            return;
        }
        nowyElement->poprzedni = aktualny;  //Ustawienie poprzednika nowego elementu na aktualny, a następnika na następnik aktualnego
        nowyElement->nastepny = aktualny->nastepny;
        aktualny->nastepny = nowyElement; //Ustawienie następnika aktualnego na nowy element
        if (nowyElement->nastepny != nullptr) {  //Jeśli nowy element ma następnik, to ustaw jego poprzednika na nowy element
            nowyElement->nastepny->poprzedni = nowyElement;
        } else {  //a jeśli nie, to nowy element jest ostatnim elementem listy, więc ustaw koniec listy na nowy element.
            koniec = nowyElement;
        }
    }
    void usunPierwszy() {
        if (poczatek == nullptr) {
            return;
        }
        ElementListy *doUsuniecia = poczatek; // przypisujemy adres pierwszego elementu do zmiennej doUsuniecia
        poczatek = poczatek->nastepny; // przypisujemy do poczatek adres drugiego elementu (lub nullptr jesli to byl jedyny element)
        if (poczatek != nullptr) { // jesli drugi element istnieje
            poczatek->poprzedni = nullptr; // ustawiamy poprzedni element drugiego elementu na nullptr
        } else { // jesli drugi element nie istnieje
            koniec = nullptr;// ustawiamy koniec na nullptr
        }
        delete doUsuniecia; // zwalniamy pamiec pierwszego elementu
    }
    void usunOstatni() {
        if (koniec == nullptr) {
            return;
        }
        ElementListy *doUsuniecia = koniec; // przypisujemy adres ostatniego elementu do zmiennej doUsuniecia
        koniec = koniec->poprzedni; // przypisujemy do koniec adres przedostatniego elementu (lub nullptr jesli to byl jedyny element)
        if (koniec != nullptr) { // jesli przedostatni element istnieje
            koniec->nastepny = nullptr; // ustawiamy nastepny element przedostatniego elementu na nullptr
        } else { //jesli przedostatni element nie istnieje
            poczatek = nullptr; // ustawiamy poczatek na nullptr
        }
        delete doUsuniecia;
    }
    void usunNaPozycji(int pozycja) {
        if (poczatek == nullptr) { //Sprawdzamy, czy lista nie jest pusta. Jeśli tak, to kończymy funkcję.
            return;
        }
        if (pozycja == 0) { //Jeśli pozycja do usunięcia to pierwszy element, wywołujemy funkcję usunPierwszy() i kończymy funkcję.
            usunPierwszy();
            return;
        }
        ElementListy *aktualny = poczatek;
        int indeks = 0;
        while (aktualny != nullptr && indeks < pozycja) { //Przechodzimy przez listę, aż dojdziemy do elementu na podanej pozycji lub końca listy.
            aktualny = aktualny->nastepny;
            indeks++;
        }
        if (aktualny == nullptr) { //Jeśli nie udało się znaleźć elementu na podanej pozycji, kończymy funkcję.
            return;
        }
        if (aktualny == poczatek) {//Jeśli znaleziony element to pierwszy element, wywołujemy funkcję usunPierwszy() i kończymy funkcję..
            usunPierwszy();
            return;
        }
        if (aktualny == koniec) { //Jeśli znaleziony element to ostatni element, wywołujemy funkcję usunOstatni() i kończymy funkcję.
            usunOstatni();
            return;
        }
        aktualny->poprzedni->nastepny = aktualny->nastepny; //Usuwamy element z listy przez zmianę wskaźników poprzedni i nastepny elementów otaczających usuwany element.
        aktualny->nastepny->poprzedni = aktualny->poprzedni;
        delete aktualny; //Usuwamy element z pamięci
    }
    int znajdzElement(int wartosc) {
        ElementListy *aktualny = poczatek;
        int indeks = 0;
        int znaleziono=0;
        while (aktualny != nullptr) { //dopóki nie dotrzemy do końca listy
            if (aktualny->wartosc == wartosc) { // jeśli znaleźliśmy element o szukanej wartości
                cout << "indeks szukanego elementu to: " << indeks << endl;// wypisujemy jego indeks na ekran
                znaleziono=1;
            }
            aktualny = aktualny->nastepny; // przechodzimy do następnego elementu
            indeks++;
        }
        if(znaleziono==0)
            cout << "-1" << endl; // jeśli nie znaleźliśmy szukanego elementu, wypisujemy -1
    }
    void wyswietl() {
        ElementListy *aktualny = poczatek;
        while (aktualny != nullptr) {
            cout << aktualny->wartosc << " ";
            aktualny = aktualny->nastepny;
        }
        cout << endl;

    }
    void zapiszDoPliku(int rozmiar) {
        ofstream dane("/Users/useruser/CLionProjects/ProjektSDIZO/tekst.txt");// otwieramy plik o podanej nazwie w trybie do zapisu// sprawdzamy czy udało się otworzyć plik
        dane << rozmiar << endl;
        ElementListy *aktualny = poczatek;
        while (aktualny != nullptr) {
            dane << aktualny->wartosc << endl; // zapisujemy wartość bieżącego elementu do pliku
            aktualny = aktualny->nastepny; // przechodzimy do kolejnego elementu
        }
        dane.close(); // zamykamy plik
    }
    ~ListaDwukierunkowa() {
        while (poczatek != nullptr) {
            usunPierwszy();
        }
    }
};
class KopiecBinarny {
private:
    int *kopiec; // tablica przechowująca elementy kopca
    int rozmiar; // rozmiar tablicy
    int liczbaElementow; // liczba elementów w kopcu
    // funkcja zwracająca indeks rodzica dla danego indeksu elementu
    int indeksRodzica(int indeks) {
        return (indeks - 1) / 2;
    }
    // funkcja zwracająca indeks lewego dziecka dla danego indeksu elementu
    int indeksLewegoDziecka(int indeks) {
        return 2 * indeks + 1;
    }
    // funkcja zwracająca indeks prawego dziecka dla danego indeksu elementu
    int indeksPrawegoDziecka(int indeks) {
        return 2 * indeks + 2;
    }
    // funkcja naprawiająca kopiec od dołu po dodaniu nowego elementu
    void naprawKopiecOdDolu() {
        int indeks = liczbaElementow - 1; // ustalamy indeks elementu, od którego rozpoczynamy naprawę kopca od dołu
        while (indeks > 0 && kopiec[indeks] > kopiec[indeksRodzica(indeks)]) {// wykonujemy pętlę tak długo, aż dotrzemy do korzenia lub kopiec będzie już naprawiony
            swap(kopiec[indeks], kopiec[indeksRodzica(indeks)]); // jeśli element jest większy od swojego rodzica, to zamieniamy je miejscami
            indeks = indeksRodzica(indeks);// przechodzimy do rodzica
        }
    }
    // funkcja naprawiająca kopiec od góry po usunięciu korzenia
    void naprawKopiecOdGory() {
        int indeks = 0;
        while (indeksLewegoDziecka(indeks) < liczbaElementow) {// dopóki indeks lewego dziecka jest mniejszy od liczby elementów w kopcu
            int indeksWiekszegoSyna = indeksLewegoDziecka(indeks);// ustawiamy indeks większego syna na indeks lewego dziecka
            // jeśli istnieje prawe dziecko i jest większe od lewego, to ustawiamy na niego indeks
            if (indeksPrawegoDziecka(indeks) < liczbaElementow &&
                kopiec[indeksPrawegoDziecka(indeks)] > kopiec[indeksWiekszegoSyna]) {
                indeksWiekszegoSyna = indeksPrawegoDziecka(indeks);
            }
            // jeśli wartość kopca na danym indeksie jest większa lub równa wartości na indeksie większego syna to przerywamy pętlę
            if (kopiec[indeks] >= kopiec[indeksWiekszegoSyna]) {
                break;
            }
            swap(kopiec[indeks], kopiec[indeksWiekszegoSyna]); // zamieniamy miejscami wartości na indeksie i indeksie większego syna
            indeks = indeksWiekszegoSyna;// ustawiamy indeks na większego syna, aby kontynuować pętlę
        }
    }
public:
    // konstruktor, tworzy pusty kopiec
    KopiecBinarny(int rozmiarMax) {
        kopiec = new int[rozmiarMax];
        rozmiar = rozmiarMax;
        liczbaElementow = 0;
    }
    ~KopiecBinarny() {
        delete[] kopiec;
    }
    void dodajElement(int wartosc,int pojemnosc) {
        // sprawdzenie, czy kopiec jest pełny
        if (liczbaElementow == pojemnosc) {
            // tworzymy nowy kopiec o rozmiarze większym o 1 od oryginalnego kopca
            int* nowy_kopiec = new int[pojemnosc + 1];
            // kopiujemy oryginalny kopiec do nowego kopca
            for (int i = 0; i < pojemnosc; i++) {
                nowy_kopiec[i] = kopiec[i];
            }
            // dodajemy nową wartość na koniec nowej tablicy
            nowy_kopiec[pojemnosc] = wartosc;
            // zwiększamy rozmiar kopca
            pojemnosc++;
            // usuwamy oryginalny kopiec
            delete[] kopiec;
            // ustawiamy wskaźnik na początek nowego kopca
            kopiec = nowy_kopiec;
        }
        // dodanie elementu na końcu kopca
        kopiec[liczbaElementow] = wartosc;
        liczbaElementow++;
        // naprawa kopca
        naprawKopiecOdDolu();

    }
// funkcja usuwająca korzeń kopca
    void usunKorzen() {
        if (liczbaElementow == 0) {
            throw logic_error("Kopiec jest pusty");
        }
        // tworzymy nową tablicę o jeden element mniejszą
        int* nowy_kopiec = new int[liczbaElementow - 1];
        // kopiujemy wszystkie elementy z wyjątkiem pierwszego
        for (int i = 1; i < liczbaElementow; i++) {
            nowy_kopiec[i - 1] = kopiec[i];
        }
        // zwalniamy pamięć zaalokowaną na pierwotny kopiec
        delete[] kopiec;
        // przypisujemy wskaźnikowi kopiec adres nowego kopca
        kopiec = nowy_kopiec;
        // zmniejszamy rozmiar kopca o jeden
        liczbaElementow--;
        if(liczbaElementow<=0)
            liczbaElementow=1;
        naprawKopiecOdGory();
    }
// funkcja wyszukująca element o podanej wartości i zwracająca jego indeks lub -1, jeśli nie znaleziono
    void wyszukajElement(int element) {
        int czyznalezionoelement=1;
        for (int i = 0; i < liczbaElementow; i++) {
            if (kopiec[i] == element) {
                cout << "indeks szukanego elementu to(indeksowanie rozpoczyna sie od 0): " << i << endl;
                czyznalezionoelement=0;
            }
        }
        if(czyznalezionoelement==1)
            cout << "-1" << endl;
    }
// funkcja wyświetlająca wszystkie elementy kopca
    void wyswietlKopiec() {
        if (liczbaElementow == 0) {
            cout << "Kopiec jest pusty" << endl;
            return;
        }
        int poziom = 0;
        int elementyNaPoziomie = 1;
        for (int i = 0; i < liczbaElementow; i++) {
            if (i == elementyNaPoziomie - 1) {
                // przejście do kolejnego poziomu
                poziom++;
                elementyNaPoziomie *= 2;
                cout << endl;
            }
            // wyświetlenie elementu oddzielone znakami ':' dla wiekszej przejrzystosci
            cout << ":" << kopiec[i] << ":";
            // wyświetlenie numerów poziomów i indeksów wierzchołków
            if (i == 0) {
                cout << " (P: " << poziom << ", I: " << i << ")";
            } else if (i == elementyNaPoziomie - 2) {
                cout << " (P: " << poziom << ", I: " << i << ")";
            }
        }
        cout << endl;
    }
    void zapiszDoPliku () {
        ofstream dane("/Users/useruser/CLionProjects/ProjektSDIZO/tekst.txt");// otwieramy plik o podanej nazwie w trybie do zapisu// sprawdzamy czy udało się otworzyć plik
        // zapisujemy liczność kopca
        dane << liczbaElementow << endl;
        // zapisujemy kolejne elementy kopca
        for (int i = 0; i < liczbaElementow; i++) {
            dane << kopiec[i] << endl;
        }
        dane.close();
    }
};
int main(){
    ofstream Wyniki;
    Wyniki.open("/Users/useruser/CLionProjects/ProjektSDIZO/wyniki.txt");
    int opcja;
    int opcja2=1;
    int indeks;
    int iloscpowtorzen;
    int czykoniec=1;
    cout << "Wybierz opcję:" << endl;
    cout << "1. Tablica" << endl;
    cout << "2. Lista" << endl;
    cout << "3. Kopiec binarny" << endl;
    cin >> opcja;
    int rozmiar;
    switch(opcja) {
        case 1: {
            while(opcja2!=0){
            rozmiar=0;
            Tablica tablica(rozmiar);
            tablica.wyswietl_tablice();
            cout << "Wybierz opcję:" << endl;
            cout << "1. Dodanie elementu na początku tablicy" << endl;
            cout << "2. Dodanie elementu na koncu tablicy" << endl;
            cout << "3. Dodanie elementu w wybranym miejscu tablicy" << endl;
            cout << "4. Usunięcie elementu na poczatku tablicy" << endl;
            cout << "5. Usunięcie elementu na koncu tablicy" << endl;
            cout << "6. Usunięcie elementu w wybranym miejscu tablicy" << endl;
            cout << "7. Znalezienie elementu w tablicy" << endl;
            cout << "0. Zakonczenie dzialania programu" << endl;
            cin>>opcja2;
            switch(opcja2){
                case 1: {
                    int wartosc;
                    cout << "Podaj wartosc liczby:";
                    cin>>wartosc;
                    auto start = high_resolution_clock::now();//mierzenie czasu opeacji
                    tablica.dodaj_do_tablicy_poczatek(wartosc);
                    auto stop = high_resolution_clock::now();
                    auto duration = duration_cast<microseconds>(stop - start);
                    tablica.zapisz_do_pliku();
                    // wyświetlamy czas operacji w mikrosekundach
                    cout << "Dodanie elementu zajelo " << duration.count() << " mikrosekund" << endl;
                    Wyniki<<duration.count()<<endl;
                    break;
                }
                case 2:{
                    int wartosc;
                    cout << "Podaj wartosc liczby: ";
                    cin>>wartosc;
                    auto start = high_resolution_clock::now();
                    tablica.dodaj_do_tablicy_koniec(wartosc);
                    auto stop = high_resolution_clock::now();
                    auto duration = duration_cast<microseconds>(stop - start);
                    tablica.zapisz_do_pliku();
                    cout << "Dodanie elementu zajelo " << duration.count() << " mikrosekund" << endl;
                    Wyniki<<duration.count()<<endl;
                    break;
                }
                case 3:{
                    cout << endl <<"Podaj indeks na ktorym ma zostać dodana liczba, indeksowanie zaczyna sie od 0, a liczba zostanie wstawiona przed podany indeks(dla indeksu 0 liczba zostanie wstawiona na pierwsze miejsce)" << endl;
                    cin >> indeks;
                    int wartosc;
                    cout << "Podaj wartosc liczby: " << endl;
                    cin>>wartosc;
                    auto start = high_resolution_clock::now();
                    tablica.dodaj_do_tablicy_dowolnie(wartosc,indeks);
                    auto stop = high_resolution_clock::now();
                    auto duration = duration_cast<microseconds>(stop - start);
                    tablica.zapisz_do_pliku();
                    cout << "Dodanie elementu zajelo " << duration.count() << " mikrosekund" << endl;
                    Wyniki<<duration.count()<<endl;
                    break;
                }
                case 4: {
                    auto start = high_resolution_clock::now();
                    tablica.usun_pierwszy_element();
                    auto stop = high_resolution_clock::now();
                    auto duration = duration_cast<microseconds>(stop - start);
                    tablica.zapisz_do_pliku();
                    cout << "Usunięcie elementu zajelo " << duration.count() << " mikrosekund" << endl;
                    Wyniki<<duration.count()<<endl;
                    break;
                }
                case 5:{
                    auto start = high_resolution_clock::now();
                    tablica.usun_ostatni_element();
                    auto stop = high_resolution_clock::now();
                    auto duration = duration_cast<microseconds>(stop - start);
                    tablica.zapisz_do_pliku();
                    cout << "Usunięcie elementu zajelo " << duration.count() << " mikrosekund" << endl;
                    Wyniki<<duration.count()<<endl;
                    break;
                }
                case 6:{
                    cout << endl <<"Podaj indeks z ktorego ma zostać usunieta liczba, indeksowanie zaczyna sie od 0" << endl;
                    cin >> indeks;
                    auto start = high_resolution_clock::now();
                    tablica.usun_dowolny_element(indeks);
                    auto stop = high_resolution_clock::now();
                    auto duration = duration_cast<microseconds>(stop - start);
                    tablica.zapisz_do_pliku();
                    cout << "Usuniecie elementu zajelo " << duration.count() << " mikrosekund" << endl;
                    Wyniki<<duration.count()<<endl;
                    break;
                }
                case 7:{
                    cout << "podaj element do znalezienia w tablicy, program wyswietli indeks danego elementu lub -1 jesli go nie znajdzie"<< endl;
                    int element;
                    cin >> element;
                    auto start = high_resolution_clock::now();
                    tablica.znajdz_element(element);
                    auto stop = high_resolution_clock::now();
                    auto duration = duration_cast<microseconds>(stop - start);
                    cout << "Szukanie elementu zajelo " << duration.count() << " mikrosekund" << endl;
                    Wyniki<<duration.count()<<endl;
                    break;
                }
            }}
            break;
        }
        case 2:{
            while(opcja2!=0){
            ListaDwukierunkowa lista;
            int x;
            ifstream dane ("/Users/useruser/CLionProjects/ProjektSDIZO/tekst.txt");
            dane >> rozmiar;
            for(int i=0;i<rozmiar;i++){
                dane >> x;
                lista.dodajNaKoniec(x);
            }
            dane.close();
            lista.wyswietl();
            cout << "Wybierz opcję:" << endl;
            cout << "1. Dodanie elementu na początku listy" << endl;
            cout << "2. Dodanie elementu na koncu listy" << endl;
            cout << "3. Dodanie elementu w wybranym miejscu listy" << endl;
            cout << "4. Usunięcie elementu na poczatku listy" << endl;
            cout << "5. Usunięcie elementu na koncu listy" << endl;
            cout << "6. Usunięcie elementu w wybranym miejscu listy" << endl;
            cout << "7. Znalezienie elementu na liscie" << endl;
            cout << "0. Zakonczenie dzialania programu" << endl;
            cin>>opcja2;
            switch (opcja2) {
                case 1:{
                    int wartosc;
                    cout << "Podaj wartosc liczby: " << endl;
                    cin>>wartosc;
                    auto start = high_resolution_clock::now();
                    lista.dodajNaPoczatek(wartosc);
                    auto stop = high_resolution_clock::now();
                    auto duration = duration_cast<microseconds>(stop - start);
                    rozmiar++;
                    lista.zapiszDoPliku(rozmiar);
                    cout << "Dodanie elementu zajelo " << duration.count() << " mikrosekund" << endl;
                    Wyniki<<duration.count()<<endl;
                    break;
                }
                case 2:{
                    int wartosc;
                    cout << "Podaj wartosc liczby: " << endl;
                    cin>>wartosc;
                    auto start = high_resolution_clock::now();
                    lista.dodajNaKoniec(wartosc);
                    auto stop = high_resolution_clock::now();
                    auto duration = duration_cast<microseconds>(stop - start);
                    rozmiar++;
                    lista.zapiszDoPliku(rozmiar);
                    cout << "Dodanie elementu zajelo " << duration.count() << " mikrosekund" << endl;
                    Wyniki<<duration.count()<<endl;
                    break;
                }
                case 3:{
                    cout << "Podaj indeks pozycji po ktorej chcesz dodac liczbe (indeksowanie zaczyna sie od 0, podanie wartosci 0 wstawi liczbe na poczatek): ";
                    int indeks;
                    cin >> indeks;
                    int wartosc;
                    cout << "Podaj wartosc liczby: " << endl;
                    cin>>wartosc;
                    auto start = high_resolution_clock::now();
                    lista.dodajNaPozycje(indeks, wartosc);
                    auto stop = high_resolution_clock::now();
                    auto duration = duration_cast<microseconds>(stop - start);
                    rozmiar++;
                    lista.zapiszDoPliku(rozmiar);
                    cout << "Dodanie elementu zajelo " << duration.count() << " mikrosekund" << endl;
                    Wyniki<<duration.count()<<endl;
                    break;
                }
                case 4:{
                    auto start = high_resolution_clock::now();
                    lista.usunPierwszy();
                    auto stop = high_resolution_clock::now();
                    auto duration = duration_cast<microseconds>(stop - start);
                    rozmiar--;
                    if(rozmiar<0)
                        rozmiar=0;
                    lista.zapiszDoPliku(rozmiar);
                    cout << "Usuniecie elementu zajelo " << duration.count() << " mikrosekund" << endl;
                    Wyniki<<duration.count()<<endl;
                    break;
                }
                case 5:{
                    auto start = high_resolution_clock::now();
                    lista.usunOstatni();
                    auto stop = high_resolution_clock::now();
                    auto duration = duration_cast<microseconds>(stop - start);
                    rozmiar--;
                    if(rozmiar<0)
                        rozmiar=0;
                    lista.zapiszDoPliku(rozmiar);
                    cout << "Usuniecie elementu zajelo " << duration.count() << " mikrosekund" << endl;
                    Wyniki<<duration.count()<<endl;
                    break;
                }
                case 6:{
                    cout << "Podaj indeks pozycji z ktorej chcesz usunac liczbe(indeksowanie zaczyna sie od 0): ";
                    int indeks;
                    cin >> indeks;
                    auto start = high_resolution_clock::now();
                    lista.usunNaPozycji(indeks);
                    auto stop = high_resolution_clock::now();
                    auto duration = duration_cast<microseconds>(stop - start);
                    rozmiar--;
                    if(rozmiar<0)
                        rozmiar=0;
                    lista.zapiszDoPliku(rozmiar);
                    cout << "Usuniecie elementu zajelo " << duration.count() << " mikrosekund" << endl;
                    Wyniki<<duration.count()<<endl;
                    break;
                }
                case 7:{
                    cout << "Podaj wartosc ktora chcesz znalezc na liscie: ";
                    int wartosc;
                    cin >> wartosc;
                    auto start = high_resolution_clock::now();
                    lista.znajdzElement(wartosc);
                    auto stop = high_resolution_clock::now();
                    auto duration = duration_cast<microseconds>(stop - start);
                    cout << "Znalezienie elementu zajelo " << duration.count() << " mikrosekund" << endl;
                    Wyniki<<duration.count()<<endl;
                    break;
                }
            }}
            break;
        }
        case 3: {
            while(opcja2!=0){
            KopiecBinarny kopiec(rozmiar);
            ifstream dane ("/Users/useruser/CLionProjects/ProjektSDIZO/tekst.txt");
            dane >> rozmiar;
            int x;
            for (int i = 0; i < rozmiar; i++){
                dane >> x;
                kopiec.dodajElement(x,rozmiar);
            }
            dane.close();
            kopiec.wyswietlKopiec();
            cout << "Wybierz opcję:" << endl;
            cout << "1. Dodanie elementu do kopca" << endl;
            cout << "2. Usunięcie korzenia kopca" << endl;
            cout << "3. Znalezienie elementu w kopcu" << endl;
            cout << "0. Zakonczenie dzialania programu" << endl;
            cin>>opcja2;
            switch (opcja2) {
                case 1:{
                    int wartosc;
                    cout << "Podaj wartosc liczby: " << endl;
                    cin >> wartosc;
                    auto start = high_resolution_clock::now();
                    kopiec.dodajElement(wartosc,rozmiar);
                    auto stop = high_resolution_clock::now();
                    auto duration = duration_cast<microseconds>(stop - start);
                    kopiec.zapiszDoPliku();
                    // wyświetlamy czas operacji w mikrosekundach
                    cout << "Dodanie elementu zajelo " << duration.count() << " mikrosekund" << endl;
                    Wyniki<<duration.count()<<endl;
                    break;
                }
                case 2:{
                    auto start = high_resolution_clock::now();
                    kopiec.usunKorzen();
                    auto stop = high_resolution_clock::now();
                    auto duration = duration_cast<microseconds>(stop - start);
                    kopiec.zapiszDoPliku();
                    cout << "Usuniecie elementu zajelo " << duration.count() << " mikrosekund" << endl;
                    Wyniki<<duration.count()<<endl;
                    break;
                }
                case 3:{
                    cout << "Podaj wartosc ktora chcesz znalezc na liscie: ";
                    int wartosc;
                    cin >> wartosc;
                    auto start = high_resolution_clock::now();
                    kopiec.wyszukajElement(wartosc);
                    auto stop = high_resolution_clock::now();
                    auto duration = duration_cast<microseconds>(stop - start);
                    cout << "Znalezienie elementu zajelo " << duration.count() << " mikrosekund" << endl;
                    Wyniki<<duration.count()<<endl;
                    break;
                }
            }}
            break;
        }
        default:
            cout << "Nieprawidłowa opcja" << endl;
            return 1;
    }
    Wyniki.close();
    return 0;
}