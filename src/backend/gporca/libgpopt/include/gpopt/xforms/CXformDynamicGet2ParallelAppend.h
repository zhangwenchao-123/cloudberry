/*-------------------------------------------------------------------------
 *
 * Licensed to the Apache Software Foundation (ASF) under one
 * or more contributor license agreements.  See the NOTICE file
 * distributed with this work for additional information
 * regarding copyright ownership.  The ASF licenses this file
 * to you under the Apache License, Version 2.0 (the
 * "License"); you may not use this file except in compliance
 * with the License.  You may obtain a copy of the License at
 *
 *   http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing,
 * software distributed under the License is distributed on an
 * "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY
 * KIND, either express or implied.  See the License for the
 * specific language governing permissions and limitations
 * under the License.
 *
 * CXformDynamicGet2ParallelAppend.h
 *
 * IDENTIFICATION
 *	  src/backend/gporca/libgpopt/include/gpopt/xforms/CXformDynamicGet2ParallelAppend.h
 *
 *-------------------------------------------------------------------------
 */
#ifndef GPOPT_CXformDynamicGet2ParallelAppend_H
#define GPOPT_CXformDynamicGet2ParallelAppend_H

#include "gpos/base.h"

#include "gpopt/operators/CLogicalDynamicGet.h"
#include "gpopt/xforms/CXformImplementation.h"

namespace gpopt
{
using namespace gpos;

//---------------------------------------------------------------------------
//	@class:
//		CXformDynamicGet2ParallelAppend
//
//	@doc:
//		Transform DynamicGet to Parallel Append
//
//---------------------------------------------------------------------------
class CXformDynamicGet2ParallelAppend : public CXformImplementation
{
private:
public:
	CXformDynamicGet2ParallelAppend(
		const CXformDynamicGet2ParallelAppend &) = delete;

	// ctor
	explicit CXformDynamicGet2ParallelAppend(CMemoryPool *mp);

	// dtor
	~CXformDynamicGet2ParallelAppend() override = default;

	// ident accessors
	EXformId
	Exfid() const override
	{
		return ExfDynamicGet2ParallelAppendTableScan;
	}

	// return a string for xform name
	const CHAR *
	SzId() const override
	{
		return "CXformDynamicGet2ParallelAppend";
	}

	// compute xform promise for a given expression handle
	EXformPromise Exfp(CExpressionHandle &exprhdl) const override;

	// actual transform
	void Transform(CXformContext *pxfctxt, CXformResult *pxfres,
				   CExpression *pexpr) const override;

};	// class CXformDynamicGet2ParallelAppend

}	// namespace gpopt

#endif	// !GPOPT_CXformDynamicGet2ParallelAppend_H

// EOF
