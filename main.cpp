#include "Simulation.h"
#include <iostream>

int main(int argc, char* argv[]) {
    if (argc != 3) {//checking if given 2 paramaters
        std::cerr << "Usage: " << argv[0] << " <configFilePath> <populationFilePath>\n";
        return 1;
    }

    try {

        Simulation sim(argv[1], argv[2]);
        sim.run();//this function is responible for runing the sequence
    } catch (const std::runtime_error& e) {
        std::cerr << "Exception encountered: " << e.what() << std::endl;
        return 1;
    }

    return 0;
}