//
//  attack.h
//  Attack_48
//
//  Created by James wang on 2/10/17.
//  Copyright © 2017 James wang. All rights reserved.
//

#ifndef attack_h
#define attack_h

#include <stdio.h>

#include "entity.h"
#include "character.h"
class projectile: public entity
{
public:
    projectile(); //constructor 
    void updateProjectile(Character& player, sf::View& view, sf::RenderWindow& window);  //update the location and the exiting time of projectile
    int movementSpeed;
    int attackDamage;
    int lifeTime; // preset the existing time of a projectile
    int direction; // 1 - up, 2 - down, 3 - left, 4 - right
    bool destroy; 
    int counterLifetime; //existing time of a projectile
};


#endif /* attack_h */
