#ifndef UFS_HPP
#define UFS_HPP


#include <list>
#include <string>
#include <map>
#include "feature.hpp"
#include "measure.hpp"
#include "similaritymat.hpp"


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
             * @param mat Similarity mat
             * @param featureN1 First feature (#1).
             * @return Feature ranking in a list.
            */
            std::list<std::string> rank(const std::map<std::string, Feature> &features, const SimilarityMat &mat, std::string featureN1="") const;
    };


#endif // UFS_HPP
