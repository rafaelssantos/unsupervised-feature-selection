#ifndef FEATURE_io
#define FEATURE_io

#include <list>
#include <map>
#include <string>
#include "feature.hpp"
#include "similaritymat.hpp"

/**
 * This class serves as a feature file manipulator designed for the ATTR format. An ATTR file, being binary, encompasses the following components: the count of instances (int), the count of resources (int), a list of resource names separated by commas (string), and the corresponding resource data (floats).
*/
class FeatureIO {
public:
    /**
     * This method create a IOFeature object. 
     * @return IOFeature object.
    */
    FeatureIO();
    /**
     * Destructor of IOFeature object.
    */
    virtual ~FeatureIO();
    /**
     * This method reads features from an feature data file format. It is a binary file composed of: number of instances (int), number of resources (int), comma-separated resource names (string) and resource data (floats).
     * @param filePath Input file path.
     * @return Map of read features.
    */
    std::map<std::string, Feature>* read(std::string filePath) const;
    /**
     * This method writes the feature ranking to a TXT file.
     * @param ranking Ranking of features in a list.
     * @param info Text info.
     * @param filePath Output file path.
    */
    void writeRanking(const std::list<std::string> &ranking, std::string info, std::string filePath) const;
    /**
     * This method writes the feature similarity to a CSV file.
     * @param mat Similarity Matrix.
     * @param info Text info.
     * @param filePath Output file path.
    */
    void writeSimilarity(const SimilarityMat &mat, std::string info, std::string filePath) const;
};

#endif // FEATURE_io
