/*
Copyright (C) 2018 Sysdig, Inc.

This file is part of sysdig.

Licensed under the Apache License, Version 2.0 (the "License");
you may not use this file except in compliance with the License.
You may obtain a copy of the License at

    http://www.apache.org/licenses/LICENSE-2.0

Unless required by applicable law or agreed to in writing, software
distributed under the License is distributed on an "AS IS" BASIS,
WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
See the License for the specific language governing permissions and
limitations under the License.

*/
#pragma once

#include "async_docker_metadata_source.h"

namespace sysdig
{

/**
 * Interface to async_windows_docker_metadata_source -- a concrete
 * async_docker_metadata_source for fetching docker metadata and metadata
 * on Windows.
 */
class async_windows_docker_metadata_source : public async_docker_metadata_source
{
public:
	const static std::string DEFAULT_API_VERSION;

	async_windows_docker_metadata_source(
			const std::string& api_version = DEFAULT_API_VERSION);

protected:
	std::string build_request(const std::string& path) override;
	sinsp_docker_response get_docker(sinsp_container_manager* manager,
	                                 const std::string& url,
	                                 std::string &json) override;
};

}