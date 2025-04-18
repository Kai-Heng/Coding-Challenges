#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Spell { 
    private:
        string scrollName;
    public:
        Spell(): scrollName("") { }
        Spell(string name): scrollName(name) { }
        virtual ~Spell() { }
        string revealScrollName() {
            return scrollName;
        }
};

class Fireball : public Spell { 
    private: int power;
    public:
        Fireball(int power): power(power) { }
        void revealFirepower(){
            cout << "Fireball: " << power << endl;
        }
};

class Frostbite : public Spell {
    private: int power;
    public:
        Frostbite(int power): power(power) { }
        void revealFrostpower(){
            cout << "Frostbite: " << power << endl;
        }
};

class Thunderstorm : public Spell { 
    private: int power;
    public:
        Thunderstorm(int power): power(power) { }
        void revealThunderpower(){
            cout << "Thunderstorm: " << power << endl;
        }
};

class Waterbolt : public Spell { 
    private: int power;
    public:
        Waterbolt(int power): power(power) { }
        void revealWaterpower(){
            cout << "Waterbolt: " << power << endl;
        }
};

class SpellJournal {
    public:
        static string journal;
        static string read() {
            return journal;
        }
}; 
string SpellJournal::journal = "";

void counterspell(Spell *spell) {
    
/* Enter your code here. Read input from STDIN. Print output to STDOUT */
    string spellName = spell->revealScrollName();
    string journal = SpellJournal::read();
    
    if(Fireball* fireball = dynamic_cast<Fireball*>(spell)){
        fireball->revealFirepower();
    }
    else if(Frostbite* frostbite = dynamic_cast<Frostbite*>(spell)){
        frostbite->revealFrostpower();
    }
    else if(Waterbolt* waterbolt = dynamic_cast<Waterbolt*>(spell)){
        waterbolt->revealWaterpower();
    }
    else if(Thunderstorm* thunderstorm = dynamic_cast<Thunderstorm*>(spell)){
        thunderstorm->revealThunderpower();
    }

    else{
        vector<vector<int>> subseq(spellName.length()+1, vector<int>(journal.length()+1, 0));
        for (int i = 1; i <= spellName.length(); i++) {
            for (int j = 1; j <= journal.length(); j++) {
                if (spellName[i - 1] == journal[j - 1])
                    subseq[i][j] = 1 + subseq[i - 1][j - 1];
                else
                    subseq[i][j] = max(subseq[i - 1][j], subseq[i][j - 1]);
            }
        }
        
        cout << subseq[spellName.length()][journal.length()] << endl;
        
    }

}

class Wizard {
    public:
        Spell *cast() {
            Spell *spell;
            string s; cin >> s;
            int power; cin >> power;
            if(s == "fire") {
                spell = new Fireball(power);
            }
            else if(s == "frost") {
                spell = new Frostbite(power);
            }
            else if(s == "water") {
                spell = new Waterbolt(power);
            }
            else if(s == "thunder") {
                spell = new Thunderstorm(power);
            } 
            else {
                spell = new Spell(s);
                cin >> SpellJournal::journal;
            }
            return spell;
        }
};

int main() {
    int T;
    cin >> T;
    Wizard Arawn;
    while(T--) {
        Spell *spell = Arawn.cast();
        counterspell(spell);
    }
    return 0;
}