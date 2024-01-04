#include <iostream>
#include <string>

using namespace std;

class TierOne {
public:
    string name;
    TierOne(string _name) {
        this->name = _name;
    }
    virtual void createTireOne() = 0;
};

class TierTwo {
public:
    string name;
    TierTwo(string _name) {
        this->name = _name;
    }
    virtual void createTireTwo() = 0;
};

class TierThree {
public:
    string name;
    TierThree(string _name) {
        this->name = _name;
    }
    virtual void createTireThree() = 0;
};

class HumanTierOne : public TierOne {
public:
    HumanTierOne() : TierOne("Footman") {}
    void createTireOne() {
        cout << "Create " << name << endl;
    }
};

class HumanTierTwo : public TierTwo {
public:
    HumanTierTwo() : TierTwo("Priest") {}
    void createTireTwo() {
        cout << "Create " << name << endl;
    }
};

class HumanTierThree : public TierThree {
public:
    HumanTierThree() : TierThree("Knight") {}
    void createTireThree() {
        cout << "Create " << name << endl;
    }
};

class OrcTierOne : public TierOne {
public:
    OrcTierOne() : TierOne("Grunt") {}
    void createTireOne() {
        cout << "Create " << name << endl;
    }
};

class OrcTierTwo : public TierTwo {
public:
    OrcTierTwo() : TierTwo("Shaman") {}
    void createTireTwo() {
        cout << "Create " << name << endl;
    }
};

class OrcTierThree : public TierThree {
public:
    OrcTierThree() : TierThree("Tauren") {}
    void createTireThree() {
        cout << "Create " << name << endl;
    }
};

class Factory {
public:
    virtual TierOne* getTierOne() = 0;
    virtual TierTwo* getTierTwo() = 0;
    virtual TierThree* getTierThree() = 0;
};

class HumanFactory : public Factory {
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

class OrcFactory : public Factory {
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
    Factory* factory;
    Player(Factory* factory) {
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

Factory* createFactory(string race) {
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