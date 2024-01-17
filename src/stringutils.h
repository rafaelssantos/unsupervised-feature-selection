#include <string>
#include <vector>


/**
 * This class implements string utility functions.
*/
class StringUtils{
    public:
        static std::vector<std::string> split(std::string original, std::string delimiter = " "){
            std::vector<std::string> parts;
            int pos = 0;

            while(pos < original.size()){
                pos = original.find(delimiter);
                parts.push_back(original.substr(0, pos));
                original.erase(0, pos + delimiter.size());
            }
            parts.push_back(original);
            return parts;
        }
};