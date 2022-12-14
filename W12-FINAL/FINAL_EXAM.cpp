// THIS WORK WAS PRODUCED INDEPENDENTLY BY NEIL DANDEKAR ONLY. THANK YOU.
#include <iostream>
#include <string>
#include <sstream>
#include <exception>

using namespace std;

class Name // Given class definition
{
    private:
        string m_name ;

    public:
        Name(string name) : m_name(name)
        {
        }

        string getName() {
            return m_name ;
        }

        virtual string toString() = 0 ;
        virtual bool contains(string search) = 0 ;
        virtual bool isTheSame(Name & another) = 0 ;
};

class BadNameException : public runtime_error { // Creates BadNameExceptions when thrown
    public:
        BadNameException(string errMsg) : runtime_error(errMsg) {

        }
};

string toUpper(string s) { // Function I created to convert passed string to uppercase (used in .contains() methods)
    for(int i = 0; i < s.length(); i++) if(s[i] > 90) s[i] -= 32;   // If ASCII code for character is greater than 90 (lowercase),
    return s;                                                       // then subtract 32 (uppercase)
}

bool blank(string s) { // Function I created to check if passed string only contains whitespace (used to create exceptions)
    for (int i = 0; i < s.length(); i++) {
        if(s[i] != ' ') return false;
    }
    return true;
}

class Word : public Name { // Word class
    private:
        string definition;

    public:
        Word(string _name, string _definition) : Name(_name), definition(_definition) {
            stringstream error; // Error string

            // Creates error message if word is empty or blank:
            if(!_name.length()) error << "[EXCEPTION] Empty Word: \'" << _name << "\'. Word cannot be empty. Try again.\n";
            else if(blank(_name)) error << "[EXCEPTION] Blank Word: \'" << _name << "\'. Word cannot be only blank(s). Try again.\n";
            
            // Creates error message if definition is empty or blank:
            if(!_definition.length()) error << "[EXCEPTION] Empty Definition: \'" << _definition << "\'. Definition cannot be empty. Try again.\n";
            else if(blank(_definition)) error << "[EXCEPTION] Blank Definition: \'" << _definition << "\'. Definition cannot be only blank(s). Try again.\n";
            if((error.str()).length()) throw new BadNameException(error.str());
        }
        
        virtual string toString() { // Converts object to string
            stringstream out;
            out << "WORD(" << this->getName() << ") DEFINITION(" << definition << ")";
            return out.str();
        }

        virtual bool contains(string search) { // Searches if the search string occurs in object's name or definition
            return (toUpper(this->getName()).find(toUpper(search)) != string::npos) || 
                   (toUpper(this->definition).find(toUpper(search)) != string::npos);
        }

        bool isTheSame(Name &another) { // Checks if two Word objects have the same name or definition
            Word* pWord = dynamic_cast<Word*> (&another); // Dynamic cast checks if it is a Word object
            if(pWord == nullptr) return false;            // Checking if dynamic cast worked
            return (this->getName() == pWord->getName()) && (this->definition == pWord->definition);
        }
};

class Item : public Name { // Item class
    private:
        double price;
    
    public:
        Item(string _name, double _price) : Name(_name), price(_price) {
            stringstream error; // Error string

            // Creates error message if name is empty or blank:
            if(!_name.length()) error << "[EXCEPTION] Empty Name: \'" << _name << "\'. Name cannot be empty. Try again.\n";
            else if(blank(_name)) error << "[EXCEPTION] Blank Name: \'" << _name << "\'. Name cannot be only blank(s). Try again.\n";
            if((error.str()).length()) throw new BadNameException(error.str());
        }
        
        virtual string toString() { // Converts object to string
            stringstream out;
            out << "ITEM(" << this->getName() << ") PRICE($" << price << ")";
            return out.str();
        }

        virtual bool contains(string search) { // Searches if the search string occurs in object's name
            return (toUpper(this->getName()).find(toUpper(search)) != string::npos);
        }

        virtual bool isTheSame(Name &another) { // Checks if two Item objects have the same name
            Item* pItem = dynamic_cast<Item*> (&another); // Dynamic cast checks if it is an Item object
            if(pItem == nullptr) return false;            // Checking if dynamic cast worked
            return (this->getName() == pItem->getName());
        }
};

void countTheSameAsLast(Name* arr[], int size, int &numSame, bool &firstLast) { // QUESTION 4
    numSame = 0;
    firstLast = arr[0]->isTheSame(*arr[size-1]);
    for (int i = 0; i < size-1; i++) {
        if(arr[i]->isTheSame(*arr[size-1])) numSame++;
    }
}

