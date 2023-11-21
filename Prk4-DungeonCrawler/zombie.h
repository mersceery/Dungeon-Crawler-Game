#ifndef ZOMBIE_H
#define ZOMBIE_H

#include "character.h"
#include "zombiecontroller.h"

class Zombie: public Character
{
public:
    Zombie(int, int);
    ~Zombie() override;
    string getTexture() const override;
    char move(Level *level) override;
private:
    zombieController* zombieController;
};

#endif // ZOMBIE_H
