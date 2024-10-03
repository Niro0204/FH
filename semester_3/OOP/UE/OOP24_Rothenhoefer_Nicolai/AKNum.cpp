#include <iostream>
#include <algorithm>
#include <vector>

class AKNum {

    private:
        int inputNum; 
        std::vector<int> digits;
        int tempResult;
    
    public:
        // constructor
        AKNum(int input) : inputNum{input}, tempResult{0}{}

        /*std::vector<int>*/ void  getDigits(){

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

        
            //std::reverse(digits.begin(),digits.end());

            //return digits;
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

            return bigNum -smallNum;
        }

        void startAlgorithm(){
            
            while(true){
                
                getDigits();

                if(!validateInput()){
                    std::cerr << "The digits cannot all be the same!" << std::endl;
                    exit(EXIT_FAILURE);
                }

                tempResult = subtract();

                std::cout << "temp result: " << tempResult << std::endl;

                inputNum = tempResult;
            }
        }

};


int main(){

    int input;

    std::cout << "Please enter a positive, 4 digit integer: ";
    std::cin >> input;

    AKNum akNum(input);

    akNum.startAlgorithm();


    return 0;
}