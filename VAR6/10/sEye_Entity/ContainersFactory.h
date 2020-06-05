#pragma once

#include "Containers.h"

class factory {
public:
    virtual container& create() = 0;
};

class vectorFactory : factory {
private:
    bool load(vector& container);
    bool save(vector& container);
public:
    vector& create() override;
    void destroy(vector& containerToDestroy);
};


class listFactory: factory {
public:
    list& create() override;
    void destroy(list& containerToDestroy);
};