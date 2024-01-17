#include <iostream>
#include <string>

#include "featureio.hpp"
#include "ufs.hpp"

using namespace std;


int main(int argc, char *argv[]) {
    if(argc < 6){
        cout << "NAME\n\tUFS\n\n";
        cout << "DESCRIPTION\n\tThe program executes the Unsupervised Feature Selection using Feature Similarity method proposed by Mitra, Murthy and Pal (2002).\n\n";
        cout << "PARAMETERS\n\tIt requires the following arguments:\n";
        cout << "\t- input feature binary file path\n";
        cout << "\t- output TXT file path. Feature ranking\n";
        cout << "\t- output CSV file path. Similarity Matrix\n";
        cout << "\t- name of first selected feature (#1)\n\n";
        cout << "\t- measure flag [0 is the 'Pearson Correlation Coefficient', 1  is the 'Least Squares Regression Error' or 2 is the 'Maximal Information Compression Index'].\n";
        cout << "EXAMPLE OF USAGE\n\t<executable> [input] [ouput] [0] ['Intensity']\n\n";
    }
    else{
        string input(argv[1]);
        string outputRanking(argv[2]);
        string outputMatrix(argv[3]); 
        string featureN1(argv[4]);
        string strFlag(argv[5]);
        string fileInfo = "";
        MeasureFlag flag;

        switch(atoi(strFlag.c_str())) {
            case 1:
                flag = MeasureFlag::LeastSquares;
                fileInfo = "'Least Squares Regression Error'";
                break;
            case 2:
                flag = MeasureFlag::MaximalInformation;
                fileInfo = "'Maximal Information Compression Index'";
                break;
            default:
                flag = MeasureFlag::Pearson;
                fileInfo = "'Pearson Correlation Coefficient'";
        }



        UFS ufs;
        FeatureIO dataIO;



        list<string> ranking;
        SimilarityMat mat;



        cout << "READING\n";
        cout << "\t" << input << "\n";
        map<string, Feature> *features = dataIO.read(input);

        cout << "RUNNING\n";
        mat.build(*features, flag);
        ranking = ufs.rank(*features, featureN1, flag);
        
        cout << "SAVING SIMILARITY MATRIX\n";
        cout << "\t" << outputMatrix << "\n";
        dataIO.writeSimilarity(mat, fileInfo, outputMatrix);

        cout << "SAVING RANKING\n";
        cout << "\t" << outputRanking << "\n";
        dataIO.writeRanking(ranking, fileInfo, outputRanking);

        delete features;
        features = nullptr;

        cout << "\n...Done!\n";
    }

    return 0;
}
