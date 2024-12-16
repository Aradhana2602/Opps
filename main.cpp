//Count lines and words


#include <iostream>
#include <fstream>
#include <cctype>  // For isalpha and isspace functions
#include <string>

using namespace std;

void countFileContents(const string& filename) {
    ifstream file(filename);
    if (!file.is_open()) {
        cout << "Error opening file!" << endl;
        return;
    }

    int lineCount = 0, wordCount = 0, letterCount = 0;
    string word;

    while (getline(file, word)) { // Reading file line by line
        lineCount++;

        for (char& ch : word) {
            if (isalpha(ch)) {
                letterCount++; // Count letters
            }
        }

        // Count words in the line
        bool inWord = false;
        for (char& ch : word) {
            if (isalpha(ch)) {
                if (!inWord) {
                    wordCount++; // Found a new word
                    inWord = true;
                }
            } else {
                inWord = false; // Not a letter, end of word
            }
        }
    }

    file.close();

    cout << "Lines: " << lineCount << endl;
    cout << "Words: " << wordCount << endl;
    cout << "Letters: " << letterCount << endl;
}

int main() {
    string filename;
    cout << "Enter file name: ";
    cin >> filename;

    countFileContents(filename);
    return 0;
}

Adding bits 

#include <iostream>
#include <stack>
#include <string>
#include <algorithm>

using namespace std;

string addBinaryNumbers(const string &bin1, const string &bin2) {
    stack<int> stack1, stack2, resultStack;
    
    // Push all bits of the first binary number onto stack1
    for (char ch : bin1) {
        stack1.push(ch - '0');  // Convert char to int (0 or 1)
    }
    
    // Push all bits of the second binary number onto stack2
    for (char ch : bin2) {
        stack2.push(ch - '0');  // Convert char to int (0 or 1)
    }
    
    int carry = 0;
    
    // Add corresponding bits until both stacks are empty and no carry left
    while (!stack1.empty() || !stack2.empty() || carry != 0) {
        int bit1 = 0, bit2 = 0;
        
        if (!stack1.empty()) {
            bit1 = stack1.top();
            stack1.pop();
        }
        
        if (!stack2.empty()) {
            bit2 = stack2.top();
            stack2.pop();
        }
        
        // Sum of the bits and the carry
        int sum = bit1 + bit2 + carry;
        
        // The resulting bit is sum % 2 (either 0 or 1)
        resultStack.push(sum % 2);
        
        // Carry for the next bit is sum / 2 (either 0 or 1)
        carry = sum / 2;
    }
    
    // Convert the result stack to a string
    string result = "";
    while (!resultStack.empty()) {
        result += to_string(resultStack.top());
        resultStack.pop();
    }
    
    return result;
}

int main() {
    string bin1, bin2;
    
    cout << "Enter first binary number: ";
    cin >> bin1;
    
    cout << "Enter second binary number: ";
    cin >> bin2;
    
    string sum = addBinaryNumbers(bin1, bin2);
    
    cout << "The sum of the two binary numbers is: " << sum << endl;
    
    return 0;
}

//Function Template for Selection Sort

#include <iostream>
using namespace std;

// Function Template for Selection Sort
template <typename T>
void selectionSort(T arr[], int size) {
    for (int i = 0; i < size - 1; ++i) {
        // Find the minimum element in the unsorted part
        int minIdx = i;
        for (int j = i + 1; j < size; ++j) {
            if (arr[j] < arr[minIdx]) {
                minIdx = j;
            }
        }
        
        // Swap the found minimum element with the first element
        if (minIdx != i) {
            T temp = arr[i];
            arr[i] = arr[minIdx];
            arr[minIdx] = temp;
        }
    }
}

