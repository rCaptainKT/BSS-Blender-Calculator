#include <string>
#include <vector>
#include <map>

#include "recipebook.h"

RecipeBook::RecipeBook() {
    fillRecipeBook();
    fillAllItemsList();
    fillBaseItemsList();
    fillBlenderItemsList();
}

void RecipeBook::fillRecipeBook() {
    recipes["red extract"] = {
        {"strawberry", 50}, 
        {"royal jelly", 10}
    };
    
    recipes["blue extract"] = {
        {"blueberry", 50}, 
        {"royal jelly", 10}
    };

    recipes["enzymes"] = {
        {"pineapple", 50}, 
        {"royal jelly", 10}
    };
    
    recipes["oil"]= {
        {"sunflower seed", 50}, 
        {"royal jelly", 10}
    };
    
    recipes["glue"] = {
        {"gumdrops", 50}, 
        {"royal jelly", 10}
    };
    
    recipes["tropical drink"] = {
        {"coconut", 10}, 
        {"enzymes", 2},
        {"oil", 2}
    };
    
    recipes["gumdrops"] = {
        {"blueberry", 3}, 
        {"strawberry", 3},
        {"pineapple", 3}
    };

    recipes["moon charm"] = {
        {"pineapple", 5}, 
        {"gumdrops", 5},
        {"royal jelly", 1}
    };

    recipes["glitter"] = {
        {"moon charm", 25}, 
        {"magic bean", 1}
    };
    
    recipes["star jelly"] = {
        {"royal jelly", 100}, 
        {"glitter", 3}
    };
    
    recipes["purple potion"] = {
        {"neonberry", 3}, 
        {"red extract", 3},
        {"blue extract", 3},
        {"glue", 3}
    };
    
    recipes["soft wax"] = {
        {"honeysuckle", 5}, 
        {"oil", 1},
        {"enzymes", 1},
        {"royal jelly", 10}
    };
    
    recipes["hard wax"] = {
        {"soft wax", 3}, 
        {"enzymes", 3},
        {"bitterberry", 33},
        {"royal jelly", 33}
    };

    recipes["swirled wax"] = {
        {"hard wax", 3}, 
        {"soft wax", 9},
        {"purple potion", 6},
        {"royal jelly", 3333}
    };
    
    recipes["caustic wax"] = {
        {"hard wax", 5}, 
        {"enzymes", 5},
        {"neonberry", 25},
        {"royal jelly", 5252}
    };
    
    recipes["field dice"] = {
        {"soft wax", 1}, 
        {"whirligig", 1},
        {"red extract", 1},
        {"blue extract", 1}
    };
    
    recipes["smooth dice"] = {
        {"field dice", 3}, 
        {"soft wax", 3},
        {"whirligig", 3},
        {"oil", 3}
    };
    
    recipes["loaded dice"] = {
        {"smooth dice", 3}, 
        {"hard wax", 3},
        {"oil", 3},
        {"glue", 1}
    };
    
    recipes["super smoothie"] = {
        {"neonberry", 3}, 
        {"star jelly", 3},
        {"purple potion", 3},
        {"tropical drink", 6}
    };
    
    recipes["turpentine"] = {
        {"super smoothie", 10}, 
        {"caustic wax", 10},
        {"star jelly", 100},
        {"honeysuckle", 1000}
    };
}

void RecipeBook::fillAllItemsList() {
    allItems.insert(allItems.end(), "Gumdrops");
    allItems.insert(allItems.end(), "Coconut");
    allItems.insert(allItems.end(), "Stinger");
    allItems.insert(allItems.end(), "Honeysuckle");
    allItems.insert(allItems.end(), "Whirligig");
    allItems.insert(allItems.end(), "Field Dice");
    allItems.insert(allItems.end(), "Smooth Dice");
    allItems.insert(allItems.end(), "Loaded Dice");
    allItems.insert(allItems.end(), "Red Extract");
    allItems.insert(allItems.end(), "Blue Extract");
    allItems.insert(allItems.end(), "Glitter");
    allItems.insert(allItems.end(), "Glue");
    allItems.insert(allItems.end(), "Oil");
    allItems.insert(allItems.end(), "Enzymes");
    allItems.insert(allItems.end(), "Tropical Drink");
    allItems.insert(allItems.end(), "Purple Potion");
    allItems.insert(allItems.end(), "Super Smoothie");
    allItems.insert(allItems.end(), "Magic Bean");
    allItems.insert(allItems.end(), "Sunflower Seed");
    allItems.insert(allItems.end(), "Strawberry");
    allItems.insert(allItems.end(), "Pineapple");
    allItems.insert(allItems.end(), "Blueberry");
    allItems.insert(allItems.end(), "Bitterberry");
    allItems.insert(allItems.end(), "Neonberry");
    allItems.insert(allItems.end(), "Moon Charm");
    allItems.insert(allItems.end(), "Soft Wax");
    allItems.insert(allItems.end(), "Hard Wax");
    allItems.insert(allItems.end(), "Caustic Wax");
    allItems.insert(allItems.end(), "Swirled Wax");
    allItems.insert(allItems.end(), "Turpentine");
    allItems.insert(allItems.end(), "Royal Jelly");
    allItems.insert(allItems.end(), "Star Jelly");
}

