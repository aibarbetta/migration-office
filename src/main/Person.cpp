#include "Person.h"

Person::Person(std::list<Feature*> features) : features(features) {}

std::list<Feature*> Person::getFeatures() {
    return features;
}

Person::~Person() {
    while (!features.empty()) {
        delete features.back();
        features.pop_back();
    }
}