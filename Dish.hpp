#ifndef DISH_HPP
#define DISH_HPP

#include <string>
#include <vector>

class Dish {
public:
    
    enum CuisineType { ITALIAN, MEXICAN, CHINESE, INDIAN, AMERICAN, FRENCH, OTHER };

    
    Dish();

   
    Dish(const std::string& name, const std::vector<std::string>& ingredients, int prep_time, double price, CuisineType cuisine_type);
    
    
    std::string getName() const;

   
    std::vector<std::string> getIngredients() const;
    
    int getIngredientCount()const;
    
    int getPrepTime() const;

    
    double getPrice() const;

    
    std::string getCuisineType() const;

    
    void setName(const std::string& name);

    
    void setIngredients(const std::vector<std::string>& ingredients);

    
    void setPrepTime(const int& prep_time);

    
    void setPrice(const double& price);

    
    void setCuisineType(const CuisineType& cuisine_type);

    
    void display() const;

    
    bool operator==(const Dish& dish)const;
    
    bool operator!=(const Dish& dish)const;
    

private:
    std::string name_;
    std::vector<std::string> ingredients_;
    int prep_time_;
    double price_;
    CuisineType cuisine_type_;

    
    bool isValidName(const std::string& name) const;
};

#endif // DISH_HPP
