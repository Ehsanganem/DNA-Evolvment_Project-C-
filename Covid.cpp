//
// Created by ganim on 05/02/2024.
//

#include "Covid.h"



//getter for the dnaseq
const string& Covid::getseq()const {
return this->seq;
}
//here i run on the target and on the seq and see if we have hits if so we raise the matches by 1 then we normalize the result and return it
double Covid::getFitness(const string& target)const  {
    int matches = 0;
    for (size_t j = 0; j < target.length(); ++j) {
        if (seq[j] == target[j]) {
            matches++;
        }
    }
    double fitness = static_cast<double>(matches) / static_cast<double>(target.length());
return fitness;
}
//setter for dnaseq
void Covid::setseq(const string& dna) {
    this->seq=dna;
}
//my <<operator
ostream &operator<<(ostream &in, const Covid &first) {
    in<<static_cast<char>(first.gettype())<<" ";
    string dna=first.getseq();
    for(char c:dna){
        in<<c<<" ";
    }
    in<<endl;
    return in;

}

const string &Covid::getIntial() const {
    return this->intalialSeq;
}

ostream& Covid::printAncestor(ostream &out) const {
    out << static_cast<char>(this->gettype()) << " "; //
    std::string dna = this->getIntial(); //print the intial dnasequnce
    for (char nucleotide : dna) {
        out << nucleotide << " ";
    }
    return out;


}


