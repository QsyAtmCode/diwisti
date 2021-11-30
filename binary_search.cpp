#include <iostream>
#include <iterator>
//#include <string>
#include <vector>
//#include "header.h"
#include <random>

#include <cstdlib>
using namespace std;

vector<int> vector_generate(unsigned size = 25, unsigned short min = 0, unsigned short max = 100){
	vector<int> out;
	random_device random_device;
    mt19937 generator(random_device());
    uniform_int_distribution<> distribution(min, max);
	for(unsigned i = 0; i < size; i++){
		int random = distribution(generator);
		out.push_back(random);
	}
	return out;
}

int binary_search(const vector<int> &array, const unsigned &target){
    auto begin = array.begin();
	auto end = array.end();
	auto middle = array.begin() + ((end - begin) / 2);
    while(middle != end && *middle != target){
		if(target < *middle){
			end = middle;
		}else {
			begin = middle + 1;
		}
		middle = begin + (end - begin) / 2;
	}
	return distance(array.begin(), middle) + 1;
}

vector<int> insertion_sort(vector<int> array){
	for (int i = 0; i < array.size() - 1; i++){
      	for (int j = i + 1; j > 0; j--){
           	if (array[j - 1] > array[j]){
                 	int temp = array[j - 1];
                 	array[j - 1] = array[j];
                 	array[j] = temp;
                  }
            }
      }
      return array;
}

int main(){
	vector<int> aa;
	aa = vector_generate();
	cout << aa.size() << endl;
	for(auto i = aa.begin(); i < aa.end(); i++){
		cout << *i << ' ';
	}
	cout << endl;
	aa = insertion_sort(aa);
	for(auto i = aa.begin(); i < aa.end(); i++){
		cout << *i << ' ';
	}
	cout << endl;
	int target = 0;
	cin >> target;
	cout << endl;
	cout << binary_search(aa, target) << endl;;
	return 0;
}