// Function to print an array
template <typename T>
void printArray(T arr[], int size) {
    for (int i = 0; i < size; ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    // Integer array input, sorting and output
    int intArr[] = {64, 25, 12, 22, 11};
    int intSize = sizeof(intArr) / sizeof(intArr[0]);
    
    cout << "Original Integer Array: ";
    printArray(intArr, intSize);
    
    selectionSort(intArr, intSize);
    
    cout << "Sorted Integer Array: ";
    printArray(intArr, intSize);
    
    // Float array input, sorting and output
    float floatArr[] = {64.5, 25.3, 12.1, 22.7, 11.8};
    int floatSize = sizeof(floatArr) / sizeof(floatArr[0]);
    
    cout << "Original Float Array: ";
    printArray(floatArr, floatSize);
    
    selectionSort(floatArr, floatSize);
    
    cout << "Sorted Float Array: ";
    printArray(floatArr, floatSize);
    
    return 0;
}

//Implement a class Complex which represents the Complex Number data type. Implement the following 1. Constructor (including a default constructor which creates the complex number 0+0i). 2. Overloaded operator+ to add two complex numbers. 3. Overloaded operator* to multiply two complex numbers.4. Overloaded << and >> to print and read Complex Numbers


#include <iostream>
using namespace std;

class Complex {
private:
    double real;
    double imag;

public:
    // Default constructor (0 + 0i)
    Complex() : real(0), imag(0) {}

    // Parameterized constructor to initialize complex number
    Complex(double r, double i) : real(r), imag(i) {}

    // Overloaded operator+ to add two complex numbers
    Complex operator+(const Complex& other) {
        return Complex(real + other.real, imag + other.imag);
    }

    // Overloaded operator* to multiply two complex numbers
    Complex operator*(const Complex& other) {
        double r = real * other.real - imag * other.imag;  // real part
        double i = real * other.imag + imag * other.real;  // imaginary part
        return Complex(r, i);
    }

    // Overloaded << to print Complex number
    friend ostream& operator<<(ostream& out, const Complex& c) {
        out << c.real;
        if (c.imag >= 0) {
            out << " + " << c.imag << "i";
        } else {
            out << " - " << -c.imag << "i";
        }
        return out;
    }

    // Overloaded >> to read Complex number
    friend istream& operator>>(istream& in, Complex& c) {
        cout << "Enter real part: ";
        in >> c.real;
        cout << "Enter imaginary part: ";
        in >> c.imag;
        return in;
    }
};

int main() {
    Complex c1, c2, result;

    // Input complex numbers using >> operator
    cout << "Enter first complex number:" << endl;
    cin >> c1;
    cout << "Enter second complex number:" << endl;
    cin >> c2;

    // Add two complex numbers
    result = c1 + c2;
    cout << "Sum: " << result << endl;

    // Multiply two complex numbers
    result = c1 * c2;
    cout << "Product: " << result << endl;

    return 0;
}


//Write a C++ program that creates an output file, writes information to it, closes the file and open it again as an input file and read the information from the file.


#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
    // Step 1: Create and write to an output file
    ofstream outputFile("example.txt");  // Creates and opens a file named "example.txt"
    
    if (!outputFile) {  // Check if the file was created successfully
        cerr << "Error opening output file." << endl;
        return 1;  // Return an error code if the file couldn't be opened
    }
    
    // Write some information to the file
    outputFile << "Hello, this is a test file." << endl;
    outputFile << "Writing some more data to the file." << endl;
    outputFile << "End of file writing." << endl;

    // Close the output file
    outputFile.close();
    
    // Step 2: Open the file again as an input file and read from it
    ifstream inputFile("example.txt");  // Opens the file for reading
    
    if (!inputFile) {  // Check if the file was opened successfully
        cerr << "Error opening input file." << endl;
        return 1;  // Return an error code if the file couldn't be opened
    }
    
    string line;
    // Read and display the content of the file line by line
    cout << "Reading from the file:" << endl;
    while (getline(inputFile, line)) {
        cout << line << endl;
    }

    // Close the input file
    inputFile.close();
    
    return 0;  // Return 0 to indicate successful execution
}

//Write C++ program using STL for sorting and searching user defined records such as Item records (Item code, name, cost, quantity etc.) using vector container.

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

// Define the structure for Item records
struct Item {
    int code;
    string name;
    double cost;
    int quantity;

    // Constructor to initialize an Item object
    Item(int c, string n, double cost, int qty) : code(c), name(n), cost(cost), quantity(qty) {}
    
    // Display the item details
    void display() const {
        cout << "Item Code: " << code << ", Name: " << name << ", Cost: $" << cost << ", Quantity: " << quantity << endl;
    }
};

// Function to compare items by cost (for sorting)
bool compareByCost(const Item& a, const Item& b) {
    return a.cost < b.cost;
}

