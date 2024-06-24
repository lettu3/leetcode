#include <iostream>
#include <vector>

using namespace std;

bool check (vector<int> set, int candidate, int target){
    int length = set.size();
    bool result = true;

    for (unsigned int i = 0u; i < length; i++){
        result = result && (((set[i] + candidate) % target != 0) && set[i] != candidate);
    }

    return result;
}


int solution (vector<int> nums, int target){
    int length = nums.size();
    int max = 0;

    for (unsigned int i = 0u; i < length; i++){
        int current = 0;
        int candidate = nums[i];
        vector<int> candidate_subset;
        candidate_subset.push_back(candidate);

        for (unsigned int j = 0u; j < length; j++){
            //check if it's sum is valid for each element of the current subset
            bool is_valid = check(candidate_subset, nums[j], target);
            if (is_valid){
                candidate_subset.push_back(nums[j]);
            }
        }

        current = candidate_subset.size();

        cout<< "{";
        for (unsigned int i = 0u; i < current; i++){
            cout << candidate_subset[i] << ", ";
        }
        cout<< "}" << endl;
        
        candidate_subset.clear();
        
        //update max for every candidate subset
        if (current > max){
            max = current;
        }
    }    
    return max;
}


int main (int argc, char ** argv){
    vector<int> example1 = {1, 7, 2, 4};
    vector<int> example2 = {1};
    int target = 3;

    int solution1 = solution(example1, target);
    int solution2 = solution(example2, target);

    cout << "The length of the maximum subset in example 1 is: " << solution1 << endl;
    cout << "The length of the maximum subset in example 2 is: " << solution2 << endl;
    
    return 0;
}
