#pragma once

class entity {
protected:
    short int mXMin;
    short int mXMax;
    short int mYMin;
    short int mYMax;

    entity(short int xMin, short int xMax, short int yMin, short int yMax);

public:
    short int getXMin() const;
    short int getXMax() const;
    short int getYMin() const;
    short int getYMax() const;

    bool setXMin(short int xMin) const;
    bool setXMax(short int xMax) const;
    bool setYMin(short int yMin) const;
    bool setYMax(short int yMax) const;

    virtual void print() const = 0;
};