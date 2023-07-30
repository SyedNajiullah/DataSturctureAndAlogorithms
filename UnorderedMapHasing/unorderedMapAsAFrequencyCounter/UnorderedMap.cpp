#include<iostream>
#include<string>
#include<unordered_map>
#include<fstream>

void read(std::ifstream& fin, std::unordered_map<std::string, int>& umap);
void write(std::ofstream& fout, std::unordered_map<std::string, int>& umap);

int main(){

	std::unordered_map<std::string, int> umap;
	
	
	std::ifstream fin;
	fin.open("words.txt");
	read(fin, umap);
	
	std::ofstream fout;
	fout.open("frequency.txt");
	write(fout, umap);

	return 0;
}

void read(std::ifstream& fin, std::unordered_map<std::string, int>& umap){
	if (fin){
		std::string word = "\0";
		while (!fin.eof()){
			fin >> word;
			umap[word]++;
		}
	}
	else{
		std::cout << "File not found" << std::endl;
	}
}
void write(std::ofstream& fout, std::unordered_map<std::string, int>& umap){
	for (auto i : umap){
		fout << i.first << " " << i.second << std::endl;
	}
}