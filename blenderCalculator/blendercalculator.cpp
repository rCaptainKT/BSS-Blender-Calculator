#include <string>
#include <map>
#include <vector>

#include "blendercalculator.h"
#ifndef RECIPE_BOOK
    #include "recipebook.h"
#endif

BlenderCalculator::BlenderCalculator() {}

std::map<std::string, long long> BlenderCalculator::calculate(const std::map<std::string, int> *const input, std::map<std::string, long long> *const inventory) {
    std::map<std::string, long long> output;
    calculate(input, inventory, &output);
    return output;
}

void BlenderCalculator::calculate(const std::map<std::string, int> *const input, std::map<std::string, long long> *const inventory,
    std::map<std::string, long long> *const output, const long long inputMultiplier) {
    for (std::map<std::string, int>::const_iterator itr = input->begin(); itr != input->end(); itr++) {
        std::map<std::string, int> *recipe = recipeBook.getRecipe(itr->first);
        
        long long quantity = itr->second;
        /*if (inventory && inventory->find(itr->first) != inventory->end() && inventory->at(itr->first) != 0) {
            long long min = std::min(inventory->at(itr->first), quantity);
            (*inventory)[itr->first] -= min;
            quantity -= min;
        }*/
        
        if (recipe != NULL && !exclusions[itr->first]) {
            calculate(recipe, inventory, output, inputMultiplier * quantity);
        }else {
            if (output->find(itr->first) != output->end()) {
                (*output)[itr->first] += inputMultiplier * quantity;
            }else {
                (*output)[itr->first] = inputMultiplier * quantity;
            }
        }
    }
}

void BlenderCalculator::addToExclusions(std::string itemName) {
    exclusions[itemName] = true;
}

void BlenderCalculator::removeFromExclusions(std::string itemName) {
    exclusions[itemName] = false;
}

bool BlenderCalculator::checkExclusions(std::string itemName) {
    return exclusions[itemName];
}
