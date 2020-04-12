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

    bool setXMin(short int xMin);
    bool setXMax(short int xMax);
    bool setYMin(short int yMin);
    bool setYMax(short int yMax);

    virtual void print() const = 0;
};


class human: public entity {
protected:
    char mSex;
    char mIsAdult;
    char mHasGlasses;
    char mHasBeard;
public:
    human(short int xMin, short int xMax, short int yMin, short int yMax);

    char getSex() const;
    char getAge() const;
    char getGlasses() const;
    char getBeard() const;

    void setSex(char sex);
    void setAge(char isAdult);
    void setGlasses(char hasGlasses);
    void setBeard(char hasBeard);

    void print() const override;
};