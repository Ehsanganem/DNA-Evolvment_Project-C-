//
// Created by ganim on 08/02/2024.
//

#include "Factory.h"
#include "XBB.h"
#include "BQ.h"
#include "CH.h"
#include "Covid.h"

//i implemented the Factory class as a help class for manging the created viruses while making sure
// the memory management of each instance of Covid is being created correctly using my CovidPtr class
CovidPtr Factory::createcovid(char type, const string& seq) {
    switch (type) {
        case static_cast<int>(Covid::type::XBB) :
            return CovidPtr(new XBB(seq));
        case static_cast<int>(Covid::type::CH) :
            return CovidPtr(new CH(seq));
        case static_cast<int>(Covid::type::BQ) :
            return CovidPtr(new BQ(seq));
        default:
            return nullptr;
    };

}
