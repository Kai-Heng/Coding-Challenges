#include <iostream>
using namespace std;
enum class Fruit { apple, orange, pear };
enum class Color { red, green, orange };

template <typename T> struct Traits;

template<>
struct Traits <Fruit>{
    static int index;
    static string name(int index){
        switch (index){
            case (int)Fruit::apple:
               return "apple";
               
            case (int) Fruit::orange:
                return "orange";
            
            case (int) Fruit::pear:
                return "pear";
                
            default:
                return "unknown"; 
        }
    }
};

template<>
struct Traits <Color>{
    static int index;
    static string name(int index){
        switch (index){
            case (int)Color::red:
               return "red";
               
            case (int) Color::green:
                return "green";
            
            case (int) Color::orange:
                return "orange";
                
            default:
                return "unknown"; 
        }
    }
};

int main()
{
	int t = 0; std::cin >> t;

    for (int i=0; i!=t; ++i) {
        int index1; std::cin >> index1;
        int index2; std::cin >> index2;
        cout << Traits<Color>::name(index1) << " ";
        cout << Traits<Fruit>::name(index2) << "\n";
    }
}
