#include <iostream>
#include <string>

// We need to forward-declare the Government class because President uses it.
class Government; 

class President {
public:
    void launchNukes(Government& gov); // Takes a Government object
};

class Government {
private:
    std::string nuclearLaunchCode = "BOOM123";

public:
    // Granting friendship to the ENTIRE President class.
    // Every member function of President can now access our private members.
    friend class President; 
};

// Now we define the President's member function.
void President::launchNukes(Government& gov) {
    std::cout << "Accessing launch codes..." << std::endl;
    std::cout << "Code: " << gov.nuclearLaunchCode << std::endl; // Access is allowed!
    // This works only because President is a friend of Government.
}

int main() {
    Government usa;
    President mr_president;

    mr_president.launchNukes(usa); 
    // Output:
    // Accessing launch codes...
    // Code: BOOM123

    return 0;
}