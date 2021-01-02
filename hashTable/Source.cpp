#include<iostream>
#include<vector>

class HashTable {
public:
	int length = 4;
	std::vector<std::vector<std::vector<std::string>>> keyMap;
	HashTable(int size = 4) {
		length = size;
		keyMap.resize(length);
	}
	int hash(const std::string& key) {
		int total = 0;
		int WEIRD_PRIME = 13;
		for (unsigned int i = 0; i < key.size(); i++) {
			char letter = key[i];
			int value = letter - 96;
			total = (total * WEIRD_PRIME + value) % length;
		}
		return total;
	}

	void set(const std::string& key, const std::string& value) {
		int index = hash(key);
		std::vector<std::string> pair = { key,value };
		keyMap[index].push_back(pair);
	}

	std::string& get(const std::string& key) {
		int index = hash(key);
		if (!keyMap[index].empty()) {
			for (int i = 0; i < length; i++) {
				if (keyMap[index][i][0] == key) {
					return keyMap[index][i][1];
				}
			}
		}


	}
	std::string& operator[](const std::string& key) {
		return get(key);
	}
	std::vector<std::string> keys() {
		std::vector<std::string> keysArr;
		for (int i = 0; i < length; i++) {
			if (!keyMap[i].empty()) {
				for (unsigned int j = 0; j < keyMap[i].size(); j++) {
					keysArr.push_back(keyMap[i][j][0]);
				}
			}
		}
		return keysArr;
	}
	std::vector<std::string> values() {
		std::vector<std::string> valuesArr;
		for (int i = 0; i < length; i++) {
			if (!keyMap[i].empty()) {
				for (unsigned int j = 0; j < keyMap[i].size(); j++) {
					valuesArr.push_back(keyMap[i][j][1]);
				}
			}
		}
		return valuesArr;
	}
	void print() {
		for (int i = 0; i < length; i++) {
			if (!keyMap[i].empty()) {
				for (unsigned int j = 0; j < keyMap[i].size(); j++) {
					std::cout << keyMap[i][j][0] << " : " << keyMap[i][j][1] << "\n";
				}
			}
		}
	}

};

//test code

int main() {
	HashTable ht1;
	std::cout << "The hash of hello is " << ht1.hash("hello");
	std::cout << "\nThe hash of french is " << ht1.hash("french");
	std::cout << "\nThe hash of french is " << ht1.hash("french");

	ht1.set("hello world", "goodbye!!");
	ht1.set("dogs", "are cool");
	ht1.set("cats", "are fine");
	ht1.set("i love", "pizza");
	ht1.set("french", "fries");
	std::cout << "\nThe hash table is now: \n";
	ht1.print();
	std::string value = ht1.get("dogs");
	std::cout << "\nThe value of the key dogs are : " << value;
	std::cout << "\nThe value of the key cats are : " << ht1["cats"];

	std::cout << "\nThe values of the table are: ";
	std::vector<std::string> values = ht1.values();
	for (unsigned i = 0; i < values.size(); i++) {
		std::cout << values[i] << " " << ",";
	}
	std::cout << "\nThe keys of the table are: ";

	std::vector<std::string> keys = ht1.keys();
	for (unsigned int i = 0; i < keys.size(); i++) {
		std::cout << keys[i] << " " << ",";
	}
}


