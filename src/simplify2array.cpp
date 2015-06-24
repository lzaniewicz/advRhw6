#include <Rcpp.h>
using namespace Rcpp;

//' @title List of vectors ==> Matrix
//' @description This function changes input list of numeric vectors to a matrix. 
//' We assume that vectors have equal length.
//'
//' @param vec_list - list of input numeric vectors
//' @return numeric matrix, where number of rows equals the length of the list and number of columns
//' equal the length of vectors in the list.
//'
//' @export
//[[Rcpp::export]]

NumericMatrix simplify2array(List vec_list) {
  int n = vec_list.size();
  NumericVector vec = vec_list[0];
  int n1 = vec.size();
  
  for (int i=0; i<n; i++){
    vec = vec_list[i];
    if (vec.size() != n1){
      stop("Vectors are not of the same length!");
    }      
  }
  NumericMatrix res(n,n1);
  for (int i=0; i<n; i++){
    vec = vec_list[i];
    for (int j=0; j<n1; j++){
      res(i, j) = vec[j];
    }
  }
  return res;
}
