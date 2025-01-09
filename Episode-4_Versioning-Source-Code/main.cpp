#include <iostream>
#include "config.h"

int main()
{
    std::cout << "Version: " << Versioning_Source_Code_VERSION_MAJOR << "." << Versioning_Source_Code_VERSION_MINOR << "." << Versioning_Source_Code_VERSION_PATCH << std::endl;
    return 0;
}