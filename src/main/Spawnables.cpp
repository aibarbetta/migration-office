#include "Spawnables.h"

Spawnables::iterator Spawnables::begin() {
    return items.begin();
}

Spawnables::iterator Spawnables::end() {
    return items.end();
}

Spawnables::iterator Spawnables::erase(Spawnables::iterator iterator) {
    return items.erase(iterator);
}

void Spawnables::sort_by_ascending_timestamp() {
    items.sort();
}

bool Spawnables::empty() {
    return items.empty();
}

void Spawnables::push_spawnable(int timestamp, Spawnable *spawnable){
    items.emplace_back(std::make_pair(timestamp,spawnable));
}

std::list<std::pair<int, Spawnable*>>& Spawnables::get_items() {
    return items;
}

Spawnables::~Spawnables() {
    while (!items.empty()) {
        delete items.back().second;
        items.pop_back();
    }
}

