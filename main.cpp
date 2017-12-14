#include <iostream>
#include "Glutton.h"
#include <vector>
#include <algorithm>

/*
 * Write a program that asks the user to enter the number of pancakes eaten for breakfast by 10 different people
 * (Person 1, Person 2, ..., Person 10)
 * Once the data has been entered the program must analyze the data and output which person ate the most pancakes for breakfast.
 */


bool myComparator(Glutton a, Glutton b){ return (a.getPancakesEaten()<b.getPancakesEaten());}
int main() {
    std::vector<Glutton> _gluttons;
    for (int i = 0; i < 3; ++i) {
        std::string name;
        int pancakesEaten;
        std::cout << "Enter your name:" << std::endl;
        std::cin >> name;
        std::cout << "How Many Pancakes:" << std::endl;
        std::cin >> pancakesEaten;
        _gluttons.push_back(Glutton(i+1,name,pancakesEaten));
    }



    //Iterating over vector
    std::vector<Glutton>::iterator itBigGlutton = _gluttons.begin();
    std::vector<Glutton>::iterator itSmallGlutton = _gluttons.begin();
    for(std::vector<Glutton>::iterator it = _gluttons.begin(); it != _gluttons.end(); ++it) {
        //Checking if has eaten more than previous stored
        if(it.operator*().getPancakesEaten()>itBigGlutton.operator*().getPancakesEaten()){
            itBigGlutton = it;
        }

        //Checking who eat less pancakes
        if(it.operator*().getPancakesEaten()<itSmallGlutton.operator*().getPancakesEaten()){
            itSmallGlutton = it;
        }
    }

    //Printing the biggest Glutton Info
    std::cout << "\n\n##### Biggest Glutton #####" << std::endl;
    std::cout << "Position: " <<itBigGlutton.operator*().getPosition() << std::endl;
    std::cout << "Name: " <<itBigGlutton.operator*().getName() << std::endl;
    std::cout << "Pancakes: " <<itBigGlutton.operator*().getPancakesEaten() << std::endl;
    std::cout << "###########################" << std::endl;

    //Printing the least Glutton Info
    std::cout << "\n\n##### Smallest Glutton #####" << std::endl;
    std::cout << "Position: " <<itSmallGlutton.operator*().getPosition() << std::endl;
    std::cout << "Name: " <<itSmallGlutton.operator*().getName() << std::endl;
    std::cout << "Pancakes: " <<itSmallGlutton.operator*().getPancakesEaten() << std::endl;
    std::cout << "###########################" << std::endl;

    //Printing ordered list
    std::sort(_gluttons.begin(), _gluttons.end(), myComparator);
    std::cout << "\n\n##### Ordered Gluttons #####" << std::endl;
    for(std::vector<Glutton>::iterator it = _gluttons.begin(); it != _gluttons.end(); ++it) {
        std::cout << "Glutton " <<it.operator*().getName()
                  << " at Position " << it.operator*().getPosition()
                  << " ate " << it.operator*().getPancakesEaten()
                  << " pancakes." << std::endl;
    }

    return 0;
}