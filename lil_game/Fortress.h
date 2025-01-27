#pragma once
#include <iostream>
#include <string>
using namespace std;

class Shooter {
public:
    string amunition;
    int shoot_count;

    virtual void shoot() {
        if (shoot_count > 0) {
            shoot_count--;
            cout << amunition << " been shot!" << endl;
        }
        else {
            cout << "No ammunition left!" << endl;
        }
    }

    virtual void give_amunition(string amunition_name, int count) {
        amunition = amunition_name;
        shoot_count = count;
    }

    virtual ~Shooter() {}
};

class Catapulta : public Shooter {
public:
    void shoot() override {
        if (shoot_count > 0) {
            shoot_count--;
            cout << "Stone been shot by catapulta!" << endl;
        }
        else {
            cout << "No stones left!" << endl;
        }
    }

    Catapulta(int count) {
        this->shoot_count = count;
        this->amunition = "stone";
    }
};

class Archer : public Shooter {
public:
    Archer(string amunition, int shoot_count) {
        this->amunition = amunition;
        this->shoot_count = shoot_count;
    }
};

class Ranger : public Shooter {
public:
    Ranger(string amunition, int shoot_count) {
        this->amunition = amunition;
        this->shoot_count = shoot_count;
    }
};

class ArcherTower {
private:
    Archer archer;
    Ranger ranger;

public:
    ArcherTower(int shoot_count) : archer("arrow", shoot_count), ranger("arrow", shoot_count) {}

    void Archershoot() {
        archer.shoot();
    }

    void Rangershoot() {
        ranger.shoot();
    }

    void giveAmmunition(int count) {
        archer.give_amunition("arrow", count);
        ranger.give_amunition("arrow", count);
    }
};

class Fortress {
private:
    ArcherTower tower;
    Catapulta catap;
    int tower_hp = 100;

public:
    Fortress(int count) : tower(count), catap(count) {}

    void Archershoot() {
        tower.Archershoot();
        tower_hp -= 5;
        check();
    }

    void Rangershoot() {
        tower.Rangershoot();
        tower_hp -= 5;
        check();
    }

    void Catapultashoot() {
        catap.shoot();
        tower_hp -= 25;
        check();
    }

    void check() {
        if (tower_hp <= 0) {
            cout << "Tower Destroyed!!!!" << endl;
        }
    }
};
