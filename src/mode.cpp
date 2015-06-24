#include <Rcpp.h>
using namespace Rcpp;

//' @title Simple function calculating mode.
//' @description This function, given the input integer vector, calculates mode - the most 
//' frequently occurring value. If the mode is ambiguous it returns last one.
//'
//' @param integer vector
//' @return mode - single integer number -  the mode
//'
//' @export
//[[Rcpp::export]]
int mode(IntegerVector x) {
   int n = x.size();
   IntegerVector count(n);
   for (int i=0; i<n; i++){
      for (int j=0; j<n; j++){
         if (x[i]==x[j]){
            count[i] += 1;
         }
      }
   }
   int mode = 0;
   int max_count = 1;
   for (int i=0; i<n; i++){
      if(max_count<=count[i]){
         max_count = count[i];
         mode = x[i];
      }
   }
   return mode;
}