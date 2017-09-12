#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <taglib/tbytevector.h>
#include <taglib/id3v2tag.h>
#include <taglib/id3v2frame.h>
#include <taglib/mpegfile.h>

#include <audiotag/MP3.hpp>
#include <audiotag/Parser.hpp>

using namespace TagLib;

int main (int argc, char * argv[]) {
  if (argc != 3)
    {
      printf("Wrong amount of arguments. Argument should be filepath to MP3-file and filepath to the file containing the new metadata.\nTry again.\n");
      exit(EXIT_FAILURE);
    }

  MPEG::File mp3File(argv[1]); // TODO: Check if file exists
  ID3v2::Tag * mp3Tag;
  std::string metafile(argv[2]); // TODO: Check if file exists

  mp3Tag = mp3File.ID3v2Tag();
  if (mp3Tag)
    {
      MP3 mp3(mp3Tag);
      // std::cout << mp3.metaInString() << std::endl;

      Parser* parser;
      ID3v2::Tag* newTag = parser->fileToTag(metafile);
      MP3 newMP3(newTag);

      std::cout << mp3.metaInString() << std::endl
                << "Change to:" << std::endl << std::endl
                << newMP3.metaInString() << std::endl;

      mp3.replace(newTag);
      mp3File.save();

    }
  return 0;
}
