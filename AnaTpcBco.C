#include "AnaTpcBco.h"
#include <sstream>
#include <string>
#include <iostream>
R__LOAD_LIBRARY(libAnaTpcBco.so)

void AnaTpcBco(const char * infile, bool isTPC, const std::string& type)
{
  std::string infilename;
  std::ostringstream ofilename;
  ofilename.str("");
  if(isTPC)
    {
      
      ofilename << "/sphenix/lustre01/sphnxpro/physics/tpc/"<<type.c_str()
		<<"/"<<infile;
      infilename = ofilename.str();
    }
  else if(!isTPC)
    {
      ofilename << "/sphenix/lustre01/sphnxpro/physics/GL1/"<<type.c_str()
		<<"/"<<infile;
      infilename = ofilename.str();
    }
  const char *filename = infilename.c_str();
    if ( filename != NULL)
    {
      pfileopen(filename);
      getfilename(filename);
      pinit();
      prun();
      pclose();
    }
}
