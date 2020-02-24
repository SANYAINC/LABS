#include "7.3.h"


date::date() {
    mDate.year = 120;
    mDate.month = 1;
    mDate.day = 1;
}
date::date(int day, int month, int year) {
    if (validate(day, month, year)) {
        mDate.year = CURRENT_YEAR - year;
        mDate.month = month;
        mDate.day = day;
    } else {
        mDate.year = 120;
        mDate.month = 1;
        mDate.day = 1;
    }
}
date &date::operator = (date date2) {
    mDate.dateEncrypted = date2.mDate.dateEncrypted;
    return *this;
}
bool date::validate(int day, int month, int year) {
    return !(day > 31 or day < 1 or month > 12 or month < 1 or year > CURRENT_YEAR or year < 1900);
}
void date::setDate(int day, int month, int year) {
    if (validate(day, month, year)) {
        mDate.year = CURRENT_YEAR - year;
        mDate.month = month;
        mDate.day = day;
    } else {
        mDate.year = 120;
        mDate.month = 1;
        mDate.day = 1;
    }
}
unsigned short int date::getDateEncrypted() {
    return mDate.dateEncrypted;
}
int date::getYear() {
    return CURRENT_YEAR - mDate.year;
}
int date::getMonth() {
    return mDate.month;
}
int date::getDay() {
    return mDate.day;
}
void date::print() {
    printf("%02u.%02u.%d\n", mDate.day, mDate.month, CURRENT_YEAR - mDate.year);
}
void date::showEncrypted() {
    printf("%u\n", mDate.dateEncrypted);
}



student::student() {
    strcpy(mName, "UNKNOWN");
    strcpy(mLastName, "UNKNOWN");
    strcpy(mPatronymic, "UNKNOWN");
    mCourse = -1;
    mAvgGP = 0;
}
student::student(const char *name, const char *lastName, const char *patronymic, date birthDate, int course, double avgGP) {
    strcpy(mName, name);
    strcpy(mLastName, lastName);
    strcpy(mPatronymic, patronymic);
    mBirthDate = birthDate;
    mCourse = course;
    mAvgGP = avgGP;
}
student &student::operator = (student student1) {
    strcpy(mName, student1.mName);
    strcpy(mLastName, student1.mLastName);
    strcpy(mPatronymic, student1.mPatronymic);
    mBirthDate = student1.mBirthDate;
    mCourse = student1.mCourse;
    mAvgGP = student1.mAvgGP;
    return *this;
}
void student::print() {
    printf("\nNAME: %s\nLAST NAME: %s\nPATRONYMIC: %s\nBIRTH DATE: %02u.%02u.%d\nCOURSE: %d\nAVERAGE GRADE POINT: %.2lf\n",
            mName, mLastName, mPatronymic, mBirthDate.getDay(), mBirthDate.getMonth(), mBirthDate.getYear(), mCourse,
            mAvgGP);
}
void student::updateInfo(const char *name, const char *lastName, const char *patronymic, date birthDate, int course, double avgGP) {
    strcpy(mName, name);
    strcpy(mLastName, lastName);
    strcpy(mPatronymic, patronymic);
    mBirthDate = birthDate;
    mCourse = course;
    mAvgGP = avgGP;
}
char *student::getLastName() {
    return mLastName;
}
double student::getAvg() {
    return mAvgGP;
}


list::unit::unit(student data, unit *nextPtr /*= nullptr*/) {
    mData = data;
    mNextPtr = nextPtr;
}
list::list() {
    mSize = 0;
    mHead = nullptr;
}
student &list::operator [] (const int index) {
    if (index >= getSize() or index < 0) {
        error(700);
    }

    int counter = 0;
    unit *current = mHead;
    //Поиск элементов до nullptr
    while (current != nullptr) {
        if (counter == index) {
            return current->mData;
        } else {
            current = current->mNextPtr;
        }
        counter++;
    }
}
void list::error(int type) {
    switch (type) {
        case 700: {
            HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
            SetConsoleTextAttribute(console, FOREGROUND_RED);
            puts("ERROR 700: INDEX OUT OF RANGE\n");
            //HANDLE console1 = GetStdHandle(STD_OUTPUT_HANDLE);
            //SetConsoleTextAttribute(console1, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);
            exit(700);
        }
    }
}
void list::pushBack(student person) {
    if (mHead == nullptr) {
        //Если список пустой, добавить элемент в голову
        mHead = new unit(person);
    } else {
        //Если не пустой, ищем элемент списка, у которого указатель на следующий nullptr
        unit *current = mHead;
        while (current->mNextPtr != nullptr) {
            current = current->mNextPtr;
        }
        //Добавляем к последнему элементу указатель на новый
        current->mNextPtr = new unit(person);
    }
    mSize++;
}
void list::pushAt(student person, const int index) {
    if (index >= getSize() or index < 0) {
        error(700);
    }

    int counter = 0;
    unit *current = mHead;  //Указатель на текущий элемнт
    unit *previous = mHead; //Указатель на предыдущий элемент

    if (index == 0) {
        //Если нужно добавить элемент в начало, меняем голову на новую
        mHead = new unit(person);
        //У нового элемента указатель на следующий ставим прошлую голову
        mHead->mNextPtr = previous;
        mSize++;
        return;
    }
    while (current != nullptr) {
        if (counter == index) {
            previous->mNextPtr = new unit(person);  //Разрываем связь с последующим связывая с нвоым
            previous = previous->mNextPtr;  //Перескакиваем но новый
            previous->mNextPtr = current;   //В новом элементе указатель на следующий элемент делаем current
            mSize++;
            return;
        } else {
            //Скачем по списку
            counter++;
            previous = current;
            current = current->mNextPtr;
        }
    }
}
void list::pushAlphabetically(student person) {
    int size = getSize();
    if (size == 0) {
        pushBack(person);
        return;
    }
    unit *current = mHead;

    if (strcmp(current->mData.getLastName(), person.getLastName()) >= 0) {
        //Если нужно добавить элемент в начало
        pushAt(person, 0);
        return;
    }

    for (int i = 0; i < size - 1; ++i) {
        if (strcmp(current->mData.getLastName(), person.getLastName()) <= 0 and
            strcmp(current->mNextPtr->mData.getLastName(), person.getLastName()) > 0) {
            //Поиск места для вставки, с последующий вставкой
            pushAt(person, i + 1);
            return;
        } else {
            current = current->mNextPtr;
        }
    }
    pushBack(person);
}
void list::removeAt(int index) {
    if (index >= getSize() or index < 0) {
        error(700);
    }

    int counter = 0;
    unit *current = mHead;
    unit *previous;

    if (index == 0) {
        //Если нужно удалить элемент с начала
        mHead = mHead->mNextPtr; //Голову перемещаем на следующий элемент
        delete current; //Удаляем прошлую шолову
        mSize--;
        return;
    }
    current = mHead;
    previous = mHead;

    while (current != nullptr) {
        if (counter == index) {
            previous->mNextPtr = current->mNextPtr; //В i-1м элементе в адрес следующего кладем указатель на следующий iго элемента
            delete current; //Удаляем то, на что указывал iый
            mSize--;
            return;
        } else {
            counter++;
            previous = current;
            current = current->mNextPtr;
        }
    }
}
int list::getSize() {
    return mSize;
}
void list::selectGoodFromAll(list &list2) {
    int counter = 0;
    unit *current = mHead;
    while (current != nullptr) {
        if (current->mData.getAvg() > 8) {
            list2.pushAlphabetically(current->mData);
            removeAt(counter);
        }
        current = current->mNextPtr;
    }
}

