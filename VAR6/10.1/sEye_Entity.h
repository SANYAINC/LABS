#pragma once

#define MAX_CHAR 25

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
    human(short int xMin, short int xMax, short int yMin, short int yMax,
            char sex, char isAdult, char hasGlasses, char hasBeard);

    char getSex() const;
    char getAge() const;
    char getGlasses() const;
    char getBeard() const;

    bool setSex(char sex);
    bool setAge(char isAdult);
    bool setGlasses(char hasGlasses);
    bool setBeard(char hasBeard);

    void print() const override;
};


class vehicle: public entity {
protected:
    char* mColor;
public:
    vehicle(short int xMin, short int xMax, short int yMin, short int yMax,
            const char* color);
    vehicle(const vehicle& anotherVehicle);
    vehicle& operator=(const vehicle& anotherVehicle);
    ~vehicle();

    const char* getColor() const;

    bool setColor(const char* color);
};


class item: public entity {
protected:
    char* mName;
    char* mFirstAppearanceTime;
public:
    item(short int xMin, short int xMax, short int yMin, short int yMax,
            const char* name, const char* timeWhenAppeared);
    item(const item& anotherItem);
    item& operator=(const item& anotherItem);
    ~item();

    const char* getName() const;
    const char* getTime() const;

    bool setName(const char* name);
    bool setTime(const char* firstAppearanceTime);

    void print() const override;
};

class bike: public vehicle {
    char mHasLock;
public:
    bike(short int xMin, short int xMax, short int yMin, short int yMax,
            const char* color,
            char hasLock);

    char getLock() const;

    bool setLock(char hasLock);

    void print() const override;
};