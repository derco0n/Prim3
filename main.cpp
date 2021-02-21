/*
 This is a simple C++ programm that finds prime-numbers either single or multithreaded
 D. Marx, (derCo0n), 2021/02
 compile with: g++ ./main.cpp lib/prime.h lib/prime_mt.h lib/prime.cpp lib/prime_mt.cpp -pthread -std=c++11
*/

//#include "./lib/prime.h" //single-threaded
#include "./lib/prime_mt.h" //multi-threaded

int main (int argc, char **argv){
 unsigned long maxval = 18446744073709551615U; // maximum (unsigned value)
    
    //prime *myprime = new prime(maxval, "./outprimes.txt"); //single-threaded
    prime_mt *myprime = new prime_mt(maxval, "./outprimes.txt", 8);  //multi-threaded
    
    myprime->getallprimes();    

    return 0;
}