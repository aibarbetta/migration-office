#include "MinisterOfSecurity.h"
#include "catch.hpp"
#include <list>

TEST_CASE("Minister") {
    MinisterOfSecurity m("../resources/alerts.txt");
    Alerts& a = m.get_alerts();
    REQUIRE(a.get_items().size() == 3);
}