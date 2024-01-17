#ifndef FEATUREMEASURE_HPP
#define FEATUREMEASURE_HPP


#include <vector>

enum MeasureFlag {
    Default = 0, 
    Pearson = 0, 
    LeastSquares = 1, 
    MaximalInformation = 2
};



/**
 * This class implements statistical and similarity measures.
*/
class Measure {
public:
    /**
     * This method calculates the mean of a random variable.
     * @param var random variable.
     * @return Mean value.
    */
    static float mean(const std::vector<float>& variable);
    /**
     * This method calculates the variance of a random variable.
     * @param variable random variable.
     * @return Variance value.
    */
    static float variance(const std::vector<float>& variable);
    /**
     * This method calculates the covariance between two random variables.
     * @param variable1 Fist random variable.
     * @param variable2 Second random variable.
     * @return Covariance value.
    */
    static float covariance(const std::vector<float>& variable1, const std::vector<float>& variable2);
    /**
     * This method calculates the Pearson correlation coefficient between two random variables.
     * @param variable1 Fist random variable.
     * @param variable2 Second random variable.
     * @return Pearson correlation coefficient value.
    */
    static float correlation(const std::vector<float>& variable1, const std::vector<float>& variable2);
    /**
     * This method calculates the Least Square Regression Error between two random variables.
     * @param variable1 Fist random variable.
     * @param variable2 Second random variable.
     * @return Least Square Regression Error value.
    */
    static float leastSquares(const std::vector<float>& variable1, const std::vector<float>& variable2);
    /**
     * This method calculates the Maximal Information Compression Index between two random variables.
     * @param variable1 Fist random variable.
     * @param variable2 Second random variable.
     * @return Maximal Information Compression Index value.
    */
    static float maximalInfo(const std::vector<float>& variable1, const std::vector<float>& variable2);
};

#endif // FEATUREMEASURE_HPP
