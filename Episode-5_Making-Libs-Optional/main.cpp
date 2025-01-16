#include <iostream>
#include "config.h"

#ifdef USE_ADDER
    #include "adder.h"
#endif

int main() {
#ifdef USE_ADDER
    std::cout << "2 + 3 = " << adder::add(2, 3) << std::endl;
#else
    std::cout << "Adder is not available." << std::endl;
#endif
    return 0;
}
