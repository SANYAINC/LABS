#pragma once

#include <iostream>
#include <fstream>
#include "EntitiesID.h"

#define FRAME_WIDTH 3840
#define FRAME_HEIGHT 2160
#define MAX_CHAR 25

//Sex: M/F/U
//Bool: Y/N/U
//BodyType: 0-10

class entity {
protected:
    int mXMin;
    int mXMax;
    int mYMin;
    int mYMax;

private:
    void validate(int min, int max, char axis);

public:
    entity(int xMin, int xMax, int yMin, int yMax);
    entity();
    virtual ~entity();

    friend std::ostream& operator<<(std::ostream& out, const entity& obj);

    int getXMin() const;
    int getXMax() const;
    int getYMin() const;
    int getYMax() const;

    void setXRange(int xMin, int xMax);
    void setYRange(int yMin, int yMax);

    virtual void print() const = 0;
    virtual char type() const = 0;

    virtual void write(std::ofstream& oFile) const = 0;
    virtual void read(std::ifstream& iFile) = 0;
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
    human(int xMin, int xMax, int yMin, int yMax,
          char sex, char isAdult, char hasGlasses, char hasBeard);
    human();
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
    char type() const override;
    void write(std::ofstream &oFile) const override;
    void read(std::ifstream &iFile) override;
};


class vehicle : virtual public entity {
protected:
    char* mColor;

private:
    void validate(const char* color);

public:
    vehicle(int xMin, int xMax, int yMin, int yMax,
            const char* vehicleColor);
    vehicle();
    vehicle(const vehicle& anotherVehicle);
    ~vehicle() override;

    vehicle& operator=(const vehicle& anotherVehicle);

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
    item(int xMin, int xMax, int yMin, int yMax,
         const char* itemName, const char* timeWhenAppeared);
    item();
    item(const item& anotherItem);
    ~item() override;

    item& operator=(const item& anotherItem);

    const char* getItemName() const;
    const char* getItemTime() const;

    void setItemName(const char* name);
    void setItemTime(const char* firstAppearanceTime);

    void print() const override;
    char type() const override;
    void write(std::ofstream &oFile) const override;
    void read(std::ifstream &iFile) override;
};

class bike : public vehicle {
protected:
    char mHasLock;

private:
    void validate(char param);

public:
    bike(int xMin, int xMax, int yMin, int yMax, const char* vehicleColor,
         char bikeHasLock);
    bike();
    ~bike() override;

    char getBikeLock() const;

    void setBikeLock(char hasLock);

    void print() const override;
    char type() const override;
    void write(std::ofstream &oFile) const override;
    void read(std::ifstream &iFile) override;
};

class motorTransport : public vehicle {
protected:
    char* mRegisterPlate;

private:
    void validate(const char* registerPlate);

public:

    motorTransport(int xMin, int xMax, int yMin, int yMax,
                   const char* VehicleColor,
                   const char* registerPlate);
    motorTransport();
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
    cyclist(int xMin, int xMax, int yMin, int yMax,
            char sex, char isAdult, char hasGlasses, char hasBeard,
            const char* vehicleColor, char bikeHasLock, char cyclistHasHelmet);
    cyclist();
    ~cyclist() override;

    char getCyclistHasHelmet() const;

    void setCyclistHasHelmet(char hasHelmet);

    void print() const override;
    char type() const override;
    void write(std::ofstream &oFile) const override;
    void read(std::ifstream &iFile) override;
};


class car : public motorTransport {
protected:
    char mBodyType;
    char mIsTaxi;

private:
    void validate(char param, char type);

public:
    car(int xMin, int xMax, int yMin, int yMax,
        const char* vehicleColor,
        const char* registerPlate,
        char carBodyType, char isTaxi);
    car();
    ~car() override;

    char getCarBodyType() const;
    char getCarIsTaxi() const;

    void setCarBodyType(char bodyType);
    void setCarIsTaxi(bool isTaxi);

    void print() const override;
    char type() const override;
    void write(std::ofstream &oFile) const override;
    void read(std::ifstream &iFile) override;
};