//
// Created by ganim on 09/02/2024.
//

#include "CovidPtr.h"
#include "Covid.h"

//copy ctor
CovidPtr::CovidPtr(const CovidPtr &other):mem(nullptr) {
    operator=(other);
}
//copy assigment
CovidPtr &CovidPtr::operator=(const CovidPtr &other) {
    if(this!=&other){
    destroy();
    this->mem=other.mem;
    mem->refcount++;  //another instance of this virus has occured so raise the number of count
    }
    return *this;
}

void CovidPtr::destroy() {
    if(this->mem!= nullptr) {
        this->mem->refcount--;//we lower the number of occurences of the virus
        if (this->mem->refcount == 0) { //if 0 none are left delete the Virus from my population
            delete this->mem->covid;
            delete this->mem;
        }
        this->mem= nullptr;
    }

}

CovidPtr::~CovidPtr() {
    destroy();
}

CovidPtr &CovidPtr::operator=(CovidPtr &&other) { //move assigment operator
    destroy();
    this->mem=other.mem;
    this->mem->refcount++; // we raise the count as another virus joined the same ancestral family
    other.destroy();
    return *this;
}
CovidPtr::CovidPtr(CovidPtr&& other):mem(nullptr) { //move ctor call
    operator=(other);
}

CovidPtr::CovidPtr(Covid *covid) { //  creating a new Virus starting with refcount 1;
    this->mem=new CovidMem();
    this->mem->covid=covid;
    this->mem->refcount=1;
}

Covid *CovidPtr::getCovid() {
    return this->mem->covid;
}

int CovidPtr::getRefCount()const {
    return this->mem->refcount;
}

CovidPtr::CovidPtr() {
    this->mem= nullptr;

}

CovidPtr::operator bool() const {
    return this->mem!= nullptr;
}

bool CovidPtr::operator<(const CovidPtr &other) const {
    return this->mem<other.mem;
}

const Covid *CovidPtr::getCovid() const {
    return this->mem->covid;
}

