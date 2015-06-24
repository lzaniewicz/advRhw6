#include <Rcpp.h>
#include <algorithm>
using namespace Rcpp;

//' @title ASS(ign) survey participants :)
//' @description This function generates all possible 0-1 assignment vectors of 2*n survey participants 
//' in such a way that exactly n of them are assigned to group 0 (control)
//' and the other n ones are assigned to group 1 (treatment). To simplyfy this task I have used  
//' std::next_permutation() - this suggestion I have found on stackoverflow.
//'
//' @param n - integer, number of participants in control or treatment group (both have equal size)
//' @return integer matrix, with all possible 0-1 participants assignments.
//'
//' @rdname ass
//'
//' @export
//[[Rcpp::export]]

int factorial(int n){
  if(n==0 || n==1){
    return(1);
  } else {
    return factorial(n - 1) * n;
  }
}

//' @rdname ass
//'
//' @export
//[[Rcpp::export]]

IntegerMatrix ass(int n){
  int k = 2 * n;
  int nf = factorial(k) / pow(factorial(n), 2);
  IntegerVector y(k);
  IntegerMatrix res(nf, k);
  int cnt = 0;
  for (int i=0; i<n; i++){
    y[i] = 0;
    y[n+i] = 1;     
  }
  do {
    for(int j=0; j<k; j++){
      res(cnt, j) = y[j];
    }
    cnt += 1;
  } while (std::next_permutation(y.begin(), y.end()));
  return res;
}


