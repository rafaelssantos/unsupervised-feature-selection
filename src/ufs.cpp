#include "ufs.hpp"

#include <cmath>

using namespace std;





UFS::UFS() {
}

UFS::~UFS() {
}


list<string> UFS::rank(const map<string, Feature> &features, const SimilarityMat &mat, string featureN1) const
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
        float min = mat.getValue(selected.front(), nonSelected.front());
        string key = nonSelected.front();

        for(auto k = nonSelected.begin(); k != nonSelected.end(); k++){
            for (auto i = selected.begin(); i != selected.end(); i++){
                float similarity = mat.getValue(features.at(*i).getName(), features.at(*k).getName());
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
