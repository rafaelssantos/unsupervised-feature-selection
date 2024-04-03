#include "measure.hpp"

#include <cmath>

using namespace std;





float Measure::mean(const vector<float> &variable) {
    float sum = 0.0f;

    for(auto v = variable.begin(); v != variable.end(); v++){
        sum = sum + *v;
    }

    return sum / variable.size();
}





float Measure::variance(const vector<float> &variable) {
    float mean;
    float sumOfSquares = 0.0f;

    mean = Measure::mean(variable);

    for (auto v = variable.begin(); v != variable.end(); v++){
        sumOfSquares = sumOfSquares + (*v - mean) * (*v - mean);
    }

    return sumOfSquares / variable.size();
}





float Measure::covariance(const vector<float> &variable1, const vector<float> &variable2) {
    float mean1, mean2;
    float sumOfProds = 0.0f;

    mean1 = Measure::mean(variable1);
    mean2 = Measure::mean(variable2);

    for(int i = 0; i < variable1.size(); i++){
        sumOfProds = sumOfProds + (variable1[i] - mean1) * (variable2[i] - mean2);
    }
    
    return sumOfProds / variable1.size();
}





float Measure::correlation(const vector<float> &variable1, const vector<float> &variable2) {
    float covar, var1, var2;

    covar = Measure::covariance(variable1, variable2);
    var1 = Measure::variance(variable1);
    var2 = Measure::variance(variable2);

    return covar / sqrtf(var1 * var2);
}





float Measure::leastSquares(const std::vector<float> &variable1, const std::vector<float> &variable2) {
    float var2, corr;

    var2 = Measure::variance(variable2);
    corr = Measure::correlation(variable1, variable2);
    
    return var2 * (1 - corr * corr);
}




float Measure::maximalInfo(const std::vector<float> &variable1, const std::vector<float> &variable2){
    float var1, var2, corr;
    
    var1 = Measure::variance(variable1);
    var2 = Measure::variance(variable2);
    corr = Measure::correlation(variable1, variable2);

    return (var1 + var2 - sqrtf(powf((var1 + var2), 2.0f)- 4.0f * var1 * var2 * (powf((1 - corr), 2.0f)))) / 2.0f;
}
