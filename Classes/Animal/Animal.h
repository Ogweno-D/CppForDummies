//
// Created by Ogweno on 29/07/2025.
//

#ifndef ANIMAL_H
#define ANIMAL_H
using namespace std;

class Animal {
    public:
        // To demonstrate fixed bound arrays!
        char noise [20]{};
        char name [10]{};
        double weight;

        Animal(const char* animalName, const char *animalNoise, double weight);
        void sound();
        void currWeight(double weight);
};

#endif
//ANIMAL_H
