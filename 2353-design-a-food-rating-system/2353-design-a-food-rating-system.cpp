class FoodRatings {
public:

   
    map<string,set<pair<int,string>>> cuisinerating;
    map<string,string> foodcuisine;
    map<string,int> foodrating;
    
    
    FoodRatings(vector<string>& foods, vector<string>& cuisines, vector<int>& ratings) {
        for(int i=0;i<foods.size();i++){
           cuisinerating[cuisines[i]].insert({-ratings[i],foods[i]});
            foodcuisine[foods[i]]=cuisines[i];
            foodrating[foods[i]]=ratings[i];
        }
    }
    
    void changeRating(string food, int newRating) {
        //changing rating for cuisine
       string cuisine=foodcuisine[food];
        int oldrating=foodrating[food];
        cuisinerating[cuisine].erase({-oldrating,food});
        cuisinerating[cuisine].insert({-newRating,food});
        foodrating[food]=newRating;
   
    }
    
    string highestRated(string cuisine) {
        return begin(cuisinerating[cuisine])->second;
    }
};

/**
 * Your FoodRatings object will be instantiated and called as such:
 * FoodRatings* obj = new FoodRatings(foods, cuisines, ratings);
 * obj->changeRating(food,newRating);
 * string param_2 = obj->highestRated(cuisine);
 */