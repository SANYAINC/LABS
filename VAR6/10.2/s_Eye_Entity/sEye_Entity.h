#pragma once

#include <iostream>

#define FRAME_WIDTH 3840
#define FRAME_HEIGHT 2160
#define MAX_CHAR 25

//Sex: M/F/U
//Bool: Y/N/U
//BodyType: 0-10

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

    char getPersonSex() const;
    char getPersonIsAdult() const;
    char getPersonHasGlasses() const;
    char getPersonHasBeard() const;

    void setPersonSex(char sex);
    void setPersonIsAdult(char isAdult);
    void setPersonHasGlasses(char hasGlasses);
    void setPersonHasBeard(char hasBeard);

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

    const char* getVehicleColor() const;

    void setVehicleColor(const char* color);
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

    const char* getItemName() const;
    const char* getItemTime() const;

    void setItemName(const char* name);
    void setItemTime(const char* firstAppearanceTime);

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

    char getBikeLock() const;

    void setBikeLock(char hasLock);

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

    const char* getMTRegisterPlate() const;

    void setMTRegisterPlate(const char* registerPlate);
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

    char getCyclistHasHelmet() const;

    void setCyclistHasHelmet(char hasHelmet);

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

    char getCarBodyType() const;
    char getCarIsTaxi() const;

    void setCarBodyType(char bodyType);
    void setCarIsTaxi(bool isTaxi);

    void print() const override;
};