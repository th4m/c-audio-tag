#include <string.h>
#include <fstream>

class Parser
{
private:
  std::string trim(std::string);
  bool contains(std::string, std::string fnd);
public:
 Tag* readFile(std::ifstream file);
};
