#ifndef VIRUS_HW1_ADVANCED_XBB_H
#define VIRUS_HW1_ADVANCED_XBB_H

#include "Covid.h"

class XBB : public Covid {
public:
    XBB(const string& dna) : Covid(dna) {}

    void mutateDNA() override;
    type gettype()const override;
};

#endif //VIRUS_HW1_ADVANCED_XBB_H
