#ifndef UFS_HPP
#define UFS_HPP


#include <list>
#include <string>
#include <map>
#include "feature.hpp"
#include "measure.hpp"


    /**
     * This class implements the Unsupervised Feature Selection Using Similarity Feature algorithm proposed by by Mitra, Murthy and Pal (2002).
     * The paper can be accessed through the following link: https://ieeexplore.ieee.org/document/990133.
    */
    class UFS{
        public:
            /**
             * This method create a UFS2 object. 
             * @return UFS2 object.
            */
            UFS();
            /**
             * Destructor of UFS2 object.
            */
            virtual ~UFS();

            /**
             * This method rank the features a similarity measure.
             * @param features Features data.
             * @param featureN1 First feature (#1).
             * @param flag Similarity measure ['Pearson Correlation Coefficient' = 0, 'Least Squares Regression Error' or 'Maximal Information Compression Index']. 'Pearson Correlation Coefficient' is Default.
             * @return Feature ranking in a list.
            */
            std::list<std::string> rank(const std::map<std::string, Feature> &features, std::string featureN1="", MeasureFlag flag=MeasureFlag::Default) const;
        
        protected:
            /**
             * This method calculates de similarity between two random variables using a similarity measure.
             * @param f1 First feature.
             * @param f2 Second feature.
             * @param flag Similarity measure ['Pearson Correlation Coefficient' = 0, 'Least Squares Regression Error' or 'Maximal Information Compression Index']. 'Pearson Correlation Coefficient' is Default.
             * @return Similarity value.
            */
            virtual float calcSimilarity(const Feature &f1, const Feature &var2, MeasureFlag flag=MeasureFlag::Default) const;
    };


#endif // UFS_HPP
