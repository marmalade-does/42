#!/bin/sh
#find
find . -name "*.sh" -exec basename {} + | sed 's/.sh$//'


#clean
find . -type f -name -print -delete "*~" -o -type f -name "#*#" -print -delete


#///////////
#// find . -name "*.sh" // Ffind all files ending with .sh
#// -exec basename {} + // Execute the basename command (not showing all the path). 
#//// '{}' place holder for current files
#//// '+' --> do the basename command in batch
#// | sed 's/.sh$//' <-- pipeline replacing ".sh$" with nothing (removing it)

