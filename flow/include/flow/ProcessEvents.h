/*
 * ProcessEvents.h
 *
 * This source file is part of the FoundationDB open source project
 *
 * Copyright 2013-2023 Apple Inc. and the FoundationDB project authors
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#ifndef FLOW_PROCESS_EVENTS_H
#define FLOW_PROCESS_EVENTS_H
#include <functional>
#include "flow/flow.h"

namespace ProcessEvents {

// A callback is never allowed to throw. Since std::function can't
// take noexcept signatures, this is enforced at runtime
using Callback = std::function<void(StringRef, StringRef, Error const&)>;

class Event : NonCopyable {
	void* impl;

public:
	Event(StringRef name, Callback callback);
	Event(std::vector<StringRef> name, Callback callback);
	~Event();
};

void trigger(StringRef name, StringRef msg, Error const& e);

} // namespace ProcessEvents

#endif // FLOW_PROCESS_EVENTS_H
