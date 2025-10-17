#include "wisdom_factory.h"

#include "wisdom_entry.h"

#include <mutex>
#include <string>
#include <unordered_map>

namespace {
std::unordered_map<std::string, WisdomFactory::Creator>& Registry() {
    static std::unordered_map<std::string, WisdomFactory::Creator> instance;
    return instance;
}

std::mutex& RegistryMutex() {
    static std::mutex mutex;
    return mutex;
}
} // namespace

bool WisdomFactory::Register(std::string type_name, Creator creator) {
    std::lock_guard<std::mutex> lock(RegistryMutex());
    Registry()[std::move(type_name)] = std::move(creator);
    return true;
}

std::unique_ptr<WisdomEntry> WisdomFactory::Create(std::string_view type_name,
                                                   const std::string& origin,
                                                   const std::string& content) {
    std::lock_guard<std::mutex> lock(RegistryMutex());
    auto it = Registry().find(std::string(type_name));
    if (it == Registry().end()) {
        return nullptr;
    }
    return it->second(origin, content);
}
