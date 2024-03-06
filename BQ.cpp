//
// Created by ganim on 05/02/2024.
//

#include "BQ.h"

void BQ::mutateDNA() {
    double mutationProbability = 1.0/seq.length();
    for (char &nucleotide : seq){
        double randProb = rand() / static_cast<double>(RAND_MAX);
        //here we did a normalzition to fall between 1 and 0 //
        // here i checked if randprob is lesss or equal than my probability//
        // than preform the requried update
        if (randProb <= mutationProbability) {
            switch (nucleotide) {
                case 'A': nucleotide = 'T'; break;
                case 'C': nucleotide = 'G'; break;
                case 'G': nucleotide = 'C'; break;
            }
        }
    }
}

Covid::type BQ::gettype() const {
    return Covid::type::BQ;
}
