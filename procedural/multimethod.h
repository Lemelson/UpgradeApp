#ifndef IZ1_PROCEDURAL_MULTIMETHOD_H
#define IZ1_PROCEDURAL_MULTIMETHOD_H

#include "wisdom.h"

#include <ostream>
#include <string>

using ProceduralPairHandler = bool (*)(const Wisdom& first,
                                       const Wisdom& second,
                                       std::string& phrase);

void RegisterPairHandler(ProceduralPairHandler handler);

void PrintPairReport(const WisdomList& list, std::ostream& out);

#endif // IZ1_PROCEDURAL_MULTIMETHOD_H
