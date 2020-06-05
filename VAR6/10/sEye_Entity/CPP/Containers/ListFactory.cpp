#include "../../ContainersFactory.h"

list& listFactory::create() {
    return *new list;
}

void listFactory::destroy(list& listToDestroy) {
    delete &listToDestroy;
}