#include <iostream>
#include <vector>
#include <random>
#include <unordered_map>
#include <ctime>

class RandomizedSet{
    public:
        RandomizedSet(){
            std::srand(std::time(0));

        }

        bool insert(int val){
            if(valToIndex.count(val)){
                return false;
            }
            values.push_back(val);
            valToIndex[val] = values.size()-1;
            return true;

        }

        bool remove(int val){
            if(valToIndex.count(val) == 0){
                return false;
            }
            int index = valToIndex[val];
            valToIndex[values.back()] = index;
            values[index] = values.back();
            values.pop_back();
            valToIndex.erase(val);
            return true;

        }

        int getRandom(){
            return values[std::rand()%values.size()];

        }

    private:
        std::vector<int> values;
        std::unordered_map<int,int> valToIndex;

};


int main(){



    return 0;
}