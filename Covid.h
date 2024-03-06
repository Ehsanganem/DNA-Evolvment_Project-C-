#ifndef VIRUS_HW1_ADVANCED_COVID1H
#define VIRUS_HW1_ADVANCED_COVID1H

#include <iostream>
#include "string"
#include "CovidPtr.h"
using namespace std;
class Covid  {
protected:
    string seq;
    string intalialSeq;

public:
    enum class type{XBB='x',CH='c',BQ='b'};//enum class for easier intallizing for the viruses based on the file passed
    Covid(const string& dna):seq(dna),intalialSeq(dna) {}
    ostream& printAncestor(ostream& out)const;//prints the ancestor;
    virtual ~Covid()=default;
    virtual void mutateDNA() =0;
    const string& getseq()const;//a getter for the dna sequence
    const string& getIntial()const;//gets the intalialstring
    void setseq(const string& dna);//setter
    double getFitness(const string& target)const ;//we get the fittnes with comparing to the target
    friend ostream& operator<<(ostream & in,const Covid& first);
    virtual type gettype()const=0;//a pure virtual get type function implemented in derived classes
};

#endif //VIRUS_HW1_ADVANCED_COVID_H
