#pragma once

#define FRAME_WIDTH 3840
#define FRAME_HEIGHT 2160
#define MAX_CHAR 25


class entity {
protected:
    short int mXMin;
    short int mXMax;
    short int mYMin;
    short int mYMax;

    entity(short int xMin, short int xMax, short int yMin, short int yMax);

private:
    void validate(short int min, short int max, char axis);

public:
    short int getXMin() const;
    short int getXMax() const;
    short int getYMin() const;
    short int getYMax() const;

    void setXRange(short int xMin, short int xMax);
    void setYRange(short int yMin, short int yMax);

    virtual void print() const = 0;
};


class human: virtual public entity {
protected:
    char mSex;
    char mIsAdult;
    char mHasGlasses;
    char mHasBeard;

private:
    void validate(char param, char type);

public:
    human(short int xMin, short int xMax, short int yMin, short int yMax,
            char sex, char isAdult, char hasGlasses, char hasBeard);

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


class vehicle: virtual public entity {
protected:
    char* mColor;

    vehicle(short int xMin, short int xMax, short int yMin, short int yMax,
            const char* color);
    vehicle(const vehicle& anotherVehicle);
    vehicle& operator=(const vehicle& anotherVehicle);
    ~vehicle();

private:
    void validate(const char* color);

public:

    const char* getColor() const;

    void setColor(const char* color);
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
protected:
    char mHasLock;
public:
    bike(short int xMin, short int xMax, short int yMin, short int yMax,
            const char* color,
            char hasLock);

    char getLock() const;

    bool setLock(char hasLock);

    void print() const override;
};

class motorTransport: public vehicle {
protected:
    char* registerPlate;

    motorTransport(short int xMin, short int xMax, short int yMin, short int yMax,
                   const char* color,
                   const char* registerPlate);
    motorTransport(const motorTransport& anotherMotorTransport);
    motorTransport& operator=(const motorTransport& anotherMotorTransport);
    ~motorTransport();

public:

    const char* getRegisterPlate();

    bool setRegisterPlate(const char* registerPlate);
};


class cyclist: public human, public bike {
protected:
    char mHasHelmet;
public:
    cyclist(short int xMin, short int xMax, short int yMin, short int yMax,
            char sex, char isAdult, char hasGlasses, char hasBeard,
            const char* color,
            char hasLock);
    cyclist(const human& person, const char* color, char hasLock);

    char getHelmet() const;

    bool setHelmet(char hasHelmet);

    void print() const override;
};


class car: public motorTransport {
protected:
    char mBodyType;
    bool mIsTaxi;
public:
    car(short int xMin, short int xMax, short int yMin, short int yMax,
        const char* color,
        const char* registerPlate,
        char bodyType, bool isTaxi);

    char getBodyType() const;
    char getTaxi() const;

    bool setBodyType(char bodyType);
    bool setTaxi(bool isTaxi);

    void print() const override;
};