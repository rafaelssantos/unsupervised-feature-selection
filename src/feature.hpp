#ifndef FEATURE_HPP
#define FEATURE_HPP


#include <string>
#include <vector>


/**
 * This class implements a feature, also known as an attribute, which consists of a name and a random variable represented as a list of values.
*/
class Feature {
public:
    /**
     * This method creates a Feature object.
     * @return Feature object.
    */
    Feature();
    /**
     * This method creates a Feature object.
     * @param name Name of the feature.
    */
    Feature(std::string name);
    /**
     * Destructor of Feature object. 
    */
    virtual ~Feature();
    /**
     * This method returns values of the feature.
     * @return Values.
    */
    const std::vector<float>& getValues() const;
    /**
     * This method set values of the feature.
     * @param values Values.
    */
    void setValues(const std::vector<float> &values);
    /**
     * This method returns the name of the feature.
     * @return name.
    */
    std::string getName() const;
    /**
     * This method set the name of the feature
     * @param name Name.
    */
    void setName(const std::string &name);


private:
    std::vector<float> m_values;
    std::string m_name;
};


#endif // FEATURE_HPP
