#ifndef SIMILARITY_HPP
#define SIMILARITY_HPP

#include <map>
#include <string>
#include "feature.hpp"
#include "measure.hpp"

class SimilarityMat{
    public:
        SimilarityMat();
        
        virtual ~SimilarityMat();

        void build(const std::map<std::string, Feature>& features, MeasureFlag flag=MeasureFlag::Default);

        float getValue(std::string f1, std::string f2) const;

        const std::map<std::string, int>& getIndexes() const;
    
    private:
        float* m_data;
        std::map<std::string, int> m_indexes;

};

#endif // SIMILARITY_HPP

