//
// Created by Ogweno on 29/07/2025.
//

#include "Animal.h"

#include <iostream>
#include <ostream>
#include <string.h>

Animal::Animal(const char*animalName, const char* animalNoise, double weight)
{
    //
    size_t name_len = strlen(animalName);
    size_t name_charToCopy= (name_len < sizeof(this->name)-1) ? name_len : sizeof(this->name)-1;
    strncpy(this->name, animalName, name_charToCopy);
    this->name[name_charToCopy] = '\0';

    //
    size_t len = strlen(animalNoise);
    size_t charToCopy = (len < sizeof(this->noise)-1) ? len : sizeof(this->noise)-1;
    strncpy(this->noise, animalNoise, charToCopy);
    this->noise[charToCopy] = '\0';

    this->weight = weight;
}

void Animal::sound()
{
    cout << " This animal " << this->noise << endl;
}
void Animal::currWeight(double weight)
{
    weight = weight * 2.0;
    cout << "Current weight: " << weight << endl;
}