// Function to compare items by name (for sorting)
bool compareByName(const Item& a, const Item& b) {
    return a.name < b.name;
}

int main() {
    // Create a vector to store Item objects
    vector<Item> items;

    // Add some items to the vector
    items.push_back(Item(101, "Laptop", 999.99, 10));
    items.push_back(Item(102, "Smartphone", 599.49, 20));
    items.push_back(Item(103, "Tablet", 299.99, 15));
    items.push_back(Item(104, "Headphones", 49.99, 50));

    // Display items before sorting
    cout << "Items before sorting:" << endl;
    for (const auto& item : items) {
        item.display();
    }

    // Sort items by cost
    sort(items.begin(), items.end(), compareByCost);

    // Display items after sorting by cost
    cout << "\nItems after sorting by cost:" << endl;
    for (const auto& item : items) {
        item.display();
    }

    // Sort items by name
    sort(items.begin(), items.end(), compareByName);

    // Display items after sorting by name
    cout << "\nItems after sorting by name:" << endl;
    for (const auto& item : items) {
        item.display();
    }

    // Searching for an item by name using binary search
    string searchName = "Tablet";
    auto it = lower_bound(items.begin(), items.end(), searchName, [](const Item& a, const string& name) {
        return a.name < name;
    });

    if (it != items.end() && it->name == searchName) {
        cout << "\nItem found: ";
        it->display();
    } else {
        cout << "\nItem not found with name: " << searchName << endl;
    }

    // Searching for an item by code using linear search
    int searchCode = 102;
    auto itCode = find_if(items.begin(), items.end(), [searchCode](const Item& item) {
        return item.code == searchCode;
    });

    if (itCode != items.end()) {
        cout << "\nItem found with code " << searchCode << ": ";
        itCode->display();
    } else {
        cout << "\nItem not found with code: " << searchCode << endl;
    }

    return 0;
}


//Quadratic Polynomial
#include <iostream>
#include <cmath>
#include <stdexcept> // For handling exceptions
using namespace std;

class Quadratic {
private:
    double a, b, c;

public:
    // Default constructor - represents the zero polynomial
    Quadratic() : a(0), b(0), c(0) {}

    // Parameterized constructor
    Quadratic(double a, double b, double c) : a(a), b(b), c(c) {}

    // Overloaded + operator to add two polynomials
    Quadratic operator+(const Quadratic& other) {
        return Quadratic(this->a + other.a, this->b + other.b, this->c + other.c);
    }

    // Overloaded << operator to print the polynomial
    friend ostream& operator<<(ostream& os, const Quadratic& q) {
        os << q.a << "x^2 + " << q.b << "x + " << q.c;
        return os;
    }

    // Overloaded >> operator to input the polynomial
    friend istream& operator>>(istream& is, Quadratic& q) {
        cout << "Enter coefficient a (for x^2): ";
        is >> q.a;
        cout << "Enter coefficient b (for x): ";
        is >> q.b;
        cout << "Enter coefficient c: ";
        is >> q.c;
        return is;
    }

    // Function to evaluate the polynomial for a given value of x
    double eval(double x) {
        return a * x * x + b * x + c;
    }

    // Function to find the roots of the equation ax^2 + bx + c = 0
    void solve() {
        double discriminant = b * b - 4 * a * c;
        
        if (a == 0) {
            throw invalid_argument("The coefficient 'a' cannot be zero for a quadratic equation.");
        }

        if (discriminant > 0) {
            // Two real roots
            double root1 = (-b + sqrt(discriminant)) / (2 * a);
            double root2 = (-b - sqrt(discriminant)) / (2 * a);
            cout << "Roots are real and distinct: x1 = " << root1 << ", x2 = " << root2 << endl;
        } else if (discriminant == 0) {
            // One real root
            double root = -b / (2 * a);
            cout << "One real root: x = " << root << endl;
        } else {
            // Complex roots
            double realPart = -b / (2 * a);
            double imaginaryPart = sqrt(-discriminant) / (2 * a);
            cout << "Complex roots: x1 = " << realPart << " + " << imaginaryPart << "i, x2 = " 
                 << realPart << " - " << imaginaryPart << "i" << endl;
        }
    }
};

