# What is this?
An audio file meta-data tagger made in C++, albeit rough.
It uses the TagLib library to read and edit the meta-data of MP3-files.

# How does it work?
After building it, run the binary in the bin folder with an MP3-file and a text-file. The meta-data in the MP3-file will then be replaced with the contents of the text-file. An example text-file exists in the examples folder.

# Future work
* Allow the user decide how the text-file is formatted.
* Allow for more than one MP3-file to have its meta-data replaced.
* Improve error checking.
* More...
