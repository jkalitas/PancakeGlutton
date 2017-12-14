//
// Created by jsilva on 14-12-2017.
//

#include "Glutton.h"


Glutton::Glutton(int position,std::string name,int nPancakesEaten){
    this->_position = position;
    this->_name = name;
    this->_nPancakesEaten = nPancakesEaten;
}

Glutton::~Glutton(){
}

std::string Glutton::getName(){
    return this->_name;
}

int Glutton::getPancakesEaten(){
    return  this->_nPancakesEaten;
}

int Glutton::getPosition(){
    return this->_position;
}