int main() {
    // Create two quadratic objects
    Quadratic q1(1, -3, 2); // Represents x^2 - 3x + 2
    Quadratic q2(1, 2, 1);  // Represents x^2 + 2x + 1

    // Output polynomials
    cout << "Polynomial 1: " << q1 << endl;
    cout << "Polynomial 2: " << q2 << endl;

    // Add two polynomials
    Quadratic q3 = q1 + q2;
    cout << "Sum of polynomials: " << q3 << endl;

    // Evaluate polynomial at a specific x value
    double x = 2;
    cout << "Evaluating Polynomial 1 at x = " << x << ": " << q1.eval(x) << endl;

    // Solve the quadratic equation (find roots)
    cout << "Solving Polynomial 1: ";
    q1.solve();

    cout << "Solving Polynomial 2: ";
    q2.solve();

    // Input a polynomial from the user
    Quadratic userPoly;
    cin >> userPoly;
    cout << "User-defined Polynomial: " << userPoly << endl;
    cout << "Evaluating user-defined polynomial at x = 5: " << userPoly.eval(5) << endl;

    cout << "Solving user-defined Polynomial: ";
    userPoly.solve();

    return 0;
}


//Student Information System in C++

#include <iostream>
#include <string>
using namespace std;

// Friend class definition
class Address;  // Forward declaration of Address class

// Student class definition
class Student {
private:
    string name;
    int rollNumber;
    string className;
    char division;
    string dob;  // Date of Birth (Format: YYYY-MM-DD)
    string bloodGroup;
    string contactAddress;
    string phoneNumber;
    string drivingLicenseNo;

    // Static member variable to keep track of the number of students
    static int studentCount;

public:
    // Default constructor
    Student() : name(""), rollNumber(0), className(""), division(' '), dob(""), bloodGroup(""), contactAddress(""), phoneNumber(""), drivingLicenseNo("") {
        studentCount++;  // Increment student count
        cout << "Default constructor called for " << name << endl;
    }

    // Parameterized constructor
    Student(string n, int roll, string cls, char div, string dob, string blood, string address, string phone, string license) 
        : name(n), rollNumber(roll), className(cls), division(div), dob(dob), bloodGroup(blood), contactAddress(address), phoneNumber(phone), drivingLicenseNo(license) {
        studentCount++;  // Increment student count
        cout << "Parameterized constructor called for " << name << endl;
    }

    // Copy constructor
    Student(const Student& s) {
        name = s.name;
        rollNumber = s.rollNumber;
        className = s.className;
        division = s.division;
        dob = s.dob;
        bloodGroup = s.bloodGroup;
        contactAddress = s.contactAddress;
        phoneNumber = s.phoneNumber;
        drivingLicenseNo = s.drivingLicenseNo;
        studentCount++;  // Increment student count
        cout << "Copy constructor called for " << name << endl;
    }

    // Destructor
    ~Student() {
        studentCount--;  // Decrement student count
        cout << "Destructor called for " << name << endl;
    }

    // Static member function to return the number of students
    static int getStudentCount() {
        return studentCount;
    }

    // Friend function declaration (allows Address class to access private members)
    friend class Address;

    // Inline function to display student information
    inline void displayInfo() const {
        cout << "Name: " << name << endl;
        cout << "Roll Number: " << rollNumber << endl;
        cout << "Class: " << className << endl;
        cout << "Division: " << division << endl;
        cout << "Date of Birth: " << dob << endl;
        cout << "Blood Group: " << bloodGroup << endl;
        cout << "Contact Address: " << contactAddress << endl;
        cout << "Phone Number: " << phoneNumber << endl;
        cout << "Driving License No.: " << drivingLicenseNo << endl;
    }

    // Dynamic memory allocation using new and delete (for a dynamic array of students)
    static Student* createStudentArray(int size) {
        return new Student[size];
    }

    static void deleteStudentArray(Student* array) {
        delete[] array;
    }
};

// Initialize static member
int Student::studentCount = 0;

// Address class definition (friend class of Student)
class Address {
public:
    void displayStudentAddress(const Student& s) {
        cout << "Contact Address: " << s.contactAddress << endl;  // Access private member
    }
};

