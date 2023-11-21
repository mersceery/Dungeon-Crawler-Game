#include "zombie.h"
#include "zombiecontroller.h"

Zombie::Zombie(int strength, int stamina):
    Character("Zombie", (zombieController = new ::zombieController()),strength,stamina,false) //same name so use class tag
{
}

Zombie::~Zombie()
{
    delete zombieController;
}

string Zombie::getTexture() const
{
    return "Zombie";
}

char Zombie::move(Level *level)
{
    return moveDirextion = zombieController->move();
}
