/*
 * Copyright © 2017 Collabora Ltd.
 *
 * This file is part of vkmark.
 *
 * vkmark is free software: you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation, either
 * version 2.1 of the License, or (at your option) any later version.
 *
 * vkmark is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with vkmark. If not, see <http://www.gnu.org/licenses/>.
 *
 * Authors:
 *   Alexandros Frantzis <alexandros.frantzis@collabora.com>
 */

#pragma once

#include <memory>

struct Options;
class WindowSystem;

class WindowSystemLoader
{
public:
    WindowSystemLoader(Options const& options);

    WindowSystem& load_window_system();

private:
    using LibHandle = std::unique_ptr<void,void(*)(void*)>;

    std::string probe_for_best_window_system();

    Options const& options;
    LibHandle lib_handle;
    std::unique_ptr<WindowSystem> window_system;
};