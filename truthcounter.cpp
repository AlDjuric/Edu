#include <iostream>

// P1..p2... definition
bool logical_imp(bool p1, bool p2, bool p3, bool p4, bool p5, bool p6, bool p7, bool p8, bool p9, bool p10) 
{
    bool left_side = (p1 || p2) && (p3 || p4) && (p5 || p6);
    bool right_side = (p7 && p8) || (p9 && p10);
    
    return !left_side || right_side;
}

int main() 
{
    const int total_assignments = 1 << 10;  // The total possible assignments (10)

    int count_true_assignments = 0;

    for (int assignment = 0; assignment < total_assignments; ++assignment) {
        /*
        * Bitwise checking LSB if it is true or false
        * check directly in function call and increment counter for ever true
        */
        if (logical_imp(
            assignment & (1 << 0),
            assignment & (1 << 1),
            assignment & (1 << 2),
            assignment & (1 << 3),
            assignment & (1 << 4),
            assignment & (1 << 5),
            assignment & (1 << 6),
            assignment & (1 << 7),
            assignment & (1 << 8),
            assignment & (1 << 9)
        )) {
            count_true_assignments++; // Count total truths
        }
    }


    std::cout << "Total times it is true: " << count_true_assignments << std::endl;

    return 0;
}
