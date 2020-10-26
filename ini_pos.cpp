#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <iomanip>
#include <random>

using namespace std;

typedef struct xyz{
   double x;
   double y;
   double z;
} VTEX;


int main() {
   int n;
   int i = 0;
   const double PI = acos(-1);

   std::cout << "Enter the number of particles : n = " ;   //r内に存在する粒子数を入力
   std::cin >> n;

   VTEX p[n];
   VTEX P[n];

   double r_0 = 1.0;
   double M;   //その半径rでの粒子の質量
   double rad;
   double theta;
   double phi;
   double Z;

   double min_M = 0.;
   double max_M = 1.0;
   double min_phi = 0.;
   double max_phi = 2.0 * PI;
   double min_Z = -1.0;
   double max_Z = 1.0;

   std::mt19937 rand_src(12345);
   std::uniform_real_distribution<> rand_M(min_M, max_M);
   std::uniform_real_distribution<> rand_phi(min_phi, max_phi);
   std::uniform_real_distribution<> rand_Z(min_Z, max_Z);

   while( i < n ){   //まず、ランダムMからrを求める
      M = rand_M(rand_src);
      rad = r_0 * pow(M,4.0/5.0) / sqrt(1.0 - pow(M,8.0/5.0));

      phi = rand_phi(rand_src);
      Z = rand_Z(rand_src);     

      P[n].x = rad * sqrt(1 - Z*Z) * cos(phi);
      P[n].y = rad * sqrt(1 - Z*Z) * sin(phi);
      P[n].z = rad * Z;   //Z=cosθ
 
      p[n].x = P[n].x;
      p[n].y = P[n].y;
      p[n].z = P[n].z;

      std::cout << std::fixed;
      std::cout << "1.00" << " " << p[n].x << " " << p[n].y << " " << p[n].z  << " " << rad << " " << sqrt(2.0*1.0/rad) << std::endl;
      i++;
   }

   return 0;
}
