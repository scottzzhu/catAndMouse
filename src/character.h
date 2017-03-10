#ifndef CHARACTER_H
#define CHARACTER_H

#include <SFML/Graphics.hpp>
#include <utility>
#include <vector>
#include <typeinfo>

#include "chest.h"
#include "entity.h"
#include "interactable.h"


class Human:public entity{
 private:
 	sf::Vector2i position;
 	sf::Sprite sprite_original;
 	int speed;
 	int sight;
       
 public:
    int movementSpeed = 4 ;
    int attackDamage = 5;
    int counterWalking = 0;
    int direction = 0;
    int counter = 0;
    int hp = 5;
    bool alive = true;
    
    // update the position of the sprite
    void update();
    //void updateMovement();
        
    Human(sf::Vector2i initPos, int v, int s);
    
    // get the sprite
    sf::Sprite& getSprite();
    
    // get the coordinate of the character
    sf::Vector2i getCoor();
    
    // get the speed
    int getSpeed();
    
    // get the sight
    int getSight();
    
    // get current position of the sprite
    sf::Vector2f getPos();
    
    // set the coordinate of character
    void setCoor(sf::Vector2i coor);
    
    // set the speed
    void setSpeed(int v);
    
    // set the sight
    void setSight(int s);

	//make the coordinate of character match with position of sprite
    void updateCoor();

    // move in dir direction
	void walk(int dir);
    
    // set a new position (relative to the map)
	void setPos(const sf::Vector2f& pos);
	
	//get the distance between the interactables and the player
    int distanceToInteractable(interactable* item);  	
	
	//Inspect the interactables that is closest to the player , which will gives a message about it
	void inspect(std::vector<interactable*> itemsList); 
	
	//React with the interactables that is closest to the player
	void react(std::vector<interactable*> itemsList); 
	
    
};
#endif
