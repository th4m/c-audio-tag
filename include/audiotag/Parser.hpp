#include <string.h>
#include <fstream>

#include <taglib/id3v2tag.h>

using namespace TagLib::ID3v2;

class Parser
{
private:
  std::string trim(std::string);
  bool contains(std::string, std::string fnd);
public:
  Tag* fileToTag(std::string);
};
