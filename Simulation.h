//
// Created by ganim on 05/02/2024.
//

#ifndef VIRUS_HW1_ADVANCED_SIMULATION_H
#define VIRUS_HW1_ADVANCED_SIMULATION_H
#include <algorithm>
#include <iostream>
#include <string>
#include "Covid.h"
#include <vector>
#include <random>
#include <map>
#include "Factory.h"
//header for simulation class i documented in the cpp file in all classes
class Simulation {

private:
    map<CovidPtr,CovidPtr> ancestors;
vector<CovidPtr> viruses;
int dimension;
string target;
Covid* fittest;
int max_time_clock;

public:
    Simulation(const std::string& configFilePath, const std::string& populationFilePath);
    void updateGeneration();
    void parseConfigFile(const std::string& filePath);
    void parsePopulationFile(const std::string& filePath);
    void printOutput()const;
    bool calculateFitness();
    void findweakest(const string& dna1,const string& dna2,const string& target,int i,int j);
    Covid* getFittest()const{ return this->fittest;}
    void groupUpdate();
    void run();


};


#endif //VIRUS_HW1_ADVANCED_SIMULATION_H
