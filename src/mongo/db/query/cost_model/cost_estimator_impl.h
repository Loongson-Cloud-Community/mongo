/**
 *    Copyright (C) 2022-present MongoDB, Inc.
 *
 *    This program is free software: you can redistribute it and/or modify
 *    it under the terms of the Server Side Public License, version 1,
 *    as published by MongoDB, Inc.
 *
 *    This program is distributed in the hope that it will be useful,
 *    but WITHOUT ANY WARRANTY; without even the implied warranty of
 *    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *    Server Side Public License for more details.
 *
 *    You should have received a copy of the Server Side Public License
 *    along with this program. If not, see
 *    <http://www.mongodb.com/licensing/server-side-public-license>.
 *
 *    As a special exception, the copyright holders give permission to link the
 *    code of portions of this program with the OpenSSL library under certain
 *    conditions as described in each individual source file and distribute
 *    linked combinations including the program with the OpenSSL library. You
 *    must comply with the Server Side Public License in all respects for
 *    all of the code used other than as permitted herein. If you modify file(s)
 *    with this exception, you may extend this exception to your version of the
 *    file(s), but you are not obligated to do so. If you do not wish to do so,
 *    delete this exception statement from your version. If you delete this
 *    exception statement from all source files in the program, then also delete
 *    it in the license file.
 */

#pragma once

#include "mongo/db/query/cost_model/cost_model_gen.h"
#include "mongo/db/query/optimizer/cascades/interfaces.h"
#include "mongo/db/query/optimizer/cascades/memo.h"

namespace mongo::cost_model {
/**
 * Default costing for physical nodes with logical delegator (not-yet-optimized) inputs.
 */
class CostEstimatorImpl : public optimizer::cascades::CostEstimator {
public:
    CostEstimatorImpl(CostModelCoefficients coefficicients)
        : _coefficients{std::move(coefficicients)} {}

    optimizer::CostAndCE deriveCost(const optimizer::Metadata& metadata,
                                    const optimizer::cascades::Memo& memo,
                                    const optimizer::properties::PhysProps& physProps,
                                    optimizer::ABT::reference_type physNodeRef,
                                    const optimizer::ChildPropsType& childProps,
                                    const optimizer::NodeCEMap& nodeCEMap) const override final;

private:
    const CostModelCoefficients _coefficients;
};

}  // namespace mongo::cost_model