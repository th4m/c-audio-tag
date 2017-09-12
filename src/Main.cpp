#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <taglib/tbytevector.h>
#include <taglib/id3v2tag.h>
#include <taglib/id3v2frame.h>
#include <taglib/mpegfile.h>

#include "MP3.hpp"

using namespace TagLib;

int main (int argc, char * argv[]) {
  if (argc != 2) {
    printf("Wrong amount of arguments. Argument should be a filepath.\nTry again.\n");
    exit(EXIT_FAILURE);
  }

  MPEG::File mp3File(argv[1]);
  ID3v2::Tag * mp3Tag;

  mp3Tag = mp3File.ID3v2Tag();
  if (mp3Tag) {
    MP3 mp3(mp3Tag);

    std::string str = mp3.metaInString();

    std::cout << str;
  }
  return 0;
}
