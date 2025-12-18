class Solution {
public:
    int maxBottlesDrunk(int numBottles, int numExchange) {
        int emptyBottles = numBottles;;
        numBottles =0;
        int bottleDrunk =emptyBottles;
        while(emptyBottles>=numExchange){
            emptyBottles -= numExchange;
            bottleDrunk++;
            numExchange++;
            emptyBottles++;
        }
        return bottleDrunk;
        
    }
};