#include <iostream>
#include <algorithm>
#include <vector>

class AKNum {

    private:
        int inputNum; 
        std::vector<int> digits;
        int tempResult;
    
    public:
        // Konstruktor
        AKNum(int input) : inputNum{input}, tempResult{0}{}

        std::vector<int> getDigits(){

            int tempInput = inputNum;
            int digit{0};   

            if(inputNum < 1000 || inputNum > 9999){
                std::cerr << "The number has to be 4 digits!" << std::endl;
                exit(EXIT_FAILURE);
            }         

            for(int i{0}; i < 4; i++){
                digit = tempInput % 10;
                tempInput = tempInput / 10;
                digits.push_back(digit);
            }

            if(!validateInput()){
                std::cerr << "The digits cannot all be the same!" << std::endl;
                exit(EXIT_FAILURE);
            }
            //std::reverse(digits.begin(),digits.end());

            return digits;
        }

        bool validateInput(){

            int firstDigit = digits[0];

            for(auto digit : digits){
                if(digit != firstDigit){
                    return true;
                }
            }
            //std::cerr << "The digits cannot all be the same!" << std::endl;
            
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

        }

        void startAlgorithm(){

        }

};


int main(){


    



    return 0;
}