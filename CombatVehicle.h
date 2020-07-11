#pragma once
#include <iostream>
#include <string>

using namespace std;

class CombatVehicle {

protected:
	string type;
	string model;
	int health;

public:
	CombatVehicle() : type("No type"), model("No model"), health(0)
	{
	}
	CombatVehicle(string type, string model, int health)
		: type(type), model(model), health(health) {}
	
	virtual ~CombatVehicle() = 0 {};
	virtual bool IsDestroyed()  {

		return health <= 0;
	}
	virtual void ShowInfo() const {
		cout << "Type: " << type << endl;
		cout << "Model: " << model << endl;
		cout << "Health: " << health << endl;
	}

	virtual int Attack() = 0 {}
	virtual void Defense(int damage) = 0 {}
};

class Tank : public CombatVehicle
{
private:
	int R;
	int A;
	int T;
public:
	Tank() : R(0), A(0), T(0), CombatVehicle() {}
	Tank(int r, int a, int t, string type, string model, int health ) 
		: R(r), A(a), T(t), CombatVehicle("Tank", model, health) {}
	
	virtual int Attack() override  {
		return (100 * A / R);
	}
	virtual void Defense(int damage) override {
		health -= damage - T;
	}

	void ShowInfo() const override {
		
		CombatVehicle::ShowInfo();
		cout << "Reload time: " << R << endl;
		cout << "Shot accuracy: " << A << endl;
		cout << "Armor thickness: " << T << endl;
	}

};

class ArmoredCar : public CombatVehicle
{
private:
	int C;
	int S;	
public:
	ArmoredCar() : C(0), S(0), CombatVehicle() {}
	ArmoredCar(int c, int s, string type, string model, int health)
		: C(c), S(s), CombatVehicle("Armored Car", model, health) {}

	virtual int Attack() override {
		return (50*C);
	}
	virtual void Defense(int damage) override {
		health -= damage - S/2;
	}

	void ShowInfo() const override {

		CombatVehicle::ShowInfo();
		cout << "Number of weapons: " << C << endl;
		cout << "Speed: " << S << endl;		
	}
};

class AirDefenseVehicle : public CombatVehicle
{
private:
	int L;
	int R;
	int M;
public:
	AirDefenseVehicle() : L(0), R(0), M(0), CombatVehicle() {}
	AirDefenseVehicle(int l, int r, int m, string type, string model, int health)
		: L(l), R(r), M(m), CombatVehicle("Air Defense Vehicle", model, health) {}

	virtual int Attack() override {
		return (150+L*(R/10));
	}
	virtual void Defense(int damage) override {
		health -= damage /M;
	}

	void ShowInfo() const override {

		CombatVehicle::ShowInfo();
		cout << "Range: " << L << endl;
		cout << "Firing speed: " << R << endl;
		cout << "Mobility: " << M << endl;
	}
};

bool Round(CombatVehicle& bm1, CombatVehicle& bm2);