#include "Kitchen.hpp"

Kitchen :: Kitchen():totalPrep_time(0),countElaborate(0) {}

bool Kitchen :: newOrder(const Dish &dish) {
    if (contains(dish)) {
        return false;
    }

    add(dish); 
    totalPrep_time= totalPrep_time + dish.getPrepTime();

    if (dish.getIngredientCount()>=5 && dish.getPrepTime()>=60) {

        countElaborate +=1;
    }

    return true;
}

bool Kitchen :: serveDish(const Dish &dish) {
    if (contains (dish)) {
        totalPrep_time = totalPrep_time - dish.getPrepTime();
        if (dish.getIngredientCount()>= 5 &&dish.getPrepTime() >=60) {

            countElaborate -=1;
        }

        remove(dish); 

        return true; 
    }
    return false; 
}

int Kitchen :: getPrepTimeSum() const {
    return totalPrep_time;
}

int Kitchen :: calculateAvgPrepTime() const {
    if (getCurrentSize()==0){

        return 0;
    }  

    int avg = static_cast <double> (totalPrep_time)/getCurrentSize();
    return std :: round(avg);
}



int Kitchen :: elaborateDishCount() {

    return countElaborate;
}

double Kitchen :: calculateElaboratePercentage() const {
    if (getCurrentSize() == 0){
        return 0.0;
    } 
    return std :: round(static_cast <double> (countElaborate)/getCurrentSize()*10000)/ 100;
}


int Kitchen :: tallyCuisineTypes(const std :: string &cuisineType) const {

    int count{0};

    for (int i = 0; i < getCurrentSize();  i+=1) {
        if (items_[i].getCuisineType()==cuisineType) {

            count+=1;
        }
    }
    return count;
}

int Kitchen :: releaseDishesBelowPrepTime(const int &prepTime){

    int removedCount{0};

    for (int k = 0; k < getCurrentSize();) {

        if (items_[k].getPrepTime() < prepTime) {
            totalPrep_time = totalPrep_time- items_[k].getPrepTime();
            if (items_[k].getIngredientCount() >= 5 && items_[k].getPrepTime() >= 60) {
                countElaborate-=1;
            }

            remove(items_[k]); 
            removedCount+=1;
        } else {
            k+=1;
        }
    }
    return removedCount;
}

int Kitchen :: releaseDishesOfCuisineType(const std :: string &cuisineType) {

    int removedCount{0};

    for (int j = 0; j < getCurrentSize();) {
        if (items_[j].getCuisineType()==cuisineType) {
            totalPrep_time -= items_[j].getPrepTime();
            if (items_[j].getIngredientCount() >=5 && items_[j].getPrepTime()>= 60) {
                countElaborate -=1;
            }
            remove(items_[j]);
            removedCount +=1;
        } else {
            j+=1;
        }
    }
    return removedCount;
}
void Kitchen :: kitchenReport() const {

    std :: cout << "ITALIAN: " << tallyCuisineTypes("ITALIAN") << "\n"
              << "MEXICAN: " << tallyCuisineTypes("MEXICAN") << "\n"
              << "CHINESE: " << tallyCuisineTypes("CHINESE") << "\n"
              << "INDIAN: " << tallyCuisineTypes("INDIAN") << "\n"
              << "AMERICAN: " << tallyCuisineTypes("AMERICAN") << "\n"
              << "FRENCH: " << tallyCuisineTypes("FRENCH") << "\n"
              << "OTHER: " << tallyCuisineTypes("OTHER") << "\n"
              << "\nAVERAGE PREP TIME: " << calculateAvgPrepTime() << "\n"
              << "ELABORATE: " << std::fixed << std::setprecision(2) 
              << calculateElaboratePercentage() << "%\n";
}
