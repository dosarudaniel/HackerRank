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

  /* Enter your code here */
  Waterbolt *w = NULL;
  Thunderstorm *t = NULL;
  Frostbite *fbt = NULL;
  Fireball *fbl = NULL;

  if (w = dynamic_cast<Waterbolt *>(spell)) {
    w->revealWaterpower();
  } else if (fbl = dynamic_cast<Fireball *>(spell)) {
    fbl->revealFirepower();
  } else if (fbt = dynamic_cast<Frostbite *>(spell)) {
    fbt->revealFrostpower();
  } else if (t = dynamic_cast<Thunderstorm *>(spell)) {
    t->revealThunderpower();
  } else {
    string a = SpellJournal::journal;
    string b = spell->revealScrollName();
    int as = a.length()+1;
    int bs = b.length()+1;
    // LCS algorithm
    int **m = new int* [as];
    for (int i = 0; i < as; i++) {
      m[i] = new int[bs];
    }
    for (int i = 0; i <= a.length(); i++) {
      m[i][0] = 0;
    }
    for (int i = 0; i <= b.length(); i++) {
      m[0][i] = 0;
    }

    for (int i = 1; i <= a.length(); i++) {
      for (int j = 1; j <= b.length(); j++) {
        if (a[i-1] == b[j-1]) {
          m[i][j] = m[i-1][j-1] + 1;
        } else {
          m[i][j] = max(m[i][j-1] , m[i-1][j]);
        }
      }
      
    }

    cout << m[a.length()][b.length()] << endl;
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