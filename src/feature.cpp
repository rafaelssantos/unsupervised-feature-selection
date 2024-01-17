#include "feature.hpp"
#include <iostream>

using namespace std;



Feature::Feature() {

}



Feature::Feature(string name) {
    name = name;
}




Feature::~Feature() {
    m_name = "";
}

const vector<float>& Feature::getValues() const {
    return m_values;
}

void Feature::setValues(const std::vector<float> &values) {
    m_values = values;
}


string Feature::getName() const {
    return m_name;
}


void Feature::setName(const std::string &name){
    m_name = name;
}