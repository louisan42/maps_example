#include<iostream>
#include<map>
#include<string>


int main() {
	int choice{ 0 };
	std::string nameOfBook{}; //value
	std::string fName{}; // key
	//std::map<std::string, std::string> myBooks{ {"louis","dragon"},{"marvel","avengers"},{"dietel","learn c++"}};
	//uncomment below to use multimap
	std::multimap<std::string, std::string> myBooks{ {"louis","dragon"},{"marvel","avengers"},{"dietel","learn c++"},{"louis","ball-z"}};
	size_t results{ 0u };
	bool exit = false;

	while (!exit)
	{
		std::cout << "----------------------------------------" << std::endl;
		std::cout << "1. Insert item\n" <<
			"2. Delete item\n" <<
			"3. Size Of map\n" <<
			"4. Find Item\n" <<
			"5. Number of values against a key\n" <<
			"6. Exit\n\n";
		std::cout << "Enter choice: ";
		std::cin >> choice;

		switch (choice)
		{
		case 1:
			nameOfBook.clear();
			fName.clear();
			std::cout << "Enter name of book to insert: ";
			std::cin >> nameOfBook;
			//std::cout << std::endl;
			std::cout << "Enter firstname of author: ";
			std::cin >> fName;
			myBooks.insert(std::pair<std::string, std::string>(fName, nameOfBook));
			break;
		case 2:
			fName.clear();
			std::cout << "Enter firstname of author of book to be removed: ";
			std::cin >> fName;
			std::cout << std::endl;
			results = myBooks.erase(fName);
			results == 1 ? std::cout << fName << " deleted\n" : std::cout << fName << " not found!\n";
			break;
		case 3:
			std::cout << "Size of map is " << myBooks.size() << std::endl;
			break;
		case 4:
			fName.clear();
			std::cout << "Enter key for item to search: ";
			std::cin >> fName;
			std::cout << std::endl;
			if (myBooks.count(fName) != 0) {
				std::cout << "Item found!\n" <<
					"Entries are:\n" <<
					"Firstname: " << myBooks.find(fName)->first << std::endl <<
					"Book: " << myBooks.find(fName)->second << std::endl;
			}
			else {
				std::cout << "Item not found" << std::endl;
			}
			break;
		case 5:
			fName.clear();
			std::cout << "Enter the key at which to count Values: ";
			std::cin >> fName;
			std::cout << "Number of value(s) is " << myBooks.count(fName) << std::endl;
			break;
		case 6:
			exit = true;
			break;
		default:
			std::cout << "Wrong option!" << std::endl;
			break;
		}

	}


	return 0;
}