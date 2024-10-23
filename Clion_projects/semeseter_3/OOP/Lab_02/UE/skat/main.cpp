#include <iostream>
#include <array>
#include <memory>


enum c {
    karo,
    herz,
    pik,
    kreuz
};

enum w {
    seven,
    eight,
    nine,
    bube,
    dame,
    könig,
    zehn,
    ass
};

struct card {
    c color;
    w worth;
};

std::array<std::shared_ptr<card>,32> fillDeck(std::array<std::shared_ptr<card>,32>& cardDeck) {

        int index = 0;

        for(int i = static_cast<int>(c::karo); i <= static_cast<int>(c::kreuz); i++) {
            for(int j = static_cast<int>(w::seven); j <= static_cast<int>(w::ass); j++) {
                cardDeck[index]= std::make_shared<card>(static_cast<c>(i), static_cast<w>(j));
                index++;
            }
        }

    return cardDeck;
}

void printDeck(std::array<std::shared_ptr<card>,32>& cardDeck) {
    for(int i = 0; i < cardDeck.size(); i++) {
        std::cout << cardDeck[i]->color;
        std::cout << cardDeck[i]->worth;
    }
}

int main(){

    std::array<std::shared_ptr<card>,32> deck;
    deck = fillDeck(deck);

    printDeck(deck);

    return 0;
}
