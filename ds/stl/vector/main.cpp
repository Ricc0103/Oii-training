#include <bits/stdc++.h>

//vector lesson, 31/10/2023 16:57
//Made by Riccardo

int main(){
  /* //Declaration and inizialization

    //Empty vector
    std::vector<int> v;
    //Vector with n elements
    int n = 4;
    std::vector<int> v(n);
    //Vector with n elements filled with value k
    int k = 6;
    std::vector<int> v(n, k);
    //or
    std::vector<int> v(n);
    fill(v.begin(), v.end(), k);

    //Like an array
    std::vector<int> v{3, 4, 2, 8};
    //From an array
    int ar[5] = {3, 4, 2, 8, 19};
    int n = sizeof(ar) / sizeof(ar[0]); //ar.size() is the same
    std::vector<int> v(ar, ar + n);
    //From another vector
    std::vector<int> a{ 10, 2, 3};
    std::vector<int> v(a.begin(), a.end()); */

  //Functions
    std::vector<std::vector<std::vector<std::vector<long long>>>> v(1, std::vector<std::vector<std::vector<long long>>> (1, std::vector<std::vector<long long>>(1, std::vector<long long>(1,0))));
    std::cout<<v.max_size()<<std::endl;
  return 0;
}