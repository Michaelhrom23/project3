
#include "Dish.hpp"
#include <iostream>
#include <iomanip> // For std::fixed and std::setprecision
#include <cctype>  // For std::isalpha, std::isspace

// Default Constructor
Dish::Dish() 
    : name_("UNKNOWN"), ingredients_({}), prep_time_(0), price_(0.0), cuisine_type_(CuisineType::OTHER) {
}

// Parameterized Constructor
Dish::Dish(const std::string& name, const std::vector<std::string>& ingredients={}, int prep_time=0, double price=0, CuisineType cuisine_type = CuisineType::OTHER)
    : name_(name), ingredients_(ingredients), prep_time_(prep_time), price_(price), cuisine_type_(cuisine_type) {
    setName(name);  // Use setName to validate the name
}

// Accessor Functions
std::string Dish::getName() const {
    return name_;
}

std::vector<std::string> Dish::getIngredients() const {
    return ingredients_;
}

int Dish::getPrepTime() const {
    return prep_time_;
}

double Dish::getPrice() const {
    return price_;
}

std::string Dish::getCuisineType() const {
    switch (cuisine_type_) {
        case CuisineType::ITALIAN: return "ITALIAN";
        case CuisineType::MEXICAN: return "MEXICAN";
        case CuisineType::CHINESE: return "CHINESE";
        case CuisineType::INDIAN: return "INDIAN";
        case CuisineType::AMERICAN: return "AMERICAN";
        case CuisineType::FRENCH: return "FRENCH";
        default: return "OTHER";
    }
}

// Mutator Functions
void Dish::setName(const std::string& name) {
    if (isValidName(name)) {
        name_ = name;
    } else {
        name_ = "UNKNOWN";
    }
}

void Dish::setIngredients(const std::vector<std::string>& ingredients) {
    ingredients_ = ingredients;
}

int Dish :: getIngredientCount()const{
    return ingredients_.size();
}


void Dish::setPrepTime(const int& prep_time) {
    prep_time_ = prep_time;
}

void Dish::setPrice(const double& price) {
    price_ = price;
}

void Dish::setCuisineType(const CuisineType& cuisine_type) {
    cuisine_type_ = cuisine_type;
}

// Display Function
void Dish::display() const {
    std::cout << "Dish Name: " << name_ << std::endl;
    std::cout << "Ingredients: ";
    for (size_t i = 0; i < ingredients_.size(); ++i) {
        std::cout << ingredients_[i];
        if (i != ingredients_.size() - 1) {
            std::cout << ", ";
        }
    }
    std::cout << std::endl;
    std::cout << "Preparation Time: " << prep_time_ << " minutes" << std::endl;
    std::cout << std::fixed << std::setprecision(2) << "Price: $" << price_ << std::endl;
    std::cout << "Cuisine Type: " << getCuisineType() << std::endl;
}

// Helper function to check if the name is valid
bool Dish::isValidName(const std::string& name) const {
    for (char c : name) {
        if (!std::isalpha(c) && !std::isspace(c)) {  // Check if each character is a letter or space
            return false;  // Name contains non-alphabetic characters other than spaces
        }
    }
    return true;  // Name is valid
}

bool Dish :: operator==(const Dish& dish)const{
        return(name_ == dish.name_) && (cuisine_type_== dish.cuisine_type_) && (prep_time_ == dish.prep_time_) && (price_ == dish.price_);

    }

bool Dish :: operator!=(const Dish& dish) const {
        return(name_ != dish.name_) || (cuisine_type_ != dish.cuisine_type_) || (prep_time_ != dish.prep_time_) || (price_ != dish.price_);
    }


