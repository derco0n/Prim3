#include <string>
#include <fstream>
#include <iostream>
#include <string>
#include <fstream>

class prime {
    protected:
        unsigned long _max;  // maximum number
        unsigned long _currentnum; // current number

        bool isprime(unsigned long number); //checks if the current number is a prime
        std::ofstream _outfile;
        std::string _outfilename;

    private:
        

    public:
        prime(unsigned long max, std::string outfile);

        virtual void getallprimes();

};