// Main function to demonstrate the functionality
int main() {
    // Creating student objects using different constructors
    Student s1("Alice", 101, "10th", 'A', "2005-03-14", "O+", "123, Elm St.", "1234567890", "DL123456");
    Student s2("Bob", 102, "10th", 'B', "2005-05-21", "A-", "456, Oak St.", "0987654321", "DL654321");
    Student s3 = s1;  // Using copy constructor

    // Displaying student information
    cout << "\nStudent 1 Info:\n";
    s1.displayInfo();

    cout << "\nStudent 2 Info:\n";
    s2.displayInfo();

    cout << "\nStudent 3 Info (copied from Student 1):\n";
    s3.displayInfo();

    // Displaying static member using static function
    cout << "\nTotal number of students: " << Student::getStudentCount() << endl;

    // Using friend class Address to display the address of a student
    Address address;
    address.displayStudentAddress(s1);

    // Using dynamic memory allocation for an array of students
    Student* studentArray = Student::createStudentArray(3);
    studentArray[0] = s1;
    studentArray[1] = s2;
    studentArray[2] = s3;

    cout << "\nDisplaying information from dynamic student array:\n";
    for (int i = 0; i < 3; ++i) {
        studentArray[i].displayInfo();
    }

    // Free the dynamically allocated memory
    Student::deleteStudentArray(studentArray);

    return 0;
}

//Covid-19 patient counts


#include <iostream>
#include <map>
#include <string>
using namespace std;

int main() {
    // Create a map with state names as keys and Covid-19 patient counts as values
    map<string, int> covidData;

    string stateName;
    int patientCount;
    char continueInput;

    // Allow the user to enter multiple states and Covid-19 patient counts
    do {
        cout << "Enter the name of a state: ";
        getline(cin, stateName); // Allowing multi-word state names

        cout << "Enter the Covid-19 patient count for " << stateName << ": ";
        cin >> patientCount;

        // Insert the state and patient count into the map
        covidData[stateName] = patientCount;

        // Ask if the user wants to enter another state
        cout << "Do you want to enter another state? (y/n): ";
        cin >> continueInput;

        // Clear the newline character left by cin to avoid issues with getline in the next loop
        cin.ignore();

    } while (continueInput == 'y' || continueInput == 'Y');

    // Now allow the user to query the map for Covid-19 patient counts
    cout << "\nEnter the name of a state to get its Covid-19 patient count: ";
    getline(cin, stateName); // Allowing multi-word state names

    // Search for the state in the map
    auto it = covidData.find(stateName);

    // Check if the state is found in the map
    if (it != covidData.end()) {
        cout << "Covid-19 patient count in " << stateName << ": " << it->second << endl;
    } else {
        cout << "State not found in the database." << endl;
    }

    return 0;
}

//Student Database

#include <iostream>
#include <string>
#include <stdexcept> // For exception handling

using namespace std;

// Base class Publication
class Publication {
protected:
    string title;
    float price;

public:
    // Constructor to initialize title and price
    Publication(string t = "", float p = 0.0) : title(t), price(p) {}

    // Function to input data for the Publication
    void inputData() {
        cout << "Enter title: ";
        getline(cin, title);

        cout << "Enter price: ";
        cin >> price;

        // Check for invalid input (price should be non-negative)
        if (price < 0) {
            throw invalid_argument("Price cannot be negative.");
        }
    }

    // Function to display data for the Publication
    void displayData() const {
        cout << "Title: " << title << endl;
        cout << "Price: " << price << endl;
    }
};

// Derived class Book from Publication
class Book : public Publication {
private:
    int pageCount;

public:
    // Constructor to initialize Book (title, price, and page count)
    Book(string t = "", float p = 0.0, int pc = 0) : Publication(t, p), pageCount(pc) {}

    // Function to input data for the Book
    void inputData() {
        Publication::inputData(); // Get title and price
        cout << "Enter page count: ";
        cin >> pageCount;

        // Check for invalid input (page count should be positive)
        if (pageCount < 0) {
            throw invalid_argument("Page count cannot be negative.");
        }
    }

    // Function to display data for the Book
    void displayData() const {
        Publication::displayData(); // Display title and price
        cout << "Page count: " << pageCount << endl;
    }
};

