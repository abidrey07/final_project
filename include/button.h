//
// Created by Abid Rey Magsambol on 10/16/25.
//

#ifndef FINALPROJECT_BUTTON_H
#define FINALPROJECT_BUTTON_H
#include <vector>

class Button {
protected:
    std::string name;
    bool isPressed = false;
public:
    Button(std::string name) : name(name) {}; //constructor for each button & its commands
    void buttonFunction() const;
    virtual bool checkIfIsPressed(); //if pressed, set to true
    ~Button() {};
    std::string getName() const;
    bool getIsPressed() const;
};

class Trigger : public Button {
private:
    double pressureValue = 0.0;
public:
    Trigger(std::string name) : Button(name) {};
    virtual bool checkIfIsPressed() override; //extra code to take into account of trigger pressure
    ~Trigger() {};
    double getPressure() const;
};

#endif //FINALPROJECT_BUTTON_H