#include <iostream>
#include <algorithm>
#include <vector>
#include <set>

class AKNum {

    private:
        
        // needed variables for the AKNum class
        int inputNum; 
        std::vector<int> digits;
        std::set<int> results;
    
    public:
        // constructor assigning user input to private variable
        AKNum(int input) : inputNum{input}{}

        // needed methods for class
        void getDigits();
        bool validateInput();
        void sortDesc(){ std::sort(digits.begin(), digits.end(), std::greater<int>());} // desc sort function to get the biggest possible number 
        void sortAsc(){ std::sort(digits.begin(),digits.end());} // asc sort funkction to get the smallest possible number
        int vecToNum();
        int subtract();
        void startAlgorithm();
};


int main(){

    int input; 

    while(true){

        //asking for input and save it in variable
        std::cout << "Please enter a positive, 4 digit integer: ";
        std::cin >> input;

        //checking for input success
        if(std::cin.fail() || input < 1000 || input > 9999){ //failing when input failed or number not in range
            std::cerr << "invalid input, the number has to be 4 digits!" << std::endl;
            std::cin.clear();               // clearing input
            std::cin.ignore(100,'\n');      // ignoring remaining characters til '\n' occurs
            continue;
        }   

        AKNum akNum(input); // generating object with input


        akNum.getDigits();  // converting the number to digits to validate the input
        if(!akNum.validateInput()){
            std::cerr << "The digits cannot all be the same!" << std::endl;
            continue; // continuing to get new input
        }

        std::cout << "enterd number: " << input << std::endl; 

        akNum.startAlgorithm(); // starting algorithm

        char choice; 

        std::cout << "Try an other number? [y/n]: ";
        std::cin >> choice;

        // stopping if user wants to
        if(choice != 'y'){
            break;
        }
    }

    return 0;
}


void  AKNum::getDigits(){

    digits.clear(); // emptying vector before new input

    int tempInput = inputNum;   
    int digit{0};   

           
    while(tempInput > 0){                                       
        digit = tempInput % 10;  // modulus to get first digit of the number 
        tempInput = tempInput / 10; // dividing by ten to to go to the next digit
        digits.push_back(digit); // pushing digits in vector
    }
}

bool AKNum::validateInput(){

    int firstDigit = digits[0];

    // if there is one different digit, the input is valid 
    for(auto digit : digits){   // iterating trough vector 
        if(digit != firstDigit){
            return true;
        }
    }
            
    return false;
}

int AKNum::vecToNum(){

    int newNum{0};

    for(auto digit : digits){
        newNum = newNum * 10 + digit; // converting vector back to an integer
    }

    return newNum;
}

int AKNum::subtract(){

    // sorting and assigning vector to temporary integers
    sortDesc();
    int bigNum = vecToNum();
    sortAsc();
    int smallNum = vecToNum();

    return bigNum - smallNum; // returning subtraction of the two numbers
}

void AKNum::startAlgorithm(){

    int tempResult{0};
            
    // loop till break condition
    while(true){  

        getDigits(); // getting single digits from int

        // validating input
        if(!validateInput()){ 
            std::cerr << "Result: 0" << std::endl;
            return; // if not valid --> new input
        }

        tempResult = subtract(); // substracting and save result in variable

        std::cout << "temp result: " << tempResult << std::endl; // printing new results on konsole

        // checking if the result already exists 
        if(results.find(tempResult) != results.end()){   
 
            std::cout << "Result: " << tempResult << std::endl;  // printing result
            break;
        }

        results.insert(tempResult); // adding new result to set
                
        inputNum = tempResult; // result is new input number
    }

    results.clear(); // emptiyng results vector when algorithm finished 
}