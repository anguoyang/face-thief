#include <vector>
#include <string>
#include <vector>
#include "opencv2/core/core.hpp"

#ifndef __GALLERIES__
#define __GALLERIES__

using std::string;

const string GALLERIES="GALLERIES";                                             
const string LABEL="LABEL";                                                   
const string COUNTER="COUNTER";
const string ADDRESS="ADDRESS"; 
const string SIZE="SIZE";
const string WIDTH="WIDTH";
const string HEIGHT="HEIGHT";
const string TYPE="TYPE";

const int INCORRECT_GALLERY_NUMBER=1;
const int INCORRECT_PHOTO_NUMBER=2;
const int LABEL_NOT_FOUND=3;
const int CANNOT_OPEN_FILE=4;
const int NO_PATH_DECLARED=5;
const int NO_SUCH_DIRECTORY=6;
const int NON_UNIFORM_GALLERY=7;
const int WRONG_PICTURE_SIZE=8;
const int WRONG_PICTURE_TYPE=9;

const int INITIAL_SIZE=-2;

class Galleries{
  struct Gallery{
    string label;
    int counter;
    std::vector<string> photos;
  };
  cv::Size _picSize;
  int _picType;
  std::vector<Gallery> _gal;
  std::string _path;
public:
  Galleries(){
    _path.clear();
    _picType=0;
    _picSize.width=INITIAL_SIZE;
    _picSize.height=INITIAL_SIZE;
  }
  Galleries(string path,string filename);
  void load(string filename);
  void save(string filename);
  void add(string label, cv::Mat image);
  int totalSize(){return _gal.size();}
  
  void setPath(string path);

  cv::Mat getPicture(string label, int number);
  cv::Mat getPicture(int galleryNumber, int photoNumber);
  cv::Size getPictureSize(){return _picSize;}
  int getPictureType(){return _picType;}
  int gallerySize(string label);
  int gallerySize(int galleryNumber);
  ~Galleries(){};
};

#endif
  