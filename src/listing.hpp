// listing.hpp

#ifndef LISTING_HPP
#define LISTING_HPP

#include <cstdint>

void OpenListFile(const char* sourceFileName);
void CloseListFile();
void DeleteListFile();
void Listing(const char*, ...);
void ListOp(uint8_t);
void ListArg(const char*, ...);
void ListAsCode(const char*, ...);
void ListWord(uint16_t);
void ListByte(uint8_t);
void ListOffset();
void ListText(const char*);
void ListingNoCRLF(const char* parms, ...);
void ListSourceLine(int num);

extern bool listCode;

#endif
