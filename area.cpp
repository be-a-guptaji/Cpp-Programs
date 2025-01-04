#include <iostream>
#include <cmath> // for sqrt() and pow()

using namespace std; // To avoid writing std:: before every standard library function

// Function to calculate the radius (distance between two points)
float radius(int x1, int x2, int y1, int y2)
{
    float r = sqrt(pow((x2 - x1), 2) + pow((y2 - y1), 2));
    cout << "\nThe radius of the circle is " << r << ".\n";
    return r;
}

// Function to calculate the area of the circle using the radius
float area(int x1, int x2, int y1, int y2, float (*distance)(int, int, int, int))
{
    // Calculate the radius using the passed function
    float r = distance(x1, x2, y1, y2);
    float area = 3.14f * r * r; // Area of the circle: π * r^2
    cout << "\nThe area of the circle is " << area << ".\n";
    return area;
}

int main()
{
    int x1, x2, y1, y2;

    // Take input from the user for the coordinates
    cout << "Enter x1: ";
    cin >> x1;
    cout << "Enter y1: ";
    cin >> y1;
    cout << "Enter x2: ";
    cin >> x2;
    cout << "Enter y2: ";
    cin >> y2;

    // Calculate and display the area using the radius function
    float dst = area(x1, x2, y1, y2, radius);

    return 0; // Exit successfully
}
