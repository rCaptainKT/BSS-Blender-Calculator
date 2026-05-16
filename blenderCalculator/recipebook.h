#include <map>
#include <vector>

#ifndef RECIPE_BOOK
    #define RECIPE_BOOK
#endif

class RecipeBook {
    public:
        // Methods
        RecipeBook();
        std::map<std::string, int> *getRecipe(const std::string &itemName);
        std::vector<std::string> *getAllItems();
        std::vector<std::string> *getBaseItems();
        std::vector<std::string> *getBlenderItems();
    private:
        // Members
        std::map<std::string, std::map<std::string, int>> recipes;
        std::vector<std::string> allItems;
        std::vector<std::string> baseItems;
        std::vector<std::string> blenderItems;

        // Methods
        void fillRecipeBook();
        void fillAllItemsList();
        void fillBaseItemsList();
        void fillBlenderItemsList();
};