#ifndef VIRUS_HW1_ADVANCED_CH_H
#define VIRUS_HW1_ADVANCED_CH_H

#include "Covid.h"

class CH : public Covid {
public:
    CH(const string& dna) : Covid(dna) {}
    type gettype()const override;

    void mutateDNA() override;
};

#endif //VIRUS_HW1_ADVANCED_CH_H
