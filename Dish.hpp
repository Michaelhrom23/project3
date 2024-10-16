#ifndef DISH_HPP
#define DISH_HPP

#include <string>
#include <vector>

class Dish {
public: //public class
    //cusintetype enum types
    enum CuisineType { ITALIAN, MEXICAN, CHINESE, INDIAN, AMERICAN, FRENCH, OTHER };

    
    Dish(); //default constructor

   //parameterized constructor, with a name, the ingredients, prep time, price and cuisine type
    Dish(const std::string& name, const std::vector<std::string>& ingredients, int prep_time, double price, CuisineType cuisine_type);
    
    
    std::string getName() const; //returns string type that is the name
   
    std::vector<std::string> getIngredients() const; //returns a vector that is made of strings, gets ingredients
    
    int getIngredientCount()const; //returns integer of the number of ingredients 
    
    int getPrepTime() const; //returns the time that it takes for the preparation in mins

    
    double getPrice() const; //returns double type

    
    std::string getCuisineType() const; //returns a string type that is a cuisine type

    
    void setName(const std::string& name); //void method that sets the name to the parameter

    
    void setIngredients(const std::vector<std::string>& ingredients); //void method that sets the ingredients to the parameter

    
    void setPrepTime(const int& prep_time); //void method that sets the preparation time of the function 

    
    void setPrice(const double& price); //void method that sets the price 

    
    void setCuisineType(const CuisineType& cuisine_type); //void method that sets the cuisine type

    
    void display() const; //void method that displays the data

    
    bool operator==(const Dish& dish)const;
    
    bool operator!=(const Dish& dish)const;
    

private: //private data members
    std::string name_;
    std::vector<std :: string> ingredients_;
    int prep_time_;
    double price_;
    CuisineType cuisine_type_;

    
    bool isValidName(const std::string& name) const; //private meehtod
};

#endif 
