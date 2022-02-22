#ifndef COLOUR_H
#define COLOUR_H

class Colour {
public:
    Colour();
    Colour(float r, float g, float b);
    float mR;
    float mG;
    float mB;

    void setColour(float r, float g, float b);
    bool isColour(Colour other);
};

#endif