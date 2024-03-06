//
// Created by ganim on 05/02/2024.
//

#include "CH.h"

void CH::mutateDNA() {
    double mutationProbability = (seq.length()-1.0)/seq.length(); // the propabilty needed for Ch.H updates
    for (char &nucleotide : seq) {
        double randProb = rand() / static_cast<double>(RAND_MAX);//here we did a normalzition process.
        if (randProb <= mutationProbability) { // here i checked if randprob is lesss or equal than my probability
            //
            switch (nucleotide) {
                case 'T': nucleotide = 'A'; break;
                case 'C': nucleotide = 'G'; break;
                case 'G': nucleotide = 'C'; break;
            }
        }
    }

}

Covid::type CH::gettype() const {
    return Covid::type::CH;
}
