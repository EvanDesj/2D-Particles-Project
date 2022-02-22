#include <math.h>
#include "mathLib2D.h"

Point2D::Point2D(){};

Point2D::Point2D(float inX, float inY) {
    this->mX = inX;
    this->mY = inY;
}

float Point2D::distanceTo(Point2D other) {
    return sqrt(pow(other.mX - this->mX, 2) + pow(other.mY - this->mY, 2));
}

float Point2D::fastDistanceTo(Point2D other) {
    return (pow(other.mX - this->mX, 2) + pow(other.mY - this->mY, 2));
}

Vec2D::Vec2D(){};

Vec2D::Vec2D(float inX, float inY) {
    this->mX = inX;
    this->mY = inY;
}

float Vec2D::length() {
    return abs(sqrt(pow(this->mX, 2) + pow(this->mY, 2)));
}

Vec2D Vec2D::normalize() {
    float x = this->mX / this->length();
    float y = this->mY / this->length();
    Vec2D ans = Vec2D(x, y);
    return ans;
}

Vec2D Vec2D::multiply(float scalar) {
    float x = this->mX * scalar;
    float y = this->mY * scalar;
    Vec2D ans = Vec2D(x, y);
    return ans;
}

Point2D Vec2D::movePoint(Point2D source) {
    float x = this->mX + source.mX;
    float y = this->mY + source.mY;
    Point2D ans = Point2D(x, y);
    return ans;
}

void Vec2D::reverse() {
    this->mX = -mX;
    this->mY = -mY;
}

Vec2D Vec2D::createVector(Point2D p1, Point2D p2) {
    float x = p2.mX - p1.mX;
    float y = p2.mY - p1.mY;
    Vec2D ans = Vec2D(x, y);
    return ans;
}