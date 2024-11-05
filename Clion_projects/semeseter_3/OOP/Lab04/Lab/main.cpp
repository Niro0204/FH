#include <iostream>
#include <memory>

using namespace std;

namespace oop {
    std::string to_string(int i) {
        return "namespace oop";
    }
}

using namespace oop;

string to_string(int i) {
    return "global";
}

// überladen von funktionen funktioniert auch mit methoden
void print(int i) {
    static int z = 0; //variable bleibt nach funktionsaufruf erhalten
    z++;
    cout << "das ist ein int: " << i << endl;
}

// static funktionen un globale variablen sind nur innerhalb dieser Quelltext datei verfügbar
static int z2;

void print(double i) {
    cout << "das ist ein double: " << i << endl;
}

void print(string s) {
    cout << "das ist ein string: " << s << endl;
}

// default parameter
void foo1(int x = 3, int y = 4) {
    cout <<  x << ", " << y << endl;
}

void foo2(int x , int y = 4) {
    cout << x << ", " << y << endl;
}

class Instrument {
    private:
        string hersteller;
        double preis;
    public:

        // Instrument(){ }                                           // standard konstruktor
        //Instrument() = default;                                 // c++ standard konstruktor
        Instrument() : hersteller{"Fender"}, preis{1500}{}; // standard konstruktoren sind konstruktoren ohne parameter

        Instrument(const string& hersteller, double preis) {
            setHersteller(hersteller);
            this->preis = preis;
        }
        Instrument(const string& hersteller) {
            setHersteller(hersteller);
            this->preis = 0;
        }
        Instrument(double preis) {
            this->preis = preis;
            this->hersteller = " ";
        }

        //destruktor
        ~Instrument() {
            cout << "Instrument von " << hersteller << "wird zerstört" << endl;
        }

        void setHersteller(const string& hersteller) {this->hersteller = hersteller;}
        string getHerstelle() {return hersteller;}

        static void doCount() {
            static int counter = 0;
            cout << "zähler: " << counter++ << endl;
        }
};

int main()
{

    cout << oop::to_string(5) << endl;

    cout << ::to_string(5) << endl;

    print(5);
    print(5.5);
    print("fünf");

    cout << endl;

    foo1(8,9);
    foo1(9);
    foo1();

    cout << endl;

    foo2(9,8);
    foo2(9);

    cout << endl;

    auto i1 = new Instrument();

    cout << i1->getHerstelle() << endl;

    auto i2 = make_shared<Instrument>("Rickenbacker", 2000);

    cout << i2->getHerstelle() << endl;

    // diese variante speichert das objekt am stack
    Instrument i3(/*"Gibson",*/ 6542);
    cout << i3.getHerstelle() << endl;
    Instrument i4("Ibanz", 6543);
    cout << i4.getHerstelle() << endl;

    return 0;
}
