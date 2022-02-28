#include <iostream>
#include <vector>
#include <ctime>

//Лаба по Синглтону

using namespace std;

class Player {
public:
	Player(string name) {
		this->name;
	}
	string name;
};

class First :public Player {
public:
	First() :Player("Master") {};
};

class Second :public Player {
public:
	Second() :Player("Beginner") {};
};

class Darts {
public:
	static Darts& getInstance() {
		static Darts* d = new Darts();
		return *d;
	}

	void add(Player* player) {
		players.push_back(player);
	}

	void DropDarts(Player* player) {
		Shot = rand() % 10;
		Score += Shot;
		cout << "Счёт игрока " << player << " = " << Score;

	}

private:
	vector <Player*> players;
	Darts() = default;
	Darts(const Darts*) = delete;
	Darts& operator = (const Darts&) = delete;
	Darts(Darts&&) = delete;
	Darts& operator=(Darts&&) = delete;

	int Shot = 0;
	int Score = 0;
};

int main() {
	setlocale(LC_ALL, "Ru");
	srand(time(0));
	Darts &d = Darts::getInstance();

	d.add(new First());
	d.DropDarts(new First());
	d.add(new Second());

	return 0;
}