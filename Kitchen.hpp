#ifndef KITCHEN_HPP
#define KITCHEN_HPP

#include "ArrayBag.hpp"
#include "Dish.hpp"
#include <iostream>
#include <iomanip> 
#include <string>
#include <vector>
#include <cmath>  

class Kitchen:public ArrayBag<Dish>
{  
    private: 
    int totalPrep_time;
    int countElaborate;

    public:
    Kitchen();

    bool newOrder(const Dish &dish);

    bool serveDish(const Dish &dish);

    int getPrepTimeSum() const;

    int calculateAvgPrepTime() const;

    int elaborateDishCount();

    double calculateElaboratePercentage() const;
    
    int tallyCuisineTypes(const std :: string &cuisineType) const;

    int releaseDishesBelowPrepTime(const int &prep_time);

    int releaseDishesOfCuisineType (const std :: string &cuisineType);
    
    void kitchenReport() const;
};
#endif 