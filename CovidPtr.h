//
// Created by ganim on 09/02/2024.
//

#ifndef VIRUS_HW1_ADVANCED_COVIDPTR_H
#define VIRUS_HW1_ADVANCED_COVIDPTR_H

class Covid;
//the CovidPtr is the class responsible
// for our actual refernce counting and is implemeted to work like a shared_ptr

class CovidPtr {
private:
    struct CovidMem{
        Covid* covid;
        int refcount;
    };
    CovidMem* mem;
    void destroy();
public:
    CovidPtr();
    CovidPtr(Covid* covid);
    CovidPtr(const CovidPtr& other);
    CovidPtr& operator=(const CovidPtr& other);
    ~CovidPtr();
    Covid* getCovid();
    int getRefCount()const;
    CovidPtr(CovidPtr&& other);
    CovidPtr& operator=(CovidPtr&& other);
    bool operator<(const CovidPtr& other)const;
    const Covid* getCovid()const;


    operator bool()const;
};


#endif //VIRUS_HW1_ADVANCED_COVIDPTR_H
