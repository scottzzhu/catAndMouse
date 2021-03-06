//
//  bigMap.cpp
//  F48
//
//  Created by James wang on 2/18/17.
//  Copyright © 2017 James wang. All rights reserved.
//

#include "bigMap.h"
#include <iostream>



bigMap::bigMap(int sz) {
	size=sz;
    Map = new grid*[size];
    for (int i = 0; i < size; i++)
        Map[i] = new grid[size];
    isDetected = new int*[size];
    for (int i = 0; i < size; i++)
        isDetected[i] = new int[size];
}
int bigMap::getSize() { return size; }
sf::Drawable& bigMap::getSprite() { return background; }
sf::Drawable& bigMap::getShade(int x, int y) { return Map[x][y].getShade(); }
bool bigMap:: getWall(int x, int y) {
    //        std::cout << x << ' ' << y << std::endl;
    if (x < 0 || y < 0)return 1;
    if (x >= size || y >= size)return 1;
    return Map[x][y].getWall();
}
void bigMap::load(sf::Image &image) {
    //        background.setTexture(texture);
    //        background.setTextureRect(sf::IntRect(0, 0, 15*80, 15*80));
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            isDetected[i][j] = 0;
            Map[i][j].getShade().setPosition(80 * (i) -1, 80 * (j) +1);
            
            //				std::cout << int(image.getPixel(i * 80, j * 80).r) << ' ' << int(image.getPixel(i * 80, j * 80).g) << ' ' << int(image.getPixel(i * 80, j * 80).b) << endl;
            if (image.getPixel(i * 80+1, j * 80+1) == sf::Color(99, 64, 0, 255))
                Map[i][j].setWall(1);
            else Map[i][j].setWall(0);
            //std::cout << i << ' ' << j << ' ' << Map[i][j].getWall() << std::endl;
            isDetected[i][j] = 0;
            Map[i][j].setShade(isDetected[i][j]);
        }
    }
}
void bigMap:: updateShade(sf::Vector2i pos, int sight) {
   for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            //                std::cout << i << ' ' << j << " " << isDetected[i][j] << std::endl;
            if (isDetected[i][j] == 2) {
                isDetected[i][j] = 1;
            }
        }
    }
    isDetected[pos.x][pos.y] = 2;
    for (int i = 0; i <= sight; i++) {
        for (int j = 0; j <= sight; j++) {
            if ((pos.x + i) < 0 || (pos.x + i) >= size || (pos.y + j) < 0 || (pos.y + j) >= size);
            else if (isDetected[pos.x + i][pos.y + j] == 2) isDetected[pos.x + i][pos.y + j] = 2;
            else if (checkVisible(0,i,j,sight)){
            //    std::cout<<"lr"<<std::endl;
                isDetected[pos.x + i][pos.y + j] = 2;
			}
            if ((pos.x + i) < 0 || (pos.x + i) >= size || (pos.y - j) < 0 || (pos.y - j) >= size);
            else if (isDetected[pos.x + i][pos.y - j] == 2) isDetected[pos.x + i][pos.y - j] = 2;
            else if (checkVisible(1,i,j,sight)){
            //    std::cout<<"ur"<<std::endl;
                isDetected[pos.x + i][pos.y - j] = 2;
	        }
            if ((pos.x - i) < 0 || (pos.x - i) >= size || (pos.y + j) < 0 || (pos.y + j) >= size);
            else if (isDetected[pos.x - i][pos.y + j] == 2) isDetected[pos.x - i][pos.y + j] = 2;
            else if (checkVisible(2,i,j,sight)){
            //    std::cout<<"ll"<<std::endl;
                isDetected[pos.x - i][pos.y + j] = 2;
            }
            
            if ((pos.x - i) < 0 || (pos.x - i) >= size || (pos.y - j) < 0 || (pos.y - j) >= size);
            else if (isDetected[pos.x - i][pos.y - j] == 2) isDetected[pos.x - i][pos.y - j] = 2;
            else if (checkVisible(3,i,j,sight)){
            //    std::cout<<"ul"<<std::endl;
                isDetected[pos.x - i][pos.y - j] = 2;
			}
        }
    }
    for (int i = 0; i < size; i++)
        for (int j = 0; j < size; j++) {
            Map[i][j].setShade(isDetected[i][j]);
        }
}

int bigMap::getDetect(int x,int y){
	return isDetected[x][y];
}

bool bigMap::checkVisible(int a,int i,int j,int sight){
	bool ans=((i*i + j*j) <= sight*sight + sight);
	switch(a){
		case 0:
			return ans;
			break;
		case 1:
			return ans;
			break;
		case 2:
			return ans;
			break;
		case 3:
			return ans;
			break;
		default:
			return false;
			break;
	}
}

