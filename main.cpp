#include <iostream>
#include <string>

using namespace std;

class TierOne {
public:
    
    TierOne(string _name, uint8_t _health, int8_t _armor, int8_t _strength) {
        this->name = _name;
        this->health = _health;
        this->armor = _armor;
        this->strength = _strength;
    }
    virtual void createTireOne() = 0;
protected:
    string name;
    uint8_t health;
    int8_t armor;  
    int8_t strength;     
};

class TierTwo {
public:
    TierTwo(string _name, uint8_t _health, int8_t _armor, int8_t _strength) {
        this->name = _name;
        this->health = _health;
        this->armor = _armor;
        this->strength = _strength;
    }
    virtual void createTireTwo() = 0;
protected:
    string name;
    uint8_t health;
    int8_t armor;  
    int8_t strength;  
};

class TierThree {
public:
    TierThree(string _name, uint8_t _health, int8_t _armor, int8_t _strength) {
        this->name = _name;
        this->health = _health;
        this->armor = _armor;
        this->strength = _strength;
    }
    virtual void createTireThree() = 0;
protected:
    string name;
    uint8_t health;
    int8_t armor;  
    int8_t strength;    
};

class HumanTierOne : public TierOne {
public:
    HumanTierOne() : TierOne("Footman", 100, 50, 80) {}
    void createTireOne() {
        cout << "Create tire 1 race Human: " << name << endl;
        cout << "Health: " << (int)health << endl;
        cout << "Armor: " << (int)armor << endl;
        cout << "Strength: " << (int)armor << endl << endl;
    }
};

class HumanTierTwo : public TierTwo {
public:
    HumanTierTwo() : TierTwo("Priest", 120, 60, 100) {}
    void createTireTwo() {
        cout << "Create tire 2 race Human: " << name << endl;
        cout << "Health: " << (int)health << endl;
        cout << "Armor: " << (int)armor << endl;
        cout << "Strength: " << (int)armor << endl << endl;
    }
};

class HumanTierThree : public TierThree {
public:
    HumanTierThree() : TierThree("Knight", 150, 100, 125) {}
    void createTireThree() {
        cout << "Create tire 3 race Human: " << name << endl;
        cout << "Health: " << (int)health << endl;
        cout << "Armor: " << (int)armor << endl;
        cout << "Strength: " << (int)armor << endl << endl;
    }
};

class OrcTierOne : public TierOne {
public:
    OrcTierOne() : TierOne("Grunt", 100, 50, 80) {}
    void createTireOne() {
        cout << "Create tire 1 race Orc: " << name << endl;
        cout << "Health: " << (int)health << endl;
        cout << "Armor: " << (int)armor << endl;
        cout << "Strength: " << (int)armor << endl << endl;
    }
};

class OrcTierTwo : public TierTwo {
public:
    OrcTierTwo() : TierTwo("Shaman", 120, 60, 100) {}
    void createTireTwo() {
        cout << "Create tire 2 race Orc: " << name << endl;
        cout << "Health: " << (int)health << endl;
        cout << "Armor: " << (int)armor << endl;
        cout << "Strength: " << (int)armor << endl << endl;
    }
};

class OrcTierThree : public TierThree {
public:
    OrcTierThree() : TierThree("Tauren", 150, 100, 125) {}
    void createTireThree() {
        cout << "Create tire 3 race Orc: " << name << endl;
        cout << "Health: " << (int)health << endl;
        cout << "Armor: " << (int)armor << endl;
        cout << "Strength: " << (int)armor << endl << endl;
    }
};

class IFactory {
public:
    virtual TierOne* getTierOne() = 0;
    virtual TierTwo* getTierTwo() = 0;
    virtual TierThree* getTierThree() = 0;
};

class HumanFactory : public IFactory {
public:
    TierOne* getTierOne() {
        return new HumanTierOne();
    }
    TierTwo* getTierTwo() {
        return new HumanTierTwo();
    }
    TierThree* getTierThree() {
        return new HumanTierThree();
    }
};

class OrcFactory : public IFactory {
public:
    TierOne* getTierOne() {
        return new OrcTierOne();
    }
    TierTwo* getTierTwo() {
        return new OrcTierTwo();
    }
    TierThree* getTierThree() {
        return new OrcTierThree();
    }
};

class Player {
public:
    IFactory* factory;
    Player(IFactory* factory) {
        this->factory = factory;
    }
    void CreateUnits() {
        TierOne* tierOne = this->factory->getTierOne();
        TierTwo* tierTwo = this->factory->getTierTwo();
        TierThree* tierThree = this->factory->getTierThree();
        tierOne->createTireOne();
        tierTwo->createTireTwo();
        tierThree->createTireThree();
    }
};

IFactory* createFactory(string race) {
    if (race == "Human") {
        return new HumanFactory();
    }
    if (race == "Orc") {
        return new OrcFactory();
    }
    else {
        return nullptr;
    }
};

int main() {
    string race_one = "Human";
    Player player_one = Player(createFactory(race_one));
    player_one.CreateUnits();

    string race_two = "Orc";
    Player player_second = Player(createFactory(race_two));
    player_second.CreateUnits();
}