#include "similaritymat.hpp"

#include "measure.hpp"
#include "cmath"

using namespace std;



SimilarityMat::SimilarityMat() {

}


SimilarityMat::~SimilarityMat() {
}

void SimilarityMat::build(const map<string, Feature> &features, MeasureFlag flag) {
    int index = 0;
    for (auto f = features.begin(); f != features.end(); f++){
        m_indexes[f->first] = index;
        index++;
    }

    m_data = new float[features.size() * features.size()];

    for (auto f1 = features.begin(); f1 != features.end(); f1++){
        for(auto f2 = features.begin(); f2 != features.end(); f2++){
            float value;
            if(f1->first != f2->first){
                if(flag == MeasureFlag::LeastSquares){
                    value = Measure::leastSquares(features.at(f1->first).getValues(), features.at(f2->first).getValues());
                }
                else if(flag == MeasureFlag::MaximalInformation){
                    value = Measure::maximalInfo(features.at(f1->first).getValues(), features.at(f2->first).getValues());
                }
                else{
                    value = Measure::correlation(features.at(f1->first).getValues(), features.at(f2->first).getValues());
                }
            }
            else{
                value = 1.0f;
            }
            *(m_data + m_indexes[f2->first] * m_indexes.size()  + m_indexes[f1->first]) = value;
        }
    }    
}



float SimilarityMat::getValue(std::string f1, std::string f2) const {
    return *(m_data + m_indexes.at(f2) * m_indexes.size()  + m_indexes.at(f1));
}



const std::map<std::string, int> &SimilarityMat::getIndexes() const {
    return m_indexes;
}
