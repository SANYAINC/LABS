#include "../../ContainersFactory.h"

#include <fstream>

using namespace std;

vector& vectorFactory::create() {
    vector* result = new vector;
    if (!load(*result)) {
        std::cerr << "CANT LOAD" << std::endl;
    }
    return *result;
}

void vectorFactory::destroy(vector& vectorToDestroy) {
    if (!save(vectorToDestroy)) {
        std::cerr << "CAN'T SAVE" << std::endl;
    }
    delete &vectorToDestroy;
}

bool vectorFactory::load(vector& container) {
    ifstream f(VECTOR_PATH_TO_STORAGE, ios::binary);
    if (!f.is_open()) {
        return false;
    }

    char type;

    f.seekg(0, ios::end);
    int eof = f.tellg();
    f.seekg(0, ios::beg);

    entity* buf;

    while (f.tellg() != eof) {
        f.read(reinterpret_cast<char*>(&type), sizeof(char));

        switch (type) {
            case HUMAN_ID: {
                buf = new human;
                break;
            }
            case ITEM_ID: {
                buf = new item;
                break;
            }
            case BIKE_ID: {
                buf = new bike;
                break;
            }
            case CYCLIST_ID: {
                buf = new cyclist;
                break;
            }
            case CAR_ID: {
                buf = new car;
                break;
            }
        }
        buf->read(f);
        container.pushBack(*buf);
        delete buf;
    }
    f.close();
    return true;
}

bool vectorFactory::save(vector& container) {
    ofstream f(VECTOR_PATH_TO_STORAGE, ios::binary);
    if (!f.is_open()) {
        return false;
    }
    for (int i = 0; i < container.getSize(); ++i) {
        container[i]->write(f);
    }
    f.close();
    return true;
}
