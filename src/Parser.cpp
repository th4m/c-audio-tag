#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sstream>
#include <fstream>

#include <taglib/id3v2tag.h>

using namespace TagLib::ID3v2;

// Helper functions

std::string trim (std::string str)
{
  size_t first = str.find_first_not_of(' ');
  size_t last = str.find_last_not_of(' ');

  return str.substr(first, last - first + 1);
}

bool contains (std::string str, std::string fnd)
{
  return str.find(fnd) != std::string::npos;
}


// Parse strings in file to tag
Tag* readFile (std::ifstream file)
{
  std::string line;
  Tag * tag = new Tag();
  while (std::getline(file, line))
    {
      // Assuming one-line tags written in file
      size_t first = line.find_first_of(':') + 1;
      if (contains(line, "#Title:"))
        {
          tag->setTitle(trim(line.substr(first)));
        }
      else if (contains(line, "#Artist:"))
        {
          tag->setArtist(trim(line.substr(first)));
        }
      else if (contains(line, "#Album:"))
        {
          tag->setAlbum(trim(line.substr(first)));
        }
      else if (contains(line, "#Comment:"))
        {
          tag->setComment(trim(line.substr(first)));
        }
      else if (contains(line, "#Genre:"))
        {
          tag->setGenre(trim(line.substr(first)));
        }
      else if (contains(line, "#Year:"))
        {
          tag->setYear(std::stoul(trim(line.substr(first))));
        }
      else if (contains(line, "#Track:"))
        {
          tag->setTrack(std::stoul(trim(line.substr(first))));
        }
    }
  return tag;
}
