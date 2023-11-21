#ifndef ZOMBIECONTROLLER_H
#define ZOMBIECONTROLLER_H

#include "controller.h"

class zombieController: public Controller
{
public:
    zombieController();
    ~zombieController() override = default;
    char move() override;
};

#endif // ZOMBIECONTROLLER_H
