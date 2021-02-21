// thread example
#include <iostream>       // std::cout
#include <thread>         // std::thread
 
void foo() 
{
  int i = 15;
  while (i > 0) {
  		std::cout << "Foo: " << i << std::endl;
		i--;
	}
}

void checkisprime(unsigned int x)
{
  while (x > 0) {
  		std::cout << "Bar: " << x << std::endl;
		x--;
	}
}

int main() 
{
  std::thread first (foo);     // spawn new thread that calls foo()
  std::thread second (checkisprime,25U);  // spawn new thread that calls bar(0)

  std::cout << "main, foo and bar now execute concurrently...\n";

  // synchronize threads:
  first.join();                // pauses until first finishes
  second.join();               // pauses until second finishes

  std::cout << "foo and bar completed.\n";

  return 0;
}
