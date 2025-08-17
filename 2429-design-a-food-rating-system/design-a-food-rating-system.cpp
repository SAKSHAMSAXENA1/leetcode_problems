class FoodRatings {
public:
unordered_map<string,int> foodToRating;
unordered_map<string,string> foodToCuisine;
unordered_map<string,map<int,set<string>>> cuisineToRatedList;
    FoodRatings(vector<string>& foods, vector<string>& cuisines, vector<int>& ratings) {
        int n=foods.size();
        for(int i=0;i<n;i++)
        {
            foodToRating[foods[i]]=ratings[i];
            foodToCuisine[foods[i]]=cuisines[i];
            cuisineToRatedList[cuisines[i]][ratings[i]].insert(foods[i]);
        }
    }
    
    void changeRating(string food, int newRating) {
        string cuisine=foodToCuisine[food];
        int originalRating=foodToRating[food];
        cuisineToRatedList[cuisine][originalRating].erase(food);

        if(cuisineToRatedList[cuisine][originalRating].empty())
        cuisineToRatedList[cuisine].erase(originalRating);

        foodToRating[food]=newRating;
        cuisineToRatedList[cuisine][newRating].insert(food);
    }
    
    string highestRated(string cuisine) {

        return *((*(cuisineToRatedList[cuisine]).rbegin()).second).begin();
    }
};

/**
 * Your FoodRatings object will be instantiated and called as such:
 * FoodRatings* obj = new FoodRatings(foods, cuisines, ratings);
 * obj->changeRating(food,newRating);
 * string param_2 = obj->highestRated(cuisine);
 */