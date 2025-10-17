//
// Created by Abid Rey Magsambol on 10/16/25.
//

#ifndef FINALPROJECT_JOYSTICK_H
#define FINALPROJECT_JOYSTICK_H

class Joystick {
private:
    double x=0;
    double y=0;
public:
    Joystick();
    void move(double x, double y);
    double getX() const;
    double getY() const;
    void setX(double newX);
    void setY(double newY);
    ~Joystick();
};

#endif //FINALPROJECT_JOYSTICK_H