// Derived class Tape from Publication
class Tape : public Publication {
private:
    float playingTime;

public:
    // Constructor to initialize Tape (title, price, and playing time)
    Tape(string t = "", float p = 0.0, float pt = 0.0) : Publication(t, p), playingTime(pt) {}

    // Function to input data for the Tape
    void inputData() {
        Publication::inputData(); // Get title and price
        cout << "Enter playing time (in minutes): ";
        cin >> playingTime;

        // Check for invalid input (playing time should be non-negative)
        if (playingTime < 0) {
            throw invalid_argument("Playing time cannot be negative.");
        }
    }

    // Function to display data for the Tape
    void displayData() const {
        Publication::displayData(); // Display title and price
        cout << "Playing time: " << playingTime << " minutes" << endl;
    }
};

int main() {
    // Instantiate Book and Tape objects
    Book book;
    Tape tape;

    try {
        // Get user input for Book
        cout << "Enter data for Book:" << endl;
        book.inputData();

        // Get user input for Tape
        cout << "\nEnter data for Tape:" << endl;
        tape.inputData();

        // Display the entered data for Book
        cout << "\nBook Data:" << endl;
        book.displayData();

        // Display the entered data for Tape
        cout << "\nTape Data:" << endl;
        tape.displayData();
    }
    catch (const exception& e) {
        // Catch any exception and reset all values to zero
        cout << "Error: " << e.what() << endl;
        cout << "Resetting all data values to zero..." << endl;

        // Resetting data for Book
        book = Book(); // Creating a new Book object with default values (zeroed)
        tape = Tape(); // Creating a new Tape object with default values (zeroed)

        // Display the reset data for Book
        cout << "\nBook Data (After Reset):" << endl;
        book.displayData();

        // Display the reset data for Tape
        cout << "\nTape Data (After Reset):" << endl;
        tape.displayData();
    }

    return 0;
}


//Encryption and Decryption File

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

// Function to encrypt the text using a Caesar Cipher (shift characters by a fixed amount)
void encryptFile(const string& inputFile, const string& outputFile, int shift) {
    ifstream inFile(inputFile);
    ofstream outFile(outputFile);

    if (!inFile.is_open()) {
        cout << "Error opening input file for encryption!" << endl;
        return;
    }

    if (!outFile.is_open()) {
        cout << "Error opening output file for encryption!" << endl;
        return;
    }

    char ch;
    while (inFile.get(ch)) {
        // If character is a letter, shift it
        if (isalpha(ch)) {
            // For lowercase letters
            if (islower(ch)) {
                ch = (ch - 'a' + shift) % 26 + 'a';
            }
            // For uppercase letters
            else if (isupper(ch)) {
                ch = (ch - 'A' + shift) % 26 + 'A';
            }
        }
        outFile.put(ch);  // Write the encoded character to the output file
    }

    inFile.close();
    outFile.close();
    cout << "File encrypted successfully!" << endl;
}

// Function to decrypt the text using a Caesar Cipher (shift characters back)
void decryptFile(const string& inputFile, const string& outputFile, int shift) {
    ifstream inFile(inputFile);
    ofstream outFile(outputFile);

    if (!inFile.is_open()) {
        cout << "Error opening input file for decryption!" << endl;
        return;
    }

    if (!outFile.is_open()) {
        cout << "Error opening output file for decryption!" << endl;
        return;
    }

    char ch;
    while (inFile.get(ch)) {
        // If character is a letter, shift it back
        if (isalpha(ch)) {
            // For lowercase letters
            if (islower(ch)) {
                ch = (ch - 'a' - shift + 26) % 26 + 'a';  // +26 to avoid negative results
            }
            // For uppercase letters
            else if (isupper(ch)) {
                ch = (ch - 'A' - shift + 26) % 26 + 'A';
            }
        }
        outFile.put(ch);  // Write the decoded character to the output file
    }

    inFile.close();
    outFile.close();
    cout << "File decrypted successfully!" << endl;
}

