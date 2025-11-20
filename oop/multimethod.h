#ifndef IZ1_OOP_MULTIMETHOD_H
#define IZ1_OOP_MULTIMETHOD_H

#include "wisdom_collection.h"

#include <ostream>
#include <string>

class WisdomEntry;

using OopPairHandler = bool (*)(const WisdomEntry& first,
                                const WisdomEntry& second,
                                std::string& phrase);

void RegisterPairHandler(OopPairHandler handler);

void PrintPairReport(const WisdomCollection& collection, std::ostream& out);

#endif // IZ1_OOP_MULTIMETHOD_H
