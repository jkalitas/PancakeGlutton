//
// Created by jsilva on 14-12-2017.
//

#ifndef PANCAKEGLUTTON_GLUTTON_H

#include <iostream>

#define PANCAKEGLUTTON_GLUTTON_H


class Glutton {
public:
    Glutton(int position,std::string name,int nPancakesEaten);
    ~Glutton();
    std::string getName();
    int getPancakesEaten();
    int getPosition();

private:
    int _position;
    int _nPancakesEaten;
    std::string _name;
};


#endif //PANCAKEGLUTTON_GLUTTON_H
