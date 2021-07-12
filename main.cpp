#include <iostream>
using namespace std;

const unsigned int DEFOULT_TANK_VOLUME = 60;
const double DEFOULT_ENGINE_CONSUMPTION = 8;
const unsigned int DEFOULT_MAX_SPEED = 250;

class Tank		//Топливный бак
{
	const unsigned int VOLUME; // объем бака
	double fuel_level;		// уровень топлива
public: 
	unsigned int get_volume() const
	{
		return VOLUME;
	}
	double get_fuel_level() const
	{
		return fuel_level;
	}
		void fill(double amount)
	{
		// amount - количество топлива
		if (amount < 0)return;
		if (fuel_level + amount < VOLUME)fuel_level += amount;
		else (fuel_level = VOLUME);
	 }
	double give_fuel(double amount)
	{
		if (fuel_level - amount > 0)fuel_level -= amount;
		else fuel_level = 0;
		return fuel_level;
	}
	Tank(const unsigned int VOLUME):VOLUME(VOLUME>=20 && VOLUME<=80 ? VOLUME:DEFOULT_TANK_VOLUME), fuel_level(0)
	
	{
		cout << "Tank is ready\t" << this << endl;
	}
	~Tank()

	{
		cout << "Tank is over\t" << this << endl;
	}
	void info()const
	{
		cout << "Tank volume: " << VOLUME << " liters\n";
		cout << "Fuel level: " << fuel_level << " liters\n";
	}

};

class Engine
{
	// Этот класс описывает двигатель
	const double CONSUMPTION;		// расход на 100 км
	double consumption_per_second;		//расход за одну секунду


	bool started;

public:
	const double get_consumpion() const
		{
			return CONSUMPTION;
		} 
	double get_consumption_per_second()const
	{
		return consumption_per_second;
	}
	bool is_started()const
	{
		return started;
	}
	void start()
	{
		started = true;
	}
	void stop()
	{
		started = false;
	}
	Engine(double consumption) :CONSUMPTION(consumption >= 4 && consumption <= 25 ? consumption : DEFOULT_ENGINE_CONSUMPTION)
	{
		this->consumption_per_second = this->CONSUMPTION * 5e-05;
		started = false;
		cout << "Engine is ready\t" << this << endl;

	}
	~Engine()
	{
		cout << "Engine is over\t" << this << endl;

	}
	void info() const
	{ 
		cout << "Engine consumes: " << CONSUMPTION << " liters per 100 km"<< endl;
		cout << "Engine consumes : " << consumption_per_second<<" liters per 1 second in IDLE" << endl;
		cout << "Engine is " << (started ? "started" : "stopped") << endl;
	}

};

class Car
{
	Tank tank;
	Engine engine;
	unsigned int speed;			// ткущая скорость
	unsigned int MAX_SPEED;

public:
	
	Car(double engine_consumption, unsigned int tank_volume, unsigned int MAX_SPEDD=DEFOULT_MAX_SPEED) :
		engine(engine_consumption), tank(tank_volume),
		speed(0), MAX_SPEED(MAX_SPEED>=100 && MAX_SPEED <=350?MAX_SPEED:DEFOULT_MAX_SPEED)
	{
		cout << "Your car is ready to go. Press Enter to get in." << this << endl;
	}
	~Car()
	{
		cout << "Your car is over:-(" << this << endl;
	}
	void info() const
	{
		tank.info();
		engine.info();
		cout << "Max speed:\t" << MAX_SPEED << "km/h" << endl;;
		cout << "Current speed:\t" << speed << "km/h" << endl;
	}


};

//#define TANK_CHECK
//#define ENGINE_CHECK

void main()
{
	setlocale(LC_ALL, "");
#ifdef TANK_CHECK
	Tank tank(11);
	tank.info();
	tank.fill(3);
	tank.info();
	tank.fill(30);
	tank.info();
	tank.fill(30);
	tank.info();
#endif // TANK_CHECK
#ifdef ENGINE_CHECK

	Engine engine(6);
	engine.info();
	engine.start();
	engine.info();


#endif // ENGINE_CHECK

	Car car(9, 75);
	car.info();



}