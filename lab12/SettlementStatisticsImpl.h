#ifndef LAB12_SETTLEMENTSTATISTICSIMPL_H
#define LAB12_SETTLEMENTSTATISTICSIMPL_H

// declarations

#include <map>
#include "SettlementStatistics.h"

class SettlementStatisticsImpl : public SettlementStatistics {
public:
    SettlementStatisticsImpl(const string& filename);
    virtual int numSettlements() const override;
    virtual int numCounties() const override;
    virtual int numSettlementsByCounty(const string& county) const override;
    virtual vector<Settlement> findSettlementsByCounty(const string& county) const override;
    virtual Settlement findSettlementsByNameAndCounty(const string& name, const string& county) const override;
    virtual Settlement maxPopulationDensity() const override;
    virtual Settlement minPopulationDensity() const override;
    virtual vector<Settlement> findSettlementsByName(const string& name) override;

private:
    multimap<string, Settlement> settlementsByCounty;
};

#endif //LAB12_SETTLEMENTSTATISTICSIMPL_H
