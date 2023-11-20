class Solution {
public:
    int findRadius(vector<int>& houses, vector<int>& heaters) {
        std::sort(houses.begin(), houses.end());
        std::sort(heaters.begin(), heaters.end());

        int radius = 0;
        int i = 0; // Index for houses
        int j = 0; // Index for heaters

        while (i < houses.size()) {
            // Find the nearest heater on the left of the current house
            while (j < heaters.size() && heaters[j] < houses[i]) {
                j++;
            }

            // Calculate the minimum distance between the house and the left heater
            int leftDistance = (j == 0) ? INT_MAX : houses[i] - heaters[j - 1];

            // Find the nearest heater on the right of the current house

            // Calculate the minimum distance between the house and the right heater
            int rightDistance = (j == heaters.size()) ? INT_MAX : heaters[j] - houses[i];

            // Update the radius based on the minimum distance for this house
            radius = std::max(radius, std::min(leftDistance, rightDistance));

            // Move to the next house
            i++;
        }

        return radius;
    }
};