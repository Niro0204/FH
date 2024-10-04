#include <iostream>
#include <algorithm>
#include <vector>
#include <set>

class AKNum {

    private:
        int inputNum; 
        std::vector<int> digits;
        std::set<int> results;
    
    public:
        // constructor
        AKNum(int input) : inputNum{input}{}

        void  getDigits(){

            digits.clear();

            int tempInput = inputNum;
            int digit{0};   

            while(tempInput > 0){                                       
                digit = tempInput % 10;
                tempInput = tempInput / 10;
                digits.push_back(digit);
            }
        }

        bool validateInput(){

            int firstDigit = digits[0];

            for(auto digit : digits){
                if(digit != firstDigit){
                    return true;
                }
            }
            
            return false;
        }

        void sortDesc(){
            sort(digits.begin(), digits.end(), std::greater<int>());
        }

        void sortAsc(){
            sort(digits.begin(),digits.end());
        }

        int vecToNum(){

            int newNum{0};

            for(auto digit : digits){
                newNum = newNum * 10 + digit;
            }

            return newNum;
        }

        int subtract(){

            sortDesc();
            int bigNum = vecToNum();
            sortAsc();
            int smallNum = vecToNum();

            return bigNum - smallNum;
        }

        void startAlgorithm(){

            int tempResult{0};
            
            while(true){

                getDigits();

                  if(!validateInput()){
                    std::cerr << "Result: 0" << std::endl;
                    return;
                }

                tempResult = subtract();

                std::cout << "temp result: " << tempResult << std::endl;

                if(results.find(tempResult) != results.end()){
                    std::cout << "Result: " << tempResult << std::endl;
                    break;
                }

                results.insert(tempResult);
                inputNum = tempResult;
            }

            results.clear();
        }

};


int main(){

    int input;

    while(true){

        std::cout << "Please enter a positive, 4 digit integer: ";
        std::cin >> input;

        if(std::cin.fail() || input < 1000 || input > 9999){
            std::cerr << "invalid input, the number has to be 4 digits!" << std::endl;
            std::cin.clear();
            std::cin.ignore(100,'\n');
            continue;
        }   

        AKNum akNum(input);
        akNum.getDigits();

        if(!akNum.validateInput()){
            std::cerr << "The digits cannot all be the same!" << std::endl;
            continue;
        }

        std::cout << "enterd number: " << input << std::endl;

        akNum.startAlgorithm();

        char choice;

        std::cout << "Try an other number? [y/n]: ";
        std::cin >> choice;

        if(choice != 'y'){
            break;
        }
    }

    return 0;
}