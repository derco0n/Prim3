#include "prime_mt.h"

prime_mt::prime_mt(unsigned long max, std::string outfile, unsigned int max_threads) 
: prime(max, outfile) {
    this->_max_threads=max_threads;
    this->cur_threads.reserve(this->_max_threads);
}

void prime_mt::checkisprime(unsigned long number){
    //Checks if a number is a prime and raises an even if so
    
    if (this->isprime(number)){
            //std::cout << "Found new prime: " << number << std::endl;
            this->_outfile << number << std::endl;
        }
}

void prime_mt::getallprimes(void){
  this->_outfile.open(this->_outfilename);
    std::cout << "Getting primes (using " << this->_max_threads << " threads). Please wait..." << std::endl;
    while (this->_currentnum < this->_max){  

        while (this->cur_threads.size() < this->_max_threads){
            //As long as we didn't reach the max-thread count

            std::thread temp (&prime_mt::checkisprime,this,this->_currentnum); //Create a new thread-object
            this->cur_threads.push_back(std::move(temp)); //and move it to the end of the "vector"
            this->_currentnum++; //Iterate to the next number to try
        }
        //Current threads is now at maximum concurrent threads
        // We wait for them to finish             
        for (std::thread& t: this->cur_threads){ //foreach thread in cur_threads...            
            //std::cout << "Waiting for Thread " << t.get_id() << std::endl; //DEBUG
            t.join();
            //std::cout << "finished wait for Thread " << std::endl; //DEBUG
        }
        
        //All threads finished
        this->cur_threads.clear(); //Clear the "arraylist/vector-thingy" again
        this->_currentnum++; //Iterate to the next number to try
       
    }
    std::cout << "maximum numbers processed." << std::endl;
    this->_outfile.close();
    return;
}