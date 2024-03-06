//
// Created by ganim on 08/02/2024.
//

#ifndef VIRUS_HW1_ADVANCED_FACTORY_H
#define VIRUS_HW1_ADVANCED_FACTORY_H


#include "Covid.h"
#include "CovidPtr.h"

class Factory {
public:
    static CovidPtr createcovid(char type,const string& seq);
};


#endif //VIRUS_HW1_ADVANCED_FACTORY_H
