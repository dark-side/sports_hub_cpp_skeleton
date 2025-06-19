#include "BaseService.h"

int main() {
    BaseService service;
    service.start();

    std::cout << "Press Enter to stop the service..." << std::endl;
    std::cin.get(); // Wait for user input to stop the service
    
    service.stop();
    return 0;
}
