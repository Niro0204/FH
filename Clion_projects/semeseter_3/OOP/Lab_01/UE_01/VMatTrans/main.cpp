#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>


class jaggedArray {

    private:
        std::vector<std::vector<char>> array;
    public:
        jaggedArray() {
            srand(time(nullptr));
            int rows = rand() % (6 - 3 + 1) + 3;
            array.resize(rows);

            for (int i = 0; i < rows; i++) {
                int elem = rand() % (8 - 4 + 1) + 4;

                for(int j = 0; j < elem; j++) {
                    char symbol = rand() % (80 - 65) + 65;
                    array[i].push_back(symbol);
                }
            }
        }

        void transposeArray();
        void printArray();
};

int main() {

    jaggedArray array = jaggedArray();

    array.printArray();
    std::cout << std::endl;
    array.transposeArray();
    return 0;
}


void jaggedArray::transposeArray() {

    int max = 0;
    int temp = 0;
    int rowCount = 0;

    for(auto& row : array) {
        for(auto& elem : row) {
            temp++;
        }
        if(temp > max) {
            max = temp;
        }
        temp = 0;
        rowCount++;
    }

    std::cout << max << std::endl;
    std::cout << rowCount << std::endl;
}




void jaggedArray::printArray() {

    for(auto& row : array) {
        for(auto& c : row) {
            std::cout << c << " ";
        }
        std::cout << std::endl;
    }
}