int main() {
    int choice, shift;
    string inputFile, outputFile;

    do {
        // Display menu
        cout << "\n--- File Encryption & Decryption ---\n";
        cout << "1. Encrypt File\n";
        cout << "2. Decrypt File\n";
        cout << "3. Exit\n";
        cout << "Enter your choice (1/2/3): ";
        cin >> choice;
        cin.ignore();  // To ignore the newline character left in the input buffer

        switch (choice) {
            case 1:  // Encrypt file
                cout << "Enter the input file name to encrypt: ";
                getline(cin, inputFile);
                cout << "Enter the output file name for encrypted data: ";
                getline(cin, outputFile);
                cout << "Enter shift value for encryption (integer): ";
                cin >> shift;

                encryptFile(inputFile, outputFile, shift);
                break;

            case 2:  // Decrypt file
                cout << "Enter the input file name to decrypt: ";
                getline(cin, inputFile);
                cout << "Enter the output file name for decrypted data: ";
                getline(cin, outputFile);
                cout << "Enter shift value for decryption (integer): ";
                cin >> shift;

                decryptFile(inputFile, outputFile, shift);
                break;

            case 3:  // Exit the program
                cout << "Exiting program..." << endl;
                break;

            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 3);

    return 0;
}


//Conversion Using Virtual Function

#include <iostream>
#include <string>
using namespace std;

// Base class Convert
class Convert {
protected:
    double val1, val2;  // val1 = initial value, val2 = converted value

public:
    // Constructor to initialize val1 and val2
    Convert(double initVal = 0.0) : val1(initVal), val2(0.0) {}

    // Getter for the initial value
    double getinit() const {
        return val1;
    }

    // Getter for the converted value
    double getconv() const {
        return val2;
    }

    // Pure virtual function for conversion logic (to be implemented by derived classes)
    virtual void compute() = 0;

    // Virtual destructor (for proper cleanup in derived classes)
    virtual ~Convert() {}
};

// Derived class for Celsius to Fahrenheit conversion
class CelsiusToFahrenheit : public Convert {
public:
    // Constructor to initialize the base class with the initial Celsius value
    CelsiusToFahrenheit(double celsius) : Convert(celsius) {}

    // Implementing the compute() function to perform Celsius to Fahrenheit conversion
    void compute() override {
        val2 = (val1 * 9 / 5) + 32;  // Formula: (Celsius * 9/5) + 32 = Fahrenheit
    }
};

// Derived class for Kilometers to Miles conversion
class KilometersToMiles : public Convert {
public:
    // Constructor to initialize the base class with the initial kilometers value
    KilometersToMiles(double kilometers) : Convert(kilometers) {}

    // Implementing the compute() function to perform Kilometers to Miles conversion
    void compute() override {
        val2 = val1 * 0.621371;  // Formula: Kilometers * 0.621371 = Miles
    }
};

// Derived class for Inches to Centimeters conversion
class InchesToCentimeters : public Convert {
public:
    // Constructor to initialize the base class with the initial inches value
    InchesToCentimeters(double inches) : Convert(inches) {}

    // Implementing the compute() function to perform Inches to Centimeters conversion
    void compute() override {
        val2 = val1 * 2.54;  // Formula: Inches * 2.54 = Centimeters
    }
};

int main() {
    int choice;
    double inputValue;

    do {
        // Display menu
        cout << "\n--- Unit Conversion Menu ---\n";
        cout << "1. Celsius to Fahrenheit\n";
        cout << "2. Kilometers to Miles\n";
        cout << "3. Inches to Centimeters\n";
        cout << "4. Exit\n";
        cout << "Enter your choice (1/2/3/4): ";
        cin >> choice;

        if (choice == 4) {
            break;
        }

        // Ask for the initial value
        cout << "Enter the value to convert: ";
        cin >> inputValue;

        Convert* convert = nullptr;  // Pointer to base class

        // Create the appropriate derived class object based on the user's choice
        switch (choice) {
            case 1:
                convert = new CelsiusToFahrenheit(inputValue);
                break;
            case 2:
                convert = new KilometersToMiles(inputValue);
                break;
            case 3:
                convert = new InchesToCentimeters(inputValue);
                break;
            default:
                cout << "Invalid choice! Please try again." << endl;
                continue;
        }

        // Perform the conversion
        convert->compute();

        // Display the results
        cout << "Initial value: " << convert->getinit() << endl;
        cout << "Converted value: " << convert->getconv() << endl;

        // Clean up memory
        delete convert;

    } while (choice != 4);

    cout << "Exiting program..." << endl;
    return 0;
}