// definitions

#include <fstream>
#include <sstream>
#include <algorithm>
#include <set>
#include <limits>
#include "SettlementStatisticsImpl.h"

SettlementStatisticsImpl::SettlementStatisticsImpl(const string& filename) {
    ifstream file(filename);
    string line;

    while( getline(file, line) ) {
        stringstream ss(line);
        string name, county;
        int population;

        getline(ss, name, ',');
        getline(ss, county, ',');
        ss >> population;

        Settlement settlement( name, county, population );
        settlementsByCounty.insert( make_pair(county, settlement) );
    }
}

int SettlementStatisticsImpl::numSettlements() const {
    return settlementsByCounty.size();
}

int SettlementStatisticsImpl::numCounties() const {
    set<string> counties;
    for (const auto& entry : settlementsByCounty) {
        counties.insert(entry.first);
    }
    return counties.size();
}

int SettlementStatisticsImpl::numSettlementsByCounty(const string& county) const {
    return settlementsByCounty.count(county);
}

vector<Settlement> SettlementStatisticsImpl::findSettlementsByCounty(const string& county) const {
    vector<Settlement> settlements;
    auto range = settlementsByCounty.equal_range(county);

    for (auto it = range.first; it != range.second; ++it) {
        settlements.push_back(it->second);
    }
    return settlements;
}

Settlement SettlementStatisticsImpl::findSettlementsByNameAndCounty(const string& name, const string& county) const {
    auto range = settlementsByCounty.equal_range(county);
    auto it = find_if(range.first, range.second, [&](const auto& entry) {
        return entry.second.getName() == name;
    });

    if (it != range.second) {
        return it->second;
    } else {
        throw out_of_range("No settlement found");
        return Settlement("", "", 0);
    }
}

Settlement SettlementStatisticsImpl::maxPopulationDensity() const {
        Settlement maxDensitySettlement("", "", 0);
        double maxDensity = -1.0;

        for( const auto& entry : settlementsByCounty ) {
            const Settlement& settlement = entry.second;

            double density = static_cast<double>(settlement.getPopulation());

            if (density > maxDensity) {
                maxDensity = density;
                maxDensitySettlement = settlement;
            }
        }

        return maxDensitySettlement;
}


Settlement SettlementStatisticsImpl::minPopulationDensity() const {
    Settlement minDensitySettlement("", "", numeric_limits<int>::max());
    int minDensity = numeric_limits<int>::max();

    for( const auto &entry : settlementsByCounty ){
        const Settlement& settlement = entry.second;

        int density = static_cast<int>( settlement.getPopulation() );

        if( density < minDensity ){
            minDensity = density;
            minDensitySettlement = settlement;
        }
    }

    return minDensitySettlement;
}

vector<Settlement> SettlementStatisticsImpl::findSettlementsByName(const string& name) {
    vector<Settlement> settlements;
    for (const auto& entry : settlementsByCounty) {
        if (entry.second.getName() == name) {
            settlements.push_back(entry.second);
        }
    }
    return settlements;
}
