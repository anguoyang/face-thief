/// \file
/// \brief Header file for class PCARec
/// \author Michał Orynicz
#include "Rec.hpp"

#ifndef PCA_REC_HPP
#define PCA_REC_HPP



///\brief Class providing object recognition based on PCA and 
///Mahalanobis distance
class PCARec:public Rec{
  cv::Mat _data; ///< Matrix containing pictures from loaded galleries
  std::list<int> _labelNr; ///< list of numeric labels of pictures
  cv::Mat _icovar; ///< inverted autocovariance matrix
  cv::PCA _pca; ///< object containing PCA
  cv::Mat _vectors; ///< matrix containing pictures projected to PCA space

  ///\cond
  // Constants for reading and loading object from files
  static std::string DATA;
  static std::string DATA_ROWS;
  static std::string DATA_COLS;
  static std::string DATA_TYPE;

  static std::string VECTORS;
  static std::string ICOVAR;
  static std::string VEC_ROWS;
  static std::string VEC_COLS;
  static std::string VEC_TYPE;

  static std::string LABEL_NR;

  static std::string EIGENVALUES;
  static std::string EIGENVECTORS;
  static std::string EIGEN_ROWS;
  static std::string EIGEN_COLS;
  static std::string EIGEN_TYPE;

  static std::string MEAN;
  static std::string MEAN_COLS;
  static std::string MEAN_TYPE;
  ///\endcond  

public:
  PCARec(); ///< Constructor 
  virtual void loadGalleries(Galleries& galleries);
  virtual void loadPrecomputedGalleries(const std::string& target);
  virtual void savePrecomputedGalleries(const std::string& target);
  virtual void compute();
  virtual void clear();
  virtual std::list<Result> recognise(const std::string& target);
  virtual std::list<Result> recognise(cv::Mat& img);
  virtual ~PCARec();
};

#endif 
  
