//
// Created by Abid Rey Magsambol on 10/16/25.
//

#ifndef FINALPROJECT_CONTROLLER_H
#define FINALPROJECT_CONTROLLER_H
#include <vector>

#include "button.h"
#include "joystick.h"

class Controller {
private:
    std::vector<Button> buttons;
    Joystick leftJoystick;
    Joystick rightJoystick;
    bool isRunning;
public:
    Controller(); //intialize controller, initialize all button and joysticks in src files
    void run(); //while running, loop for userinput
    void getUserInput() const; //wait for user input. send it over to translate
    void callCommand() const;
    //gets translation from translateUserInputToCommand, calls buttonFunction if button is pressed, calls move() if joystick
    bool getIsRunning() const;
    ~Controller();
    void translateUserInputToCommand() const; //TODO: figureout how to translate controller commands to pc using XInput
};

#endif //FINALPROJECT_CONTROLLER_H