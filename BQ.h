#ifndef VIRUS_HW1_ADVANCED_BQ_H
#define VIRUS_HW1_ADVANCED_BQ_H

#include "Covid.h"

class BQ : public Covid {
public:
    BQ(const string& dna) : Covid(dna) {}
    void mutateDNA() override;
    type gettype()const override;
};

#endif //VIRUS_HW1_ADVANCED_BQ_H

