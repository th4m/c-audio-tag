#include "audiotag/MP3.hpp"

#include <taglib/id3v2tag.h>

using namespace TagLib::ID3v2;

// Gets the tag and assigns all metadata to the data structure.
MP3::MP3(Tag* _tag)
{
  if (tag) { // If not null, assign metadata
    tag     = _tag;

    title   = tag->title();
    artist  = tag->artist();
    album   = tag->album();
    comment = tag->comment();
    genre   = tag->genre();
    year    = tag->year();
    track   = tag->track();
  }
}

std::string MP3::metaInString()
{
  std::string str = std::string();

  str += "Title:   ";
  str += title.toCString();
  str += "\n";

  str += "Artist:  ";
  str += artist.toCString();
  str += "\n";

  str += "Album:   ";
  str += album.toCString();
  str += "\n";

  str += "Comment: ";
  str += formattedComment();
  str += "\n";

  str += "Genre:   ";
  str += genre.toCString();
  str += "\n";

  str += "Year:    ";
  str += std::to_string(year);
  str += "\n";

  str += "Track:   ";
  str += std::to_string(track);
  str += "\n";

  return str;
}

// Formats the comment for cases where it is several lines by adding some spaces
// at the start of each line.
// TODO: Replace with something more elegant.
std::string MP3::formattedComment()
{
  std::string str = std::string(comment.toCString());
  std::string res = std::string();
  std::string cutoff = "\n";
  size_t pos;
  int rowCount = 0;

  while ( ( pos = str.find(cutoff) ) != std::string::npos )
    {
      str.erase(0, pos + cutoff.length());
      rowCount++;
    }

  str = std::string(comment.toCString());

  // Add the first line
  pos = str.find(cutoff);
  res += str.substr(0, pos);
  str.erase(0, pos + cutoff.length());

  // Add the rest of the lines
  for ( int i = 0; i < rowCount; i++ )
    {
      res += "\n         ";
      pos = str.find(cutoff);
      res += str.substr(0, pos);
      str.erase(0, pos + cutoff.length());
    }
  return res;
}
