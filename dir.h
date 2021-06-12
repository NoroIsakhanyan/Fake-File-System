#ifndef DIR
#define DIR
#include <iostream>
#include <string>
#include <vector>
#include <memory>

class dir{
public:
	dir(const std::string& name);
	~dir();
public:
	std::string& getName();
	std::vector<dir*>& getDirectories();
	std::vector<std::string>& getFiles();
private:
	std::string m_name;
	std::vector<dir*> m_directories;
	std::vector<std::string> m_files;
};


#endif //DIR