Name** createTwoNames() { // QUESTION 5: Creates 0, 1, or 2 Name object(s) and returns an array of the pointer(s) to the object(s)
    Name** arr = new Name*[2];

    string _word;
    string _definition;
    string _name;
    double _price;

    cout << "\nEnter Word: ";
    getline(cin, _word);

    cout << "Enter Definition: ";
    getline(cin, _definition);

    try {
        arr[0] = new Word(_word, _definition);
    }
    catch(BadNameException *e) {
        cout << "\n" << e->what() << endl;
        arr[0] = nullptr;
    }

    cout << "\nEnter Item Name: ";
    getline(cin, _name);

    cout << "Enter Item Price: ";
    cin >> _price;

    try {
        arr[1] = new Item(_name, _price);
    }
    catch(BadNameException *e) {
        cout << "\n" << e->what() << endl;
        arr[1] = nullptr;
    }

    return arr;
};

void testQ4(Name* arr[], int size, int &numSame, bool &firstLast) { // Function I created to output question 4 test cases
    countTheSameAsLast(arr, size, numSame, firstLast);
    for(int i = 0; i < 4; i++) {
        cout << "\tarr[" << i << "]: " << arr[i]->toString() << endl;
    }
    cout << "\n\tcountTheSameAsLast(_arr, 4): " << endl;
    cout << "\tNumber of objects same as the last one: " << numSame << endl;
    cout << "\tAre the first and last objects the same? " << boolalpha << firstLast << endl;
    cout << endl;
}

int main() {
    // QUESTION 2 & 3 OUTPUT:
    Word school("school", "an educational institution");
    Item eraser("eraser", 1.05);
    cout << "QUESTION 2 & 3 (contains method):"  << endl;
    cout << "\tWord object \'school\': "           << school.toString() << endl;
    cout << "\t\tschool.contains(\"school\"): "      << boolalpha << school.contains("school")      << endl;
    cout << "\t\tschool.contains(\"educational\"): " << boolalpha << school.contains("educational") << endl;
    cout << "\t\tschool.contains(\"School\"): "      << boolalpha << school.contains("School")      << endl;
    cout << "\t\tschool.contains(\"eraser\"): "      << boolalpha << school.contains("eraser")      << endl;
    
    cout << "\tItem object \'eraser\': "           << eraser.toString() << endl;
    cout << "\t\teraser.contains(\"eraser\"): "      << boolalpha << eraser.contains("eraser")      << endl;
    cout << "\t\teraser.contains(\"school\"): "      << boolalpha << eraser.contains("school")      << endl;

    // QUESTION 4 OUTPUT:
    Name*   _arr[4];
    int     _numSame;
    bool    _firstLast;

    cout << "\nQUESTION 4:" << endl;
    // TEST CASE 1:
    _arr[0] = new Word("school", "an educational institution");
    _arr[1] = new Word("eraser", "a rubber or plastic tool that rubs out something written");
    _arr[2] = new Item("eraser", 1.05);
    _arr[3] = new Word("school", "an educational institution");
    cout << "\tTEST CASE 1:" << endl;
    testQ4(_arr, 4, _numSame, _firstLast);

    // TEST CASE 2:
    _arr[0] = new Word("school", "an educational institution");
    _arr[1] = new Word("church", "a religious institution");
    _arr[2] = new Item("eraser", 1.05);
    _arr[3] = new Word("church", "a religious institution");
    cout << "\tTEST CASE 2:" << endl;
    testQ4(_arr, 4, _numSame, _firstLast);

    // TEST CASE 3:
    _arr[0] = new Word("school", "an educational institution");
    _arr[1] = new Word("church", "N/A");
    _arr[2] = new Item("eraser", 1.05);
    _arr[3] = new Word("church", "a religious institution");
    cout << "\tTEST CASE 3:" << endl;
    testQ4(_arr, 4, _numSame, _firstLast);

    // TEST CASE 4:
    _arr[0] = new Word("eraser", "a rubber or plastic tool that rubs out something written");
    _arr[1] = new Word("school", "an educational institution");
    _arr[2] = new Word("book", "an object used to read information from");
    _arr[3] = new Item("eraser", 1.05);
    cout << "\tTEST CASE 4:" << endl;
    testQ4(_arr, 4, _numSame, _firstLast);

    // QUESTION 5 OUTPUT:
    cout << "QUESTION 5: " << endl;
    Name** arr = createTwoNames();
    if(*arr != nullptr && *(arr + 1) != nullptr) {
        cout << "\nSuccessfully created both Name objects: " << endl;
        cout << "\t" << (*arr)->toString() << endl;
        cout << "\t" << (*(arr + 1))->toString() << endl;
    }
    else if(*arr != nullptr || *(arr + 1) != nullptr) {
        cout << "\nSuccessfully created one Name object: " << endl;
        if(*arr != nullptr) cout << "\t" << (*arr)->toString() << endl;
        else cout << "\t" << (*(arr + 1))->toString() << endl;
    }
    else cout << "\nUnsuccesful. Neither Name object was created." << endl;
    cout << endl;

    return 0;
}