#include <chrono>
#include <fstream>
#include <iostream>
#include <string>

#include "featureio.hpp"
#include "ufs.hpp"

using namespace std;
using namespace std::chrono;


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
                fileInfo = "Least Squares Regression Error";
                break;
            case 2:
                flag = MeasureFlag::MaximalInformation;
                fileInfo = "Maximal Information Compression Index";
                break;
            default:
                flag = MeasureFlag::Pearson;
                fileInfo = "Pearson Correlation Coefficient";
        }



        UFS ufs;
        FeatureIO featureIO;



        list<string> ranking;
        SimilarityMat mat;



        cout << "READING\n";
        cout << "\t" << input << "\n";
        map<string, Feature> *features = featureIO.read(input);

        cout << "RUNNING\n";
        auto start = high_resolution_clock::now();

        mat.build(*features, flag);
        ranking = ufs.rank(*features, mat, featureN1);

        auto stop = high_resolution_clock::now();
        auto duration = duration_cast<seconds>(stop - start);


        cout << "SAVING SIMILARITY MATRIX\n";
        cout << "\t" << outputMatrix << "\n";
        featureIO.writeSimilarity(mat, fileInfo, outputMatrix);

        cout << "SAVING RANKING\n";
        cout << "\t" << outputRanking << "\n";
        featureIO.writeRanking(ranking, fileInfo, outputRanking);

        delete features;
        features = nullptr;


        ofstream file;
        file.open("runtime.log", ios::app);
        file << input << "\n";
        file << fileInfo << "\n";
        file << "Runtime (in seconds): " << duration.count() << "\n";
        
        file.close();

        cout << "\n...Done!\n";
    }

    return 0;
}
