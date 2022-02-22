#include "colour.h"
#include <math.h>

Colour::Colour(){
    this->mR = 0.3 * ((rand() % 3) + 1);
    this->mG = 0.3 * ((rand() % 3) + 1);
    this->mB = 0.3 * ((rand() % 3) + 1);
};

Colour::Colour(float inR, float inG, float inB) {
    this->mR = inR;
    this->mG = inG;
    this->mB = inB;
}

void Colour::setColour(float r, float g, float b) {
    this->mR = r;
    this->mG = g;
    this->mB = b;
}
    
bool Colour::isColour(Colour other){
    return (this->mR == other.mR && this->mG == other.mG && this->mB == other.mB);
}