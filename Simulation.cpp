//
// Created by ganim on 05/02/2024.
//

#include <fstream>
#include "Simulation.h"
#include "XBB.h"


//here i will calculate the fitness of each virus in my vector and finding the fittest virus of all
bool Simulation::calculateFitness() {
    double maxFitness = 0.0;
    fittest = nullptr;

    for (size_t i = 0; i < viruses.size(); ++i) {
        double fitness = viruses[i].getCovid()->getFitness(target);
        // Update the fittest virus if current virus's fitness is higher
        if (fitness > maxFitness) {
            maxFitness = fitness;
            fittest = viruses[i].getCovid();
        }

        if (abs(fitness - 1.0) < 0.000001) {
            return true;
        }

    }
        return false;
}

//in this function i have ran on my viruses vector comparing each viruses vector
// and eventually finding the weakest and replacing it.
void Simulation::findweakest(const string &dna1, const string &dna2,const string& target,int index1 ,int index2) {
    CovidPtr* weak1;
    CovidPtr* weak2;
    if(viruses[0].getCovid()->getFitness(target)<viruses[1].getCovid()->getFitness(target)){
        weak1=&viruses[0];
        weak2=&viruses[1];
    }
    else{
        weak1=&viruses[1];
        weak2=&viruses[0];
    }
    for (unsigned int i=2;i<viruses.size();i++ ) {
        if(viruses[i].getCovid()->getFitness(target)<weak1->getCovid()->getFitness(target)){
            weak2=weak1;
            weak1=&viruses[i];//decelaring the weakests
        }
        else if(viruses[i].getCovid()->getFitness(target)<weak2->getCovid()->getFitness(target)){
            weak2=&viruses[i];//weakest is viruses[i]
        }
    }
    weak1->getCovid()->setseq(dna1);
    ancestors[*weak1]=viruses[index1];
    weak2->getCovid()->setseq(dna2);
    ancestors[*weak2]=viruses[index2];
}

//our constructor for starting the simulation process and retreving data from files using the two functions
Simulation::Simulation(const std::string& configFilePath, const std::string& populationFilePath) {
    parseConfigFile(configFilePath);
    parsePopulationFile(populationFilePath);
}
//here i parse the data i got from my file defining the dimension and target and the number of runs
void Simulation::parseConfigFile(const string &filePath) {
    std::ifstream file(filePath);
    if (!file) throw std::runtime_error("Cannot open config file");
    file >> dimension;
    file.ignore(256,'\n');
    std::getline(file, target);
    target.erase(std::remove(target.begin(), target.end(), ' '), target.end());
    file>>max_time_clock;
}
//here i populate my viruses vector and ancestor map(for refernce counting) from the file.
void Simulation::parsePopulationFile(const std::string& filePath) {
    std::ifstream file(filePath);
    if (!file) throw std::runtime_error("Cannot open population file");

    int populationSize;
    file >> populationSize;
    file.ignore(256,'\n');
    for (int i = 0; i < populationSize; ++i) {
        char type;
        std::string dna;
        file >> type;
        getline(file,dna);
        dna.erase(std::remove(dna.begin(), dna.end(), ' '), dna.end());

        CovidPtr virus = Factory::createcovid(type,dna);

        if (virus.getCovid()!= nullptr){
            viruses.push_back(virus);
            ancestors[virus]=virus;
        }
    }
}



// Function to perform recombination between two DNA sequences
void recombineDNA(std::string& dna1, std::string& dna2) {
    if (dna1.empty() || dna2.empty()) return;

    int length = dna1.length();
    int start = 2+rand() % (length-3);
    int t=3+rand()%(length-1-3+1);
    // Exchange DNA segments between dna1 and dna2
    for(int i=start+1;i<t+1;i++){
        char tmp=dna1[i];
        dna1[i]=dna2[i];
        dna2[i]=tmp;
    }

}
//

void Simulation::updateGeneration() {
for (CovidPtr c:viruses){
    c.getCovid()->mutateDNA();
}
}

//the run function is responsible for runing the simulation and calling the neccesarily updates for the viruses
void Simulation::run() {
    for (int generation = 0; generation <max_time_clock; ++generation) {
        bool x=calculateFitness();
        if (x) {
            std::cout << "Optimal fitness reached in generation " << generation << std::endl;
            break;
        }
        groupUpdate(); //group update call
        updateGeneration(); // Updating the generation
    }
    printOutput();
    // output will be printed
}
// this function will start the groupupdate first selecting two random indexs and then sending these indexes
//for recombantion and replaciment with the other sequence
void Simulation::groupUpdate() {


int i=rand()%viruses.size();//index 1
int j=rand()%(viruses.size()-1);//index 2
if(j>=i){ //checking and valditing that i!=j
    j++;
}
string s1=viruses[i].getCovid()->getseq();
string s2=viruses[j].getCovid()->getseq();
recombineDNA(s1,s2);
findweakest(s1,s2,target,i,j);
}
//this print output function is responsible for the ancestor printing format
void Simulation::printOutput() const {
    for(unsigned int i=0;i<viruses.size();i++){//orignal sequence print
        string s=viruses[i].getCovid()->getseq();
        for(char c:s){
            cout<<c<<" ";
        }
        std::cout << std::endl;
//        cout<<*(viruses[i].getCovid())<<endl; //
    }
    cout<<endl;
    for(unsigned int i=0;i<viruses.size();i++){
        int count=0;
        for(const pair<CovidPtr,CovidPtr>& p:ancestors){ //we raise the number of occurence of the same ancesotr
            if(viruses[i].getCovid()==p.second.getCovid()){
                count++;
            }
        }
        viruses[i].getCovid()->printAncestor(cout)<<" "<<(count)<<endl;

    }
    cout<<endl;
    cout<<*fittest<<endl;
}








