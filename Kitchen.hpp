//pre-proceses
#ifndef KITCHEN_HPP
#define KITCHEN_HPP

//needed libraries

#include <iostream>
#include <iomanip>
#include "Dish.hpp" 
#include <string>
#include <vector>
#include <cmath>
#include "ArrayBag.hpp"

class Kitchen:public ArrayBag<Dish> //using array bag
{  
    public: //public class
    Kitchen(); //default constructor 

    bool newOrder(const Dish &dish); //public method to create a new dish

    bool serveDish(const Dish &dish); //public method to remove a dish

    int getPrepTimeSum() const; //public method that returns an int for the prpeation time

    int calculateAvgPrepTime() const; //public method that gets the average prep time

    int elaborateDishCount(); //count of elaborate dishes

    double calculateElaboratePercentage() const; //returns type double to calcuate the percentage of dishes that are elaborate
    
    int tallyCuisineTypes(const std :: string &cuisineType) const; //couting the types of cuisines

    int releaseDishesBelowPrepTime(const int &prep_time); //returns int type

    int releaseDishesOfCuisineType (const std :: string &cuisineType); //returns int type
    
    void kitchenReport() const; // is the display of all the information

    private: 
    int totalPrep_time;
    int countElaborate;
};
#endif 
