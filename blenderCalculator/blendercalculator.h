#include <string>
#include <map>

#ifndef RECIPE_BOOK
    #include "recipebook.h"
#endif

#ifndef CALCULATOR
    #define CALCULATOR
#endif

class BlenderCalculator {
    public:
        // Methods
        BlenderCalculator();
        std::map<std::string, long long> calculate(const std::map<std::string, int> *const input, std::map<std::string, long long> *const inventory = NULL);
        void addToExclusions(std::string itemName);
        void removeFromExclusions(std::string itemName);
        bool checkExclusions(std::string itemName);
    private:
        // Members
        RecipeBook recipeBook;
        std::map<std::string, bool> exclusions;

        // Methods
        void calculate(const std::map<std::string, int> *const input, std::map<std::string, long long> *const inventory,
            std::map<std::string, long long> *const output, const long long inputMultiplier = 1);
};
