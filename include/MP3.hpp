#include <string.h>

#include <taglib/id3v2tag.h>
#include <taglib/tstring.h>

using namespace TagLib::ID3v2;

class MP3
{
private:
  Tag* tag;
  TagLib::String title;
  TagLib::String artist;
  TagLib::String album;
  TagLib::String comment;
  TagLib::String genre;
  unsigned int year;
  unsigned int track;
  std::string formattedComment();

public:
  MP3(Tag*);
  std::string metaInString();
};
