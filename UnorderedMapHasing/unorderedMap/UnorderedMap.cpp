#include<iostream>
#include<string>
#include<unordered_map>

//INSERTION 
void insert(int key, std::string value, std::unordered_map<int, std::string>& umap);
//DELETION
void deletion(int key, std::unordered_map<int, std::string>& umap);
//SEARCHING
bool searching(int key, std::unordered_map<int, std::string>& umap);
//Display
void display(std::unordered_map<int, std::string>& umap);


int main(){

	std::unordered_map<int, std::string> umap;

	int choose = 0;
	while (choose != 5){
		std::cout << "-------------------------" << std::endl;
		std::cout << "1. For insertion" << std::endl;
		std::cout << "2. Deletion" << std::endl;
		std::cout << "3. Searching" << std::endl;
		std::cout << "4. Display" << std::endl;
		std::cout << "5. Exit" << std::endl;
		std::cout << "-------------------------" << std::endl;
		std::cout << "Enter here :";
		std::cin >> choose;
		if (choose == 1){
			int key = 0;
			std::string value = "\0";
			std::cout << "Enter key :";
			std::cin >> key;
			std::cin.ignore();
			std::cout << "Enter value :";
			getline(std::cin, value);
			insert(key, value, umap);
		}
		else if (choose == 2){
			int key = 0;
			std::cout << "Enter key :";
			std::cin >> key;
			deletion(key, umap);
		}
		else if (choose == 3){
			int key = 0;
			std::cout << "Enter key :";
			std::cin >> key;
			if (searching(key, umap)){
				std::cout << "FOUND AT " << umap[key] <<std::endl;
			}
			else{
				std::cout << "NOT FOUND" << std::endl;
			}
		}
		else if (choose == 4){
			display(umap);
		}
		else if (choose == 5){
			break;
		}
		else{
			std::cout << " : Invalid enter again : " << std::endl;
		}
	}

	return 0;
}


void insert(int key, std::string value, std::unordered_map<int, std::string>& umap){
	umap[key] = value;
}
//DELETION
void deletion(int key, std::unordered_map<int, std::string>& umap){
	if (umap.find(key) != umap.end()){
		umap.erase(key);
		std::cout << "Deleted successfully" << std::endl;
	}
	else{
		std::cout << "Key is not present in hash" << std::endl;
	}
}
//SEARCHING
bool searching(int key, std::unordered_map<int, std::string>& umap){
	if (umap.find(key) != umap.end()){
		return true;
	}
	else{
		return false;
	}
}
//Display
void display(std::unordered_map<int, std::string>& umap){
	for (auto i : umap){
		std::cout << i.first << " " << i.second << std::endl;
	}
}