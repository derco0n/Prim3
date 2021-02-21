#include "prime.h"
#include <thread>
#include <vector>

// These are not needed here, as prime.h includes them
//#include <string>
//#include <fstream>
//#include <iostream>
//#include <string>

class prime_mt : public prime { //A multithreaded extension of prime
    protected:    

    private:
        unsigned int _max_threads;
        std::vector<std::thread> cur_threads; //An ArrayList-like object (vetor) that will contain thread-objects
        void checkisprime(unsigned long number);
        

    public:
        prime_mt(unsigned long max, std::string outfile, unsigned int max_threads);

        void getallprimes() override;

};