#include "TableBasedAdjuster.h"
TableBasedAdjuster& TableBasedAdjuster::addBreakpoint(float x, float y) {
    breakpoints.insert(std::make_pair(x,y));
    return *this;
}
/**
     * If map breakpoints is empty, returns the value
     * unmodified. Else calculates an adjusted value (a)
     * from the given un-adjusted value (u) passed as
     * argument and the breakpoints with their associated
     * values in the map (bp) as follows (remember that
     * keys in a map are sorted):
     *
     * * Let k_min be the key in bp with the smallest value
     *   and k_max be the key with the largest value. Let the
     *   value associated with any key k_n be v_n.
     *
     * * If u <= k_min then a = v_min - (k_min - u)
     *
     * * If u >= k_max then a = v_max + (u - k_max)
     *
     * * For any two adjacent keys k_n and k_(n+1):
     *   If k_n < u <= k_(n+1) then
     *     a = (u - k_n) / (k_(n+1) - k_n) * (v_(n+1) - v_n) + v_n
     *
     * An example for a function with points (-1, -0,5)
     * and (2, 1) is shown in the exam paper.
     *
     * (15 points)
     */
float TableBasedAdjuster::adjust(float value) const {

    if(breakpoints.empty()) {
        return value;
    }else {
        float k_min = breakpoints.begin()->first;
        float v_min = breakpoints.begin()->second;
        float k_max = breakpoints.rbegin()->first;
        float v_max = breakpoints.rbegin()->second;

        if( value <= k_min) {
            return (v_min - (k_min - value));
        }else if( value >= k_max) {
            return (v_max + (value - k_max));
        }else {

            for( auto iter = breakpoints.rbegin() ; iter != breakpoints.rend() ; ++iter) {

                if( value >= iter->first ) {
                    float k_n= iter->first;
                    float v_n = iter->second;
                    float k_next = prev(iter)->first;
                    float v_next = prev(iter)->second;
                    float a =  (value - k_n) / (k_next - k_n) * (v_next - v_n) + v_n;
                    return a;
                }
            }

        }
        return value;


    }

}
