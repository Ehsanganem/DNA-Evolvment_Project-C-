//
// Created by ganim on 05/02/2024.
//

#include "XBB.h"



void XBB::mutateDNA() {
    double mutationProbability = 0.25;
    for (char &nucleotide : seq) {
        double randProb = rand() / static_cast<double>(RAND_MAX); //here we did a normalzition to fall between 1 and 0 //
        // here i checked if randprob is lesss or equal than my probability//
        // than preform the requried update
        if (randProb <= mutationProbability) {
            if (nucleotide == 'A') {
                nucleotide = 'T';
            } else if (nucleotide == 'T') {
                nucleotide = 'A';
            }
        }
    }
}

Covid::type XBB::gettype() const {
    return Covid::type::XBB;
}


