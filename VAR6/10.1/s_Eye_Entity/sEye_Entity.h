#pragma once

#include <iostream>

#define FRAME_WIDTH 3840
#define FRAME_HEIGHT 2160
#define MAX_CHAR 25


class entity {
protected:
    short int mXMin;
    short int mXMax;
    short int mYMin;
    short int mYMax;

private:
    void validate(short int min, short int max, char axis);

public:
    entity(short int xMin, short int xMax, short int yMin, short int yMax);
    virtual ~entity();

    friend std::ostream& operator<<(std::ostream& out, const entity& obj);

    short int getXMin() const;
    short int getXMax() const;
    short int getYMin() const;
    short int getYMax() const;

    void setXRange(short int xMin, short int xMax);
    void setYRange(short int yMin, short int yMax);

    virtual void print() const = 0;
};


class human : virtual public entity {
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
    ~human() override;

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


class vehicle : virtual public entity {
protected:
    char* mColor;

private:
    void validate(const char* color);

public:
    vehicle(short int xMin, short int xMax, short int yMin, short int yMax,
            const char* color);
    vehicle(const vehicle& anotherVehicle);
    vehicle& operator=(const vehicle& anotherVehicle);
    ~vehicle() override;

    const char* getColor() const;

    void setColor(const char* color);
};


class item : public entity {
protected:
    char* mName;
    char* mFirstAppearanceTime;

private:
    void validate(const char* string);

public:
    item(short int xMin, short int xMax, short int yMin, short int yMax,
         const char* name, const char* timeWhenAppeared);
    item(const item& anotherItem);
    item& operator=(const item& anotherItem);
    ~item() override;

    const char* getName() const;
    const char* getTime() const;

    void setName(const char* name);
    void setTime(const char* firstAppearanceTime);

    void print() const override;
};

class bike : public vehicle {
protected:
    char mHasLock;

private:
    void validate(char param);

public:
    bike(short int xMin, short int xMax, short int yMin, short int yMax, const char* color,
         char hasLock);
    ~bike() override;

    char getLock() const;

    void setLock(char hasLock);

    void print() const override;
};

class motorTransport : public vehicle {
protected:
    char* mRegisterPlate;

private:
    void validate(const char* registerPlate);

public:

    motorTransport(short int xMin, short int xMax, short int yMin, short int yMax,
                   const char* color,
                   const char* registerPlate);
    motorTransport(const motorTransport& anotherMT);
    motorTransport& operator=(const motorTransport& anotherMT);
    ~motorTransport() override;

    const char* getRegisterPlate();

    void setRegisterPlate(const char* registerPlate);
};


class cyclist : public human, public bike {
protected:
    char mHasHelmet;

private:
    void validate(char param);

public:
    cyclist(short int xMin, short int xMax, short int yMin, short int yMax,
            char sex, char isAdult, char hasGlasses, char hasBeard,
            const char* color, char hasLock, char hasHelmet);
    ~cyclist() override;

    char getHelmet() const;

    void setHelmet(char hasHelmet);

    void print() const override;
};


class car : public motorTransport {
protected:
    char mBodyType;
    char mIsTaxi;

private:
    void validate(char param, char type);

public:
    car(short int xMin, short int xMax, short int yMin, short int yMax,
        const char* color,
        const char* registerPlate,
        char bodyType, char isTaxi);
    ~car() override;

    char getBodyType() const;
    char getTaxi() const;

    void setBodyType(char bodyType);
    void setTaxi(bool isTaxi);

    void print() const override;
};