void RecipeBook::fillBaseItemsList() {
    baseItems.insert(baseItems.end(), "Coconut");
    baseItems.insert(baseItems.end(), "Stinger");
    baseItems.insert(baseItems.end(), "Honeysuckle");
    baseItems.insert(baseItems.end(), "Whirligig");
    baseItems.insert(baseItems.end(), "Magic Bean");
    baseItems.insert(baseItems.end(), "Sunflower Seed");
    baseItems.insert(baseItems.end(), "Strawberry");
    baseItems.insert(baseItems.end(), "Pineapple");
    baseItems.insert(baseItems.end(), "Blueberry");
    baseItems.insert(baseItems.end(), "Bitterberry");
    baseItems.insert(baseItems.end(), "Neonberry");
    baseItems.insert(baseItems.end(), "Royal Jelly");
}

void RecipeBook::fillBlenderItemsList() {
    blenderItems.insert(blenderItems.end(), "Red Extract");
    blenderItems.insert(blenderItems.end(), "Blue Extract");
    blenderItems.insert(blenderItems.end(), "Enzymes");
    blenderItems.insert(blenderItems.end(), "Oil");
    blenderItems.insert(blenderItems.end(), "Glue");
    blenderItems.insert(blenderItems.end(), "Tropical Drink");
    blenderItems.insert(blenderItems.end(), "Gumdrops");
    blenderItems.insert(blenderItems.end(), "Moon Charm");
    blenderItems.insert(blenderItems.end(), "Glitter");
    blenderItems.insert(blenderItems.end(), "Star Jelly");
    blenderItems.insert(blenderItems.end(), "Purple Potion");
    blenderItems.insert(blenderItems.end(), "Soft Wax");
    blenderItems.insert(blenderItems.end(), "Hard Wax");
    blenderItems.insert(blenderItems.end(), "Swirled Wax");
    blenderItems.insert(blenderItems.end(), "Caustic Wax");
    blenderItems.insert(blenderItems.end(), "Field Dice");
    blenderItems.insert(blenderItems.end(), "Smooth Dice");
    blenderItems.insert(blenderItems.end(), "Loaded Dice");
    blenderItems.insert(blenderItems.end(), "Super Smoothie");
    blenderItems.insert(blenderItems.end(), "Turpentine"); 
}

//void RecipeBook::fillBlenderItemsList() {
//    blenderItems.insert(blenderItems.end(), "Gumdrops");
//    blenderItems.insert(blenderItems.end(), "Field Dice");
//    blenderItems.insert(blenderItems.end(), "Smooth Dice");
//    blenderItems.insert(blenderItems.end(), "Loaded Dice");
//    blenderItems.insert(blenderItems.end(), "Red Extract");
//    blenderItems.insert(blenderItems.end(), "Blue Extract");
//    blenderItems.insert(blenderItems.end(), "Glitter");
//    blenderItems.insert(blenderItems.end(), "Glue");
//    blenderItems.insert(blenderItems.end(), "Oil");
//    blenderItems.insert(blenderItems.end(), "Enzymes");
//    blenderItems.insert(blenderItems.end(), "Tropical Drink");
//    blenderItems.insert(blenderItems.end(), "Purple Potion");
//    blenderItems.insert(blenderItems.end(), "Super Smoothie");
//    blenderItems.insert(blenderItems.end(), "Moon Charm");
//    blenderItems.insert(blenderItems.end(), "Soft Wax");
//    blenderItems.insert(blenderItems.end(), "Hard Wax");
//    blenderItems.insert(blenderItems.end(), "Caustic Wax");
//    blenderItems.insert(blenderItems.end(), "Swirled Wax");
//    blenderItems.insert(blenderItems.end(), "Turpentine");
//    blenderItems.insert(blenderItems.end(), "Star Jelly");
//}

std::map<std::string, int> *RecipeBook::getRecipe(const std::string &itemName) {
    if (recipes.find(itemName) == recipes.end()) {
        // Item recipe not found
        return NULL;
    }else {
        // Item recipe found
        return &recipes[itemName];
    }
}

std::vector<std::string> *RecipeBook::getAllItems() {
    return &allItems;
}

std::vector<std::string> *RecipeBook::getBaseItems() {
    return &baseItems;
}

std::vector<std::string> *RecipeBook::getBlenderItems() {
    return &blenderItems;
}
