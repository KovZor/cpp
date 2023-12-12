#include <iostream>
#include <algorithm>
#include "Settlement.h"
#include "SettlementStatistics.h"
#include "SettlementStatisticsImpl.h"

using namespace std;

int main() {
    SettlementStatistics* settlementStatistics = new SettlementStatisticsImpl("telepulesek.csv");
    cout << "Num. Settlements: " << settlementStatistics->numSettlements() << endl;
    cout << "Num. Counties: " << settlementStatistics->numCounties() << endl;
    cout << "Num. Settlements in MS: " << settlementStatistics->numSettlementsByCounty("MS") << endl;
    for( const auto it : settlementStatistics->findSettlementsByCounty("MS") ){
        cout << it << endl;
    }
    cout << settlementStatistics->findSettlementsByNameAndCounty("Miercurea Nirajului", "MS") << endl;
    cout << "Max population density: " << settlementStatistics->maxPopulationDensity() << endl;
    cout << "Min population density: " << settlementStatistics->minPopulationDensity() << endl;
    for( const auto it : settlementStatistics->findSettlementsByName("Targu Mures") ){
        cout << it << endl;
    }




    // last steps
    delete settlementStatistics;

    return 0;
}