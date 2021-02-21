#include "prime.h"


prime::prime(unsigned long max, std::string outfile) {
            this->_max=max;
            this->_currentnum=0;
            this->_outfilename = outfile;
            std::cout << "will write results to: " << outfile << std::endl;

/*
            std::ifstream file;
            file.open(this->_outfilename);

            file.close();
*/
}

bool prime::isprime(unsigned long number){  //Checks if the current number is a prime
     if (number <= 1){
        return false;  // not a prime
    }

    // Check from 2 to n-1
    for (unsigned long i = 2; i < number; i++)
        if (number % i == 0)
        {
            return false;  // not a prime
        }
 
    return true; // a prime
}

void prime::getallprimes(void){ // iterates to max-value and checks them all for primes
    this->_outfile.open(this->_outfilename);
    std::cout << "Getting primes. Please wait..." << std::endl;
    while (this->_currentnum < this->_max){    
                
        if (this->isprime(this->_currentnum)){
            std::cout << "Found new prime: " << this->_currentnum << std::endl;
            this->_outfile << this->_currentnum << std::endl;
        }
        this->_currentnum++;
    }
    std::cout << "maximum numbers processed." << std::endl;
    this->_outfile.close();
    return;
}