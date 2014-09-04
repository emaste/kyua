// Copyright 2010 Google Inc.
// All rights reserved.
//
// Redistribution and use in source and binary forms, with or without
// modification, are permitted provided that the following conditions are
// met:
//
// * Redistributions of source code must retain the above copyright
//   notice, this list of conditions and the following disclaimer.
// * Redistributions in binary form must reproduce the above copyright
//   notice, this list of conditions and the following disclaimer in the
//   documentation and/or other materials provided with the distribution.
// * Neither the name of Google Inc. nor the names of its contributors
//   may be used to endorse or promote products derived from this software
//   without specific prior written permission.
//
// THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
// "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
// LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
// A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
// OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
// SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
// LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
// DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
// THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
// (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
// OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

/// \file engine/test_case.hpp
/// Interface to interact with test cases.

#if !defined(ENGINE_TEST_CASE_HPP)
#define ENGINE_TEST_CASE_HPP

#include "model/test_case_fwd.hpp"
#include "model/test_result_fwd.hpp"
#include "utils/config/tree.hpp"
#include "utils/fs/path.hpp"

namespace engine {


/// Hooks to introspect the execution of a test case.
///
/// There is no guarantee that these hooks will be called during the execution
/// of the test case.  There are conditions in which they don't make sense.
///
/// Note that this class is not abstract.  All hooks have default, empty
/// implementations.  The purpose of this is to simplify some tests that need to
/// pass hooks but that are not interested in the results.  We might want to
/// rethink this and provide an "empty subclass" of a base abstract template.
class test_case_hooks {
public:
    virtual ~test_case_hooks(void);

    virtual void got_stdout(const utils::fs::path&);
    virtual void got_stderr(const utils::fs::path&);
};


model::test_result debug_test_case(
    const model::test_case*, const utils::config::tree&,
    test_case_hooks&, const utils::fs::path&,
    const utils::fs::path&, const utils::fs::path&);
model::test_result run_test_case(
    const model::test_case*, const utils::config::tree&,
    test_case_hooks&, const utils::fs::path&);


}  // namespace engine


#endif  // !defined(ENGINE_TEST_CASE_HPP)
