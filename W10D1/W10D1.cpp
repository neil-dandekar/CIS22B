#include <iostream>
#include <string>
#include <sstream>
#include <exception>
#include <iomanip>
#include <vector>

using namespace std; 
 
class User {
    private: 
        int    m_id; 
        string m_name; 
    public: 
        User(int id, string name): m_id(id), m_name(name) {

        }

        virtual string toString() {
           stringstream ss; 
           ss << "ID(" << m_id << ") NAME("<< m_name << ")" ; 
           return ss.str() ; 
        }

        bool isIDLarger(User & another) { 
           return m_id > another.m_id ; 
        }
};

// QUESTION 1:
class BadValueException : public exception {
    
};