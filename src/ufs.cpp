#include "ufs.hpp"

#include <cmath>

using namespace std;





UFS::UFS() {
}

UFS::~UFS() {
}


list<string> UFS::rank(const map<string, Feature> &features, string featureN1, MeasureFlag flag) const
{
    list<string> selected;
    list<string> nonSelected;

    if(featureN1 == ""){
        selected.emplace_back((*features.begin()).first);
    }
    else{
        selected.emplace_back(featureN1);
    }
    for(auto it = features.begin(); it != features.end(); it++){
        if((*it).first != selected.front()){
            nonSelected.emplace_back((*it).first);
        }
    }

    while (nonSelected.size() > 0){
        float min = this->calcSimilarity(features.at(selected.front()), features.at(nonSelected.front()), flag);
        string key = nonSelected.front();

        for(auto k = nonSelected.begin(); k != nonSelected.end(); k++){
            for (auto i = selected.begin(); i != selected.end(); i++){
                float similarity = this->calcSimilarity(features.at(*i), features.at(*k), flag);
                if(similarity < min){
                    min = similarity;
                    key = *k;
                }
            }
        }
        selected.emplace_back(key);
        nonSelected.remove(key);
    }

    return selected;
}



float UFS::calcSimilarity(const Feature &f1, const Feature &f2, MeasureFlag flag) const {
    float similarity;

    
    if(flag == MeasureFlag::LeastSquares){
        similarity = Measure::leastSquares(f1.getValues(), f2.getValues());
    }
    else if (flag == MeasureFlag::MaximalInformation){
        similarity = Measure::maximalInfo(f1.getValues(), f2.getValues());
    }
    else {
        similarity = Measure::correlation(f1.getValues(), f2.getValues());
    }
    
    return fabsf(similarity);
}
