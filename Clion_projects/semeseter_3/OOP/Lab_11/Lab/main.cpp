#include <iostream>
#include <array>
#include <deque>
#include <forward_list>
#include <list>
#include <vector>
#include <set>
#include <map>

template<typename T>
class trio {
public:
    const T first, second, third;

    trio(T first, T second, T third) : first(first), second(second), third(third) {};

};

// nicht-typ-parameter bei templates
template<typename T, int val = 0>
T foo(const T& a, const T& b) {
    // val++; funktioniert hier nicht, es ist eine read only variable
    auto v = val;
    //v++; so würde es funktionieren
    return (a + b) * val;
}

// struct template
template<typename T, typename T2>
struct diverseDuo {
    T a;
    T2 b;
};


int main() {

    trio<int> t1(10,20,30);
    trio<float> t2(3.5,4.5,5.0);
    trio<std::string> t3("Luke", "Han", "Leia");

    std::cout << t3.second << std::endl;

    auto f1 = foo<int,123>(12,23);
    std::cout << f1 << std::endl;

    diverseDuo<double,float> dd1;
    dd1.a = 1.0;
    dd1.b = 2.5;

    std::cout << dd1.a << " " << dd1.b << std::endl;

    // sequentielle container
    //std::array<int,10> arr; // klassisches statisches array
    //std::vector<int> vec; // dynamisches array
    //std::list<int> dll; // doppelt verkettet liste
    //std::pmr::forward_list<int> sll; // einfach verkettete liste
    //std::deque<int> deck; // Deck, double ended queue, dynamisches array, das auch vorne hinzufügen kann

    std::deque<double> deque;
    deque.push_back(1.0);
    deque.push_front(2.0);

    // direkter zugriff über index möglich, anders als bei liste
    deque[0] = 123.34;

    std::list<int> list;
    list.push_back(1);
    list.push_front(2);


    // iteratoren: abstrakte Zeiger, navigation über iterator++ und iterator--
    auto listIter= list.begin(); // Zeiger AUF erstes element in liste
    auto listIter2= list.end(); // Zeiger NACH das letzte element
    auto listIter3= list.rbegin(); // Zeiger AUF das letzte element
    auto listIter4= list.rend(); // Zeiger VOR das erste element

    list.insert(++list.begin(), 3);

    // rend<-[begin]<->[]<->[]<->[]<->[rbegin]-> end

    for (auto iterForward = list.begin(); iterForward != list.end(); ++iterForward) {
        std::cout << *iterForward << " ";
    }
    std::cout << std::endl;

    for( auto iterBack = list.rbegin(); iterBack != list.rbegin(); --iterBack) {
        std::cout << *iterBack << " ";
    };
    std::cout << std::endl;

    //container adapter
    //std::stack<int> stack;
    //std::queue<int> queue;

    //Assoziative Container (Bäume/Baumstruktur)
    //std::set<int> bst;   // binärer suchbaum
    //std::map<std::string,int> hashmap; // Hashmap

    std::set<std::string> bst;

    bst.insert("Leia");
    bst.insert("Luke");
    bst.insert("Han");
    bst.insert("Luke"); // Duplikate werden verworfen

    for(auto it = bst.begin(); it != bst.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;

    auto it = bst.find("Leia");
    if (it != bst.end()) {
        std::cout << *it << " gefunden " << std::endl;
    } else {
        std::cout << *it << " nicht gefunden " << std::endl;
    }

    std::map<std::string, int> map;
    map.insert(std::pair<std::string, int>("Tatooine", 4));
    map.insert(std::pair<std::string, int>("Hoth", 5));
    map.insert(std::pair<std::string, int>("Endor", 6));
    map["Naboo"] = 1;

    if(map.insert(std::make_pair("Tatooine", 1)).second == false) {  // wenn ergebnis false, dann gibt es schon einen solchen eintrag
        std::cout << "Tatooine existiert bereits" << std::endl;
    }

    if(map.find("Alderaan") != map.end() ) {
        std::cout << "Alderaan wurde gefunden" << map.at("Alderaan") << std::endl;
    } else {
        std::cout << "Alderaan wurde nicht gefunden" << std::endl;
    }

    if(map.find("Endor") != map.end() ) {
        std::cout << "Endor wurde gefunden und ist wichtig in film nummer: " << map.at("Endor") << std::endl;
    } else {
        std::cout << "Endor wurde nicht gefunden" << std::endl;
    }

    auto pers = std::make_tuple(1,"Anakin Skywalker", "S");
    std::cout << std::get<1>(pers) << std::endl;

    return 0;
}
