#include <iostream>
#include <bitset>

using namespace std;

class FizzBuzz
{
public:
 FizzBuzz(uint32_t fizz, uint32_t buzz) : fizz_(fizz), buzz_(buzz)
    {
    }
    void process(uint32_t value)
    {
        cout << value;
        if (isFizz(value))
            cout << " Fizz";
        if (isBuzz(value))
            cout << " Buzz";
 }
protected:
    const uint32_t fizz_;
    const uint32_t buzz_;
    virtual bool isFizz(uint32_t value)
    {
        return fizz_ == value;
    }

    virtual bool isBuzz(uint32_t value)
    {
        return buzz_ == value;
    }
};

class FizzBuzz1 : public FizzBuzz
{
public:
    FizzBuzz1(uint32_t fizz, uint32_t buzz) : FizzBuzz(fizz, buzz){}

protected:
    // Use modulo to check if the value is divisible by fizz_ or fizz_
    bool isFizz(uint32_t value) override{
        return value % fizz_ == 0;
    }

    bool isBuzz(uint32_t value) override{
        return value % buzz_ == 0;
    }
};

class FizzBuzz2 : public FizzBuzz
{
private:
    uint32_t target_;
    // Use XOR to count 1s, which represent numbers of bits needs to be flipped
    uint32_t calculateBitFlipped(uint32_t x, uint32_t y){
        return bitset<32>(x^y).count();
    }
public:
    FizzBuzz2(uint32_t fizz, uint32_t buzz, uint32_t target) : FizzBuzz(fizz, buzz), target_(target){}

protected:
    // If numbers of bits equal fizz_, return true 
    bool isFizz(uint32_t value) override{
        return calculateBitFlipped(value, target_) == fizz_;
    }

    bool isBuzz(uint32_t value) override{
        return calculateBitFlipped(value, target_) == buzz_;
    }
};

int main(){
    cout << "Fizz Buzz!\n";
    // FizzBuzz fizzbuzz(2, 3);
    FizzBuzz1 fizzbuzz(2, 3);
    // FizzBuzz2 fizzbuzz(2, 3, 4); 
    const uint32_t count = 32;
    for (uint32_t i = 1; i < count; i++)
    {
        //FizzBuzz2 test cases:
        // Fizz: 2, Buzz: 3
        // 5: 101 4: 100 Flip 1 neither Fizz nor Buzz
        // 7: 111 4: 100 Flip 2 output: Fizz 
        // 
        fizzbuzz.process(i);
        cout << ", ";
    }
    fizzbuzz.process(count);
    cout << "Done\n";

    return 0;
}