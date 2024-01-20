#include <iostream>
#include <fstream>
#include <string>
#include <random>
#include <vector>

class World {
public:
    int getTrauma() {
        int trauma;
        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_int_distribution<> dis(0, 100);
        trauma = dis(gen);
        return trauma;
    }
    int getExperience() {
        int exp;
        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_int_distribution<> dis(0, 100);
        exp = dis(gen);
        return exp;
    }
};

class Space : public World {
    double atomCount = 120310932138;
};

class SolarSystem : public Space {
    int planetCount = 8;
};

class Earth : public SolarSystem {
    double mass = 6 * 10 ^ 24;
};

class Nature : public Earth {
};

class Animal : public Nature {
    std::string species;
};

class People : public Animal {
public:
    std::string race;
    std::string socialCridits;
};

class Artist : public People {
private:
    std::string name;
    int inspirationLevel;
    int experience;
    int trauma;
public:
    Artist(std::string name) : name(name), inspirationLevel(), trauma(0), experience(0) {
        trauma = getTrauma();
        experience = getExperience();
        inspirationLevel = setInspirationLvl();
    }

    int setInspirationLvl() {
        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_int_distribution<> dis(0, 100);
        inspirationLevel = dis(gen);
        return inspirationLevel;
    }

    int getTraumLvl() const {
        return trauma;
    }

    int getExperiencLvl() const {
        return experience;
    }

    std::string getName() const {
        return name;
    }
};

class Painting {
private:
    std::string genre;
    std::string material;
    int price;
    Artist& artist;
public:
    Painting(std::string genre, std::string material, Artist& artist) : genre(genre), material(material), price(0), artist(artist){
        price = artist.getTraumLvl() * artist.getExperiencLvl() * artist.setInspirationLvl();
        std::cout << "Картина создана." << std::endl;
    }

    void printPrice() {
        std::cout << "Цена: " << getPrice() << "$" << std::endl;
    }

    std::string getGenre() const {
        return genre;
    }

    std::string getMaterial() const {
        return material;
    }

    std::string getName() const {
        return artist.getName();
    }

    int getPrice() const {
        return price;
    }

    friend std::ostream& operator<<(std::ostream& os, Painting& painting) {
        os << "Жанр: " << painting.getGenre() << std::endl;
        os << "Материал: " << painting.getMaterial() << std::endl;
        os << "Артист: " << painting.getName() << std::endl;
        os << "Цена: " << painting.getPrice() << "$" << std::endl;
        return os;
    }
};

int main() {
    setlocale(LC_ALL, "Russian");

    Artist artist("Леонадро");

    Painting painting1("Пейзаж", "Масло", artist);
    Painting painting2("Портрет", "Акварель", artist);

    std::cout << painting1;

    return 0;
}