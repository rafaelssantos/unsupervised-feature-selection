#include "featureio.hpp"

#include <fstream>
#include <string>
#include <list>
#include "stringutils.h"

using namespace std;





FeatureIO::FeatureIO() {

}


FeatureIO::~FeatureIO() {
}




map<string, Feature>* FeatureIO::read(string filePath) const{
    ifstream file;

    file.open(filePath, ios::binary | ios::in);

    int n;
    int headerSize;

    file.read(reinterpret_cast<char*>(&n), sizeof(int));
    file.read(reinterpret_cast<char*>(&headerSize), sizeof(int));

    char headerChar[headerSize];
    file.read(&headerChar[0], headerSize);
    string header(headerChar);

    map<string, Feature>*features = new map<string, Feature>();

    vector<string> names = StringUtils::split(header, ",");

    for(int i = 0; i < names.size(); i++){
        Feature feature;
        vector<float> values;
        
        feature.setName(names[i]);

        for(int j = 0; j < n; j++){
            float value;
            file.read(reinterpret_cast<char*>(&value), sizeof(float));
            values.emplace_back(value);
        }
        feature.setValues(values);
        features->insert(make_pair(names[i], feature));
    }
    file.close();

    return features;
}


void FeatureIO::writeRanking(const list<string> &ranking, string info, string filePath) const {
    ofstream file;

    file.open(filePath, ios::out);

    file << fixed;
    file << info << "\n";
    int i = 1;
    for (auto f = ranking.begin(); f != ranking.end(); f++) {
        file << "\t" << i << ".\t" << *f << "\n"; 
        i++;
    }
    file.close();
}

void FeatureIO::writeSimilarity(const SimilarityMat &mat, string info, string filePath) const {
    ofstream file;

    file.open(filePath, ios::out);
    
    file << fixed;
    file << info << ",";
    for(auto f = mat.getIndexes().begin(); f != mat.getIndexes().end(); f++){
        f++;
        if(f != mat.getIndexes().end()){
            f--;
            file << f->first << ",";
        }
        else{
            f--;
            file << f->first << "\n";
        }
    }
    
    for(auto f1 = mat.getIndexes().begin(); f1 != mat.getIndexes().end(); f1++){
        file << f1->first;
        for(auto f2 = mat.getIndexes().begin(); f2 != mat.getIndexes().end(); f2++){
            file << "," << mat.getValue(f1->first, f2->first);
        }
        file << "\n";
    }

    file.close();
}